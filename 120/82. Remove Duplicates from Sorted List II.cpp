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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        while(curr != nullptr && curr->next != nullptr){
            bool flag = false;
            while(curr != nullptr && curr->next != nullptr && curr->val == curr->next->val ){
                flag = true;
                curr = curr->next;
            }
            if(curr){
                if(flag){
                    prev->next = curr->next;
                }
                if(!flag){
                    prev = curr;
                }
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};
