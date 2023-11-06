#include "playerfish.h"

#include <QDebug>
#include <cmath>

PlayerFish::PlayerFish() : FishAbstract()
{
    if (!m_texture.loadFromFile("resources/player.png")) {
        qDebug() << "File not found";
    }

    m_sprite.setTexture(m_texture);

    reset();
}

void PlayerFish::move(Direction direction)
{
    m_dir = direction;

    if (direction == Direction::RIGHT) {
        ax += 0.1;
    }
    else if (direction == Direction::LEFT) {
        ax -= 0.1;
    }
    else if (direction == Direction::UP) {
        ay -= 0.1;
    }
    else if (direction == Direction::DOWN) {
        ay += 0.1;
    }

    ax = std::max(std::min(ax, MAX_ACCEL), -MAX_ACCEL);
    ay = std::max(std::min(ay, MAX_ACCEL), -MAX_ACCEL);
}

void PlayerFish::updatePosition()
{
    float x = m_sprite.getPosition().x;
    float y = m_sprite.getPosition().y;

    ax /= 1.01;
    ay /= 1.05;

    if (ax > 0) {
        m_sprite.setScale(m_scale, m_scale);
    }
    if (ax < 0) {
        m_sprite.setScale(-m_scale, m_scale);
    }

    x += ax;
    y += ay;

    m_sprite.setPosition(x, y);
}

void PlayerFish::reset()
{
    ax = ay = 0;
    setScale(DEFAULT_SCALE);
    this->setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
}
