class Solution {
    const int dx4[4] = {1, 0, -1, 0};
    const int dy4[4] = {0, 1, 0, -1};

    struct Node {
        Node* a[26];
        bool isLeaf;
        Node() {
            for(int i = 0; i < 26; i++) a[i] = nullptr;
            isLeaf = false;
        }
        ~Node() {
            for(int i = 0; i < 26; i++)
                if(a[i]) delete a[i];
        }
    };

    Node* root;
    int n, m;

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new Node();
        n = board.size();
        m = board[0].size();

        for(string &word : words) {
            Node* curr = root;
            for(char c : word) {
                int ind = c - 'a';
                if(!curr->a[ind]) curr->a[ind] = new Node();
                curr = curr->a[ind];
            }
            curr->isLeaf = true;
        }

        vector<string> ans;
        string path = "";

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                dfs(i, j, root, board, path, ans);
            }
        }

      
        return ans;
    }

private:
    void dfs(int i, int j, Node* curr, vector<vector<char>>& board, string &path, vector<string>& ans) {
        if(i < 0 || i >= n || j < 0 || j >= m) return;
        char c = board[i][j];
        if(c == '#' || !curr->a[c - 'a']) return;

        curr = curr->a[c - 'a'];
        path.push_back(c);

        if(curr->isLeaf) {
            ans.push_back(path);
            curr->isLeaf = false; 
        }

        board[i][j] = '#'; 
        for(int k = 0; k < 4; k++)
            dfs(i + dx4[k], j + dy4[k], curr, board, path, ans);
        board[i][j] = c; 

        path.pop_back();
    }
};
