/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode* ans  = new ListNode();
        ListNode* curr = ans;
        bool carry = false;
        while(curr1 || curr2){
            int num = 0;
            if(curr2) num += curr2->val;
            if(curr1) num += curr1->val;
            if(carry){
                num += carry;
                carry = false;
            }
            if(num > 9){
                num = num%10;
                carry = true;
            }
                curr->next = new ListNode(num);
                curr = curr->next;
            if(curr1) curr1 = curr1->next;
            if(curr2) curr2 = curr2->next;
        }
        if(carry) curr->next = new ListNode(1);
        return ans->next;
    }
};
