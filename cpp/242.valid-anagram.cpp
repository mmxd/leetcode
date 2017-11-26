class Solution {
public:
    bool isAnagram(string s, string t) {
        int charCount[26] = {0};

        for (int i = 0; i < s.size(); i++) {
            charCount[s[i] - 'a']++;
        }

        for (int i = 0; i < t.size(); i++) {
            if (charCount[t[i] - 'a'] == 0) {
                return false;
            }
            charCount[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (charCount[i] != 0) {
                return false;
            }
        }

        return true;
    }
};
