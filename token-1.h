#ifndef TOKEN_H
#define TOKEN_H
#include<iostream>
using namespace std;

class Token
{
public:
    
    Token();
    Token(int _type);
    virtual ostream &Show();
    friend ostream & operator<<(ostream & outs, Token * PrintMe);
    virtual int GetType();

private :
int Type;
};

#endif // TOKEN_H
