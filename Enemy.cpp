#include "Enemy.h"
using namespace std;

// コンストラクタ：初期状態を0（接近）に設定
Enemy::Enemy() : currentState(0) {}

// 接近
void Enemy::Approach() {
    cout << "敵が接近！" << endl;
}

// 攻撃
void Enemy::Attack() {
    cout << "敵が攻撃！" << endl;
}

// 離脱
void Enemy::Retreat() {
    cout << "敵が離脱！" << endl;
}

// 状態更新（行動＋ユーザー入力による遷移）
void Enemy::Update() {
    // 現在の状態に応じた関数を実行
    (this->*stateTable[currentState])();

    // ユーザーに次の状態に移行するかを確認
    cout << "次の状態に移行しますか？ (0: はい、 他の数字: いいえ) > ";
    int input;
    cin >> input;

    // 入力に応じて状態を進める（0→1→2→0）
    if (input == 0) {
        currentState = (currentState + 1) % 3;
    }
}

// 関数ポインタテーブルの初期化
Enemy::StateFunc Enemy::stateTable[3] = {
    &Enemy::Approach,
    &Enemy::Attack,
    &Enemy::Retreat
};
