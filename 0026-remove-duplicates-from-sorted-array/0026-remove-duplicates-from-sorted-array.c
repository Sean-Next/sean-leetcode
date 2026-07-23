int removeDuplicates(int* nums, int numsSize) 
{
    int a = 0;
    int b = 0;

    while (b < numsSize)
    {
        if (nums[b] != nums[a])
        {
            nums[++a] = nums[b];
        }
        b++;
    }

    return a + 1;
}