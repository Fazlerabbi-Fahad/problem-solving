// Problem: Maximum Product Subarray (#152)
// Pattern: Modified Kadane's Algorithm (Min-Max tracking)
// Key Insight: Multiplication flips sign — a very negative
//              running product can become the best answer if
//              multiplied by another negative number
// Algorithm: At each index, compute 3 candidates:
//            nums[i], nums[i]*prevMax, nums[i]*prevMin
//            Take max → new max_value, min → new min_value
// Complexity: O(n) time, O(1) space
// Trap: Tracking only max_value (like normal Kadane's) loses
//       the ability to recover large positives from very
//       negative products when multiplied by a negative number
// Initialization: max_value=1, min_value=1 (identity),
//                 result=INT_MIN (handles all-negative arrays)

#include<iostream>
#include<vector>
#include <climits>
#include <algorithm>
using namespace std;

int maxProduct(vector<int>& nums) {
    int max_value=1;
    int min_value=1;
    int result=INT_MIN;

    for(int i=0;i<nums.size();i++)
    {
        int candidate1=nums[i];
        int candidate2=nums[i] * max_value;
        int candidate3=nums[i] * min_value;

        max_value=max({candidate1,candidate2,candidate3});
        min_value=min({candidate1,candidate2,candidate3});

        if(max_value>result)
        {
            result=max_value;
        }
    }

    return result;
}

int main()
{
    vector<int> nums = {2,3,-2,4};

    int result = maxProduct(nums);

    cout<<result<<endl;

    return 0;
}
