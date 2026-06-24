/*
Problem: Longest Consecutive Sequence

My Thought Process:
Initially I thought of sorting the array and then checking
for consecutive numbers.

However, sorting would take O(n log n) time.

To achieve O(n), I stored all elements in an unordered_set.

For every element, I first check whether it is the start
of a sequence.

If (current element - 1) is not present in the set,
then the current element is the beginning of a consecutive sequence.

From there, I keep extending the sequence until the next
number is not found.

I maintain the maximum sequence length encountered.

Time Complexity: O(n)
Space Complexity: O(n)

What I Learned:
Hash sets can eliminate the need for sorting and allow
constant-time lookups, leading to linear-time solutions.
*/

#include <iostream>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int> st;
        int n=nums.size();
        int k=0,it;
        int count=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
           st.insert(nums[i]);
        }
        for(auto it:st)
        {
        if(st.find(it - 1) == st.end())
        {
            count=1;
            k=it;

            while(st.find(k+1)!=st.end())
            {
                count++;
                k++;
            }
            ans=max(count,ans);
        }
        }
        return ans;
        
    }
};