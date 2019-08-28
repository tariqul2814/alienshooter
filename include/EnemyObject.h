// PlayerObject
#ifndef EnemyObject_H
#define EnemyObject_H

class EnemyObject
{
public:
    EnemyObject();
    float GetRandomEnemyPos();
    float enemyLeftXpos=-0.2f;
    float enemyRightXpos=0.2f;
    float move_enemy=1.4f;
    bool isHit=false;
    int playerLife=5;
    float randomXpos=0.0f;
    void DrawEnemyObject();
    void DrawEnemyObject2();
    void DrawEnemyObject3();
    void DrawLevel2EnemyObject();
    void DrawLevel2EnemyObject2();
    void DrawLevel2EnemyObject3();
};
#endif
