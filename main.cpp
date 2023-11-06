#include "SafeBuffer.h"
//#include "Event.h"
#include <iostream>
#include <thread>
#include <vector>


static const int num_threads = 100;
const int size = 5;

void updateTask(std::shared_ptr<SafeBuffer> theBuffer, int numLoops){
  //what happens here?
}

// /*! \fn producer
//     \brief Creates events and adds them to buffer
// */
void producer(std::shared_ptr<SafeBuffer> theBuffer, int numLoops){
  for(int i = 0; i < numLoops; ++i){
    //Produce event and add to buffer
    std::shared_ptr<Event> e = std::make_shared<Event>();
    theBuffer->put(e);
  }
}

// /*! \fn consumer
//     \brief Takes events from buffer and consumes them
// */
void consumer(std::shared_ptr<SafeBuffer> theBuffer, int numLoops){
  for(int i = 0; i < numLoops; ++i){
    //Consume event and remove from buffer
    std::shared_ptr<Event> e = theBuffer->get();
    e->consume();
  }
}

int main(void){
  //SafeBuffer sb = SafeBuffer();
  std::vector<std::thread> vt(num_threads);
  std::shared_ptr<SafeBuffer> aBuffer = std::make_shared<SafeBuffer>(size);
  /**< Launch the threads  */
  //int i = 0;
  for(std::thread& t: vt){
    t = std::thread(updateTask, aBuffer, 10);
  }
  /**< Join the threads with the main thread */
  for (auto& v :vt){
      v.join();
  }
  //std::cout << sharedVariable << std::endl;
  return 0;
}