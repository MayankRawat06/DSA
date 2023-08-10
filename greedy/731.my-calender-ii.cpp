class MyCalendarTwo {
    map<int, int> map;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        map[start]++;
        map[end]--;
        int count = 0;
        for(auto it : map) {
            count += it.second;
            if(count >= 3) {
                map[start]--;
                map[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */