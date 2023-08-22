class StockSpanner {
    // previous greater element
    stack<pair<int, int>> s;
public:
    StockSpanner() {
        
    }
    int next(int price) {
        int count = 0;
        while(!s.empty() && s.top().first <= price) {
            count += s.top().second;
            s.pop();
        }
        s.push({price, count + 1});
        return count + 1;
    }
};
