// by watercolor, 2022-08-15

struct RomanToIntTable {
    string r;
    int i;
};

class Solution {
public:
    int romanToInt(string s) {
        static RomanToIntTable rtis[13] = {
            {"M", 1000}, {"CM", 900}, {"D", 500}, 
            {"CD", 400}, {"C", 100}, {"XC", 90},
            {"L", 50}, {"XL", 40}, {"X", 10},
            {"IX", 9}, {"V", 5}, {"IV", 4},
            {"I", 1}
        };
        
        int pos=0, result=0;

        while(pos < s.length()) {
            for(int i = 0; i < 13; i++) {
                if(s.substr(pos, rtis[i].r.length()) == rtis[i].r) {
                    result += rtis[i].i;
                    pos += rtis[i].r.length();
                    break;
                }
            }
        }

        return result;
    }
};
