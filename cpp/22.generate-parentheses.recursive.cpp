class Solution {
private:
    void generateParenthesisHelper(int n, int leftCount, int rightCount, string &s, vector<string> &ans) {
        if (leftCount == rightCount && leftCount == n) {
            ans.push_back(s);
            return;
        }

        if (leftCount < n) {
            s.push_back('(');
            generateParenthesisHelper(n, leftCount + 1, rightCount, s, ans);
            s.pop_back();
        }

        if (rightCount < leftCount) {
            s.push_back(')');
            generateParenthesisHelper(n, leftCount, rightCount + 1, s, ans);
            s.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string s;
        vector<string> ans;

        generateParenthesisHelper(n, 0, 0, s, ans);

        return ans;
    }
};
