void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) 
{
    int a = m - 1;
    int b = n - 1;
    int c = m + n - 1;

    while (a >= 0 && b >= 0)
    {
        if (nums1[a] >= nums2[b])
        {
            nums1[c--] = nums1[a--];
        }
        else
        {
            nums1[c--] = nums2[b--];
        }
    }
 
    while (b >= 0)
    {
        nums1[b] = nums2[b];
        b--;
    }

    return;
}