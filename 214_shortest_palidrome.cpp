class Solution {
public:
    string shortestPalindrome(string s) {
        int n=s.size();
        string rev=s;
        reverse(rev.begin(),rev.end());
        string temp=s+'$'+rev;
        vector<int>lps(temp.size(),0);
        int prefix=0,suffix=1;
        while(suffix<temp.size()) {
            if(temp[prefix]==temp[suffix]) {
                lps[suffix]=prefix+1;
                suffix++;
                prefix++;
            } else {
                if(prefix==0) {
                    lps[suffix]=0;
                    suffix++;
                } else {
                    prefix=lps[prefix-1];
                }
            }
        }
        int len=lps[temp.size()-1];
        return rev.substr(0,s.size()-len)+s;
    }
};
