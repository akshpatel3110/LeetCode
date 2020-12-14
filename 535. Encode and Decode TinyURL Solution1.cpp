class Solution {
public:
    unordered_map<string, string> l2s;
    unordered_map<string, string> s2l;
    string chars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    string random_str(int k) {
        string res;
        while (k--)
            res += chars[rand() % chars.size()];
        return res;
    }
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (l2s.count(longUrl)) {
            return "http://tinyurl.com/" + l2s[longUrl];
        }
        
        while (true) {
            auto shortUrl = random_str(6);
            if (s2l.count(shortUrl) == 0) {
                s2l[shortUrl] = longUrl;
                l2s[longUrl] = shortUrl;
                return "http://tinyurl.com/" + shortUrl; 
            }
        }
        return "";
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string t = shortUrl.substr(shortUrl.find_last_of("/") + 1);
        return s2l.count(t) ? s2l[t] : t;    
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
