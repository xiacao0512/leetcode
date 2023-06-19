// by watercolor, 2023-03-23

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r) 
    {
        vector<bool> result;

        for(int i = 0; i < l.size(); i++) {
            vector<int> v(begin(nums)+l[i], begin(nums)+r[i]+1);
            sort(begin(v), end(v));
            
            bool isArithmetic = isArithmeticSubarray(v);
            result.push_back(isArithmetic);
        }

        return result;
    }

private:
    bool isArithmeticSubarray(vector<int> v)
    {
        if(v.size() <= 2) {
            return true;
        }

        int differ = v[1] - v[0];
        for(int i = 2; i < v.size(); i++) {
            if(v[i] - v[i-1] != differ) {
                return false;
            }
        }

        return true;
    }
};
