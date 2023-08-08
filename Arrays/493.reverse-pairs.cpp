class Solution {
    void merge(int l, int mid, int r, vector<int>& v) {
        int i = l, j = mid;
        vector<int> temp;
        while(i <= mid - 1 && j <= r) {
            if(v[i] >= v[j]) temp.push_back(v[j++]);
            else temp.push_back(v[i++]);
        }
        while(i <= mid - 1) temp.push_back(v[i++]);
        while(j <= r) temp.push_back(v[j++]);
        for(int x = l; x <= r; x++) v[x] = temp[x - l];
    }
    long long op(int l, int mid, int r, vector<int>& v) {
        int j = mid;
        long long count = 0;
        for(int i = l; i <= mid - 1; i++) {
            while(j <= r && (long long)2 * v[j] < v[i]) j++;
            count += j - mid;
        }
        return count;
    }
    long long f(int l, int r, vector<int>& v) {
        long long count = 0;
        if(r > l) {
            int mid = l + (r - l) / 2;
            count += f(l, mid, v);
            count += f(mid + 1, r, v);
            count += op(l, mid + 1, r, v);
            merge(l, mid + 1, r, v);
        }
        return count;
    }
public:
    int reversePairs(vector<int>& v) {
        int n = v.size();
        return f(0, n - 1, v);
    }
};