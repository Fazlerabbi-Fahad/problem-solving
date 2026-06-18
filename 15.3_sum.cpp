// Problem: 3Sum (#15)
// Pattern: Sort + Two Pointers (extended from Two Sum)
// Key Insight: Fix nums[i], reduce to Two Sum with
//              target = -nums[i] on sorted subarray
// Complexity: O(n²) time, O(1) space (excluding output)
// Duplicate handling:
//   - Outer loop: if nums[i]==nums[i-1] → skip
//   - After match: while nums[left]==nums[left-1] → left++
//                  while nums[right]==nums[right+1] → right--
// Trap: After finding match, move pointers FIRST (left++,
//       right--), THEN skip duplicates with while, not if

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    vector<int> triplet;
    vector<vector<int>> threeSum;

    for(int i=0; i<nums.size();i++)
    {
        if(i>0 && nums[i]==nums[i-1]) continue;
        int left=i+1;
        int right=nums.size()-1;

        while(left<right)
        {
            int sum=nums[i]+nums[left]+nums[right];
            if(sum==0)
            {
                triplet.push_back(nums[i]);
                triplet.push_back(nums[left]);
                triplet.push_back(nums[right]);
                threeSum.push_back(triplet);
                triplet.clear();
                left++;
                right--;

                while(left < right && nums[left] == nums[left-1]) left++;
                while(left < right && nums[right] == nums[right+1]) right--;
            }
            else if(sum<0)
            {
                left++;
            }
            else{
                right--;
            }
        }
    }
    return threeSum;
}


int main()
{
    vector<int> nums = {0,0,0};

    vector<vector<int>> result = threeSum(nums);

    for (int i = 0; i < result.size(); i++)
    {
        cout << "[" << result[i][0] << ", " << result[i][1]<< ", " << result[i][2] << "]" << endl;
    }


    return 0;
}
