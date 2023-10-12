#include "SafeBuffer.h"

/*! \class Buffer
    \brief A Buffer Implementation

   Uses C++11 features to implement a Buffer class that contains an array of events, as well as Semaphores to controll access
   to the events array. It contains Add() and Remove() methods to add and remove events from the array.

*/

/*! Parameterless constructor for the Buffer Class*/
SafeBuffer::SafeBuffer(){
    position = 0;
    events = std::vector(5);
    mutex = std::make_shared<Semaphore>(1); //control access to the buffer
    items = std::make_shared<Semaphore>(0); //blocks when the buffer is empty
    positionSem = std::make_shared<Semaphore>(1);
}

/*! Add an event to the buffer */   
void SafeBuffer::put(std::shared_ptr<Event> e){
    mutex->Wait();
    events[position] = e;
    UpdatePosition();
    mutex->Signal();
    items->Signal();
}

/*! Remove an event from the buffer*/
std::shared_ptr<Event> SafeBuffer::get(){
    items->Wait();
    mutex->Wait();
    Event e = events[position];
    UpdatePosition();
    mutex->Signal();
    return e;
}

void SafeBuffer::UpdatePosition(){
    positionSem->Wait();
    if(++position == events.size()){//if we reached the end of the list, go back to the start
        position = 0;
    }
    positionSem->Signal();
}