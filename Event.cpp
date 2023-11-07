#include "Event.h"


/*! \class Event
    \brief An class representing an Event

   A simple event class used to represent events for simulation purposes. Contains
   a character value and a consume() method that will display the character value in uppercase.

*/

/*! Parameterless constructor for the Event Class*/
Event::Event(){
    //generate a lower case letter randomnly
    value = 'a' + rand()%26;//make this random
    //output the lower letter's value
    //std::cout << value;
    printf("%c\n", value);
}

/*! Consume method that outputs the character value of the event in upper case*/
void Event::consume(){
    printf("%c\n", toupper(value));
}