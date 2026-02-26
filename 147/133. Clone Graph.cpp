/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    map<int, Node*>mp;
    Node* sv(Node* node){
        if(!node) return nullptr;
        if(mp[node->val]) return mp[node->val];
        Node* newNode = new Node(node->val);
        mp[node->val] = newNode;
        for(Node* n : node->neighbors){
            newNode->neighbors.push_back( sv(n) );
        }

        return newNode;
        
    }
public:
    Node* cloneGraph(Node* node) {
        return sv(node);
    }
};
