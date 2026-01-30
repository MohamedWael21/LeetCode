/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* ans = new Node(0);
        map<Node*, Node*>mp;
        Node* curr = ans;
        while(head){
            curr->next = new Node(head->val);
            mp[head] = curr->next;
            curr->next->random = head->random;
            head = head->next;
            curr = curr->next;
        }

        curr = ans->next;
        while(curr){
            if(curr->random)
                curr->random = mp[curr->random];
            curr = curr->next;
        }
        return ans->next;
    }
};
