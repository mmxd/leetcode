class Solution {
private:
    void combinationSumHelper(vector<int> &candidates, int target, int idx, vector<int> &buf, vector<vector<int>> &ans) {
        if (target == 0) {
            ans.push_back(buf);
            return;
        }

        for (int i = idx; i < candidates.size() && target >= candidates[i]; i++) {
            buf.push_back(candidates[i]);
            combinationSumHelper(candidates, target - candidates[i], i, buf, ans);
            buf.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> buf;
        vector<vector<int>> ans;

        sort(candidates.begin(), candidates.end());
        combinationSumHelper(candidates, target, 0, buf, ans);

        return ans;
    }
};
