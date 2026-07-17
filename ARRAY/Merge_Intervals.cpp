/*
Problem: Merge Intervals

My Thought Process:
If the intervals are sorted based on their starting points,
then overlapping intervals will appear next to each other.

I first sort the intervals and then iterate through them.

- If the current interval does not overlap with the last
  interval stored in the answer, I simply add it.
- Otherwise, I merge them by updating the ending point
  with the maximum ending value.

This way, all overlapping intervals are combined into one.

Time Complexity: O(n log n)
(The sorting step dominates the complexity.)

Space Complexity: O(n)
(Used for storing the merged intervals.)

Key Concept:
- Sorting
- Greedy
- Interval Merging

What I Learned:
Sorting transforms the problem into a simple linear scan,
where overlapping intervals can be merged efficiently by
comparing each interval with the last merged interval.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& interval) {

        sort(interval.begin(), interval.end());

        int n = interval.size();

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {

            if (ans.empty() || interval[i][0] > ans.back()[1]) {
                ans.push_back(interval[i]);
            }
            else {
                ans.back()[1] = max(ans.back()[1], interval[i][1]);
            }
        }

        return ans;
    }
};