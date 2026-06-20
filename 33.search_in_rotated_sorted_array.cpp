// Problem: Search in Rotated Sorted Array (#33)
// Pattern: Modified Binary Search
// Key Insight: At any midpoint, at least ONE half is always
//              fully sorted. Check nums[left] <= nums[mid] to
//              determine which half is sorted, then check if
//              target lies within that sorted half's range
// Complexity: O(log n) time, O(1) space
// Trap: Don't slice arrays in recursion (O(n) copy cost per
//       call kills the O(log n) benefit) — pass left/right
//       indices instead. Boundary conditions: <= on the outer
//       edge, < on the mid edge (since mid is checked separately)


#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
    int left=0;
    int right=nums.size()-1;

    while(left<=right)
    {
        int mid = (left+right)/2;
        if(nums[mid]==target) return mid;
        if(nums[left]<=nums[mid])
        {
            if(nums[left]<=target && target<nums[mid])
            {
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        else{
            if(nums[mid]<target && target<=nums[right])
            {
                left=mid+1;
            }else{
                right=mid-1;
            }
        }

    }
    return -1;
}

int main()
{
    vector<int> nums = {4,5,6,7,0,1,2};
    int target=4;

    int result = search(nums,target);

    cout<< result<<endl;

    return 0;
}
