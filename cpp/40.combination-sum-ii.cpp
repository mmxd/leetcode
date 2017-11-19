class Solution {
private:
    void combinationSum2Helper(vector<int> &candidates, int target, int idx, vector<int> &buf, vector<vector<int>> &ans) {
        if (target == 0) {
            ans.push_back(buf);
            return;
        }

        for (int i = idx; i < candidates.size() && target >= candidates[i]; i++) {
            if (i == idx || candidates[i] != candidates[i - 1]) {
                buf.push_back(candidates[i]);
                combinationSum2Helper(candidates, target - candidates[i], i + 1, buf, ans);
                buf.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> buf;
        vector<vector<int>> ans;

        sort(candidates.begin(), candidates.end());
        combinationSum2Helper(candidates, target, 0, buf, ans);

        return ans;
    }
};
