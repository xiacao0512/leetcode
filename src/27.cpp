// by watercolor, 2023-01-14

class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        auto it1 = remove(begin(nums), end(nums), val);
        nums.erase(it1, end(nums));
        return nums.size();
    }
};
