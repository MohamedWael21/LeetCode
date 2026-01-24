class Trie {
    struct Node{
        Node* a[26];
        bool isLeaf;
        Node(){
            for(int i=0; i<26; i++) a[i] = nullptr;
            isLeaf = false;
        }
        ~Node(){
            for(int i=0; i<26; i++){
                if(a[i]) delete a[i];
            }
        }
    };
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for(int i=0; i<word.size(); i++){
            int ind = word[i]-'a';
            if(curr->a[ind] == nullptr){
                curr->a[ind] = new Node();
            }
            if(i==word.size()-1) curr->a[ind]->isLeaf = true;
            curr = curr->a[ind];
        }
    }
    
    bool search(string word) {
        Node* curr = root;
        for(char c : word){
            int ind = c-'a';
            if(curr->a[ind] == nullptr) return false;
            curr = curr->a[ind];
        }
        return curr->isLeaf;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(char c : prefix){
            int ind = c-'a';
            if(curr->a[ind] == nullptr) return false;
            curr = curr->a[ind];
        }
        return true;
    }
    ~Trie(){
        delete root;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
