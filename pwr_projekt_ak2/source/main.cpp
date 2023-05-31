#include <stdio.h>
#include <math.h>
#include <processthreadsapi.h>
#include "TwosComplement_Num.h"
#include "TwosComplement_Exception.h"

using namespace std;

// pobranie czasu procesora
long double get_cpu_time() {
    FILETIME a, b, c, d;
    if (GetProcessTimes(GetCurrentProcess(), &a, &b, &c, &d) != 0) {
        return (long double) (d.dwLowDateTime | ((unsigned long long) d.dwHighDateTime << 32)) * 0.0001;
    }
    // error
    return -1.0;
}


int main() {
    long long  n = 16;
    int repeat = 1000;
    int repeat_each = 10;
    long long max = pow(2,31) + 1;
    float value;
    long double begin, end, elapsed;
    TwosComplement_Num c = *new TwosComplement_Num(value, n, -4);


    while (n < max) {
        long double sum = 0.0;
        value = 1.25 * n * n;
        TwosComplement_Num a = *new TwosComplement_Num(value, n, -4);
        TwosComplement_Num b = *new TwosComplement_Num(value, n, -4);
        for(int k=0;k<repeat_each;k++){
            begin = get_cpu_time();
            for(int i=0;i<repeat;i++){
                c = TwosComplement_Num::multiply(a, b);
            }
            end = get_cpu_time();
            sum += (end - begin);
        }

        long double avg = sum/repeat_each*1000/repeat;
        // value;n;microseconds
        // printf("%.3f;%Ld;%.4Lf\n", value, n, elapsed);
        printf("%.3Lf\n", avg);

        n *= 2;
    }

    printf("%f\n", c.floatVal());

    return 0;
}