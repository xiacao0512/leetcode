// by watercolor, 2023-03-03

class Solution {
public:
    vector<int> plusOne(vector<int> &digits)
    {
        vector<int> result;
        int isCarry = 0;

        result = digits;
        reverse(begin(result), end(result));

        for(unsigned int i = 0; i < result.size(); i++) {
            int base = result[i] + isCarry;
            base = (i == 0) ? base+1 : base;

            result[i] = base % 10;
            isCarry = base / 10;
        }

        if(isCarry != 0) {
            result.push_back(1);
        }

        reverse(begin(result), end(result));
        return result;
    }
};
