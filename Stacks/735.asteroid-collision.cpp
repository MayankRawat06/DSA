class Solution {
public:
    vector<int> asteroidCollision(vector<int>& v) {
        int n = v.size(), i = 0;
        stack<int> s;
        for(int& a : v) {
            while(!s.empty() && s.top() > 0 && a < 0) {
                int sum = a + s.top();
                if(sum < 0) s.pop();
                else if(sum > 0) a = 0;
                else {
                    s.pop();
                    a = 0;
                }
            }
            if(a != 0) s.push(a);
        }
        vector<int> res(s.size());
        for(int i = res.size() - 1; i >= 0; i--) {
            res[i] = s.top();
            s.pop();
        }
        return res;
    }
};
