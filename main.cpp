#include <iostream>
using namespace std;

class Enemy {
public:
    void Update();

    void Approach(); // �ӽ�
    void Attack();   // ����
    void Retreat();  // �x��

    // �v���ݥ��󥿤ΥƩ`�֥�
    static void (Enemy::* stateTable[])();

private:
    int index = 0; // �F�ڤ�״�B��ʾ������ǥå�����0: �ӽ�, 1: ����, 2: �x�ѣ�
};


// ��״�B�Όgװ
void Enemy::Approach() {
    cout << "�����ӽ���" << endl;
}

void Enemy::Attack() {
    cout << "�������ģ�" << endl;
}

void Enemy::Retreat() {
    cout << "�����x�ѣ�" << endl;
}

// Update�v����״�B�w�Ƥ��Ф�
void Enemy::Update() {
    // �F�ڤ�״�B�ˌ��ꤹ���v����g��
    (this->*stateTable[index])();

    // ״�B���Ф��椨�뤫�ɤ������`���`�˴_�J
    cout << "�Τ�״�B�����Ф��ޤ����� (0: �Ϥ�����������: ������) > ";
    int input;
    cin >> input;

    if (input == 0) {
        index = (index + 1) % 3; // 0��1��2��0 �Υ�`��
    }
}

// �v���ݥ��󥿥Ʃ`�֥�ζ��x
void (Enemy::* Enemy::stateTable[])() = {
    &Enemy::Approach, // ����ǥå���0
    &Enemy::Attack,   // ����ǥå���1
    &Enemy::Retreat   // ����ǥå���2
};

// �ᥤ���v��
int main() {
    Enemy enemy;

    while (true) {
        enemy.Update();
    }

    return 0;
}
