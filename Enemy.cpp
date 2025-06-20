#include "Enemy.h"
using namespace std;

// ���󥹥ȥ饯��������״�B��0���ӽ������O��
Enemy::Enemy() : currentState(0) {}

// �ӽ�
void Enemy::Approach() {
    cout << "�����ӽ���" << endl;
}

// ����
void Enemy::Attack() {
    cout << "�������ģ�" << endl;
}

// �x��
void Enemy::Retreat() {
    cout << "�����x�ѣ�" << endl;
}

// ״�B���£��Єӣ���`���`�����ˤ���w�ƣ�
void Enemy::Update() {
    // �F�ڤ�״�B�ˏꤸ���v����g��
    (this->*stateTable[currentState])();

    // ��`���`�˴Τ�״�B�����Ф��뤫��_�J
    cout << "�Τ�״�B�����Ф��ޤ����� (0: �Ϥ��� ��������: ������) > ";
    int input;
    cin >> input;

    // �����ˏꤸ��״�B���M��루0��1��2��0��
    if (input == 0) {
        currentState = (currentState + 1) % 3;
    }
}

// �v���ݥ��󥿥Ʃ`�֥�γ��ڻ�
Enemy::StateFunc Enemy::stateTable[3] = {
    &Enemy::Approach,
    &Enemy::Attack,
    &Enemy::Retreat
};
