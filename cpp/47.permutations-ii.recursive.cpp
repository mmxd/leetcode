class Solution {
private:
    void permuteUniqueHelper(vector<int> nums, int idx, vector<vector<int>> &ans) {
        int i = 0;

        if (idx == nums.size() - 1) {
            ans.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            if (i != idx && nums[i] == nums[idx]) {
                continue;
            }
            swap(nums[i], nums[idx]);
            permuteUniqueHelper(nums, idx + 1, ans);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        permuteUniqueHelper(nums, 0, ans);

        return ans;
    }
};
