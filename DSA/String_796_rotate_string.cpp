class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;  
        string text=s+s;
        string pattern=goal;
        int n=pattern.size();
        vector<int>lps(n,0);
        int prefix=0,suffix=1;
        while(suffix<n) {
            if(pattern[prefix]==pattern[suffix]) {
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
        int i = 0, j = 0;
        while (i < text.size()) {
            if (text[i] == pattern[j]) {
                i++;
                j++;
                if (j == pattern.size()) return true;
            } else {
                if (j == 0) {
                    i++;
                } else {
                    j = lps[j - 1];
                }
            }
        }
        return false;
    }
};
