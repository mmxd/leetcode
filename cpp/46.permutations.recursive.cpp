class Solution {
private:
    void permuteHelper(vector<int> &nums, int idx, vector<vector<int>> &ans) {
        if (idx == nums.size() - 1) {
            ans.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);
            permuteHelper(nums, idx + 1, ans);
            swap(nums[idx], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        permuteHelper(nums, 0, ans);

        return ans;
    }
};
