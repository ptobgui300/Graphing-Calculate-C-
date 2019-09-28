#include "number.h"

Number::Number()
{
    type=1;
    num=0;
}
Number::Number(int n){
    type=1;
    num=n;
}
Number::Number(string sign){

    type=1;
    num=0;

}
ostream& Number::Show(){

    cout<<num;
}
int Number::GetType(){

    return type;

}
double Number::GetValue(){

   // returns the integer value of the number

    return num;
}
