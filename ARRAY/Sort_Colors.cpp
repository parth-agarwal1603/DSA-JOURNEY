/*
Problem: Sort Colors

My Thought Process:
Initially I thought of using the built-in sort() function.
However, that would take O(n log n) time.

Since the array contains only 0, 1, and 2,
I realized we could place:
- 0s at the beginning
- 2s at the end
- 1s automatically remain in the middle
- The unsorted part of the array is between low and high pointers.

Workflow:
1. If the current element is 0, swap it with the element at low pointer and move both pointers forward.
2. If the current element is 1, just move the mid pointer forward.
3. If the current element is 2, swap it with the element at high pointer and move the high pointer backward.

I used three pointers:
low  -> position for next 0
mid  -> current element being processed
high -> position for next 2

This allows the array to be sorted in a single traversal.

Time Complexity: O(n)
Space Complexity: O(1)

What I Learned:
The Dutch National Flag Algorithm can partition an array
containing three distinct values in one pass.
*/#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int high=nums.size()-1;
        int low=0;
        int mid=0;
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[mid],nums[low]);
                low++;
                mid++;

            }
            else if(nums[mid]==1)
            {
                
                mid++;

            }
            else 
            {
                swap(nums[mid],nums[high]);
                high--;
                

            }

        }

        
    }
};