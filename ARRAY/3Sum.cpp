

/*
Problem: 3Sum

My Thought Process:
I first sort the array so that duplicate elements can be
handled efficiently and the two-pointer technique can be used.

I fix one element at a time and then use two pointers:
- One pointer starts from the next element.
- The other starts from the end of the array.

Based on the sum of the three elements:
- If the sum is smaller than 0, I move the left pointer.
- If the sum is greater than 0, I move the right pointer.
- If the sum is equal to 0, I store the triplet and skip
  duplicate values to avoid repeated answers.

Time Complexity: O(n²)
Space Complexity: O(1) Auxiliary Space
(The output vector is not counted as extra space.)

Key Concept:
- Sorting
- Two Pointers
- Duplicate Handling

What I Learned:
Sorting the array allows the two-pointer technique to be
applied efficiently, reducing the brute-force O(n³)
solution to O(n²) while naturally handling duplicates.
*/
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int sum=INT_MIN;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            int j=i+1;
            int k=n-1;
            if(i>0 && nums[i-1]==nums[i])
            continue;
            else
            {
            while(j<k)
            {
                sum=nums[i]+nums[j]+nums[k];
                if(sum<0)
                {
                    j++;
                    
                }
                else if(sum>0)
                {
                    k--;
                }
                else
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;

                    while(j < k && nums[j] == nums[j-1]) j++;
                    while(j < k && nums[k] == nums[k+1]) k--;
                }
            }
            }
        }
        return ans;
    }
};