/*
 *  TITLE: 1. Two Sum
 *  DESCRIPTION:
 *      Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 *      You may assume that each input would have exactly one solution, and you may not use the same element twice.
 *      You can return the answer in any order.
 *
 *  CONSTRAINTS:
 *      - 2 <= nums.length <= 104
 *      - -109 <= nums[i] <= 109
 *      - -109 <= target <= 109
 *      - Only one valid answer exists
 */

// Solutions
// C++
// 1.
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); i++) { // Iterate through the vector
            // Find the complement 
            int complement = target - nums[i];

            // If the complement has already been seen, return
            if (seen.count(complement)) {
                return {seen[complement], i};
            }

            seen[nums[i]] = i;
        }
        return {};
    }
};