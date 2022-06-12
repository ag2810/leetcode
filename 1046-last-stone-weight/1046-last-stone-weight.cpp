class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        if(n == 1) return stones[0];
        
        priority_queue<int> q;
        
        for(auto i : stones) q.push(i);
        
        while(n > 1) {
            int first = q.top();
            q.pop();
            int second = q.top();
            q.pop();
            n -= 2;
            
            if(first - second > 0) {
                q.push(first - second);
                n += 1;
            }
        }
        
        if(!q.empty()) return q.top();
        return 0;
    }
};
