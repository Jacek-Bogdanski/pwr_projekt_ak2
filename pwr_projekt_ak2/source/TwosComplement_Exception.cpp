//
// Created by admin on 28.05.2023.
//

#include "TwosComplement_Exception.h"
#include <string.h>
#include <stdio.h>
#include <exception>

TwosComplement_Exception::TwosComplement_Exception(char* msg){
    this->message = msg;
}


char * TwosComplement_Exception::what()  {
    return this->message;
}