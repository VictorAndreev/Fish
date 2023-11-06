#include "gamewidget.h"

#include <QDebug>

#ifdef Q_WS_X11
    #include <Qt/qx11info_x11.h>
    #include <X11/Xlib.h>
#endif

GameWidget::GameWidget(QWidget *parent) : QWidget{parent}, initialized(false)
{
    srand(time(NULL));

    setAttribute(Qt::WA_PaintOnScreen);
    setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_NoSystemBackground);

    timer.setInterval(1000.0 / FPS);

    setFixedSize(QSize(WINDOW_WIDTH, WINDOW_HEIGHT));
}

void GameWidget::showEvent(QShowEvent *)
{
    if (!initialized)
    {
        #ifdef Q_WS_X11
            XFlush(QX11Info::display());
        #endif

        sf::RenderWindow::create(reinterpret_cast<sf::WindowHandle>(winId()), sf::ContextSettings(0, 0, 8));

        OnInit();

        connect(&timer, SIGNAL(timeout()), this, SLOT(repaint()));
        timer.start();

        initialized = true;
    }
}

void GameWidget::paintEvent(QPaintEvent *)
{
    OnUpdate();
    sf::RenderWindow::display();
}

void GameWidget::OnInit()
{
    if (!bgTexture.loadFromFile("resources/bg.jpg")) {
        qDebug() << "Background sprite not found";
    }

    bgSprite.setTexture(bgTexture);
    bgSprite.setScale(
        BG_SCALE, BG_SCALE
    );
    bgSprite.setPosition(0, 0);

    if (font.loadFromFile("resources/arial.ttf")) {
        gameOverText = sf::Text("GAME OVER", font, 48);
        gameOverText.setFillColor(sf::Color::White);

        gameOverText.setPosition(this->getSize().x / 2 - gameOverText.getLocalBounds().width / 2,
                                 this->getSize().y / 2 - gameOverText.getLocalBounds().height / 2);
    } else {
        qDebug() << "Font not found!";
    }

    startGame();
}

void GameWidget::OnUpdate()
{
    sf::Event event;
    while (this->pollEvent(event)) {
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        player.move(Direction::UP);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        player.move(Direction::DOWN);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        player.move(Direction::LEFT);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        player.move(Direction::RIGHT);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        startGame();

    checkGameOver();
    addNewEnemies();

    if (enemies.empty() && player.scale() >= WINNING_SCALE)
        status = Status::Win;

    sf::RenderTarget::draw(bgSprite);

    player.updatePosition();
    for (auto& enemy : enemies) {
        enemy->updatePosition();
        enemy->draw(this);
    }
    player.draw(this);

    if (status == Status::Lose) {
        gameOverText.setString("GAME OVER");
        sf::RenderTarget::draw(gameOverText);
    }
    else if (status == Status::Win) {
        gameOverText.setString("YOU WIN");
        sf::RenderTarget::draw(gameOverText);
    }
}

void GameWidget::startGame()
{
    status = Status::Playing;
    enemies.clear();
    player.reset();
}

void GameWidget::checkGameOver()
{
    if (status != Status::Playing)
        return;

    for (std::list<std::shared_ptr<EnemyFish>>::iterator iter = enemies.begin(); iter != enemies.end();) {
        if (iter->get()->isColliding(player)) {
            if (player.isCanEat(*iter->get())) {
                player.setScale(player.scale() + 0.05);

                auto toRemove = iter;
                ++iter;
                enemies.erase(toRemove);

            } else {
                status = Status::Lose;
                enemies.clear();
                return;
            }


        } else if (iter->get()->outOfBounds()) {
            auto toRemove = iter;
            ++iter;
            enemies.erase(toRemove);
        }
        else {
            ++iter;
        }
    }

}

void GameWidget::addNewEnemies()
{
    if (status != Status::Playing)
        return;

    int died = MAX_ENEMIES - enemies.size();

    if (player.scale() < WINNING_SCALE && player.scale() > 0.0) {
        for (int i = 0; i < died; i++) {
            enemies.push_back(EnemyFish::createFish(player.scale()));
        }
    }
}

QPaintEngine *GameWidget::paintEngine() const
{
    return nullptr;
}
