#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
vector<int> removeDuplicates(vector<int>& ip) {
    unordered_map<int, bool> m;
    vector<int> op;
    for(int i = 0; i < ip.size(); i++) {
        if(m.count(ip[i]) == 0) {
            // continue;
            m[ip[i]] = true;
            op.push_back(ip[i]);
        }
    }
    return op;
}
int maxFreq(vector<int> v) {
    unordered_map<int, int> hash;
    for(int i = 0; i < v.size() ; i++) {
        hash[v[i]]++;
    }
    int maxFreq = 0; 
    int res = -1;
    for(auto i : hash) {
        if(i.second >= maxFreq) {
            maxFreq = i.second;
            res = i.first;
        }
    }
    return res;
}
vector<int> intersection(vector<int> a, int n1, vector<int> b, int n2) {
    vector<int> v;
    unordered_map<int, int> hash;
    for(int i= 0; i< n1; i++) {
        hash[a[i]]++;
    }
    for(int i= 0; i< n2; i++) {
        if(hash.count(b[i]) > 0)
        {
            v.push_back(b[i]);
        }
    }
    return v;
}
int pairSumToZero(vector<int> v, int n) {
    unordered_map<int, int> hash;
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(hash.count(abs(v[i])) > 0) {
            count++;
        }
        hash[v[i]]++;
    }
    return count;
}
string extractUnique(string s) {
    unordered_map<char, int> m;
    string x;
    for(int i = 0; i< s.length(); i++) {
        if(m.count(s[i]) == 0) {
            m[s[i]]++;
            x += s[i];
        }
    }
    return x;
}
vector<int> longestConsecSeq(vector<int>& a, int n) {
    unordered_map<int, bool> m;
    for(int i = 0; i < n; i++) {
        m[a[i]] = true; 
    }
    int maxCount = 0;
    int maxStart = -1;
    for(int i = 0; i < n; i++) {
        int count = 0;
        int start = a[i];
        if(m[a[i]] == true) {
            int j = 1;
            while(m.count(a[i] + j) == true) {
                m[a[i] + j] = false;
                count++;
                j++;
            }
            j = 1;
            while(m.count(a[i] - j) == true) {
                m[a[i] - j] = false;
                count++;
                start = a[i] - j;
                j++;
            }
        }
        if(count > maxCount) {
            maxCount = count;
            maxStart = start;
        }
        else if(count == maxCount) {
            int x1, x2;
            for(int i = 0; i < n; i++) {
                if(a[i] == maxStart) {
                    x1 = i;
                }
                if(a[i] == start) {
                    x2 = i;
                }
            }
            if(x2 < x1) {
                maxStart = start;
            }
        }
    }
    vector<int> v;
    v.push_back(maxStart);
    v.push_back(maxStart + maxCount);
    return v;
}
int pairDiffK(vector<int>& a, int n, int k) {
    unordered_map<int, int> map;
    if(k < 0) {
        return 0;
    }
    int count = 0;
    // for(int i = 0; i < n; i++) {
    //     map[a[i]]++;
    // }
    // int count = 0;
    // for(int i = 0; i < n; i++) {
    //     if(map[a[i] + abs(f)] || map[a[i] - abs(f)]) {
    //         int z = map[a[i]]; 
    //         if(map[a[i] + abs(f)]) {
    //             int x = map[a[i] + abs(f)]; 
    //             count += x*z;
    //         }  
    //         if(map[a[i] - abs(f)]) {
    //             int x = map[a[i] - abs(f)];
    //             count += x*z;
    //         }    
    //         map.erase(a[i]);
    //         // cout << map[a[i]] << " ";
    //     }
    // }
    for(int i: a) {
        map[i]++;
    }
    for(auto p : map) {
        if((!k && p.second > 1) || (k && map.count(p.first + k))) {
            count++;
        }
    } 

    return count;
}
int zeroSumLongestSub(vector<int> &a, int n) {
    int sum = 0;
    int ml = 0;
    int l = 0;
    unordered_map<int, int> map;
    for(int i = 0; i < n; i++) {
        sum+= a[i];
        if(sum == 0) {
            l = i + 1;
        }
        else if(map.count(sum) > 0) {
            l = i - map[sum];
        }
        map[sum] = i;
        if(l > ml) {
            ml = l;
        }
    }
    return ml;
}

int main() {
    // unordered_map<string, int> m;
    // //insert
    // m["hey"] = 1;
    // pair<string, int> p("hello", 2);
    // m.insert(p);
    // //find or access
    // cout << m["hey"] << endl;
    // cout << "size : " << m.size() << endl; 
    // cout << m.at("hello") << endl;
    // // cout << m.at("ghi") << endl; -- will throw exception
    // cout << m["ghi"] << endl; 
    // cout << "size : " << m.size() << endl; 
    // // will return 0 if not found but will create a new entry
    // // check
    // if(m.count("ghi") > 0) {
    //     cout << "ghi is present" << endl;
    // }
    // // erase
    // m.erase("ghi");
    // cout << "size : " << m.size() << endl;
    // if(m.count("ghi") > 0) {
    //     cout << "ghi is present" << endl;
    // } 
    // vector<int> x = removeDuplicates(v);
    // for(int i = 0; i < x.size(); i++) {
    //     cout << x[i] << endl;
    // }
    // cout << maxFreq(v) << endl;
    // int n;
    // cin >> n;
    // while(n--) {
    //     int n1;
    //     cout << "Enter the number of elements" << endl;
    //     cin >> n1;
    //     vector<int> a(n1);
    //     cout << "Enter the elements" << endl;
    //     for(int i = 0; i < n1; i++) cin >> a[i];
    //     int n2;
    //     cout << "Enter the number of elements" << endl;
    //     cin >> n2;
    //     vector<int> b(n2);
    //     cout << "Enter the elements" << endl;
    //     for(int i = 0; i < n2; i++) cin >> b[i];
    //     vector<int> x= intersection(a, n1, b, n2);
    //     cout << "intersection elements are" << endl;
    //     for(auto i : x) {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }
    // vector<int> a(n);
    // for(int i = 0; i < n; i++) {
    //     cin >> a[i];
    // }
    // int x = pairSumToZero(a, n);
    // cout << x << endl;

    // working of iterator on map

    // unordered_map<string, int> m;
    // m["abc"] = 1;
    // m["uvw"] = 2;
    // m["hji"] = 3;
    // m["efg"] = 4;
    // m["xyz"] = 5; 
    // use of iterator to erase an element 
    // find function returns an iterator
    // unordered_map<string, int> :: iterator it2 = m.find("xyz");
    // m.erase(it2, m.end());

    // unordered_map<string, int> :: iterator it= m.begin();
    // while(it!= m.end()) {
    //     cout << "key: " << it->first << " value: " << it->second << endl;
    //     it++;
    // }

    // working of iterator on vector 

    // vector<int> v;
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);
    // v.push_back(4);
    // v.push_back(5); 
    // v.push_back(6);
    // v.push_back(7);
    // v.push_back(8);
    // vector<int> :: iterator it1 = v.begin();
    // while(it1!= v.end()) {
    //     cout << *it1 << endl;
    //     it1++;
    // }
    // string s;
    // cin >> s;
    // cout << extractUnique(s) << endl;
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // int f;
    // cin >> f;
    // vector<int> v = longestConsecSeq(a, n);
    // vector<int> :: iterator i = v.begin();
    // while(i != v.end()) {
    //     cout << *i << endl;
    //     i++;
    // }
    int x = zeroSumLongestSub(a, n);
    cout << x << endl;
    return 0;
}