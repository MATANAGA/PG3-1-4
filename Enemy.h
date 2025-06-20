#pragma once
#include <iostream>

class Enemy {
public:
    Enemy();         // ���󥹥ȥ饯��
    void Update();   // ״�B���£��F�ڤ΄��� + �w�ƴ_�J��

private:
    void Approach(); // ״�B: �ӽ�
    void Attack();   // ״�B: ����
    void Retreat();  // ״�B: �x��

    using StateFunc = void (Enemy::*)();  // �����v���ݥ�����
    static StateFunc stateTable[3];       // �v���ݥ��󥿥Ʃ`�֥�

    int currentState; // �F�ڤ�״�B��0:�ӽ�, 1:����, 2:�x�ѣ�
};
