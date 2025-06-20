#include <cstdio>

// ���說�饹�����󥯥饹��
class Animal {
public:
    virtual void sound() const = 0; // ���������v�����ݥ��`�ե�����Τ��ᣩ
    virtual ~Animal() {}            // ����ǥ��ȥ饯��
};

// Ȯ���饹
class Dog : public Animal {
public:
    void sound() const override {
        printf("�����Q���������\n");
    }
};

// è���饹
class Cat : public Animal {
public:
    void sound() const override {
        printf("�ͥ��Q����:�˥�`\n");
    }
};

int main() {
    Animal* animal1 = new Dog(); // Ȯ���󥹥���
    Animal* animal2 = new Cat(); // è���󥹥���

    animal1->sound(); // �ݥ��`�ե�����ˤ�� Dog::sound() ���ӳ���
    animal2->sound(); // ͬ���� Cat::sound() ���ӳ���

    delete animal1;
    delete animal2;

    return 0;
}
