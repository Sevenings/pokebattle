#ifndef H_EVENTBUS
#define H_EVENTBUS

#include <vector>
using namespace std;



class Event {
private:
    enum class EventType {
        
    };


public:
    
};


class EventListenner {
    
};


class EventBus {
private:
    vector<EventListenner*> listenners;

public:

    void addListenner(EventListenner *listenner) {
        listenners.push_back(listenner);;
    }

    void emit(Event event);

};


#endif 
