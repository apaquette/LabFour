#include "Event.h"


/*! \class Event
    \brief An class representing an Event

   A simple event class used to represent events for simulation purposes. Contains
   a character value and a consume() method that will display the character value in uppercase.

*/

/*! Parameterless constructor for the Event Class*/
Event::Event(){
    value = 'a';//make this random
    //std::cout << "Created\n";
    //generate a lower case letter randomnly
    //output the lower letter's value
}

/*! Consume method that outputs the character value of the event in upper case*/
void Event::consume(){
    //std::cout << "Consumed\n";
    std::cout << toupper(value);
    //output the letter as an uppercase
}