int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    
    int writeIndex = 1;
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1]) {
            nums[writeIndex] = nums[i];
            writeIndex++;
        }
    }
    
    return writeIndex;
}
