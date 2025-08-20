/*  
 *  TITLE: 4. Median of Two Sorted Arrays
 *  DESCRIPTION: 
 *      Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
 *      The overall run time complexity should be O(log (m+n)).
 *
 *  CONSTRAINTS:
 *      - nums1.length == m
 *      - nums2.length == n
 *      - 0 <= m <= 1000
 *      - 0 <= n <= 1000
 *      - 1 <= m + n <= 2000
 *      - -106 <= nums1[i], nums2[i] <= 106
*/  

// Solutions
// C++
// 1.
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m;

        while (left <= right) {
            int i = (left + right) / 2; // Partition in nums1
            int j = (m + n + 1) / 2 - i; // Partition in nums2

            // Edge cases: use INT_MIN/INT_MAX for empty sides
            int nums1_left = (i == 0) ? INT_MIN : nums1[i - 1];
            int nums1_right = (i == m) ? INT_MAX : nums1[i];
            int nums2_left = (j == 0) ? INT_MIN : nums2[j - 1];
            int nums2_right = (j == n) ? INT_MAX : nums2[j];

            // Check if partition is correct
            if (nums1_left <= nums2_right && nums2_left <= nums1_right) {
                if ((m + n) % 2 == 0) {
                    return (max(nums1_left, nums2_left) + min(nums1_right, nums2_right)) / 2.0;
                } else {
                    return max(nums1_left, nums2_left);
                }
            } else if (nums1_left > nums2_right) {
                // Move i left
                right = i - 1;
            } else {
                // Move i right
                left = i + 1;
            }
        }
        return 0.0;
    }
};