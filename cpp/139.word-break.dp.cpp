class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> wordSet;

        if (n == 0) {
            return true;
        }

        for (int i = 0; i < wordDict.size(); i++) {
            wordSet.insert(wordDict[i]);
        }

        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (!dp[j]) {
                    continue;
                }

                string word = s.substr(j, i - j);
                if (wordSet.find(word) != wordSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};
