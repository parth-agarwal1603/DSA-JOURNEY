/*
Problem: Next Permutation

My Thought Process:
The next permutation should be just larger than the current one.

I first searched from the right and found the first position
where the sequence stops decreasing.

This position is called the breakpoint.

Then I searched from the right again to find the smallest
element greater than the breakpoint element and swapped them.

Finally, I reversed the remaining suffix to obtain the
smallest possible arrangement after the breakpoint.

Special Case:
If no breakpoint exists, the array is already the largest
permutation. In that case, reversing the entire array gives
the smallest permutation.

Time Complexity: O(n)
Space Complexity: O(1)

What I Learned:
When dealing with permutations, working from the right side
often reveals the next lexicographically larger arrangement.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i=-1;
        for(int k=n-2;k>=0;k--)
        {
            if(nums[k]<nums[k+1])
            {
                i=k;
                break;
            }
            
        }
        if(i==-1)
        {
            reverse(nums.begin(),nums.end());
            return; 
        }
        for(int j=n-1;j>i;j--)
        {
            if(nums[j]>nums[i])
            {
            swap(nums[j],nums[i]);
            reverse(nums.begin()+i+1,nums.end());
            return;
            }

        }


        

        
    }
};