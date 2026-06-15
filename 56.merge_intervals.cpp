// Problem: Merge Intervals (#56)
// Pattern: Sort + Linear Scan with "current" tracker
// Key Insight: Sort by start time → overlapping intervals
//              become adjacent → one pass is enough
// Overlap condition: current.end >= next.start
// Merge: current.end = max(current.end, next.end)
// Complexity: O(n log n) time, O(n) space
// Trap: Don't push inside overlap block — only push when
//       you're DONE with current (else block + after loop)

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(),
         [](vector<int> &a, vector<int> &b) { return a[0] < b[0]; });

    vector<vector<int>> merged;
    vector<int> current = intervals[0];

    for (int i = 1; i < intervals.size(); i++)
    {
        if (current[1] >= intervals[i][0])
        {
            if (intervals[i][1] > current[1])
            {
                current[1] = intervals[i][1];
            }
        }
        else
        {
            merged.push_back(current);
            current = intervals[i];
        }
    }
    merged.push_back(current);

    return merged;
}

int main()
{
    vector<vector<int>> nums = {{1,3}, {2, 6}, {10, 8}};

    vector<vector<int>> result = merge(nums);

   for (int i = 0; i < result.size(); i++)
    {
        cout << "[" << result[i][0] << ", " << result[i][1] << "]" << endl;
    }

    return 0;
}
