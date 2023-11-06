#ifndef FISHABSTRACT_H
#define FISHABSTRACT_H

#include "common.h"
#include <SFML/Graphics.hpp>

/**
 * @brief Класс FishAbstract представляет абстрактную рыбу в игре.
 */
class FishAbstract
{
public:
    /**
     * @brief Конструктор класса FishAbstract.
     */
    FishAbstract();

    /**
     * @brief Виртуальный метод для перемещения рыбы в заданном направлении.
     * @param direction Направление движения рыбы (LEFT, RIGHT, UP, DOWN).
     */
    virtual void move(Direction direction) = 0;

    /**
     * @brief Виртуальный метод для обновления позиции рыбы.
     */
    virtual void updatePosition() = 0;

    /**
     * @brief Установить позицию рыбы.
     * @param x Координата X позиции.
     * @param y Координата Y позиции.
     */
    void setPosition(float x, float y);

    /**
     * @brief Установить координату X позиции рыбы.
     * @param x Координата X.
     */
    void setX(float x);

    /**
     * @brief Установить координату Y позиции рыбы.
     * @param y Координата Y.
     */
    void setY(float y);

    /**
     * @brief Проверить, может ли данная рыба съесть другую рыбу (коллизия по размерам).
     * @param other Другая рыба, с которой проверяется возможность съесть.
     * @return true, если рыба может съесть другую рыбу, в противном случае - false.
     */
    bool isCanEat(const FishAbstract& other);

    /**
     * @brief Проверить, сталкивается ли данная рыба с другой рыбой.
     * @param other Другая рыба, с которой проверяется столкновение.
     * @return true, если рыба сталкивается с другой рыбой, в противном случае - false.
     */
    bool isColliding(const FishAbstract& other);

    /**
     * @brief Установить текстуру рыбы.
     * @param texture Текстура, которую следует установить для рыбы.
     */
    void setTexture(sf::Texture& texture);

    /**
     * @brief Отрисовать рыбу на окне.
     * @param window Указатель на окно, на котором нужно отрисовать рыбу.
     */
    void draw(sf::RenderWindow* window);

    /**
     * @brief Получить масштаб рыбы.
     * @return Масштаб рыбы.
     */
    float scale() const;

    /**
     * @brief Установить новый масштаб рыбы.
     * @param newScale Новый масштаб, который следует установить для рыбы.
     */
    void setScale(float newScale);

protected:
    sf::Texture m_texture; ///< Текстура рыбы
    sf::Sprite m_sprite;   ///< Спрайт рыбы

    Direction m_dir;       ///< Текущее направление движения рыбы
    float m_scale;         ///< Масштаб рыбы
};


#endif // FISHABSTRACT_H
