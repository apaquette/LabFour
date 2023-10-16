#include "SafeBuffer.h"

/*! \class Buffer
    \brief A Buffer Implementation

   Uses C++11 features to implement a Buffer class that contains an array of events, as well as Semaphores to controll access
   to the events array. It contains Add() and Remove() methods to add and remove events from the array.

*/

/*! Constructor for the Buffer Class with size*/
template <typename T>
SafeBuffer<T>::SafeBuffer(int size){
    position = 0;
    events = std::vector<T>(size);
    mutex = std::make_shared<Semaphore>(1); //control access to the buffer
    items = std::make_shared<Semaphore>(0); //blocks when the buffer is empty
    positionSem = std::make_shared<Semaphore>(1);
}

/*! Add an event to the buffer */
template <typename T> 
void SafeBuffer<T>::put(T e){
    mutex->Wait();
    events[position] = e;
    UpdatePosition();
    mutex->Signal();
    items->Signal();
}

/*! Remove an event from the buffer*/
template <typename T> 
T SafeBuffer<T>::get(){
    items->Wait();
    mutex->Wait();
    T e = events[position];
    UpdatePosition();
    mutex->Signal();
    return e;
}

template <typename T> 
void SafeBuffer<T>::UpdatePosition(){
    positionSem->Wait();
    if(++position == events.size()){//if we reached the end of the list, go back to the start
        position = 0;
    }
    positionSem->Signal();
}