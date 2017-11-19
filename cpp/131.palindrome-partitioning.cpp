class Solution {
private:
    bool isPalindrome(string &s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }

    void partitionHelper(string &s, int idx, vector<string> &buf, vector<vector<string>> &ans) {
        if (idx == s.size()) {
            ans.push_back(buf);
            return;
        }

        for (int i = idx; i < s.size(); i++) {
            string ss = s.substr(idx, i - idx + 1);
            if (isPalindrome(ss)) {
                buf.push_back(ss);
                partitionHelper(s, i + 1, buf, ans);
                buf.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<string> buf;
        vector<vector<string>> ans;

        partitionHelper(s, 0, buf, ans);

        return ans;
    }
};
