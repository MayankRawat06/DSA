class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n = v.size();
        int mini = v[0], profit = 0;
        for(int i = 1; i < n; i++) { // if i sell today
            profit = max(profit, v[i] - mini); // profit = curr element - minimum just before curr element
            mini = min(mini, v[i]); // update for further elements
        }
        return profit;
    }
};