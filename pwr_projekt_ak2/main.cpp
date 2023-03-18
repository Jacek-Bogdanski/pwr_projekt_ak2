#include <iostream>
#include <string>
#include "source/ArithmeticLibrary.h"

int main(int argc, char *argv[])
{
    // błąd wywołania, teoretycznie nie powinno nigdy mieć miejsca
    if(argc==0){
        std::cout << "Invalid execution";
        return 1;
    }

    // brak pierwszego parametru - nazwy operacji
    if(argc==1){
        std::cout << "Method not specified";
        return 0;
    }

    // realizacja operacji zawsze dla 2 liczb

    // za mało argumentów
    if(argc<4){
        std::cout << "Too few arguments";
        return 0;
    }
    // za dużo argumentów
    if(argc>5){
        std::cout << "Too many arguments";
        return 0;
    }
    int a = std::stoi(argv[2]);
    int b = std::stoi(argv[3]);

    // suma wersja 1
    if(std::strcmp(argv[1],"sum1")==0){
        std::cout<<ArithmeticLibrary::sum_v1(a,b);
        return 0;
    }

    // suma wersja 2
    if(std::strcmp(argv[1],"sum2")==0){
        std::cout<<ArithmeticLibrary::sum_v2(a,b);
        return 0;
    }


    // różnica
    if(std::strcmp(argv[1],"subtract")==0){
        std::cout<<ArithmeticLibrary::subtract(a,b);
        return 0;
    }

    // iloczyn
    if(std::strcmp(argv[1],"multiply")==0){
        std::cout<<ArithmeticLibrary::multiply(a,b);
        return 0;
    }

    // iloraz
    if(std::strcmp(argv[1],"divide")==0){
        std::cout<<ArithmeticLibrary::divide(a,b);
        return 0;
    }

    std::cout << "Method not implemented";
    return 0;
}
