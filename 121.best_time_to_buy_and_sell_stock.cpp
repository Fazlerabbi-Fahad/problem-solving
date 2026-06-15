#include<iostream>
#include<vector>
#include <climits>
using namespace std;

int maxProfit(vector<int>& prices) {
    int min=INT_MAX;
    int max=0;
    int i=0;

    while(i<prices.size())
    {
        if(min>prices[i]) min=prices[i];

        int profit=prices[i]-min;

        if(max<profit) max = profit;

        i++;
    }
    return max;
}

int main()
{
    vector<int> nums = {7,1,5,3,6,4};

    int result = maxProfit(nums);

    cout<<result<<endl;

    return 0;
}
