#include "variables.h"

variables::variables()
{
    type=-1;
}
variables::variables(string other)
{
    type=-1;
    VAR = other;
}
ostream& variables::Show(){

    cout<<VAR;
}
int variables::GetType(){

    return type;

}

