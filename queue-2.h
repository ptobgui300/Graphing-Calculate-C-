#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
using namespace std;

#include"node.h"
#include"linkedlist.h"

template<typename T>
class Queue
{
public:
    Queue();
    void Push(T item);
    void PrintQ(const Queue<T> & Other);
    T Front();
    T Pop();
    bool Empty();

    template<typename TT>
    friend ostream & operator <<(ostream & outs, const Queue<TT> & PrintMe);

    //Big Three
    ~Queue();
    Queue(const Queue<T> & newlist);
    Queue & operator =(const Queue<T> & Other);

private:
    node<T>* hptr;
    node<T>* tptr;

};
template<typename T>
Queue<T>::~Queue(){
   // cout<<"Destructor firing..."<<endl;
    ClearAll(hptr);
}
template<typename T>
Queue<T>::Queue(const Queue<T> &Other){

    //cout<<"Copy constructor firing.."<<endl;

    hptr=CopyQ(Other.hptr,Other.tptr);

}
template<typename T>
Queue<T> &Queue<T>::operator =(const Queue<T> & Other){

    //cout<<"   assignment operator fired..."<<endl;
    if(this!=&Other){
        ClearAll(hptr);
        hptr=CopyQ(Other.hptr,Other.tptr);
    }
    return *this;

}
template<typename T>
Queue<T>::Queue()
{
    //two pointers starting at pointing to NULL.
    //One pointer is to point to the front of the queue.
    //The other is to point at the back of the queue.

    hptr=NULL;
    tptr=NULL;

}
template<typename T>
T Queue<T>::Pop(){

    if(!Empty()){

        if(hptr==tptr){

            tptr=NULL;
        }
        return Delete(hptr,hptr);
    }
}
template<typename T>
void Queue<T>::Push(T item){

    if(hptr==NULL && tptr==NULL){
        tptr=Inserthead(tptr,item);
        hptr=tptr;

    }
    else{
        tptr=InsertAfter(tptr,item);
    }
}
template<typename T>
void Queue<T>::PrintQ(const Queue<T> & Other){
    PrintQueue(cout,Other.hptr);
}
template<typename T>
T Queue<T>::Front()
{
    if(!Empty()){
        return hptr->_item;// Returns the item at the front of the queue.
    }
}
template<typename T>
bool Queue<T>::Empty(){

    if(hptr==NULL){// If the headpointer is not NULL then the queue cannot be empty.
        return true;
    }
    else{
        return false;
    }
}
template<typename TT>
ostream & operator <<(ostream & outs, const Queue<TT> & PrintMe ){
    Queue<TT> temp=PrintMe;
    PrintQueue(outs,temp.hptr);
    return outs;
}

#endif // QUEUE_H
