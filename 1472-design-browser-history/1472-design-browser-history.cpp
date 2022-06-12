vector<string> history(5001);
class BrowserHistory {
public:
    int curr, end;
    
    BrowserHistory(string homepage) {
        history[0] = homepage;
        curr = 0;
        end = 0;
    }
    
    void visit(string url) {
        if(history[curr] != url) {
            curr++;
            history[curr]= url;
            end = curr;
        }
    }
    
    string back(int steps) {
        curr = max(0, curr - steps);
        return history[curr];
    }
    
    string forward(int steps) {
        curr = min(curr + steps, end);    
        return history[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */