class Node {
public:
    int key;
    int val;
    int count;
    Node *prev;
    Node *next;
    Node(int key, int val) {
        this -> key = key;
        this -> val = val;
        this -> prev = NULL;
        this -> next = NULL;
        this -> count = 1;
    }
    Node(int key, int val, int count) {
        this -> key = key;
        this -> val = val;
        this -> prev = NULL;
        this -> next = NULL;
        this -> count = count;
    }
};
class List {
public:
    Node *head;
    Node *tail;
    int size;
    List() {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head -> next = tail;
        tail -> prev = head;
        size = 0;
    }
    void addFront(Node *node) {
        Node *temp = head -> next;
        node -> next = temp;
        node -> prev = head;
        head -> next = node;
        temp -> prev = node;
        size++;
    }
    void deleteNode(Node *node) {
        Node *prevDel = node -> prev;
        Node *nextDel = node -> next;
        prevDel -> next = nextDel;
        nextDel -> prev = prevDel;
        size--;
    }
    int getSize() {
        return this -> size;
    }
};
class LFUCache {
    unordered_map<int, List*> freqList;
    unordered_map<int, Node*> keyNode;
    int capacity;
    int minFreq;
public:
    LFUCache(int capacity) {
        this -> capacity = capacity;
        this -> minFreq = 1e9;
    }
    void update(Node *node) {
        int count = node -> count;
        List * pastList = freqList[count];
        pastList -> deleteNode(node);
        if(pastList -> getSize() == 0 && count == minFreq) minFreq++;
        List * newList = new List();
        if(freqList.find(count + 1) != freqList.end()) newList = freqList[count + 1];
        else {
            freqList[count + 1] = newList;
        }
        int key = node -> key;
        int val = node -> val;
        node -> count = count + 1;
        newList -> addFront(node);
        keyNode[key] = newList -> head -> next;
    }
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()) {
            Node *node = keyNode[key];
            int val = node -> val;
            update(node);
            return val;
        } else return -1;
    }
    
    void put(int key, int value) {
        if(keyNode.find(key) != keyNode.end()) {
            Node *node = keyNode[key];
            node -> val = value;
            update(node);
        } else {
            if(keyNode.size() >= capacity) {
                List * list = freqList[minFreq];
                Node *node = list -> tail -> prev;
                list -> deleteNode(node);
                keyNode.erase(node -> key);
            }
            List * newList = new List();
            int count = 1;
            Node *node = new Node(key, value, count);
            if(freqList.find(count) != freqList.end()) newList = freqList[count];
            else {
                freqList[count] = newList;
            }
            newList -> addFront(node);
            keyNode[key] = newList -> head -> next;
            minFreq = 1;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */