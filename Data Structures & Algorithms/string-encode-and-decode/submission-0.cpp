class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";

        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            result += to_string(s.length()) + "#" + s;
        }

        return result;

    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;

        while (i < s.length()) {
            int j = i;

            // find '#'
            while (s[j] != '#') {
                j++;
            }

            // get length
            int len = stoi(s.substr(i, j - i));

            // move to start of word
            j++;

            // extract word
            string word = s.substr(j, len);
            result.push_back(word);

            // move to next
            i = j + len;
        }

        return result;

    }
};
