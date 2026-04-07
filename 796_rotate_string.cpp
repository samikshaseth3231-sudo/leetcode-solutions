class Solution {
public:
    void lpsfind(vector<int>&lps,string s) {
        int prefix=0,suffix=1;
        while(suffix<s.size()) {
            if(s[prefix]==s[suffix]) {
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
    }
    bool kmpmatch(string s1,string s2) {
        vector<int>lps(s2.size(),0);
        lpsfind(lps,s2);
        int first=0,sec=0;
        while(first<s1.size() && sec<s2.size()) {
        if(s1[first]==s2[sec]) {
            first++;
            sec++;
        } else {
            if(sec==0) {
                first++;
            } else {
                sec=lps[sec-1];
            }
        }
    }
    if(sec==s2.size()) {
        return true;
    }
    return false;
    }
    int repeatedStringMatch(string a, string b) {
        if(a==b) {
            return true;
        }
        int repeat=1;
        string temp=a;
        while(temp.size()<b.size()) {
            temp+=a;
            repeat++;
        }
        if(kmpmatch(temp,b)==1) {
            return repeat;
        }
        if(kmpmatch(temp+a,b)==1) {
            return repeat+1;
        }
        return -1;
    }
};
