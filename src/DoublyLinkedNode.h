//
// Created by mfbut on 2/11/2019.
//

#ifndef LINKEDLIST_DOUBLELINKEDNODE_H
#define LINKEDLIST_DOUBLELINKEDNODE_H
#include <iostream>

template<typename T>
class DoublyLinkedNode {
 public:
  DoublyLinkedNode(): next(nullptr),previous(nullptr){}
  DoublyLinkedNode(T& value):value(value),next(nullptr),previous(nullptr){}

  const DoublyLinkedNode* getNext() const{
    return next;
  }
  DoublyLinkedNode* getNext(){
    return next;
  }

  const T& getValue() const{
    return value;
  }
  T& getValue(){
    return value;
  }

  const DoublyLinkedNode* getPrev() const{
    return previous;
  }
  DoublyLinkedNode* getPrev(){
    return previous;
  }

  void setPrev(DoublyLinkedNode* prev){
    previous= prev;
  }
//  void setPrev(const DoublyLinkedNode* prev){
//    previous= prev;
//  }

  void setNext(DoublyLinkedNode* n){
    next = n;
  }
//  void setNext(const DoublyLinkedNode* n){
//    next = n;
//  }

//  void setValue(T& val){
//    value= val;
//  }
  void setValue(const T& val){
    value = val;
  }
 private:
   T value;
   DoublyLinkedNode* next;
   DoublyLinkedNode* previous;


};

#endif //LINKEDLIST_DOUBLELINKEDNODE_H
