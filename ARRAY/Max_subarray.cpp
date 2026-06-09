/*
Problem: Maximum Subarray

My Thought Process:
At first I thought of generating all possible subarrays and
finding their sums, but that would be very slow.

Then I noticed that if the current sum becomes negative,
it will only decrease the sum of any future subarray.

So whenever the current sum becomes negative,
I start a new subarray from the next element.

I keep track of:
1. Current subarray sum
2. Maximum sum found so far

Special Case:
If all elements are negative, the answer should be the
largest element in the array, not 0.

Time Complexity: O(n)
Space Complexity: O(1)

What I Learned:
A negative running sum can never help increase a future
subarray sum, so it can be discarded.
This idea forms the basis of Kadane's Algorithm.
*/
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int maxsum=INT_MIN;
        for(int i=0;i<n;i++)
        {
            sum=sum+nums[i];
            maxsum=max(sum,maxsum);
            if(sum<0)
            sum=0;
        }
        return maxsum;
        
    }
};