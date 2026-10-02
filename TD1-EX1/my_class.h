//
// Created by grego on 28/09/2026.
//

#ifndef TD1_EX1_MY_CLASS_H
#define TD1_EX1_MY_CLASS_H
#include <string>

class my_class {
private:
    std::string ma_chaine;

public:
    my_class();

    my_class(std::string texte);

    void print_my_element() const;
};

#endif //TD1_EX1_MY_CLASS_H