// by watercolor, 2023-06-19

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) 
    {
        vector<int> line;
        vector<vector<int>> answer;

        backtracking(nums, line, answer);
        return answer;
    }

private:
    void backtracking(vector<int> &nums, vector<int> &line, vector<vector<int>> &answer)
    {
        if(nums.size() == 0) {
            answer.push_back(line);
        } else {
            for(auto i : nums) {
                line.push_back(i);

                vector<int> nums2 = nums;
                auto iter = remove(begin(nums2), end(nums2), i);
                nums2.erase(iter);

                backtracking(nums2, line, answer);
                line.pop_back();
            }
        }

        return;
    }
};