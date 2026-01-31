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
    pair<ListNode*, int> del(ListNode* head, int n){
        if(!head) return {nullptr, 0};
        pair<ListNode*, int>res = del(head->next, n);
        if(res.second+1 == n)
            return {head->next, res.second+1};
        head->next = res.first;
        return {head, res.second+1};
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        pair<ListNode*, int> ans = del(head, n);
        head = ans.first;
        return head;
    }
}a;
