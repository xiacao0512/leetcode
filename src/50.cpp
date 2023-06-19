// by watercolor,  2022-08-21

class Solution {
public:
    double myPow(double x, int n) 
    {
        if(x == 0 || x == 1) {
            return x;
        } else if(x == -1) {
            return (n % 2 == 0) ? 1 : -1;
        }

        if(n == 0) {
            return 1;
        } else if(n < 0) {
            if(n == -2147483648) {
                return 0;
            } else {
                return 1/myPow(x, -n);
            }
        } else {
            int i = 0;
            double ans = 1;

            while(i < n) {
                ans *= x;
                i++;

                // **保险代码**
                if(ans == 0) {
                    break;
                }
            }

            return ans;
        }
    }
};
