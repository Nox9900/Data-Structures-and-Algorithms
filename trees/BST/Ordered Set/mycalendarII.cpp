#include<map>

/*
    MY CALENDAR II
    https://leetcode.com/problems/my-calendar-ii/
*/

class MyCalendarTwo {
    map<int, int> time;
public:
    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        time[start]++;
        time[end]--;

        int cnt=0;
        for(auto& [t, d] : time) {
            cnt += d;
            if(cnt>=3) {
                time[start]--;
                time[end]++;

                if(time[start] == 0) time.erase(start);
                if(time[end] == 0) time.erase(end);
                return false;
            }
        }
        return true;
    }
};
