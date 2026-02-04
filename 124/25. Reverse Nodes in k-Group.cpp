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
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* iter = head;
        int cnt = 0;
        while(iter){
            cnt++;
            iter = iter->next;
        }
        int t = cnt /k;
        if(t == 0) return head;
        ListNode* dummy = new ListNode();
        ListNode* prevL = dummy;
        iter = head;
        while(t--){
            ListNode* prev = nullptr;
            ListNode* end = iter;
            for(int i=0; i<k; i++){
                ListNode* temp = iter->next;
                iter->next = prev;
                prev = iter;
                iter = temp;
            }
            prevL->next = prev;
            prevL = end;
        }
        prevL->next = iter;
        return dummy->next;
    }
};
