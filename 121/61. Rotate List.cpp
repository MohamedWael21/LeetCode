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
    ListNode* rotateRight(ListNode* head, int k) {
        int sz = 0;
        ListNode* iter = head;
        while(iter){
            sz++;
            iter = iter->next;
        }
        if(sz == 0) return head;
        k = k % sz;

        if(k == 0) return head;
        iter = head;
        k = sz - k;
        while(k--){
            head = head->next;    
        }
       
        ListNode* start = head;

        ListNode* dummy = new ListNode();
        ListNode* newL = dummy;
        while(head){
            newL->next = new ListNode(head->val);
            newL = newL->next;
            head = head->next;
        }

        while(iter!=start){
            newL->next = new ListNode(iter->val);
            newL = newL->next;
            iter = iter->next;
        }

        return dummy->next;

    }
};