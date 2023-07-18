class LRUCache {
    int n;
    unordered_map<int, pair<list<int> :: iterator, int>> map;
    list<int> v;
public:
    void makeRecentlyUsed(int key) {
        v.erase(map[key].first); 
        v.push_front(key);
        map[key].first = v.begin();
    }
    
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        if(map.find(key) != map.end()) {
            int val = map[key].second;
            makeRecentlyUsed(key);
            return val;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()) {
            map[key].second = value;
            makeRecentlyUsed(key);
        }
        else {
            v.push_front(key);
            map[key] = {v.begin(), value};
            n--;
        }
        if(n < 0) {
            int delKey = v.back();
            v.pop_back();
            map.erase(delKey);
            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */