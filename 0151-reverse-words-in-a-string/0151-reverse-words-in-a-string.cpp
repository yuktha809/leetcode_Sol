class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int start = 0;
        for(int end =0;end<=s.size();end++){
            if(end == s.size() || s[end]==' '){
                reverse(s.begin()+start,s.begin()+end);
                start = end +1;
            }
        }
        string ans ="";
        int i=0;
        while(i<s.size()){
            while(i<s.size() && s[i]== ' ' ){
            i++;
        }
        if(i==s.size()) break;
        if(!ans.empty()) ans += " ";
        while(i<s.size() && s[i]!=' '){
            ans += s[i];
            i++;
        }
        
        
        }
        
    return ans;
    }
};