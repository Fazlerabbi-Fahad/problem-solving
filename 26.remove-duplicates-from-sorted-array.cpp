// Two Pointers

// Problem: Remove Duplicates from Sorted Array
// Pattern: Slow & Fast Pointer
// Key Insight:
//   Since the array is sorted, duplicates are adjacent.
//   Use one pointer to track the position of the next unique element,
//   and another pointer to scan the array.
//
// Algorithm:
//   1. Initialize k = 1.
//   2. Traverse array from index 1.
//   3. If nums[i] != nums[k - 1]:
//        - Place nums[i] at nums[k].
//        - Increment k.
//   4. Return k.
//
// Complexity:
//   Time:  O(n)
//   Space: O(1)
//
// Important Trap:
//   Array is sorted.
//   This approach does NOT work correctly for unsorted arrays.
//
// Pointers:
//   k -> next position for unique element
//   i -> scans the array
//
// Result:
//   First k elements contain all unique values in order.
//
// Similar Problems:
//   Remove Element (LC 27)
//   Move Zeroes (LC 283)
//   Sort Colors (LC 75)
//   Remove Duplicates from Sorted Array II (LC 80)

#include<iostream>
#include<vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    if(nums.empty()) return 0;

    int k=1;

    for(int i=1; i<nums.size();i++)
    {
        if(nums[i]!=nums[k-1])
        {
            nums[k]=nums[i];
            k++;
        }
    }

    return k;
}

int main()
{
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    int result = removeDuplicates(nums);

    cout << result << endl;

    return 0;
}
