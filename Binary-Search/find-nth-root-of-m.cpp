long long check(int k, int n, int m) {
  long long res = 1;
  for(int i = 0; i < n; i++) {
    res *= k;
    if(res > m) return INT_MAX;
  }
  return res;
}
int NthRoot(int n, int m) {
  // Write your code here.
  int low = 1, high = m;
  while(low <= high) {
    int mid = low + (high - low) / 2;
    long long power = check(mid, n, m);
    if(power == m) return mid;
    else if(power < m) low = mid + 1;
    else high = mid - 1;
  }
  return -1;
}