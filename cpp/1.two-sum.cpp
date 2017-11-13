class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hm;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            if (hm.find(target - nums[i]) != hm.end()) {
                ans.push_back(hm[target - nums[i]]);
                ans.push_back(i);
                break;
            }
            hm[nums[i]] = i;
        }

        return ans;
    }
};
