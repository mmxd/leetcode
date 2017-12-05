class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int ans = 0;
        vector<int> charIndex(256, -1);

        for (int i = 0; i < s.size(); i++) {
            start = max(charIndex[s[i]] + 1, start);
            charIndex[s[i]] = i;
            ans = max(ans, i - start + 1);
        }

        return ans;
    }
};
