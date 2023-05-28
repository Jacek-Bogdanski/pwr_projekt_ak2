//
// Created by admin on 28.05.2023.
//

#ifndef PWR_PROJEKT_AK2_TWOSCOMPLEMENT_EXCEPTION_H
#define PWR_PROJEKT_AK2_TWOSCOMPLEMENT_EXCEPTION_H


#include <exception>
#include <string>

class TwosComplement_Exception : public std::exception{
private:
    char * message;

public:
    TwosComplement_Exception(char* msg);

    char * what();
};


#endif //PWR_PROJEKT_AK2_TWOSCOMPLEMENT_EXCEPTION_H
