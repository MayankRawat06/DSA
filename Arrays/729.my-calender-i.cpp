class MyCalendar {
    vector<pair<int, int>> v;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto e : v) {
            if(max(e.first, start) < min(end, e.second)) {
                return false;
            }
        }
        v.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */