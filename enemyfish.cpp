#include "enemyfish.h"

#include <QDebug>
#include <cmath>

EnemyFish::EnemyFish(float mainY, Direction dir, float scale, float speed) : FishAbstract()
{
    m_speed = speed;
    m_mainY = mainY;
    m_dir = dir;

    if (dir == Direction::RIGHT) {
        setX(-100);
    } else {
        setX(WINDOW_WIDTH + 100);
    }

    setY(mainY);

    if (!m_texture.loadFromFile("resources/enemy.png")) {
        qDebug() << "Enemy sprite not found";
    }

    m_sprite.setTexture(m_texture);
    setScale(scale);
}

bool EnemyFish::outOfBounds()
{
    return (m_dir == Direction::RIGHT && m_sprite.getPosition().x > WINDOW_WIDTH) ||
           (m_dir == Direction::LEFT && m_sprite.getPosition().x < -m_sprite.getLocalBounds().width);
}

void EnemyFish::move(Direction direction)
{
    float x = m_sprite.getPosition().x;
    float y = m_mainY + 20 * std::sin(x / 100);

    m_dir = direction;

    switch(direction) {
        case Direction::LEFT:
            m_sprite.setScale(-m_scale, m_scale);
            x -= m_speed;
            break;
        case Direction::RIGHT:
            m_sprite.setScale(m_scale, m_scale);
            x += m_speed;
            break;
        default:
            break;
    }

    m_sprite.setPosition(x, y);
}

void EnemyFish::updatePosition()
{
    move(m_dir);
}

std::shared_ptr<EnemyFish> EnemyFish::createFish(float playerScale)
{
    int y = rand() % WINDOW_HEIGHT;
    float bias = (rand() % 10 + 10) / 100.0f;

    bias = (rand() % 100 < 50) ? -bias : bias;

    float speed = (rand() % 200 + 50) / 100.0;
    Direction dir = (Direction)(rand() % 100 > 50);

    std::shared_ptr<EnemyFish> fish = std::shared_ptr<EnemyFish>(new EnemyFish(y, dir, bias + playerScale, speed));

    return fish;
}
