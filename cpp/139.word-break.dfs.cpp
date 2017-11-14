// TLE
class Solution {
private:
    bool wordBreakHelper(string &s, unordered_set<string> &wordSet, int idx) {
        if (idx == s.size()) {
            return true;
        }

        for (int j = 1; j <= s.size() - idx; j++) {
            string word = s.substr(idx, j);
            if (wordSet.find(word) == wordSet.end()) {
                continue;
            }
            if (wordBreakHelper(s, wordSet, idx + j)) {
                return true;
            }
        }

        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet;

        for (int i = 0; i < wordDict.size(); i++) {
            wordSet.insert(wordDict[i]);
        }

        return wordBreakHelper(s, wordSet, 0);
    }
};
