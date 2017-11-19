class Solution {
private:
    void subsetsHelper(vector<int> &nums, int idx, vector<int> &buf, vector<vector<int>> &ans) {
        if (idx == nums.size()) {
            ans.push_back(buf);
            return;
        }

        subsetsHelper(nums, idx + 1, buf, ans);
        buf.push_back(nums[idx]);
        subsetsHelper(nums, idx + 1, buf, ans);
        buf.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> buf;
        vector<vector<int>> ans;

        subsetsHelper(nums, 0, buf, ans);
        return ans;
    }
};
