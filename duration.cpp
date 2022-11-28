#include <iostream>
#include <vector>
#include <assert.h>
#include <string>
#include "duration.hpp"


duration::duration() : time(0), alarm(0), alarm_has_been_set(false) {}

duration::duration(int time) : time(time), alarm(0), alarm_has_been_set(false)
{
    assert(time > 0);
}

bool duration::check_and_update_alarm()
{
    if(alarm < time && alarm_has_been_set){
        alarm = 0;
        alarm_has_been_set = false;
        return true;
    }
    return false;
}

void duration::set_alarm(int alarm_time)
{
    if(alarm_time < time){
        std::cout << "can't set alarm to a time in the past" << std::endl;
        return;
    }
    alarm_has_been_set = true;
    alarm = alarm_time;
}

bool duration::tick()
{
    time++;
    return check_and_update_alarm();
}

bool duration::tick(int amount)
{
    time += amount;
    return check_and_update_alarm();
}

int duration::get_duration()
{
    return time;
}
