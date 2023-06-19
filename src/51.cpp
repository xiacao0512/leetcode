// by watercolor, 2022/12/18

class Solution {
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<int> path;
        vector<vector<int>> ansline;
        vector<vector<string>> result;

        backtracking(n, 0, path, ansline);
        line2str(n, ansline, result);

        return result;
    }

    void backtracking(int n, int k, vector<int> &path, vector<vector<int>> &ansline)
    {
        if(k == n) {
            ansline.push_back(path);
        } else {
            for(int i = 0; i < n; i++) {
                int j;
                for(j = 0; j < k; j++) {
                    if(i == path[j] || i == path[j]-(k-j) || i == path[j]+(k-j)) {
                        break;
                    }
                }

                if(j == k) {
                    path.push_back(i);
                    backtracking(n, k+1, path, ansline);
                    path.pop_back();
                }
            }
        }

        return;
    }

    void line2str(int n, vector<vector<int>> ansline, vector<vector<string>> &result) 
    {
        string s;
        vector<string> vs;

        for(int i = 0; i < ansline.size(); i++) {
            for(int j = 0; j < ansline[i].size(); j++) {
                for(int k = 0; k < n; k++) {
                    if(k == ansline[i][j]) {
                        s += 'Q';
                    } else {
                        s += '.';
                    }
                }

                vs.push_back(s);
                s = "";
            }
            result.push_back(vs);
            vs.clear();
        }
    }
};
