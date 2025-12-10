int removeElement(int* nums, int numsSize, int val) {
    int writeIndex = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[writeIndex] = nums[i];
            writeIndex++;
        }
    }
    
    return writeIndex;
}
