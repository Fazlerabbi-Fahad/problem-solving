// Problem: Find Minimum in Rotated Sorted Array (#153)
// Pattern: Modified Binary Search (no target — search for break point)
// Key Insight: Compare nums[mid] vs nums[right] to find which
//              side has the "drop" (rotation point):
//              - nums[mid] > nums[right] → min is in [mid+1, right]
//              - nums[mid] <= nums[right] → min is in [left, mid]
// Complexity: O(log n) time, O(1) space
// Loop condition: left < right (not <=) — loop ends when
//                 left==right, which IS the answer
// Trap: Don't add redundant "min tracker" variables — trust
//       the loop invariant. nums[left] at the end is guaranteed
//       to be the minimum since [left,right] always contains it
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int findMin(vector<int>& nums) {
    int left=0;
    int right=nums.size()-1;
    while(left<right)
    {
        int mid = (left+right)/2;
        if(nums[mid]>nums[right])
        {
            left=mid+1;
        }
        else{
            right=mid;
        }

    }
    return nums[left];
}

int main()
{
    vector<int> nums = {1};

    int result = findMin(nums);

    cout<< result<<endl;

    return 0;
}
