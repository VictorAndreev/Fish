#ifndef ENEMYFISH_H
#define ENEMYFISH_H

#include "fishabstract.h"
#include <memory>

class EnemyFish : public FishAbstract
{

public:

    void move(Direction direction) override;
    void updatePosition() override;

    bool outOfBounds();

    static std::shared_ptr<EnemyFish> createFish(float playerScale);

private:
    EnemyFish(float mainY, Direction dir, float scale, float speed);
    float m_mainY;
    float m_speed;
};

#endif // ENEMYFISH_H
