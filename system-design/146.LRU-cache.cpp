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


// alternative solution

class LRUCache {
    class Node {
public:
    int key;
    int val;
    Node *prev;
    Node *next;
    Node(int key, int val) {
        this -> key = key;
        this -> val = val;
        this -> prev = NULL;
        this -> next = NULL;
    }
};
    int cap;
    unordered_map<int, Node*> map;
    Node *head;
    Node *tail;
    void insertNode(int key, int val) {
        Node *node = new Node(key, val);
        Node *temp = head -> next;
        temp -> prev = node;
        node -> next = temp;
        node -> prev = head;
        head -> next = node;
    }
    void deleteNode(Node *node) {
        Node *prev = node -> prev;
        Node *next = node -> next;
        prev -> next = next;
        next -> prev = prev;
        delete node;
    }
public:
    LRUCache(int capacity) {
        this -> cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        if(map.find(key) != map.end()) {
            Node *node = map[key];
            int val = node -> val;
            deleteNode(node);
            insertNode(key, val);
            map[key] = head -> next;
            return val;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()) {
            Node *node = map[key];
            deleteNode(node);
        } else {
            if(map.size() >= cap) {
                Node* leastRecent = tail -> prev;
                int keyToDelete = leastRecent -> key;
                map.erase(keyToDelete);
                deleteNode(leastRecent);
            }
        }
        insertNode(key, value);
        map[key] = head -> next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */