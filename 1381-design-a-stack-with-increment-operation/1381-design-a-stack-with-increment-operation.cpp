class CustomStack {
private:
    vector<int> st;
    int maxi;
public:
    CustomStack(int maxSize) {
        maxi = maxSize;
    }
    
    void push(int x) {
        if (st.size() == maxi) return;
        else st.push_back(x);
    }
    
    int pop() {
        if (st.size() == 0) return -1;
        else {
            int x = st.back();
            st.pop_back();
            return x;
        }
    }
    
    void increment(int k, int val) {
        if (k > st.size()) {
            for(int i = 0;i < st.size();i++) st[i] = st[i] + val;
        }
        else {
            for(int i = 0;i < k;i++) st[i] = st[i] + val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */