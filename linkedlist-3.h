#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"
#include<cassert>
template<typename T>
node<T> * Removes(node<T>*&headptr,node<T> *getridptr);

template<typename T>
node<T>* Inserthead(node<T>* &head_ptr, T item);

template<typename T>
ostream& Print(ostream& outs, const node<T>* head_ptr);

template<typename T>
node<T>*Find(node<T>*&headptr,T num);

template<typename T>
node<T> *Findsorted(node<T>*&headptr, T num);

template<typename T>
node<T>*Cut(node<T> *&headptr, T item);

template<typename T>
void ClearAll(node<T>* &clearmy);

template<typename T>
T Delete(node<T> *headptr);

template<typename T>
node<T>*Previous(node<T>*headptr,node<T>*p);

template<typename T>
node<T> * Copy(const node<T> * headptr);

template<typename T>
node<T>* InsertSorted(node<T> * &headptr, T item);

template<typename T>
node<T> * ReplaceWith(node<T> * &headptr, T item);

template<typename T>
node<T> * InsertAfter(node<T> *&afterme, T item);

template<typename T>
node<T> *InsertBefore(node<T>*&headptr, T item);

template<typename T>
ostream& PrintQueue(ostream& outs, const node<T> *head_ptr);

template<typename T>
node<T> *CopyQ(const node<T> *headptr,const node<T>* tailptr);

template<typename T>
node<T> *Inserthead(node<T> *&head_ptr, T item){
    //three steps:
    //1. create new node:
    node<T>* temp = new node<T>(item);
    //2. temp's next poits to where head_ptr is pointing:
    temp->_next = head_ptr;
    //3. Point head_ptr to where temp is pointing:
    head_ptr = temp;
    return temp;
}
template<typename T>
ostream& Print(ostream& outs, const node<T> *head_ptr){
    const node<T>* walker = head_ptr;
    outs<<"H-ptr->";
    while (walker){
        outs<<"["<<walker->_item<<"]->";
        walker = walker->_next;
    }
    cout<<"|||";
    return outs;

}
template<typename T>
node<T> *Find(node<T> *&headptr, T num){

    node<T>* walker=headptr;

    while(walker !=NULL){
        if(walker->_item==num){

            return walker;
        }
        walker=walker->_next ;
    }
    return NULL;
}
template<typename T>
node<T> *Findsorted(node<T> *&headptr, T num){
    node<T>* walker=headptr;

    while(walker !=NULL)
        if(walker->_item==num){

            return walker;
            if(walker->_item >num){
                return NULL;
            }

            walker=walker->_next ;
        }

    return NULL;
}
template<typename T>
void ClearAll(node<T>* &clearmy){
    //clears the whole linked list, and sets the head pointer to NULL.


    node<T> *walker=clearmy;
    node<T> *aheadwalker;

    while(walker != NULL){

        aheadwalker=walker->_next;
        delete walker;
        walker=aheadwalker;

    }
    clearmy=NULL;
}
template<typename T>
node<T> *Cut(node<T> *&headptr, T item){//Given any item T it removes what is inside the node.

    node<T> *walker=headptr;
    walker=Find(walker,item);
    walker->_item=NULL;

    return walker;
}
template<typename T>
T Delete(node<T> *&headptr, node<T> *&deleteme){

    T item;
    item=deleteme->_item;

    Removes(headptr,deleteme);

    return item;
}

template<typename T>
node<T> *ReplaceWith(node<T> *&headptr, T item){
    node<T>*walker=headptr;

    walker=walker->_next;
    walker->_item=item;
}
template<typename T>
node<T> *InsertAfter(node<T> *&afterme, T item){

    node<T> *temp;
    temp=new node<T>;
    temp->_item=item;

    temp->_next=afterme->_next;
    afterme->_next=temp;
    return temp;

}
template<typename T>
node<T> * Removes(node<T> *&headptr, node<T> *getridptr){

    if(headptr==getridptr){
        headptr=headptr->_next;

    }

    else{

        Previous(headptr,getridptr)->_next=getridptr->_next;

    }
    getridptr->_next=NULL;
    return getridptr;
}

template<typename T>
node<T> *Copy(const node<T> *headptr){

    const node<T>*walker=headptr;
    node<T>* temp=NULL;
    node<T>* w2 =NULL;

    while(walker!=NULL){
        if(temp==NULL){
            Inserthead(temp,walker->_item);
            w2=temp;

        }

        else{
            w2=InsertAfter(w2,walker->_item);
        }

        walker=walker->_next;

    }
    return temp;
}
template<typename T>
node<T> *InsertBefore(node<T>*&headptr, T item){

    InsertAfter(headptr,headptr->_item);

    headptr->_item=item;
    return headptr;

}
template<typename T>
node<T> *InsertSorted(node<T> *&headptr, T item){

    node<T>* pos;
    pos= wheredoesthisgo(headptr,item);

    if(pos==NULL){

        return Inserthead(headptr,item);

    }

    return InsertAfter(pos,item);
}
template<typename T>
node<T> *Previous(node<T> *headptr, node<T>*p){

    assert(p);
    assert(headptr);

    node<T>*walker=headptr;
    while(walker !=NULL){

        if(walker->_next==p)// If walkers next equals to the pointer that you're trying to find the previous
                            //return walker since it is pointing to the previous node.
        {
            return walker;
        }
        walker=walker->_next;
    }
    return NULL;
}
template<typename T>
node<T> *wheredoesthisgo(node<T> *headptr,T item){

    //Given an item and a node pointer, this function finds where it goes in the linked list.
    node<T>*walker=headptr;
    node<T>*w2;
    w2=NULL;

    while(walker!=NULL){

        if(walker->_item<item){// < makes it decending and > makes it acending
            return w2;
        }

        w2=walker;
        walker=walker->_next;

    }

    return w2;
}
template<typename T>
ostream& PrintQueue(ostream& outs, const node<T> *head_ptr){
    const node<T>* walker = head_ptr;
    outs<<"H-ptr->";
    while (walker){
        outs<<"["<<walker->_item<<"]->";
        walker = walker->_next;
    }
    cout<<"<-T-ptr";
    return outs;

}
template<typename T>
node<T> *CopyQ(const node<T> *headptr,const node<T>*tailptr){

    const node<T>*walker=headptr;
    node<T>* temp=NULL;
    node<T>* w2 =NULL;

    while(walker!=NULL){
        if(temp==NULL){
            Inserthead(temp,walker->_item);
            w2=temp;

        }

        else{
            w2=InsertAfter(w2,walker->_item);
        }

        walker=walker->_next;
        tailptr=walker;

    }
    return temp;
}
#endif // LINKEDLIST_H
