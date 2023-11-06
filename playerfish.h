#ifndef PLAYERFISH_H
#define PLAYERFISH_H

#include "fishabstract.h"

/**
 * @brief Класс PlayerFish представляет игровую рыбу, унаследованную от FishAbstract.
 */
class PlayerFish : public FishAbstract
{
public:
    const float DEFAULT_SCALE = 0.35f; // Масштаб по умолчанию для игрока
    const float MAX_ACCEL = 3.0f;      // Максимальное ускорение игрока

    /**
     * @brief Конструктор класса PlayerFish.
     */
    PlayerFish();

    /**
     * @brief Переместить игрока в заданном направлении.
     * @param direction Направление движения игрока (LEFT, RIGHT, UP, DOWN).
     */
    void move(Direction direction);

    /**
     * @brief Обновить позицию игрока.
     */
    void updatePosition();

    /**
     * @brief Сбросить параметры игрока к начальным значениям.
     */
    void reset();

private:
    float ax, ay; // Ускорение игрока по координатам X и Y
};


#endif // PLAYERFISH_H
