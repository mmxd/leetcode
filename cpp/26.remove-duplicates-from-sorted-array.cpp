class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 1;

        if (nums.size() == 0) {
            return 0;
        }

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[idx - 1]) {
                continue;
            }
            nums[idx] = nums[i];
            idx++;
        }

        return idx;
    }
};
