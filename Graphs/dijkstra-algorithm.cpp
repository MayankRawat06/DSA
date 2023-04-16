class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int s)
    {
        // using priority queue -- min heap
        vector<int> dis(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, s});
        dis[s] = 0;
        while(!pq.empty()) {
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            for(auto x : adj[node]) {
                int neighbor = x[0];
                int far = x[1];
                if(dis[neighbor] > d + far) {
                    dis[neighbor] = d + far;
                    pq.push({dis[neighbor], neighbor});
                }
            }
        }
        return dis;
    }
};