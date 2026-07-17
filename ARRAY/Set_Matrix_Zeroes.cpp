/*
Problem: Set Matrix Zeroes

My Thought Process:
Initially I thought of using two extra arrays to store
which rows and columns contain zeroes.

However, that requires O(n + m) extra space.

Then I realized that the first row and first column of
the matrix can themselves be used as markers.

Algorithm:
1. Traverse the matrix.
2. Whenever a zero is found:
   - Mark its row by setting matrix[row][0] = 0.
   - Mark its column by setting matrix[0][col] = 0.
3. Since the first column is also being used as a marker,
   maintain a separate variable 'col' to remember whether
   the first column originally contained a zero.
4. Traverse the matrix again (excluding the first row and
   first column) and update cells based on the markers.
5. Finally, update the first row and first column if required.

Time Complexity: O(n × m)
Space Complexity: O(1)

What I Learned:
Using the matrix itself as a storage for markers eliminates
the need for extra arrays and achieves constant extra space.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& nums) {

        int col = 1;

        int n = nums.size();
        int m = nums[0].size();

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                if(nums[i][j] == 0) {

                    nums[i][0] = 0;

                    if(j != 0)
                        nums[0][j] = 0;
                    else
                        col = 0;
                }
            }
        }

        for(int i = 1; i < n; i++) {

            for(int j = 1; j < m; j++) {

                if(nums[i][j] != 0) {

                    if(nums[i][0] == 0 || nums[0][j] == 0)
                        nums[i][j] = 0;
                }
            }
        }

        if(nums[0][0] == 0) {

            for(int i = 0; i < m; i++)
                nums[0][i] = 0;
        }

        if(col == 0) {

            for(int i = 0; i < n; i++)
                nums[i][0] = 0;
        }
    }
};