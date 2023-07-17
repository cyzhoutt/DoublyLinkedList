//
// Created by mfbut on 11/24/2019.
//

#ifndef TESTDOUBLELINKEDLIST_DOUBLYLINKEDLISTEMPTYERROR_H
#define TESTDOUBLELINKEDLIST_DOUBLYLINKEDLISTEMPTYERROR_H
  #include <stdexcept>
  #include "DoublyLinkedListError.h"
 class DoublyLinkedListEmptyError: public DoublyLinkedListError  {
 public:
  const char* what() const noexcept override{
    return "The list is empty";
  }
};



#endif //TESTDOUBLELINKEDLIST_DOUBLYLINKEDLISTEMPTYERROR_H
