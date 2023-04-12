#include <iostream>
using namespace std;


int sum(int a, int b) {
    int32_t sum;
    int32_t carry = 0;

    asm("xor %%edx, %%edx;"
        "add %2, %0;"
        "adc %3, %0;"
            : "+r" (sum)
            : "d" (carry), "r" (a), "r" (b)
            );

    // Check for overflow
    if ((a < 0 && b < 0 && sum >= 0) || (a > 0 && b > 0 && sum <= 0)) {
        std::cout << "Error: Overflow occurred." << std::endl;
        return 0;
    }

    return sum;
}
