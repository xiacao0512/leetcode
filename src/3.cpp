// by watercolor, 2022-08-15
// 15:00 ~ 15:25

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<char> a;

        if(s.length() < 2) {
            return s.length();
        }

        int max = 0, i, j, k, len = 0;
        bool isExist;
        for(i = 0; i < s.length(); i++) {
            for(j = 0; j < s.length()-i; j++) {
                isExist = false;

                for(k = 0; k < a.size(); k++) {
                    if(s[i+j] == a[k]) {
                        isExist = true;
                        break;
                    }
                }

                if(isExist == true) {
                    if(len > max) {
                        max = len;
                    }
                    len = 0;
                    a.clear();

                    break;
                } else {
                    a.push_back(s[i+j]);
                    len++;
                }
            }
        }

        return max;
    }
};
