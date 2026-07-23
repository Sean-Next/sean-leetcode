void reverse(int* arr, int left, int right)
{
    while (left <= right)
    {
        int temp = arr[left];
        arr[left++] = arr[right];
        arr[right--] = temp; 
    }

    return;
}

void rotate(int* nums, int numsSize, int k) 
{
    k = k % numsSize;

    reverse(nums, 0, numsSize - k - 1);
    reverse(nums, numsSize - k, numsSize - 1);
    reverse(nums, 0, numsSize - 1);

    return;
}