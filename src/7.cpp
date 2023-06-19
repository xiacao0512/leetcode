// by watercolor, 2022-08-16

class Solution {
public:
    int reverse(int x) 
    {
        if(x == 0) {
            return 0;
        } else if(x < 0) {
            if(x == -2147483648) {
                return 0;
            } else {
                return -reverse(-x);
            }
        }

        string s = to_string(x);
        std::reverse(s.begin(), s.end());

        if(s.length() >= 10 && s > string("2147483647")) {
            return 0;
        } else {
            return stoi(s);
        }
    }
};
