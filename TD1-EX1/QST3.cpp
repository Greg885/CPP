//
// Created by grego on 28/09/2026.
//

#include <iostream>
#include <string>
#include "main.h"

// void question3(std::string str)
// {
//     std::cout << str << std::endl;
// }

class myclass {
private:
    std::string str;

public:
    myclass() {
        str = "Hello";
    }

myclass(std::string texte) {
        str = texte;
    }
void print_my_element() {
        std::cout << str << std::endl;
    }

};
