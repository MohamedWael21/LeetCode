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
    int sv(ListNode* head, int& place){
        if(head == nullptr) return 0;
        int after = sv(head->next, place);
        int ans = after + (1<<place)*(head->val);
        place++;
        return ans;
    }
public:
    int getDecimalValue(ListNode* head) {
        int place = 0;
        return sv(head, place);
    }
};
