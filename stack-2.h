#ifndef STACK_H
#define STACK_H

#include"list.h"

template<typename T>

class Stack
{
public:
    Stack();
    void Push(T item);
    T Pop();
    T Top();

    bool Empty();

    void PrintStack(const Stack<T> & MyStack);

    template<typename TT>
    friend ostream & operator <<(ostream & outs, const Stack<TT> & PrintMe);

private:

    List<T> MyList;

};

template<typename T>
Stack<T>::Stack()
{

}
template<typename T>
void Stack<T>::Push(T item){
    MyList.insert_head(item);
}

template<typename TT>
ostream & operator <<(ostream & outs, const Stack<TT> & PrintMe ){
    Stack<TT> temp=PrintMe;
    temp.MyList.PrintL(temp.MyList);
    return outs;
}
template<typename T>
void Stack<T>::PrintStack(const Stack<T> & MyStack ){

    Stack<T> temp=MyStack;
    temp.MyList.PrintL(temp.MyList);
}
template<typename T>
bool Stack<T>::Empty(){ // Checks to see if anything is in my stack.

    if(MyList.Begin()==NULL){
        return true;
    }

    else{
        return false;
    }
}
template<typename T>
T Stack<T>::Pop(){

    T value;
    if(MyList.Begin()!=NULL){
        node<T>*head=NULL;
        head= MyList.Begin();
        value=Top();
        MyList.remove_list(head);

    return value;
    }

}
template<typename T>
T Stack<T>::Top(){
    node<T>*head=NULL;
    head=MyList.Begin();
    return head->_item;
}

#endif // STACK_H
