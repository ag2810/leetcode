class Solution {
public:
    void numTilePossibilities(int index, string tiles, string& temp, set<string>& s) {
        if(temp.size()) s.insert(temp);
        if(index == tiles.length()) return;
        
        for(int i = index;i < tiles.length();i++) {
            swap(tiles[index], tiles[i]);
            temp += tiles[index];
            numTilePossibilities(index + 1, tiles, temp, s);
            temp.pop_back();
            swap(tiles[index], tiles[i]);
        }
    }
    int numTilePossibilities(string tiles) {
        set<string> s;
        string temp;
        numTilePossibilities(0, tiles, temp, s);
        return s.size();
    }
};