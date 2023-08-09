vector<int> Solution::repeatedNumber(const vector<int> &v) {
    long long n = v.size();
    long long m = -1, r = -1;
    long long sum = 0, sumsq = 0;
    for(int i = 0;i < n; i++) {
        sum += v[i];
        sumsq += ((long long)v[i] * (long long)v[i]);
    }
    long long sn = n * (n + 1) / 2, s2n = n * (n + 1) * (2 * n + 1) / 6;
    long long diff = sn - sum, diffsq = s2n - sumsq;
    long long z = diffsq / diff;
    m = (z + diff) / 2;
    r = m - diff;
    return {r, m};
}