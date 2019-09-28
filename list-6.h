#ifndef LIST_H
#define LIST_H
typedef int T;

#include <iostream>
using namespace std;

#include"node.h"
#include"linkedlist.h"

template<typename T>

class List
{
public:

    List();

    //Big Three
    ~List();
    List(const List<T> & newlist);
    List & operator =(const List<T> & Other);

    void remove_list(node<T> *head);
    node<T>* Begin();
    void copy_list(const List& newlist)const;
    void insert_sorted(T item);
    node<T>* where_this_goes(T item);
    void insert_before(node<T>*ptr, T item);
    void clear_all();
    void replace_with(T item);
    node<T>*find_list(T item);
    void insert_after(node<T>*, T item);
    node<T> *insert_head(T item);
    void PrintL(const List<T> & Other);
    void delete_list(node<T> *head);
    node<T> * find_sorted(T item);

    friend ostream & operator<<(ostream & outs,const List<T> & PrintMe);

private :

    node<T> *a;

};
template<typename T>
List<T>::List()
{
    a=NULL;
}

template<typename T>
node<T>* List<T>::insert_head(T item){

    return Inserthead(a,item);

}
template<typename T>
List<T>::~List(){
  //  cout<<"Destructor firing..."<<endl;
    ClearAll(a);
}

template<typename T>
List<T>::List(const List<T> &Other){

    //cout<<"Copy constructor firing.."<<endl;

    a=Copy(Other.a);

}
template<typename T>
List<T> &List<T>::operator =(const List<T> & Other){

   // cout<<"   assignment operator fired..."<<endl;
    if(this!=&Other){
        ClearAll(a);
        a=Copy(Other.a);
    }
    return *this;

}
template<typename T>
void List<T>::clear_all(){

    ClearAll(a);
}
template<typename TT>
ostream & operator<<(ostream & outs,const List<TT> & PrintMe){

    Print(outs,PrintMe.a);
    return outs;
}

template<typename T>
void List<T>::PrintL(const List<T> & Other){
    Print(cout,Other.a);
}
template<typename T>
void List<T>::insert_after(node<T>*ptr,T item){
    InsertAfter(ptr,item);
}
template<typename T>
node<T>* List<T>::find_list(T item){
    return Find(a,item);
}
template<typename T>
void List<T>::insert_before(node<T>*ptr,T item){
    InsertBefore(ptr,item);
}
template<typename T>
node<T>* List<T>::where_this_goes(T item){
    return wheredoesthisgo(a,item);
}
template<typename T>
void List<T>::insert_sorted(T item){
    InsertSorted(a,item);
}
template<typename T>
void List<T> ::copy_list(const List<T> & newlist)const{

    List<T> temp=newlist;

    a=Copy(temp.a);
}
template<typename T>
node<T>* List<T>::Begin(){
    return a;
}
template<typename T>
void List<T>::remove_list(node<T>*head){

    Removes(a,head);
}
template<typename T>
void List<T>::delete_list(node<T>*head){

    Delete(a,head);
}

#endif // LIST_H
