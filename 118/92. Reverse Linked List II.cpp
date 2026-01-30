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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        int cnt = 0;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(cnt<left-1){
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        ListNode* startPrev = prev;
        ListNode* start = curr;
        prev = nullptr;
        while(cnt<right){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            cnt++;
        }

        if(startPrev) startPrev->next = prev;
        if(start == head){
            head = prev;
        }
        start->next = curr;
        return head;
    }
};
