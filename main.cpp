#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <functional>

// �Y����ʾ�v�������`��Хå��Ȥ���ʹ�ã�
void DispResult(int* dummy, int* userChoice) {
    int dice = rand() % 2; // 0: ����ż������1: �루������

    if (dice == *userChoice) {
        if (dice == 0)
            printf("%d�Ƕ�(ż��)�Ǥ����������꣡\n", dice);
        else
            printf("%d�ǰ�(����)�Ǥ����������꣡\n", dice);
    }
    else {
        if (dice == 0)
            printf("%d�Ƕ�(ż��)�Ǥ������Ϥ��죡\n", dice);
        else
            printf("%d�ǰ�(����)�Ǥ������Ϥ��죡\n", dice);
    }
}

// һ���r�g���äƤ��饳�`��Хå�����֣��������ɣ�
void setTimeout(std::function<void(int*, int*)> callback, int second, int key) {
    for (int i = 0; i < second; ++i) {
        Sleep(1000);
        printf("%d...\n", second - i);
    }

    int dummy = 0; // ��ζ�Ϥʤ������v�������򜺤�������
    callback(&dummy, &key);
}

int main() {
    int userInput;

    srand(static_cast<unsigned int>(time(NULL)));

    printf("��(ż��)�ʤ�0����(����)�ʤ�1���������Ƥ�������: ");
    scanf_s("%d", &userInput);

    if (userInput == 0) {
        puts("���ʤ��϶�(ż��)���x�Ӥޤ�����");
    }
    else {
        puts("���ʤ��ϰ�(����)���x�Ӥޤ�����");
    }

    // ����ʽ�ǥ�`���`�����򥭥�ץ��㤷�����`��Хå��v��������
    std::function<void(int*, int*)> callback = [=](int* s, int* k) {
        DispResult(s, k);
        };

    // SetTimeout�v����3����äƤ���Y�����ʾ
    setTimeout(callback, 3, userInput);

    return 0;
}
