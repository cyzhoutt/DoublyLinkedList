//
// Created by mfbut on 11/24/2019.
//

#ifndef TESTDOUBLELINKEDLIST_DOUBLYLINKEDLISTOUTOFBOUNDSERROR_H
#define TESTDOUBLELINKEDLIST_DOUBLYLINKEDLISTOUTOFBOUNDSERROR_H
#include "DoublyLinkedListError.h"
class DoublyLinkedListOutOfBoundsError: public DoublyLinkedListError{
 public:
  const char* what() const noexcept override{
    return "Out of bound";
  }

};

#endif //TESTDOUBLELINKEDLIST_DOUBLYLINKEDLISTOUTOFBOUNDSERROR_H
