class Solution {
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker) 
    {
        int size = profit.size();
        for(int i = 1; i < size; i++) {
            for(int j = 0; j < size-i; j++) {
                if(profit[j] < profit[j+1]) {
                    swap(profit[j], profit[j+1]);
                    swap(difficulty[j], difficulty[j+1]);
                }
            }
        }

        int result = 0;
        int size_w = worker.size();
        for(int i = 0; i < size_w; i++) {
            for(int j = 0; j < size; j++) {
                if(worker[i] >= difficulty[j]) {
                    result += profit[j];
                    break;
                }
            }
        }

        return result;
    }
};
