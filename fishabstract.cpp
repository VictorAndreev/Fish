#include "fishabstract.h"

#include <math.h>

FishAbstract::FishAbstract() {}

void FishAbstract::setPosition(float x, float y)
{
    m_sprite.setPosition(x, y);
}

void FishAbstract::setX(float x)
{
    m_sprite.setPosition(x, m_sprite.getPosition().y);
}

void FishAbstract::setY(float y)
{
    m_sprite.setPosition(m_sprite.getPosition().x, y);
}

bool FishAbstract::isCanEat(const FishAbstract &other)
{
    return this->m_scale >= other.m_scale;
}

bool FishAbstract::isColliding(const FishAbstract &other)
{
    return this->m_sprite.getGlobalBounds().intersects(other.m_sprite.getGlobalBounds());
}

void FishAbstract::setTexture(sf::Texture &texture)
{
    m_texture = texture;
    m_sprite.setTexture(texture);
}

void FishAbstract::draw(sf::RenderWindow *window)
{
    window->draw(m_sprite);
}

float FishAbstract::scale() const
{
    return m_scale;
}

void FishAbstract::setScale(float newScale)
{
    m_scale = newScale;

    m_sprite.setScale(m_scale, m_scale);
    m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().height / 2);
}

