/*
Problem: 4Sum

My Thought Process:
I first sort the array so that duplicate elements can be
handled easily and the two-pointer technique can be applied.

I fix the first two elements using two nested loops.
Then, I use two pointers to find the remaining two elements
whose sum makes the total equal to the target.

Whenever a quadruplet is found, I store it in the answer
and skip duplicate values to avoid repeated quadruplets.

Time Complexity: O(n³)
Space Complexity: O(1) Auxiliary Space
(The output vector is not counted as extra space.)

Key Concept:
- Sorting
- Two Pointers
- Duplicate Handling

What I Learned:
Sorting combined with the two-pointer technique reduces the
problem from checking all possible quadruplets to an efficient
O(n³) solution while avoiding duplicate answers.
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n=nums.size();
        int st=0,end=0;
        long long sum=0;
        for(int i=0;i<n-3;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            continue;
            for(int j=i+1;j<n-2;j++)
            {
                if(j > i+1 && nums[j] == nums[j-1])
                continue;
                st=j+1;
                end=n-1;
                
                
                while(st < end)
                {
                    sum=(long long)nums[i]+nums[j]+nums[st]+nums[end];
                    if(sum > target )
                    end--;
                    else if(sum < target)
                    st++;
                    else 
                    {
                    ans.push_back({nums[i],nums[j],nums[st],nums[end]});
                    st++;
                    end--;
                    

                    while(st < end && nums[st] == nums[st-1])
                    st++;

                    while(st < end && nums[end] == nums[end+1])
                    end--;
                    }


                }
                

            }

        }
        return ans;
        
        
        
    }
};