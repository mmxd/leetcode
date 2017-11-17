class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> hm;

        for (int i = 0; i < nums.size(); i++) {
            int left = 0;
            int right = 0;
            int len = 0;

            if (hm.find(nums[i]) != hm.end()) {
                continue;
            }

            if (hm.find(nums[i] - 1) != hm.end()) {
                left = hm[nums[i] - 1];
            }
            if (hm.find(nums[i] + 1) != hm.end()) {
                right = hm[nums[i] + 1];
            }

            hm[nums[i]] = len;
            len = left + right + 1;
            ans = max(ans, len);
            hm[nums[i] - left] = len;
            hm[nums[i] + right] = len;
        }

        return ans;
    }
};
