int removeElement(int* nums, int numsSize, int val) 
{
    int a = 0;
    int b = 0;

    while (b < numsSize)
    {
        if (nums[b] != val)
        {
            nums[a++] = nums[b];
        }
        b++;
    }

    return a;
}