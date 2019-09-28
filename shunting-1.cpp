#include "shunting.h"
#include"constants.h"
#include<iostream>
#include <cmath>
using namespace std;

Queue<Token*> Input(string s){

    Queue<Token*> Result;

    for(int i=0; i<s.length();i++){

        //checking operators if it is then push the operator into the queue
        if(s.substr(i,1)=="+" || s.substr(i,1)=="-" || s.substr(i,1)=="^" || s.substr(i,1)=="/"|| s.substr(i,1)=="*" || s.substr(i,1)=="(" || s.substr(i,1)==")")
        {

            Result.Push(new Operator(s.substr(i,1)));

        }

        // checks to see if it is a single character which means a variable.
        //if it's a varaiable then push it into resulting queue as a variable

        if(isalpha(s[i])&& !isalpha(s[i+1])){
            Result.Push(new variables(s.substr(i,1)));

        }

        //checks to see if it is a function
        if(isalpha(s[i]) && isalpha(s[i+1])){

            int funcLen = 0;
            while (isalpha(s[i])) {
                funcLen++, i++;

            }
            Result.Push(new Operator(s.substr(i - funcLen, funcLen)));

            --i;
        }

        //checks to see if it is a number, if so it converts it into a number and pushes into result queue.
        if(isdigit(s[i])){
            int digits=0;
            while (isdigit(s[i]) || s[i] == '.') {
                ++digits, ++i;
            }


            Result.Push(new Number(stod(s.substr(i - digits, digits))));

            --i;

        }


    }

    return Result;
}
double RPN(Queue<Token*>  MyQueue, double x_value){

    double num1=0;
    double num2=0;
    double input=0;

    Stack<double> Result;

    while(!MyQueue.Empty()){

        Token * New=MyQueue.Pop();

        Operator* c= static_cast<Operator*>(New);
        Number* b= static_cast<Number*>(New);

        //if it is a variable push into result queue as a number as each new value

        if(New->GetType()==-1){
            num1=x_value;
            Result.Push(num1);

        }

        //Numbers get pushed into result queue

        if(New->GetType()==1){//if its a number

            b=static_cast<Number*>(New);
            Result.Push(b->GetValue());

        }

        //if its an operator

        else{

            if(New->GetType()==0){

                c=static_cast<Operator*>(New);

                if(c->GiveMeSign()=="^"){//exponent

                    num1=Result.Pop();
                    num2=Result.Pop();

                    num1=pow(num2,num1);
                    Result.Push(num1);

                }


                if(c->GiveMeSign()=="+"){// addition

                    num2 = Result.Pop();
                    num1 = Result.Pop();

                    input=num1+num2;

                    Result.Push(input);

                }
                if(c->GiveMeSign()=="-"){//subtraction

                    num2 = Result.Pop();
                    num1 = Result.Pop();

                    input=num1-num2;

                    Result.Push(input);

                    return Result.Top();
                }

                if(c->GiveMeSign()=="*"){//multiplication

                    num2 = Result.Pop();
                    num1 = Result.Pop();

                    input=num1*num2;

                    Result.Push(input);

                }
                if(c->GiveMeSign()=="/"){//division

                    num2 = Result.Pop();
                    num1 = Result.Pop();

                    input=num1/num2;

                    Result.Push(input);

                }

                if(c->GiveMeSign()=="sin"){

                    num1=Result.Pop();

                    num1=sin(num1);

                    Result.Push(num1);

                }
                if(c->GiveMeSign()=="cos"){

                    num1=Result.Pop();

                    num1=cos(num1);
                    Result.Push(num1);

                }

                if(c->GiveMeSign()=="tan"){

                    num1=Result.Pop();

                    num1=tan(num1);
                    Result.Push(num1);


                }

                if(c->GiveMeSign()=="e"){

                    num1=Result.Pop();

                    num1=pow(e,num1);
                    Result.Push(num1);

                }
            }
        }

    }
    return Result.Pop();
}

Queue<Token*> shuntingchanges(Queue<Token*>  MyQueue)
{
    Token * New;
    Stack<Token*>MyOp;
    Queue<Token*> Result;

    while(!MyQueue.Empty())
    {

        New=MyQueue.Pop();

        // if it's a number push into result queue
        if(New->GetType()==1)
        {

            Number * Num=static_cast<Number*>(New);
            Result.Push(Num) ;
            cout<<endl;

        }

        // if it's a variable push into result queue
        if(New->GetType()==-1)
        {
            variables* num = static_cast<variables*>(New);
            Result.Push(num);

        }

        if(New->GetType()==0)//operator
        {
            Operator* O1=static_cast<Operator*>(New);
            Operator* O2=static_cast<Operator*>(New);
            Operator* Parenthesis =static_cast<Operator*>(New);

            if(MyOp.Empty())// if stack is empty you can just push the operator in.
            {
                MyOp.Push(New);

            }

            else
            {

                // if parenthesis are found in the queue
                if(Parenthesis->GiveMeSign()==")")
                {

                    Operator* temp=static_cast<Operator*>(MyOp.Pop());

                    while(temp->GiveMeSign()!="(")
                    {
                        cout<<endl;

                        Result.Push(temp);

                        temp=static_cast<Operator*>(MyOp.Pop());


                    }

                }

                else if(Parenthesis->GiveMeSign()=="(")
                {
                    MyOp.Push(Parenthesis);
                }

                else{

                    O2=static_cast<Operator*>(MyOp.Top());//get top operator

                    //Sorts queue accordingly, making sure order of operations is performed correctly
                    while(  O1->GetPrecedence()<= O2->GetPrecedence()&& !MyOp.Empty() ){

                        O2=static_cast<Operator*>(MyOp.Pop());

                        Result.Push(O2);
                        if (!MyOp.Empty())
                        {
                            O2 = static_cast<Operator*>(MyOp.Top());
                        }
                    }

                    MyOp.Push(O1);

                }

            }

        }

    }


    while(!MyOp.Empty()){// Makes sure all operators in the stack get poped and pushed into the result queue.

        Token* pop= MyOp.Pop();
        Operator*popped=static_cast<Operator*>(pop);


        Result.Push(popped);
    }

    cout<<endl<<endl;

    MyQueue=Result;

    return Result;
}
