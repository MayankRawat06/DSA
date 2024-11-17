class Solution {
  vector<int> res;
  void f(int i, int sum, vector<int> v) {
      int n = v.size();
      if(i == n) {
          res.push_back(sum);
          return;
      }
      f(i + 1, sum, v);
      f(i + 1, sum + v[i], v);
  }
  public:
    vector<int> subsetSums(vector<int> v, int n) {
        // Write Your Code here
        f(0, 0, v);
        return res;
    }
};