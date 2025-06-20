#include <iostream>
using namespace std;

class Enemy {
public:
    void Update();

    void Approach(); // 接近
    void Attack();   // 攻撃
    void Retreat();  // 離脱

    // 関数ポインタのテーブル
    static void (Enemy::* stateTable[])();

private:
    int index = 0; // 現在の状態を示すインデックス（0: 接近, 1: 攻撃, 2: 離脱）
};


// 各状態の実装
void Enemy::Approach() {
    cout << "敵が接近！" << endl;
}

void Enemy::Attack() {
    cout << "敵が攻撃！" << endl;
}

void Enemy::Retreat() {
    cout << "敵が離脱！" << endl;
}

// Update関数：状態遷移を行う
void Enemy::Update() {
    // 現在の状態に対応する関数を実行
    (this->*stateTable[index])();

    // 状態を切り替えるかどうかをユーザーに確認
    cout << "次の状態に移行しますか？ (0: はい、他の数字: いいえ) > ";
    int input;
    cin >> input;

    if (input == 0) {
        index = (index + 1) % 3; // 0→1→2→0 のループ
    }
}

// 関数ポインタテーブルの定義
void (Enemy::* Enemy::stateTable[])() = {
    &Enemy::Approach, // インデックス0
    &Enemy::Attack,   // インデックス1
    &Enemy::Retreat   // インデックス2
};

// メイン関数
int main() {
    Enemy enemy;

    while (true) {
        enemy.Update();
    }

    return 0;
}
