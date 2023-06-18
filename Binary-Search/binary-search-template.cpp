while (left < right) {
    int mid = (left + right) / 2;
    if (condition)
        right = mid;
    else
        left = mid + 1;
}
return left;