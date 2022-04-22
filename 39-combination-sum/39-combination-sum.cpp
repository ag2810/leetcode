class Solution {
public:
    void combinationSumUtil(int index, vector<int>& candidates, int target,
    vector<int>& temp, vector<vector<int>>& answer) 
    {
        if(target == 0 && index == (candidates.size() - 1))
        {
            answer.push_back(temp);
            return;
        }
        
        if(index == candidates.size())
        {
            return;
        }
        
        if(target < 0) 
        {
            return;
        }
        
        temp.push_back(candidates[index]);
        combinationSumUtil(index, candidates, (target - candidates[index]), temp,                   answer);
        temp.pop_back();
        
        combinationSumUtil(index + 1, candidates, target, temp, answer);
            
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> temp;
        combinationSumUtil(0, candidates, target, temp, answer);
        return answer;
    }
};