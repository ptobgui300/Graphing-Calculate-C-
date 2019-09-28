#ifndef OPERATOR_H
#define OPERATOR_H
#include<string>
#include"token.h"

class Operator : public Token
{
public:
    Operator();
    ostream &Show();
    Operator(string sign);
    int GetType();
    string GiveMeSign();
    int GetPrecedence();

private:
    string opp;
    int type;
    int order;// precedence

};

#endif // OPERATOR_H
