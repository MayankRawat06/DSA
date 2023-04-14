class Solution{
    public:
    string findOrder(string dict[], int n, int k) {
        //code here
        vector<vector<int>> adj(k);
        vector<int> indegree(k, 0);
        for(int i = 1; i < n; i++) {
            string s = dict[i - 1];
            string t = dict[i];
            for(int i = 0; i < min(s.size(), t.size()); i++) {
                if(s[i] != t[i]) {
                    adj[s[i] - 'a'].push_back(t[i] - 'a');
                    indegree[t[i] - 'a']++;
                    break;
                }
            }
        }
        queue<int> q;
        for(int i = 0; i < k; i++) if(indegree[i] == 0) q.push(i);
        string res = "";
        while(!q.empty()) {
            int node = q.front(); q.pop();
            char c = 'a' + node;
            res += c;
            for(int x : adj[node]) {
                indegree[x]--;
                if(indegree[x] == 0) q.push(x);
            }
        }
        return res;
    }
};