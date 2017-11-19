class Solution {
private:
    void subsetsWithDupHelper(vector<int> &nums, int idx, vector<int> buf, vector<vector<int>> &ans) {
        int start = idx;
        int end = start;

        if (idx == nums.size()) {
            ans.push_back(buf);
            return;
        }

        for (end = idx; end < nums.size(); end++) {
            if (nums[end] != nums[idx]) {
                break;
            }
        }

        subsetsWithDupHelper(nums, end, buf, ans);
        for (int i = start; i < end; i++) {
            buf.push_back(nums[idx]);
            subsetsWithDupHelper(nums, end, buf, ans);
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> buf;
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        subsetsWithDupHelper(nums, 0, buf, ans);
        return ans;
    }
};
