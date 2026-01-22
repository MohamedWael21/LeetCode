class Solution {
    map<string, string>en,de;
    string curr = "000000";
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        en[curr] = longUrl;
        string temp = curr;
        for(int i=curr.size()-1; i>=0; i++){
            if(curr[i] == '9'){
                curr[i] = '0';
                continue;
            }else{
                 curr[i] = (char)(curr[i]+1);
                 break;
            }
        }
        return temp;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return en[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));