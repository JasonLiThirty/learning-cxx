#include "../exercise.h"

// READ: 函数模板 <https://zh.cppreference.com/w/cpp/language/function_template>
// TODO: 将这个函数模板化
// int plus(int a, int b) {
//     return a + b;
// }
template<typename T>
T plus(T a, T b) {
    return (a + b);
}

template<typename T>
bool float_equals(T a, T b, T epsilon = 1e-9) {
    return std::labs(a - b) < epsilon;
}

int main(int argc, char **argv) {
    ASSERT(plus(1, 2) == 3, "Plus two int");
    ASSERT(plus(1u, 2u) == 3u, "Plus two unsigned int");

    // THINK: 浮点数何时可以判断 ==？何时必须判断差值？
    ASSERT(plus(1.25f, 2.5f) == 3.75f, "Plus two float");
    ASSERT(plus(1.25, 2.5) == 3.75, "Plus two double");
    // TODO: 修改判断条件使测试通过
    ASSERT(float_equals(plus(0.1, 0.2), 0.3), "How to make this pass?");

    return 0;
}

/*
plus(0.1, 0.2) == 0.3 断言失败的根本原因是：浮点数（double/float）的二进制存储存在精度损失——0.1 和 0.2 无法被二进制浮点数精确表示，
相加后的结果并非严格等于 0.3（实际是 0.30000000000000004 左右）。

浮点数判等的核心规则：
✅ 可直接用 ==：能被二进制精确表示的浮点数（如 0.5/1.25/3.75，分母是 2 的幂）；
❌ 必须用差值判断：无法被二进制精确表示的浮点数（如 0.1/0.2/0.3，分母含 2 以外的质因数）。
*/