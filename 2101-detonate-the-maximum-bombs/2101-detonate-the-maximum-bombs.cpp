class Solution {
#define ll long long int
public:
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int& count, int& i)
    {
        visited[i] = true;
        count++;
        for(int j = 0;j < graph[i].size();j++)
        {
            if(!visited[graph[i][j]])
                dfs(graph, visited, count, graph[i][j]);   
        }
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> graph(n);
        
        for(int i = 0;i < n;i++) {
            ll r = bombs[i][2];
            ll x1 = bombs[i][0], y1 = bombs[i][1];
            
            for(int j = 0;j < n;j++) {
                if(i != j) {
                    ll x2 = bombs[j][0], y2 = bombs[j][1];
                    if(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)) <= r * r)                                 graph[i].push_back(j);
                }
            }
        }
        
        int ans = INT_MIN;
        
        for(int i = 0;i < n;i++)
        {
            int c = 0;
            vector<bool> visited(n, false);
            dfs(graph, visited, c, i);
            ans = max(ans, c);
        }
        
        return ans;
    }
};