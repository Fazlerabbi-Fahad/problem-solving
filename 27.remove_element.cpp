// Fast & Slow Pointer (In-Place Filtering)

// Problem: Remove Element
// Pattern: Fast/Slow Pointer
// Key Insight: Keep all elements that are NOT equal to val
//              at the beginning of the array.
// Complexity: O(n) time, O(1) extra space
// Trap: Do NOT shift elements one by one.
//       Do NOT access nums[i+1] (can cause out-of-bounds).
// Similar problems: Remove Duplicates from Sorted Array,
//                   Move Zeroes, Partition Array

#include<iostream>
#include<vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    if(nums.empty()) return 0;

    int k=0;

    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]!=val)
        {
            nums[k]=nums[i];
            k++;
        }
    }

    return k;
}


int main()
{
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;

    int result = removeElement(nums,val);

    cout << result << endl;

    return 0;
}
