/*  
 *  TITLE: 3. Longest Substring Without Repeating Characters
 *  DESCRIPTION: Given a string s, find the length of the longest substring without duplicate characters.
 * 
 *  CONSTRAINTS:
 *      - 0 <= s.length <= 5 * 104
 *      - s consists of English letters, digits, symbols and spaces.
*/  

// Solutions
// C++
// 1.

#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> chars;

        // 'left' is the start index of the sliding window
        int left = 0, maxLength = 0;

        // 'right' iterates over each character in the string
        for (int right = 0; right < s.length(); right++) {
            // If s[right] is already in the set, we have a duplicate
            // Remove characters from the left until the duplicate is gone
            while (chars.count(s[right])) {
                chars.erase(s[left]); // remove the leftmost character
                left++; // move the start of the window forward
            }
            // Insert the current character into the set
            chars.insert(s[right]);
            
            // Update maxLength if the current window is longer
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};