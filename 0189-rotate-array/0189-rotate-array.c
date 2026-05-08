void reverse(int* nums, int left, int right)
{
    while (left < right)
    {
        int tmp = nums[left];
        nums[left++] = nums[right];
        nums[right--] = tmp;
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