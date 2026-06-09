/*
Problem: Best Time to Buy and Sell Stock

My Thought Process:
Initially I thought of checking every possible buy and sell day,
but that would take O(n²) time.

Then I realized that for every day, I only need to know the
minimum stock price seen before that day.

For each price:
Profit = Current Price - Minimum Price Seen So Far

I keep updating:
1. Minimum buying price
2. Maximum profit

This allows me to find the answer in a single traversal.

Time Complexity: O(n)
Space Complexity: O(1)

What I Learned:
Maintaining a running minimum can eliminate the need for
nested loops in optimization problems.
*/
#include <iostream>
#include <vector>
#include <climitS>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& nums) {

        int cost = 0;
        int profit = INT_MIN;
        int mini = nums[0];

        int n = nums.size();

        for(int i = 1; i < n; i++) {

            cost = nums[i] - mini;

            profit = max(profit, cost);

            mini = min(mini, nums[i]);
        }

        if(profit > 0)
            return profit;
        else
            return 0;
    }
};