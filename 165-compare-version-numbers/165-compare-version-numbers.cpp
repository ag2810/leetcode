class Solution {
public:
    int compareVersion(string v1, string v2) {
        int len1 = v1.length();
        int len2 = v2.length();
        
        int i = 0, j = 0, n1 = 0, n2 = 0;
        
        while(i < len1 || j < len2) {
            n1 = 0; n2 = 0;
            
            while(i < len1 && v1[i] != '.') {
                n1 = n1 * 10 + (v1[i] - '0');
                i++;
            }
            
            while(j < len2 && v2[j] != '.') {
                n2 = n2 * 10 + (v2[j] - '0');
                j++;                
            }

            if(n1 > n2) return 1;
            else if(n1 < n2) return -1;
         
            i++;j++;
        }
        
        return 0;
    }
};