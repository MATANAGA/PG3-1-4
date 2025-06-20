#include <iostream>
using namespace std;

// クラステンプレート定義
template <typename Type1, typename Type2>
class TemplateClass {
public:
    // コンストラクタ
    TemplateClass(Type1 number1, Type2 number2)
        : Number1(number1), Number2(number2) {}

    // 小さい方の値を返す
    Type1 Min() {
        if (Number1 < Number2)
            return static_cast<Type1>(Number1);
        else
            return static_cast<Type1>(Number2);
    }

private:
    Type1 Number1;
    Type2 Number2;
};

int main() {
    // 各パターンのインスタンス生成
    TemplateClass<int, float> intFloatTemplate(100, 50.0f);
    TemplateClass<int, double> intDoubleTemplate(80, 20.0);
    TemplateClass<float, int> floatIntTemplate(2.0f, 18);
    TemplateClass<float, double> floatDoubleTemplate(11.0f, 3.5);
    TemplateClass<double, int> doubleIntTemplate(234.0, 123);
    TemplateClass<double, float> doubleFloatTemplate(400.1, 500.2f);

    // Min関数の実行と表示
    cout << "int(100) と float(50.0f) を比べて小さい方: "
        << intFloatTemplate.Min() << endl;

    cout << "int(80) と double(20.0) を比べて小さい方: "
        << intDoubleTemplate.Min() << endl;

    cout << "float(2.0f) と int(18) を比べて小さい方: "
        << floatIntTemplate.Min() << endl;

    cout << "float(11.0f) と double(3.5) を比べて小さい方: "
        << floatDoubleTemplate.Min() << endl;

    cout << "double(234.0) と int(123) を比べて小さい方: "
        << doubleIntTemplate.Min() << endl;

    cout << "double(400.1) と float(500.2f) を比べて小さい方: "
        << doubleFloatTemplate.Min() << endl;

    return 0;
}
