class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        deque<int> dq;
        while(deck.size() > 0) {
            int element = deck[deck.size() - 1];
            deck.pop_back();
            if(!dq.empty()) {
                int last = dq.back();
                dq.pop_back();
                dq.push_front(last);
            }
            dq.push_front(element);
        }
        return vector<int>(dq.begin(), dq.end());
    }
};