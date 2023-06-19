// by watercolor, 2022-08-16
// 8:30 - 8:58

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> mid;

        int median = nums1.size() + nums2.size();

        if(median % 2 == 0) {
            mid.push_back(median/2);
        }
        mid.push_back(median/2+1);

        int pos = 0, pos_1 = 0, pos_2 = 0;
        int i = 0;
        double result = 0;

        while(i < mid.size()) {
            int n1, n2, current;

            if(pos_1 < nums1.size()) {
                n1 = nums1[pos_1];
            } else {
                n1 = 0x7fffffff;
            }

            if(pos_2 < nums2.size()) {
                n2 = nums2[pos_2];
            } else {
                n2 = 0x7fffffff;
            }

            if(n1 <= n2) {
                current = n1;
                pos_1++;
            } else {
                current = n2;
                pos_2++;
            }
            pos++;

            if(pos == mid[i]) {
                result += current;
                i++;
            }
        }

        return result / mid.size();
    }
};
