// by watercolor, 2023-06-18

class Solution {
public:
    vector<int> grayCode(int n) 
    {
        if(n == 1) {
            return {0, 1};
        } else {
            vector<int> answer = grayCode(n-1);

            vector<int> bottomHalf = answer;
            reverse(begin(bottomHalf), end(bottomHalf));

            for(auto i : bottomHalf) {
                i += 1 << (n-1);
                answer.push_back(i);
            }

            return answer;
        }
    }
};
