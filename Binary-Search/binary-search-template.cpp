while (left < right) {
    int mid = (left + right) / 2;
    if (condition)
        right = mid;
    else
        left = mid + 1;
}
return left;
/*
 When using mid and mid-1 put (l + r + 1) // 2 -- choosing maximum 
 When using mid and mid + 1 put (l + r)//2 or l + (r - l) / 2 -- choosing minimum

This is because we want to push the boundaries in both cases. When using mid and mid +1 we are pushing the lower bondary with mid+1 so to also push the higher boundary we use by default a lower mid (aka l+r//2). And vice versa.
*/
