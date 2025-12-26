#include "../exercise.h"

// constexpr unsigned long long fibonacci(int i) {
//     switch (i) {
//         case 0:
//             return 0;
//         case 1:
//             return 1;
//         default:
//             return fibonacci(i - 1) + fibonacci(i - 2);
//     }
// }

constexpr unsigned long long fibonacci(int i) {
    switch (i) {
        case 0:
            return 0;
        case 1:
            return 1;
    }

    unsigned long long fib_1 = 0;
    unsigned long long fib_2 = 1;
    unsigned long long fib_i = 0;
    for (int j = 2; j <= i; ++j) {
        fib_i = fib_1 + fib_2;
        fib_1 = fib_2;
        fib_2 = fib_i;
    }
    return fib_i;

}

int main(int argc, char **argv) {
    constexpr auto FIB20 = fibonacci(20);
    ASSERT(FIB20 == 6765, "fibonacci(20) should be 6765");
    std::cout << "fibonacci(20) = " << FIB20 << std::endl;

    // TODO: 观察错误信息，修改一处，使代码编译运行
    // PS: 编译运行，但是不一定能算出结果……
    constexpr auto ANS_N = 90;
    constexpr auto ANS = fibonacci(ANS_N);
    std::cout << "fibonacci(" << ANS_N << ") = " << ANS << std::endl;

    return 0;
}
