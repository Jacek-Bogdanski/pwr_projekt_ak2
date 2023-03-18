#include <iostream>
#include "source/ArithmeticLibrary.h"

int main(int argc, char *argv[])
{
    if(argc==0){
        return 1;
    }

    std::cout<<argv[0]<<ArithmeticLibrary::sum(1,3)<<std::endl;
    return 0;
}
