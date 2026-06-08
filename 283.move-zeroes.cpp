// Problem: Move Zeroes
// Pattern: Two Pointers
// Key Insight:
//   Keep a pointer `k` that tracks the position where the next
//   non-zero element should be placed.
//
// Algorithm:
//   1. Traverse the array with pointer `i`.
//   2. Whenever nums[i] is non-zero, swap nums[i] with nums[k].
//   3. Increment k.
//   4. After all non-zero elements are moved forward,
//      all zeroes automatically end up at the end.
//
// Example:
//   nums = [0,1,0,3,12]
//
//   i=1 -> swap(1,0)  => [1,0,0,3,12], k=1
//   i=3 -> swap(3,1)  => [1,3,0,0,12], k=2
//   i=4 -> swap(4,2)  => [1,3,12,0,0], k=3
//
//   Result: [1,3,12,0,0]
//
// Time Complexity: O(n)
// Space Complexity: O(1)

#include<iostream>
#include<vector>

using namespace std;

vector<int> moveZeroes(vector<int>& nums) {
    if(nums.empty()) return {};

    int k=0;

    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]!=0)
        {
            swap(nums[i],nums[k]);
            k++;
        }
    }
    return nums;
}


int main()
{
    vector<int> nums = {0,1,0,3,12,0};

    vector<int> result = moveZeroes(nums);

    for(int i=0;i<result.size();i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}
