// by watercolor, 2022/09/11

class Solution {
public:
    int firstMissingPositive(vector<int> &nums)
    {
        unordered_set<int> hashmap;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) {
                hashmap.insert(nums[i]);
            }
        }

        int max = 1;
        while(max <= hashmap.size()) {
            if(hashmap.find(max) == hashmap.end()) {
                return max;
            }

            max++;
        }

        return max;
    }
};
