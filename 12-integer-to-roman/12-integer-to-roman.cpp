class Solution {
public:
    string intToRoman(int num) {
        int numeral[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        string symbol[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        
        string t = "";
    
        int i = 12;
        
        while(num > 0)
        {
            if(num >= numeral[i]) {
                int mod = num / numeral[i];
                num = num % numeral[i];
                cout<<num<<" ";
                cout<<i<<" ";
                while(mod--) {
                    t += symbol[i];
                }
                i--;
            }
            else {
                i--;
                continue;
            }
        }
        return t;
    }
};