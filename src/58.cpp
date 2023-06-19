// by watercolor, 2023/03/19

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        bool isFirst = true;

        reverse(begin(s), end(s));
        for(auto c : s) {
            if(c == ' ') {
                if(isFirst == false) {
                    break;
                }
            } else {
                isFirst = false;
                length++;
            }
        }

        return length;   
    }
};
