#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    unordered_map<int, int> map;
    for(int i = 0; i < 3; i++) {
        map[i]++;
    }
    // map[3]++;
    cout << map.count(3) << endl;
    cout << map.size() << endl;
    cout << map[3] << endl;
}