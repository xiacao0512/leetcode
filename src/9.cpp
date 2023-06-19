// by watercolor, 2022/09/10

class Solution {
public:
    int getbit(int x, int y)
    {
        return (x / (int)pow(10, y-1)) % 10;
    }


    bool isPalindrome(int x)
    {
        if(x >= 10 && x % 10 == 0) {
            return false;
        } else if(x < 0) {
            return false;
        } else if(x >= 0 && x <= 9) {
            return true;
        } else {
            int bits = 1;
            int left, right;

            while(bits < 10 && (x / (int)pow(10, bits) != 0)) {
                bits++;
            }

            left = bits/2;
            right = (bits % 2 == 0) ? bits/2+1 : bits/2+2;
            while(left > 0) {
                if(getbit(x, left) != getbit(x, right)) {
                    return false;
                }

                left--;
                right++;
            }
        }

        return true;
    }
};
