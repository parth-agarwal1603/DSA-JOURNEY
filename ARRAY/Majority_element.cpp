/*
Problem: Majority Element

My Thought Process:
Initially I thought of using a hash map to count frequencies.
That solution works in O(n) time but requires O(n) extra space.

Then I learned BOYER_MOORE_VOTING_ALGORITHM.

My intution:
If there is a element which is more than n/2 times in a array than it mean 
that if I cancel out the majority element by other elements or even by itself at last 
the majority elemsnt will still be left because it appears more than n/2 times.


Idea:
If we pair every occurrence of the majority element with a different element,
the majority element will still remain because it appears more than n/2 times.

The algorithm keeps a candidate and a count.
When count becomes 0, a new candidate is selected.

Time Complexity: O(n)
Space Complexity: O(1)

What I Learned:
Not all counting problems require a hash map.
Sometimes a clever observation can reduce space complexity.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums)
     {
        int count=1;
     
        int n=nums.size();
        int maj=nums[0];
        
        for(int i=1;i<n;i++)
        {
            
            if(nums[i]==maj)
            {
           count++;
            }
            else
            {
                count--;
            }
            if(count==0)
            {
                maj=nums[i+1];
            }

    
    
    }
    
    return maj;

        
    }
};