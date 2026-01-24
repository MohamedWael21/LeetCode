class Solution {
    class Trie{
        struct Node{
            Node* a[26];
            set<string>words;
            Node(){
                for(int i=0; i<26; i++) a[i] = nullptr;
            }
            ~Node(){
                for(int i=0; i<26;i++){
                    delete a[i];
                    a[i] = nullptr;
                }
            }
        };
        Node* root;
        public:
            Trie(){
                root = new Node();
            }
            void insert(string word){
                Node* curr = root;
                for(char c : word){
                    int indx  = c-'a';
                    if(curr->a[indx] == nullptr)
                        curr->a[indx] = new Node();
                    curr->a[indx]->words.insert(word);
                    curr = curr->a[indx];
                }
            }
            vector<string> search(string word){
                Node* curr = root;
                vector<string>ans;
                for(char c : word){
                    int indx = c - 'a';
                    if(curr->a[indx] == nullptr) return ans;
                    curr = curr->a[indx];
                }
                for(string s : curr->words){
                    ans.push_back(s);
                    if(ans.size() == 3) break;
                }
                return ans; 
            }
            ~Trie(){
                delete root;
                root = nullptr;
            }
    };
    
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie;
        for(string product : products){
            trie.insert(product);
        }
        string curr = "";
        vector<vector<string>>ans;
        for(char c : searchWord){
            curr += c;
            ans.push_back(trie.search(curr));
        }
        return ans;
    }
};
