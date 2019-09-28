#ifndef NUMBER_H
#define NUMBER_H
#include "token.h"

class Number: public Token
{
public:
    Number();
    Number(int n);
    ostream &Show();
    int GetType();
    double GetValue();

    Number(string sign);

private:
    double num;
    int type;
};

#endif // NUMBER_H
