/*
Problem: Spiral Matrix

My Thought Process:
The matrix can be traversed layer by layer.

I maintain four boundaries:
1. Starting Row
2. Ending Row
3. Starting Column
4. Ending Column

For every layer:
- Traverse the top row from left to right.
- Traverse the right column from top to bottom.
- Traverse the bottom row from right to left.
- Traverse the left column from bottom to top.

After completing one layer, shrink all four boundaries
towards the center and repeat until all elements are visited.

Special conditions are required while traversing the
bottom row and left column to avoid duplicate elements
in matrices having only one row or one column.

Time Complexity: O(m × n)
Space Complexity: O(1) Auxiliary Space
(The output vector is not counted as extra space.)

What I Learned:
Maintaining four boundaries is an elegant way to solve
matrix traversal problems while avoiding revisiting elements.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> ans;

        int srow = 0, scol = 0;
        int erow = m - 1, ecol = n - 1;

        while (srow <= erow && scol <= ecol) {

            // Top Row
            for (int j = scol; j <= ecol; j++)
                ans.push_back(matrix[srow][j]);

            // Right Column
            for (int i = srow + 1; i <= erow; i++)
                ans.push_back(matrix[i][ecol]);

            // Bottom Row
            if (srow < erow) {
                for (int j = ecol - 1; j >= scol; j--)
                    ans.push_back(matrix[erow][j]);
            }

            // Left Column
            if (scol < ecol) {
                for (int i = erow - 1; i > srow; i--)
                    ans.push_back(matrix[i][scol]);
            }

            srow++;
            scol++;
            erow--;
            ecol--;
        }

        return ans;
    }
};