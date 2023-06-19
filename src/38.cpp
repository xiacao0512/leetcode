// by watercolor, 2022-10-05

class Solution {
public:
    string countAndSay(int n)
    {
        vector<int> result;
        string answer;

        result.push_back(1);
        for(int i = 1; i < n; i++) {
            result = countAndSay_sub(result);
        }

        for(int i = 0; i < result.size(); i++) {
            answer += (char) result[i]+0x30;
        }
        return answer;
    }

private:
    vector<int> countAndSay_sub(vector<int> array)
    {
        vector<int> result;
        int lastnum = array[0], prefix=0;

        for(int i = 0; i < array.size(); i++) {
            if(array[i] != lastnum) {
                result.push_back(prefix);
                result.push_back(lastnum);

                lastnum = array[i];
                prefix = 1;
            } else {
                prefix++;
            }
        }

        result.push_back(prefix);
        result.push_back(lastnum);

        return result;
    }
};
