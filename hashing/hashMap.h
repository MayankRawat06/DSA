#include <string>
#include <unordered_map>
using namespace std;
template<typename V>
class MapNode {
    public:     
        string key;
        V value;
        MapNode* next;
        MapNode(string key, V value) {
            this-> key = key;
            this-> value = value;
            next = NULL;
        }
        ~MapNode() {
            delete next;
        }
};
template<typename V>
class OurMap {
    private:
        MapNode<V>** buckets;
        int count;
        int numBuckets;
        int getBucketIndex(string key) {
            int hashCode = 0;
            int currCoeff = 1;
            for(int i = key.length(); i >= 0; i--) {
                hashCode += key[i] * currCoeff;
                hashCode = hashCode % numBuckets;
                currCoeff *= 37;
                currCoeff = currCoeff % numBuckets;
            }
            return hashCode % numBuckets;
        }
        void rehash() {
            int oldBucketSize = numBuckets;
            numBuckets *= 2;
            count = 0;
            MapNode<V>** temp = buckets;
            buckets = new MapNode<V>* [numBuckets];
            for(int i = 0; i < numBuckets; i++) {
                buckets[i] = NULL;
            }
            for(int i = 0; i < oldBucketSize; i++) {
                MapNode<V>* head = temp[i];
                while(head != NULL) {
                    insert(head-> key, head-> value);
                    head = head-> next;
                }
            }
        }
    public:
        OurMap() {
            count = 0;
            numBuckets = 5;
            buckets = new MapNode<V>*[numBuckets]; 
        }
        ~OurMap() {
            for(int i = 0; i < numBuckets; i++) {
                delete buckets[i];
            }
            delete []buckets;
        }
        int size() {
            return count;
        }
        V getValue(string key) {
            int bucketIndex = getBucketIndex(key);
            MapNode<V> *head = buckets[bucketIndex];
            while(head != NULL) {
                if(head -> key == key) {
                    return head-> value;
                }
                head = head -> next;
            } 
            return 0;
        }
        void insert(string key, V value) {
            int bucketIndex = getBucketIndex(key);
            MapNode<V>* head = buckets[bucketIndex];
            while(head != NULL) {
                if(head-> key == key) {
                    head-> value = value;
                    return;
                }
                head = head -> next;
            }
            head = buckets[bucketIndex];
            MapNode<V>* newNode = new MapNode<V>(key, value);
            newNode-> next = head;
            buckets[bucketIndex] = newNode;
            count++;
            double loadFactor = (1.0* count)/ numBuckets;
            if(loadFactor > 0.7) {
                // rehashing 
                rehash();
            }
        }
        V remove(string key) {
            int bucketIndex = getBucketIndex(key);
            MapNode<V>* head = buckets[bucketIndex];
            if(head == NULL) {
                return 0;
            }
            if(head -> key == key) {
                int val = head -> value;
                MapNode<V>* delNode = head;
                head = head -> next;
                buckets[bucketIndex] = head;
                delNode-> next = NULL;
                delete delNode;
                count--;
                return val;
            } 
            MapNode<V>* temp = head;
            while(temp-> next != NULL) {
                if(temp-> next-> key == key) {
                    MapNode<V>* delNode = temp-> next;
                    int val= delNode -> value;
                    temp -> next = delNode-> next;
                    delNode-> next = NULL;
                    delete delNode;
                    count--;
                    return val;
                }
                temp = temp-> next;
            }
            return 0;
        }
        double getLoadFactor() {
            return (1.0 * count)/ numBuckets;
        }
};