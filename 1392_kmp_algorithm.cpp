class Solution {
public:
    string longestPrefix(string s) {
        int n=s.size();
        vector<int>lps(n,0);
        int prefix=0,suffix=1;
        while(suffix<n) {
            if(s[prefix]==s[suffix]) {
                lps[suffix]=prefix+1;
                prefix++;
                suffix++;
            } else  {
                if(prefix==0) {
                    lps[suffix]=0;
                    suffix++;
                } else {
                    prefix=lps[prefix-1];
                }
            }
        }
        return s.substr(0, lps[n-1]);
    }
};
