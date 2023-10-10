#include "SafeBuffer.h"

/*! \class Buffer
    \brief A Buffer Implementation

   Uses C++11 features to implement a Buffer class that contains an array of events, as well as Semaphores to controll access
   to the events array. It contains Add() and Remove() methods to add and remove events from the array.

*/

/*! Parameterless constructor for the Buffer Class*/
Buffer::Buffer(){
    position = 0;
    events = {};
    mutex = std::make_shared<Semaphore>(1); //control access to the buffer
    itemSem = std::make_shared<Semaphore>(0); //blocks when the buffer is empty
}

/*! Add an event to the buffer */   
void Buffer::Add(){
    
}

/*! Remove an event from the buffer*/
void Buffer::Remove(){

}