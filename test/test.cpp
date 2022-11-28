
#include "catch2/catch_all.hpp"
#include "duration.hpp"
#include <iostream>
#include <array>

TEST_CASE("duration initial_time test")
{
    std::array initial_times = {1, 10, 20, 40, 100};

    for (auto &init_time : initial_times)
    {
        duration test(init_time);
        REQUIRE(test.get_duration() == init_time);
    }
}

TEST_CASE("duration tick test test")
{
    duration test;
    test.tick();
    REQUIRE(test.get_duration() == 1);

    std::array ticks = {1, 10, 20, 40, 100};
    for (auto &tick : ticks)
    {
        duration test;
        test.tick(tick);
        REQUIRE(test.get_duration() == tick);
    }
}

struct alarm_test
{
    int alarm;
    int tick;
};

TEST_CASE("duration alarm test")
{

    alarm_test test_array[] = {{100, 1}, {20, 10}, {10, 20}, {1, 40}, {101, 100}};

    for (auto &[alarm, tick] : test_array)
    {
        duration temp;
        temp.set_alarm(alarm);
        REQUIRE(temp.tick(tick) == tick > alarm);
    }
}