#ifndef TIMER_H
#define TIMER_H


using namespace std ;
class Timer{
public:
    Timer();
    ~Timer();
    int start_tick_;
    int paused_tick_;
    bool is_paused_;
    bool is_started_;
    void start();
    void stop();
    void paused();
    void unpaused();
    int get_ticks();
    bool is_paused();
    bool is_started();
};

#endif // TIMER_H
