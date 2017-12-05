class Solution {
private:
    bool isPalindrome(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
public:
    string longestPalindrome(string s) {
        int i = 0;
        int len = 0;

        for (len = s.size(); len > 0; len--) {
            for (i = 0; i <= s.size() - len; i++) {
                if (isPalindrome(s, i, i + len - 1)) {
                    return s.substr(i, len);
                }
            }
        }

        return "";
    }
};
