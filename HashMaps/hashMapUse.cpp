#include <iostream>
#include <string>
#include "hashMap.h"
using namespace std;
int main() {
    OurMap<int> m;
    // cout<<m.size()<< endl;
    // m.insert("abc", 2);
    // m.insert("ef", 5);
    // m.insert("sds", 3);
    // cout<<m.size()<< endl;
    // m.insert("abc", 6);
    // cout<<m.size()<< endl;
    // cout<<m.getValue("abc")<< endl;
    // cout<<m.remove("sds")<< endl;
    // cout<<m.size()<< endl;
    // cout<<m.remove("a")<< endl;

    for(int i = 0; i < 10; i++) {
        string key = "abc";
        char num = '0' + i;
        key = key + num;
        int value = i+1;
        m.insert(key, value);
        cout << m.getLoadFactor() << endl;
    }
    cout << m.size() << endl;
    m.remove("abc6");
    m.remove("abc7");
    m.size();
    for(int i = 0; i < 10; i++) {
        string key = "abc";
        char num = '0' + i;
        key = key + num; 
        cout << key << ":" << m.getValue(key) << endl;
    }
}