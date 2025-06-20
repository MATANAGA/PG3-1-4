#pragma once
#include <iostream>

class Enemy {
public:
    Enemy();         // コンストラクタ
    void Update();   // 状態更新（現在の動作 + 遷移確認）

private:
    void Approach(); // 状態: 接近
    void Attack();   // 状態: 攻撃
    void Retreat();  // 状態: 離脱

    using StateFunc = void (Enemy::*)();  // メンバ関数ポインタ型
    static StateFunc stateTable[3];       // 関数ポインタテーブル

    int currentState; // 現在の状態（0:接近, 1:攻撃, 2:離脱）
};
