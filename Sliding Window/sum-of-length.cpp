
class Solution {
  public:
    int sumoflength(int v[], int n) {
        int i = 0, count = 0;
        unordered_map<int, int> map;
        for(int j = 0; j < n; j++) {
            map[v[j]]++;
            while(i < n && map[v[j]] > 1) {
                map[v[i]]--;
                i++;
            }
            count += ((j - i + 2) * (j - i + 1) / 2);
        }
        return count;
    }
};