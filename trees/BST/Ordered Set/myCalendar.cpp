/*
    MY CALENDAR I
    https://leetcode.com/problems/my-calendar-i
*/

#include<bits/stdc++.h>
using namespace std;


class MyCalendar {
    map<int, int> calendar;
public:
    MyCalendar() {}
    
    bool book(int startTime, int endTime) {
        auto prev = calendar.upper_bound(startTime);
        if(prev != calendar.begin()) {
            prev--;
            if(prev->second > startTime ) return false;
        }

        auto next = calendar.lower_bound(startTime);
        if(next != calendar.end() && next->first < endTime) {
            return false;
        }

        calendar[startTime] = endTime;
        return true;
    }
};
