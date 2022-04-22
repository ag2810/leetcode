class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        vector<int> answer(n, 0);
        
        int balls = 0;
        
        for(int i = 1;i < n;i++) {
            if(boxes[i - 1] == '1') balls++;
            left[i] = left[i - 1] + balls;
        }
        
        balls = 0;
        
        for(int i = n - 2;i >= 0;i--) {
            if(boxes[i + 1] == '1') balls++;
            right[i] =  right[i + 1] + balls;
        }
        
        for(int i = 0;i < n;i++) answer[i] = left[i] + right[i];
        
        return answer;
    }
};