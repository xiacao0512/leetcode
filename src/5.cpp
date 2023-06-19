// by watercolor, 2023-06-18

class Solution {
public:
    string longestPalindrome(string s) 
    {
        bool dp[MaxLength][MaxLength];
        int length = s.length();

        if(length < 2) {
            return s;
        }

        for(int i = 0; i < length; i++) {
            for(int j = 0; j < length-i; j++) {
                if(j == 0) {
                    dp[i][j] = true;
                } else {
                    dp[i][j] = false;
                }
            }
        }

        for(int j = 1; j < length; j++) {
            for(int i = 0; i < length-j; i++) {
                if(j == 1 && s[i] == s[i+1]) {
                    dp[i][j] = true;
                } else if(j > 1 && dp[i+1][j-2] == true && s[i] == s[i+j]) {
                    dp[i][j] = true;
                }
            }
        }

        int largestLength = 0, start;
        for(int i = 0; i < length; i++) {
            for(int j = 0; j < length-i; j++) {
                if(dp[i][j] == true && j+1 > largestLength) {
                    largestLength = j+1;
                    start = i;
                }
            }
        }

        return s.substr(start, largestLength);
    }

private:
    const int MaxLength = 1000;
};
