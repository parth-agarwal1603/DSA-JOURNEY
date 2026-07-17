/*
Problem: Merge Sorted Array

My Thought Process:
Since nums1 already has enough extra space at the end to
store all elements of nums2, merging from the beginning
would overwrite useful elements.

Instead, I start comparing elements from the end of both
arrays and place the larger element at the last available
position in nums1.

Algorithm:
1. Initialize three pointers:
   - i at the last valid element of nums1.
   - j at the last element of nums2.
   - k at the last position of nums1.
2. Compare nums1[i] and nums2[j].
3. Place the larger element at nums1[k].
4. Move the corresponding pointer.
5. If any elements remain in nums2, copy them into nums1.
6. Remaining elements in nums1 are already in their correct
   positions, so no extra work is required.

Time Complexity: O(m + n)
Space Complexity: O(1)

Key Concept:
- Two Pointers
- In-place Merging
- Backward Traversal

What I Learned:
Working from the end of the array prevents overwriting
elements that have not yet been compared, allowing the
merge to be completed in constant extra space.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0) {

            if (nums1[i] >= nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            }
            else {
                nums1[k] = nums2[j];
                j--;
            }

            k--;
        }

        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};