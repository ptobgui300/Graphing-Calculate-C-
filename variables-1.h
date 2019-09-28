#ifndef VARIABLES_H
#define VARIABLES_H
#include <iostream>
#include "token.h"
using namespace std;

class variables:public Token
{
public:
    variables();
    variables(string other);

    ostream& Show();
    int GetType();


private:
    string VAR;
    int type;
};

#endif // VARIABLES_H
