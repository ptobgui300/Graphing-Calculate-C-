#include "token.h"

Token::Token()
{


}
Token::Token(int _type)
{
    Type = _type;
}
ostream & operator<<(ostream & outs, Token*  PrintMe){

    PrintMe->Show();
    return outs;

}
ostream & Token::Show(){
//empty


}
int Token::GetType(){

    //Empty
    return Type;
}
