// by watercolor, 2022/09/10

struct IntToRomanTable {
    string r;
    int i;
};

class Solution {
public:
    string intToRoman(int num)
    {
        static IntToRomanTable itrs[13] = {
            {"M", 1000}, {"CM", 900}, {"D", 500}, 
            {"CD", 400}, {"C", 100}, {"XC", 90},
            {"L", 50}, {"XL", 40}, {"X", 10},
            {"IX", 9}, {"V", 5}, {"IV", 4},
            {"I", 1}
        };

        string result;
        int num2 = num;

        for(int i = 0; i < 13; i++) {
            while(num / itrs[i].i != 0) {
                result += itrs[i].r;
                num -= itrs[i].i;
            }
        }

        return result;
    }
};
