//
// Created by mfbut on 2/11/2019.
//

#ifndef LINKEDLIST_DOUBLYLINKEDLIST_H
#define LINKEDLIST_DOUBLYLINKEDLIST_H

#include <vector>
#include <memory>
#include "DoublyLinkedNode.h"
#include "DoublyLinkedListEmptyError.h"
#include "ConstDoublyLinkedListIterator.h"
#include "DoublyLinkedListIterator.h"
#include "ConstReverseDoublyLinkedIterator.h"
#include "ReverseDoublyLinkedListIterator.h"
#include <stdlib.h>

//class ConstDoublyLinkedListIterator{};

template<typename T>
class DoublyLinkedList {
 public:
  using Node_Ptr = DoublyLinkedNode<T>*;

  using iterator = DoublyLinkedListIterator<T>;//put the type of your iterator here
  using const_iterator = ConstDoublyLinkedListIterator<T>;  //put the type of your const iterator here
  using reverse_iterator = ReverseDoublyLinkedListIterator<T>; //put the type of your reverse iterator here
  using const_reverse_iterator = ConstReverseDoublyLinkedListIterator<T>; //put the type of your const reverse iterator here

  //create a Doubly Linked List that has the same values
  //as in the vector and in the same order
  explicit DoublyLinkedList(const std::vector<T>& values);

  //create an empty DoublyLinkedList
  DoublyLinkedList();

  //destructor
  virtual ~DoublyLinkedList();

  //remove all of the elements from your list
  void clear();

  //get a reference to the front element in the list
  const T& front() const;
  T& front();

  //get a reference to the last element in the list
  const T& back() const;
  T& back();

  //add a value to the front of the list
  void push_front(const T& value);

  //add a value to the back of the list
  void push_back(const T& value);

  //is the list empty?
  bool empty() const;

  //return the number of elements in the list
  int size() const;

  //return a constant bidirectional iterator to the front of the list
  const_iterator begin() const;
  const_iterator end() const;

  //return a nonconstant bidirectional iterator to the front of the list
  iterator begin();
  iterator end();

  const_reverse_iterator crbegin() const;
  const_reverse_iterator crend() const;

  reverse_iterator rbegin();
  reverse_iterator rend();

  //insert the value at the position in the list
  //I promise not to use the iterator again after the insertion is done
  //An example if we had the list 1 <-> 9 <-> 17
  //And the iterator was pointing to the 9 and we wanted to
  //insert -22 the result would be
  //1 <-> 22 <-> 9 <-> 17
  void insert(iterator& position, const T& value);

  //remove the element at the position pointed to
  //by the iterator.
  //I promise not to use the iterator again after the erase is done
  //An example if we had the list 1 <-> 9 <-> 17
  //And when the wanted to erase the iterator was at the 9
  //1 <-> 17
  void erase(iterator& position);

 private:
//  DoublyLinkedNode<T>* node;
  DoublyLinkedNode<T>* head;
  DoublyLinkedNode<T>* tail;
  int llSize;
};

//write to the stream each element in the list in order
//with a space in between them
template<typename T>
std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T>& doublyLinkedList);

//read elements from the stream as long as it is good
// or until a newline (\n) is encountered
//if a newline is encountered it should be consumed
template<typename T>
std::istream& operator>>(std::istream& in, DoublyLinkedList<T>& doublyLinkedList);

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
  head = nullptr;
  tail = nullptr;
  llSize = 0;
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const std::vector<T>& values): DoublyLinkedList(){
//  llSize = values.size();
//  DoublyLinkedNode node(values[0]);
//  head = &node;
//  llsize--;
//
//  while(l--){
//    item->next = new Item(e, nullptr);
//    item = item->next;
//  }
//
//  for (auto& it = values.begin();) {
   for(const T& val:values){
    push_back(val);
  }
}

template<typename T>
bool DoublyLinkedList<T>::empty() const {
  return (head == nullptr && tail == nullptr && llSize == 0);
}

template<typename T>
int DoublyLinkedList<T>::size() const {
  return llSize;
}

template<typename T>
const T& DoublyLinkedList<T>::front() const {
  if(this->empty()){
    throw DoublyLinkedListEmptyError();
  }
  return head->getValue();
}

template<typename T>
T& DoublyLinkedList<T>::front() {
  if(this->empty()){
    throw DoublyLinkedListEmptyError();
  }
  return head->getValue();
}

template<typename T>
const T& DoublyLinkedList<T>::back() const {
  if(this->empty()){
    throw DoublyLinkedListEmptyError();
  }
  return tail->getValue();
}

template<typename T>
T& DoublyLinkedList<T>::back() {
  if(this->empty()){
    throw DoublyLinkedListEmptyError();
  }
  return tail->getValue();
}

template<typename T>
void DoublyLinkedList<T>::push_front(const T& value) {
  DoublyLinkedNode<T>* node;
  node = new DoublyLinkedNode<T>;
  node->setValue(value);
  if (this->empty()){
    tail = node;
  }else {
    node->setNext(head);
    head->setPrev(node);
  }
  head = node;
  llSize = llSize + 1;
}

template<typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
  DoublyLinkedNode<T>* node;
  node = new DoublyLinkedNode<T>;
  node->setValue(value);
  if (this->empty()){
    head = node;
  }else{
    node->setPrev(tail);
    tail->setNext(node);
  }
  tail = node;
  llSize = llSize + 1;
}

template<typename T>
void DoublyLinkedList<T>::clear() {
//  DoublyLinkedNode<T>* node;
//  node = head;
//  for (int i = 0; i < llSize; ++i) {
//    DoublyLinkedNode<T>* nextNode = node->getNext();
//    delete node;
//    node = nextNode;
//  }
  for (DoublyLinkedListIterator<T> it = begin(); it != end(); ++it) {
    delete it.curNode;
  }
  head = nullptr;
  tail = nullptr;
  llSize =0;

//for(DoublyLinkedNode<T>* node = head; node; node= head){
//  head = head->getNext();
//  delete node;
//}
//head = nullptr;
//tail = nullptr;
//llSize = 0;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
  clear();
}

template<typename T>
typename DoublyLinkedList<T>::const_iterator DoublyLinkedList<T>::begin() const {
//ConstDoublyLinkedListIterator<T> itr = this -> front();
  ConstDoublyLinkedListIterator<T> itr(head);
  return itr;
}

template<typename T>
typename DoublyLinkedList<T>::const_iterator DoublyLinkedList<T>::end() const {
  ConstDoublyLinkedListIterator<T> itr;
  return itr;
//return nullptr;
}

template<typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::begin() {
  DoublyLinkedListIterator<T> itr(head);
  return itr;
}

template<typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::end() {
  DoublyLinkedListIterator<T> itr;
  return itr;
}

template<typename T>
void DoublyLinkedList<T>::insert(iterator& position, const T& value) {
//  if(!position) {
//    throw DoublyLinkedListEmptyError();
//  }
  DoublyLinkedNode<T>* node = new DoublyLinkedNode<T>;
  node->setValue(value);
  if (llSize==0) {
    head = node;
    tail = node;
  }else if(position.curNode == nullptr){
    push_back(value);
    delete node;
    llSize = llSize-1;
  }else if(position.curNode == head){
    push_front(value);
    delete node;
    llSize = llSize -1;
//  }else if(llSize == 1){
//    if(position.curNode == tail) {
//      node->setPrev(tail);
//      tail->setNext(node);
//      tail = node;
//      head = position.curNode;
//    }
//    if(position.curNode == head){
//      node->setNext(head);
//      head->setPrev(node);
//      head= node;
//      tail = position.curNode;
//    }
//    push_back(value);
  }else{
    DoublyLinkedNode<T>* nodeA = (--position).curNode;
    DoublyLinkedNode<T>* nodeC = nodeA->getNext();
    DoublyLinkedNode<T>* nodeB = node;
    nodeA->setNext(nodeB);
    nodeB->setPrev(nodeA);
    nodeB->setNext(nodeC);
    nodeC->setPrev(nodeB);
  }
  llSize = llSize+1;
}

template<typename T>
void DoublyLinkedList<T>::erase(iterator& position) {
  if(!position) {
    throw DoublyLinkedListEmptyError();
  }
  DoublyLinkedNode<T>* node;
  node = position.curNode;
  if (llSize==0){
    throw DoublyLinkedListEmptyError();
  }else if (llSize==1){
    delete node;
    head = nullptr;
    tail = nullptr;
  }else if(node == tail){
    tail = node->getPrev();
    delete node;
    tail->setNext(nullptr);
  }else if(node == head){
    head = node->getNext();
    delete node;
    head->setPrev(nullptr);
  }else{
    node->getNext()->setPrev(node->getPrev());
    node->getPrev()->setNext(node->getNext());
    delete node;
  }

  llSize -= 1;
}

template<typename T>
typename DoublyLinkedList<T>::const_reverse_iterator DoublyLinkedList<T>::crbegin() const {
  ConstReverseDoublyLinkedListIterator<T> itr(tail);
  return itr;
}

template<typename T>
typename DoublyLinkedList<T>::const_reverse_iterator DoublyLinkedList<T>::crend() const {
  ConstReverseDoublyLinkedListIterator<T> itr;
  return itr;
}

template<typename T>
typename DoublyLinkedList<T>::reverse_iterator DoublyLinkedList<T>::rbegin() {
  ReverseDoublyLinkedListIterator<T> itr(tail);
  return itr;
}

template<typename T>
typename DoublyLinkedList<T>::reverse_iterator DoublyLinkedList<T>::rend() {
  ReverseDoublyLinkedListIterator<T> itr;
  return itr;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T>& doublyLinkedList) {
  for(const T& val:doublyLinkedList){
    out << val<<" ";
  }
  return out;
}

template<typename T>
std::istream& operator >> (std::istream& in, DoublyLinkedList<T>& doublyLinkedList) {
//  for(T& val:doublyLinkedList){
//   in >> val;
//  }
  T temp;
//  in >> temp;
  while(in >> temp){
    doublyLinkedList.push_back(temp);
  }
  return in;
}

#endif //LINKEDLIST_DOUBLYLINKEDLIST_H
