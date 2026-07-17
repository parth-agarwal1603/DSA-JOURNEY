/*
Problem: Pascal's Triangle

My Thought Process:
Each row of Pascal's Triangle starts and ends with 1.

For every other element, its value is the sum of the
two elements directly above it from the previous row.

So, I build the triangle row by row:
1. Create a new row.
2. Put 1 at the beginning and end.
3. For the remaining positions, calculate the sum of
   the two adjacent elements from the previous row.
4. Add the completed row to the answer.

Time Complexity: O(numRows²)
Space Complexity: O(1) Auxiliary Space
(The output vector is not counted as extra space.)

Key Concept:
- Dynamic Construction
- Simulation
- 2D Vector

What I Learned:
Many problems can be solved by building the answer
incrementally using previously computed results.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> ans;

        for (int i = 0; i < numRows; i++) {

            vector<int> temp;

            for (int j = 0; j <= i; j++) {

                if (j == 0 || j == i) {
                    temp.push_back(1);
                }
                else {
                    temp.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
                }
            }

            ans.push_back(temp);
        }

        return ans;
    }
};