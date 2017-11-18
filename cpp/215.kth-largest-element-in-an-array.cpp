class Solution {
private:
    // two-way partition
    int partition(vector<int> &nums, int left, int right) {
        int i = left;
        int idx = left + rand() % (right - left + 1);

        swap(nums[idx], nums[right]);
        for (i = left, idx = left; i < right; i++) {
            if (nums[i] > nums[right]) {
                swap(nums[idx++], nums[i]);
            }
        }
        swap(nums[idx], nums[right]);

        return idx;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int idx = 0;
        int left = 0;
        int right = nums.size() - 1;

        while (true) {
            idx = partition(nums, left, right);
            if (k - 1 < idx) {
                right = idx - 1;
            } else if (k - 1 > idx) {
                left = idx + 1;
            } else {
                break;
            }
        }

        return nums[k - 1];
    }
};
