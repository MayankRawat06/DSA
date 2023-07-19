class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        vector<int> ev1(2), ev2(2);
        for(int i = 0; i < 2; i++) {
            string s = event1[i];
            for(char c : s) {
                if(c >= '0' && c <= '9') {
                    ev1[i] *= 10;
                    ev1[i] += (c - '0');
                }
            }
        }
        for(int i = 0; i < 2; i++) {
            string s = event2[i];
            for(char c : s) {
                if(c >= '0' && c <= '9') {
                    ev2[i] *= 10;
                    ev2[i] += (c - '0');
                }
            }
        }
        if(ev1[0] > ev2[0]) {
            vector<int> temp(ev1.begin(), ev1.end());
            ev1 = ev2;
            ev2 = temp;
        }
        int s1 = ev1[0], e1 = ev1[1], s2 = ev2[0], e2 = ev2[1];
        return !(s2 > e1);
    }
};