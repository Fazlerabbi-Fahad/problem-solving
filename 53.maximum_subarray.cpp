// Problem: Maximum Subarray (#53)
// Pattern: Kadane's Algorithm
// Key Insight: Reset running sum when it goes negative —
//              negative sum only hurts future elements
// Complexity: O(n) time, O(1) space
// Trap: Initialize maxSum=INT_MIN not 0 —
//       handles all-negative arrays

#include<iostream>
#include<vector>
#include <climits>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int current_sum=0;
    int max_sum=INT_MIN;

    for(int i=0;i<nums.size();i++)
    {
        current_sum=current_sum+nums[i];

        if(current_sum>max_sum) max_sum=current_sum;
        if(current_sum<0) current_sum=0;
    }
    return max_sum;
}

int main()
{
    vector<int> nums = {5,4,-1,7,8};

    int result = maxSubArray(nums);

    cout<<result<<endl;

    return 0;
}
