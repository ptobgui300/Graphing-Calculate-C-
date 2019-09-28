#include "operator.h"

Operator::Operator():Token(0)
{

    opp="0";
    type=0;

}
ostream & Operator::Show(){

    cout<<opp;

}
Operator::Operator(string sign)
{
    opp=sign;
    type=0;

    // each operator is given these precedences (orders) based off of their order of operations.

    if(opp=="+"|| opp=="-"){

        order=1;
    }

    if(opp=="*"|| opp=="/"){

        order=2;

    }
    if(opp=="^"){

        order=3;

    }

   if(opp=="(" ){

        order=-1;

    }


    if(opp=="sin"||opp=="cos"||opp=="e"||opp=="tan" ){

        order=4;

    }

}
int Operator::GetType(){

    // returns the type, which indicates whether it is an operator,variable, or number.
    return type;
}
string Operator::GiveMeSign(){
   //returns the actual operator
    return opp;
}
int Operator::GetPrecedence(){

    //returns the precedence of the specific operator
    return order;
}
