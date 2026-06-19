// Problem: Container With Most Water (#11)
// Pattern: Two Pointers (greedy, shrinking window)
// Key Insight: Always move the SHORTER pointer inward —
//              moving the taller one can only hurt (width
//              decreases, height limit stays same or worse)
// Complexity: O(n) time, O(1) space
// Trap: Width × min(heights) — not max. The shorter wall
//       always determines water level (water spills over it)

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height) {
    int left=0;
    int right=height.size()-1;
    int max_area=0;

    while(left<right)
    {
        int width=right-left;
        int min_height=min(height[left],height[right]);
        int area=width*min_height;

        if(area>max_area) max_area=area;

        if(height[left]<height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return max_area;
}

int main()
{
    vector<int> nums = {1,8,6,2,5,4,8,3,7};

    int result = maxArea(nums);

    cout<< result<<endl;

    return 0;
}
