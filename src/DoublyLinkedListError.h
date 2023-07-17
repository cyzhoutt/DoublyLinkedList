//
// Created by mfbut on 11/24/2019.
//

#ifndef TESTDOUBLELINKEDLIST_DOUBLYLINKEDLISTERROR_H
#define TESTDOUBLELINKEDLIST_DOUBLYLINKEDLISTERROR_H
#include <string>
#include <stdexcept>
 class DoublyLinkedListError: public std::exception {
    public:
     const char* what() const noexcept override{
       return "The list is wrong";
     }

};

#endif //TESTDOUBLELINKEDLIST_DOUBLYLINKEDLISTERROR_H
