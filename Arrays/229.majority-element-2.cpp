class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
        int n = v.size();
        // moore's voting
        int e1 = 0, e2 = 0, cnt1 = 0, cnt2 = 0;
        for(int x : v) {
            if(cnt1 == 0 && x != e2) {
                e1 = x;
                cnt1 = 1;
            }
            else if(cnt2 == 0 && x != e1) {
                e2 = x;
                cnt2 = 1;
            }
            else if(x == e1) cnt1++;
            else if(x == e2) cnt2++;
            else cnt1--, cnt2--;
        }
        // verify
        int freq1 = 0, freq2 = 0;
        for(int x : v) {
            if(x == e1) freq1++;
            else if(x == e2) freq2++;
        }
        vector<int> res;
        if(freq1 > n / 3) res.push_back(e1);
        if(freq2 > n / 3) res.push_back(e2);
        return res;
    }
};