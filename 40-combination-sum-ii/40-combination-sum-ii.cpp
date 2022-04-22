class Solution {
public:
    void combinationSumUtil(int index, int target, vector<int>& candidates,                       vector<int> temp, vector<vector<int>>& answer) {
        if(target == 0)
        {
            answer.push_back(temp);
            return;
        }
        
        if(index >= candidates.size())
            return;
        
        for(int i = index;i < candidates.size();i++)
        {
            if(i > index && candidates[i] == candidates[i - 1]) continue;
            if(candidates[i] > target) break;
            
            temp.push_back(candidates[i]);
            combinationSumUtil(i + 1, target - candidates[i], candidates, temp,                         answer);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<int> temp;
        vector<vector<int>> answer;
        
        combinationSumUtil(0, target, candidates, temp, answer);
        
        return answer;
    }
};