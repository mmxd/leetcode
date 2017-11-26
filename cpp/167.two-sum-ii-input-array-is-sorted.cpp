class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        int val = 0;
        vector<int> ans;

        while (left < right) {
            val = numbers[left] + numbers[right];
            if (val == target) {
                ans.push_back(left + 1);
                ans.push_back(right + 1);
                break;
            } else if (val < target) {
                left++;
            } else {
                right--;
            }
        }

        return ans;
    }
};
