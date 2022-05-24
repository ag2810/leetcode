class Solution {
public:
    int mincostTicketsUtil(int index, vector<int>& days, vector<int>& costs, vector<int>& dp) {
        if(index >= days.size()) return 0;
        
        if(dp[index] != -1) return dp[index];
        
        int oneDayPass = costs[0] + mincostTicketsUtil(index + 1, days, costs, dp);
        
        int i;
        
        for(i = index;i < days.size();i++) if(days[index] + 7 <= days[i]) break;
        int sevenDayPass = costs[1] + mincostTicketsUtil(i, days, costs, dp);
        
        for(i = index;i < days.size();i++) if(days[index] + 30 <= days[i]) break;
        int thirtyDayPass = costs[2] + mincostTicketsUtil(i, days, costs, dp);
        
        return dp[index] = min(oneDayPass, min(sevenDayPass, thirtyDayPass));
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), -1);
        return mincostTicketsUtil(0, days, costs, dp);
    }
};