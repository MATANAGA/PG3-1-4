#include <iostream>
using namespace std;

// ���饹�ƥ�ץ�`�ȶ��x
template <typename Type1, typename Type2>
class TemplateClass {
public:
    // ���󥹥ȥ饯��
    TemplateClass(Type1 number1, Type2 number2)
        : Number1(number1), Number2(number2) {}

    // С�������΂��򷵤�
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
    // ���ѥ��`��Υ��󥹥�������
    TemplateClass<int, float> intFloatTemplate(100, 50.0f);
    TemplateClass<int, double> intDoubleTemplate(80, 20.0);
    TemplateClass<float, int> floatIntTemplate(2.0f, 18);
    TemplateClass<float, double> floatDoubleTemplate(11.0f, 3.5);
    TemplateClass<double, int> doubleIntTemplate(234.0, 123);
    TemplateClass<double, float> doubleFloatTemplate(400.1, 500.2f);

    // Min�v���Όg�Фȱ�ʾ
    cout << "int(100) �� float(50.0f) ��Ȥ٤�С������: "
        << intFloatTemplate.Min() << endl;

    cout << "int(80) �� double(20.0) ��Ȥ٤�С������: "
        << intDoubleTemplate.Min() << endl;

    cout << "float(2.0f) �� int(18) ��Ȥ٤�С������: "
        << floatIntTemplate.Min() << endl;

    cout << "float(11.0f) �� double(3.5) ��Ȥ٤�С������: "
        << floatDoubleTemplate.Min() << endl;

    cout << "double(234.0) �� int(123) ��Ȥ٤�С������: "
        << doubleIntTemplate.Min() << endl;

    cout << "double(400.1) �� float(500.2f) ��Ȥ٤�С������: "
        << doubleFloatTemplate.Min() << endl;

    return 0;
}
