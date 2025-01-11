// https://leetcode.com/problems/is-subsequence/

class Solution {
public:
    bool isSubsequence(string a, string b) {
        bool ans = false;
        int x = 0;
        if(a=="" && b=="") return true;
        for(char c:b){
            if(c==a[x]){
                x++;
            }
            if(x==a.size()){
                ans = true;
                break;
            }
        }
        return ans; 
    }
};