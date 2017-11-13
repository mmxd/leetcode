class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int m = 1;

        if (n == 0) {
            return vector<int>();
        }

        vector<int> ans(n, 1);

        for (int i = 1; i < nums.size(); i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            ans[i] = ans[i] * m;
            m *= nums[i];
        }

        return ans;
    }
};
