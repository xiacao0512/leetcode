// by watercolor, 2022/09/10

class Solution {
public:
    int binarySearch(vector<int> &nums, int left, int right, int target) 
    {
        if(right - left < 2) {
            return right;
        }

        int mid = (left+right+2)/2-1;
        int a = nums[mid];

        if(a == target) {
            return mid;
        } else if(a < target) {
            return binarySearch(nums, mid, right, target);
        } else  {
            return binarySearch(nums, left, mid, target);
        }
    }

    int searchInsert(vector<int> &nums, int target)
    {
        if(target <= nums[0]) {
            return 0;
        } else if(target > nums[nums.size()-1]) {
            return nums.size();
        } else {
            return binarySearch(nums, 0, nums.size()-1, target);
        }
    }
};
