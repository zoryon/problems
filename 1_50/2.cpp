/*
 *  TITLE: 2. Add Two Numbers
 *  DESCRIPTION:
 *      You are given two non-empty linked lists representing two non-negative integers.
 *      The digits are stored in reverse order, and each of their nodes contains a single digit.
 *      Add the two numbers and return the sum as a linked list.
 *      You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 *  CONSTRAINTS:
 *      - The number of nodes in each linked list is in the range [1, 100]
 *      - 0 <= Node.val <= 9
 *      - It is guaranteed that the list represents a number that does not have leading zeros
 */

// Solutions
// C++
// 1.
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Create a dummy node to simplify handling the head of the result list
        ListNode *dummy = new ListNode(0);
        // 'ans' will point to the current node in the result list
        ListNode *ans = dummy;

        int carry = 0;

        // Loop until both lists are fully traversed and no carry remains
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry; // Start with carry from previous addition
            
            // Add the value from l1 if available
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next; // Move to next node in l1
            }

            // Add the value from l2 if available
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next; // Move to next node in l2
            }

            carry = sum / 10;  // Update carry for next iteration
            ans->next = new ListNode(sum % 10); // Create a new node with the digit (sum modul 10) and attach it to the result list
            ans = ans->next;
        }

        // Return the head of the new list (skip the dummy node)
        return dummy->next;
    }
};