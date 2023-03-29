#include <iostream>
#include <string>
#include "source/ArithmeticLibrary.h"

int main(int argc, char *argv[]) {

    // błąd wywołania, teoretycznie nie powinno nigdy mieć miejsca
    if (argc == 0) {
        std::cout << "Invalid execution";
        return 1;
    }

    // Zbyt mało parametrów
    if (argc == 1) {
        std::cout << "Too few parameters";
        return 0;
    }

    int *valueA = nullptr;
    int *valueB = nullptr;
    int methodNum = 0;

    for (int i = 1; i < argc; i++) {
        ////////////////////
        // konfiguracja

        // tryb debugowania
        if (std::strcmp(argv[i], "--debug") == 0 || std::strcmp(argv[i], "-d") == 0) {
            ArithmeticLibrary::setDebugMode(true);
            continue;
        }

        ////////////////////
        // metody

        // suma (domyślna)
        if (std::strcmp(argv[i], "sum") == 0) {
            methodNum = 10;
            continue;
        }

        // suma na XOR-ach z przeniesieniem
        if (std::strcmp(argv[i], "sum1") == 0) {
            methodNum = 10;
            continue;
        }

        // suma (z konwersją z U2 na NB)
        if (std::strcmp(argv[i], "sum2") == 0) {
            methodNum = 11;
            continue;
        }

        // różnica
        if (std::strcmp(argv[i], "subtract") == 0) {
            methodNum = 20;
            continue;
        }

        // iloczyn
        if (std::strcmp(argv[i], "multiply") == 0) {
            methodNum = 30;
            continue;
        }

        // iloraz
        if (std::strcmp(argv[i], "divide") == 0) {
            methodNum = 40;
            continue;
        }

        ////////////////////
        // dane liczbowe

        // sprawdzenie, czy liczba danych wejsciowych jest prawidłowa
        if (valueA != nullptr && valueB != nullptr) {
            std::cout << "Too many arguments";
            return 0;
        }

        // sprawdzenie poprawnosci wprowadzonej liczby
        char *end;
        int input = strtol(argv[i], &end, 10);

        // correct input
        if (*end == '\0') {
            if (valueA == nullptr) {
                valueA = new int;
                *valueA = input;
                continue;
            }
            if (valueB == nullptr) {
                valueB = new int;
                *valueB = input;
                continue;
            }
        }
    }

    if (methodNum == 0) {
        std::cout << "Invalid method";
        return 0;
    }

    // za mało argumentów (pipe nie uzupełni wyniku)
    if (valueA == nullptr) {
        std::cout << "Invalid input";
        return 0;
    }

    if (valueB == nullptr && !std::cin.eof()) {
        valueB = valueA;
        valueA = new int;
        std::cin >> *valueA;

        if (ArithmeticLibrary::debugMode) {
            std::cout << "Operand received from pipe:  " << *valueA << std::endl;
            std::cout << "Operand received from parameter:  " << *valueB << std::endl;
        }
    }

    switch (methodNum) {
        // suma wersja 1
        case 10:
            std::cout << ArithmeticLibrary::sum_v1(*valueA, *valueB);
            return 0;

            // suma wersja 2
        case 11:
            std::cout << ArithmeticLibrary::sum_v2(*valueA, *valueB);
            return 0;

        case 20:
            // różnica
            std::cout << ArithmeticLibrary::subtract(*valueA, *valueB);
            return 0;

        case 30:
            // iloczyn
            std::cout << ArithmeticLibrary::multiply(*valueA, *valueB);
            return 0;

        case 40:
            // iloraz
            std::cout << ArithmeticLibrary::divide(*valueA, *valueB);
            return 0;
    }
}
