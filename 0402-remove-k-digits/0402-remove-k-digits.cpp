class Solution {
public:
    string removeKdigits(string num, int k) {
        string s;
        for(char n:num){
            while(!s.empty()&& k>0 && s.back()>n){
                s.pop_back();
                k--;
            }
            s.push_back(n);
        }
        while(k>0){
            s.pop_back();
            k--;
        }
        int i =0;
        while(i<s.size() && s[i]=='0'){
            i++;
        }
        s=s.substr(i);
        if(s.empty()) return "0";
        return s;
    }
};