/*
Problem: Rearrange Array Elements by Sign

My Thought Process:
The final array should have positive and negative numbers
alternating with each other.

I noticed that:
- Positive numbers must occupy even indices.
- Negative numbers must occupy odd indices.

So I created a new array and maintained two pointers:
pos = 0 for positive numbers
neg = 1 for negative numbers

Whenever I encountered a positive number, I placed it at
the current positive index and moved the pointer by 2.
I did the same for negative numbers.

Time Complexity: O(n)
Space Complexity: O(n)

What I Learned:
Sometimes directly placing elements in their final positions
is simpler than repeatedly swapping elements.
*/

#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos=0;
        int neg=1;
        
        int n=nums.size();
        vector<int>arr(n);
        for(int i=0;i<n;i++)
        {
            if(nums[i]>=0)
            {
                arr[pos]=nums[i];
                pos+=2;
            }
            else
            {
                arr[neg]=nums[i];
                neg+=2;
            }
            
        }
        return arr;
        
    }
};
        
   