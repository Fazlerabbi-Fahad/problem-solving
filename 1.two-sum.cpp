// Complement Lookup using HashMap

// Problem: Two Sum
// Pattern: Complement Lookup — HashMap
// Key Insight: For each nums[i], check if (target - nums[i])
//              already exists in map
// Complexity: O(n) time, O(n) space
// Trap: Store AFTER lookup to avoid using same index twice
// Similar problems: Three Sum, Four Sum, Two Sum variants

#include<iostream>
#include<vector>
#include<map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    map<int,int> m;

    for(int i=0; i<nums.size();i++)
    {
        int second_number=target-nums[i];
        if(m.find(second_number)!=m.end())
        {
            return {i,m[second_number]};
        }

        m[nums[i]]=i;
    }
    return {};
}

int main()
{
    vector<int> nums = {3,2,4};
    int target = 6;

    vector<int> result = twoSum(nums, target);

    cout << "[" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
