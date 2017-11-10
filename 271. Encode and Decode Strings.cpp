/*
123abc, xyz

6/123abc3/xyz
     i

*/


class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded = "";
        for (const string& s: strs) {
            int len = s.size();
            encoded += to_string(len) + "/" + s;
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decoded;
        int pos = 0;
        while (pos < s.size()) {
            int slashPos = s.find_first_of('/', pos);
            int len = stoi(s.substr(pos, slashPos - pos));
            pos = slashPos + 1;
            decoded.push_back(s.substr(pos, len));
            pos += len;
        }
        return decoded;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
