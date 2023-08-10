class MyCalendarThree {
    map<int, int> map;
public:
    MyCalendarThree() {
        
    }
    
    int book(int s, int e) {
        map[s]++;
        map[e]--;
        int curr = 0, res = 0;
        for(auto it : map) {
            curr += it.second;
            res = max(res, curr);
        }
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */