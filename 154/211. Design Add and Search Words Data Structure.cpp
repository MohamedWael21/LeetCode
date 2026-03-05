class WordDictionary {
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
    WordDictionary() {
        root = new Node();

    }
    
    void addWord(string word) {
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
        for(int i=0; i<word.size(); i++){
            char c = word[i];
            bool isExist = false;
            if(c == '.'){
                for(char ch='a'; ch<='z'; ch++){
                    string tmp = word;
                    tmp[i] = ch;
                    isExist = search(tmp);
                    if(isExist) return true;
                }
                return false;
            }

            int ind = c-'a';

            if(curr->a[ind] == nullptr) return false;
            curr = curr->a[ind];
        }
        return curr->isLeaf;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
