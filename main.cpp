#include "SafeBuffer.h"
#include <iostream>
#include <thread>
#include <vector>


static const int num_threads = 50;
const int size = 5;

// /*! \fn producer
//     \brief Creates events and adds them to buffer
// */
void producer(std::shared_ptr<SafeBuffer> theBuffer, int numLoops){
  for(int i = 0; i < numLoops; ++i){
    //Produce event and add to buffer
    //std::shared_ptr<Event> e = std::make_shared<Event>();
    theBuffer->put(std::make_shared<Event>());
  }
}

// /*! \fn consumer
//     \brief Takes events from buffer and consumes them
// */
void consumer(std::shared_ptr<SafeBuffer> theBuffer, int numLoops){
  for(int i = 0; i < numLoops; ++i){
    //Consume event and remove from buffer
    theBuffer->get();
  }
}

int main(void){
  std::vector<std::thread> producers(num_threads);
  std::vector<std::thread> consumers(num_threads);
  std::shared_ptr<SafeBuffer> aBuffer = std::make_shared<SafeBuffer>(size);
  int numLoops = 10;
  /**< Launch the threads  */
  for(int i = 0; i < num_threads; ++i){
    producers[i] = std::thread(producer, aBuffer, numLoops);
  }
  for(int i = 0; i < num_threads; ++i){
    consumers[i] = std::thread(consumer, aBuffer, numLoops);
  }

  /**< Join the threads with the main thread */
  for (auto& v :producers){
      v.join();
  }

  for (auto& v :consumers){
      v.join();
  }
  //std::cout << sharedVariable << std::endl;
  return 0;
}