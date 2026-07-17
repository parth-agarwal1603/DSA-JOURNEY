/*
Problem: Majority Element II

My Thought Process:
A number can appear more than n/3 times only if there are
at most two such elements.

So, I use an extended version of the Boyer-Moore Voting
Algorithm to find two potential candidates.

Algorithm:
1. Maintain two candidates and their counts.
2. Traverse the array:
   - If the current element matches a candidate,
     increase its count.
   - If a candidate's count becomes zero,
     replace it with the current element.
   - Otherwise, decrease both counts.
3. The first traversal only gives potential candidates.
4. Traverse the array again to verify whether the
   candidates actually occur more than n/3 times.

Time Complexity: O(n)
Space Complexity: O(1)

Key Concept:
- Boyer-Moore Voting Algorithm
- Candidate Elimination
- Array Traversal

What I Learned:
The Boyer-Moore Voting Algorithm can be extended to find
elements occurring more than n/k times by maintaining
(k - 1) candidates and verifying them in a second pass.
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int count1 = 0, count2 = 0;
        int el1 = INT_MIN, el2 = INT_MIN;

        int n = nums.size();

        // Find potential candidates
        for (int i = 0; i < n; i++) {

            if (count1 == 0 && nums[i] != el2) {
                count1++;
                el1 = nums[i];
            }
            else if (count2 == 0 && nums[i] != el1) {
                count2++;
                el2 = nums[i];
            }
            else if (nums[i] == el1) {
                count1++;
            }
            else if (nums[i] == el2) {
                count2++;
            }
            else {
                count1--;
                count2--;
            }
        }

        // Verify the candidates
        count1 = 0;
        count2 = 0;

        for (int i = 0; i < n; i++) {

            if (nums[i] == el1)
                count1++;

            if (nums[i] == el2)
                count2++;
        }

        vector<int> ans;
        int required = (n / 3) + 1;

        if (count1 >= required)
            ans.push_back(el1);

        if (count2 >= required)
            ans.push_back(el2);

        return ans;
    }
};