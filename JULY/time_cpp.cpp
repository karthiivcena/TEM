#include <iostream>
#include <ctime>

struct TimeStamp
{
        int tm_hour;
        int tm_min;
        int tm_sec;
}t;

class Time 
{
private:
    int hour;
    int minute;
    int second;

public:
    
    Time() 
    {
        void initialize();
        long getTime();
        void getTime();
        
        // Set hour, minute, and second
        hour = currentTime->tm_hour;
        minute = currentTime->tm_min;
        second = currentTime->tm_sec;
    }

    int getHour() const 
    {
        return hour;
    }

    int getMinute() const 
    {
        return minute;
    }

    int getSecond() const 
    {
        return second;
    }
};

Time::initialize()
{
    // Get current time
    time_t time_stamp = time(0);
    struct t* currentTime = localtime(&time_stamp);
}

int main() 
{
    Time currentTime;

    int hour = currentTime.getHour();
    int minute = currentTime.getMinute();
    int second = currentTime.getSecond();

    std::cout << "Current Time: " << hour << ":" << minute << ":" << second << std::endl;

    return 0;
}

    
