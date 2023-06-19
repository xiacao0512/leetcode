// by watercolor, 2022/12/15

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string path;

        if(digits.size() != 0) {
            backtracking(0, digits, path, result);
        }
        return result;
    }

    void backtracking(unsigned int k, string digits, string &path, vector<string> &result) {
        unordered_map<char, string> digit_map = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };

        if(k == digits.size()) {
            result.push_back(path);
        } else {
            for(int i = 0; i < digit_map[digits[k]].size(); i++) {
                path.push_back(digit_map[digits[k]][i]);
                backtracking(k+1, digits, path, result);
                path.pop_back();
            }
        }

        return;
    }
};
