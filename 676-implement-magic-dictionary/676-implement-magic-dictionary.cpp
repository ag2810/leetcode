class MagicDictionary {
private:
    vector<string> mp;
public:
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto word : dictionary) mp.push_back(word);
    }
    
    bool search(string searchWord) {
        for(auto word : mp) {
            if(word.length() == searchWord.length()) {
                 if(difference(word, searchWord)) return true;
            }
        }
        return false;
    }
    
    bool difference(string a, string b) {
        int changes = 0;
        for(int i = 0;i < a.length();i++) {
            if(a[i] != b[i]) changes++;
        }
        if(changes == 1) return true;
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */