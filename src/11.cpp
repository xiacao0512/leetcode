// by watercolor, 2022-09-01

class Solution {
public:
    int maxArea(vector<int> &height)
    {
        int max = 0;
        int left = 0, right = height.size()-1;

        while(left < right) {
            int a = min(height[left], height[right]) * (right - left);
            
            if(a > max) {
                max = a;
            }

            if(height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max;
    }
};
