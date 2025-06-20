#include <cstdio>

// 動物クラス（抽象クラス）
class Animal {
public:
    virtual void sound() const = 0; // 純粋仮想関数（ポリモーフィズムのため）
    virtual ~Animal() {}            // 仮想デストラクタ
};

// 犬クラス
class Dog : public Animal {
public:
    void sound() const override {
        printf("イヌ鳴き声：ワン\n");
    }
};

// 猫クラス
class Cat : public Animal {
public:
    void sound() const override {
        printf("ネコ鳴き声:ニャー\n");
    }
};

int main() {
    Animal* animal1 = new Dog(); // 犬インスタンス
    Animal* animal2 = new Cat(); // 猫インスタンス

    animal1->sound(); // ポリモーフィズムにより Dog::sound() 呼び出し
    animal2->sound(); // 同様に Cat::sound() 呼び出し

    delete animal1;
    delete animal2;

    return 0;
}
