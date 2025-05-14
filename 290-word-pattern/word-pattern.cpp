class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> chartoword;
        unordered_map<string, char> wordtochar;
        vector<string> words;

        int i = 0;
        while (i < s.size()) {
            while (i < s.size() && isspace(s[i])) {
                i++;
            }
            string word = "";
            while (i < s.size() && !isspace(s[i])) {
                word += s[i];
                i++;
            }

            if (!word.empty()) {
                words.push_back(word);
            }
        }

        if (words.size() != pattern.size())
            return false;

        for (i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];

            if (chartoword.count(c)) {
                if (chartoword[c] != w)
                    return false;
            } else {
                if (wordtochar.count(w))
                    return false;
                chartoword[c] = w;
                wordtochar[w] = c;
            }
        }
        return true;
    }
};