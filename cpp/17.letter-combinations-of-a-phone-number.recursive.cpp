class Solution {
private:
    void helper(const vector<string> &digitMap, const int idx, const string &digits, vector<string> &ans, string &s) {
        if (idx == digits.size()) {
            ans.push_back(s);
        }

        int digit = digits[idx] - '0';
        for (int i = 0; i < digitMap[digit].size(); i++) {
            s[idx] = digitMap[digit][i];
            helper(digitMap, idx + 1, digits, ans, s);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        int idx = 0;
        int n = digits.size();
        vector<string> digitMap = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;

        if (n == 0) {
            return ans;
        }

        string s(n, '\0');
        helper(digitMap, idx, digits, ans, s);

        return ans;
    }
};
