/*
Initial Idea:
Check every possible pair.

Problem:
This requires O(n²) comparisons.

Optimization:
For each element, calculate the value needed to reach
the target and check if that value has already been seen.

Using an unordered_map allows O(1) average lookup time,
reducing the overall complexity to O(n).

Time Complexity: O(n)
Space Complexity: O(n)
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
    class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int>mp;
    int n=nums.size();
    
    for(int i=0;i<n;i++)
    {
        int k=target-nums[i];
        if(mp.count(k))
        return {i,mp[k]};
    else mp[nums[i]]=i;}
    return{};
    }
};
