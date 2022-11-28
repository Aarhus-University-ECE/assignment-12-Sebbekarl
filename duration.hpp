#pragma once

class duration{
        int time;
        int alarm;
        bool alarm_has_been_set;
        bool check_and_update_alarm();
        
    public:
        duration();
        duration(int time);
        void set_alarm(int alarm_time);
        bool tick();
        bool tick(int amount);
        int get_duration();
};