class Solution {//expand and approach
public:
    string longestPalindrome(string s) {
       int strt=0,maxlen=1;
       for(int i =0;i<s.size();i++){
        int left =i,right=i;
        while(left>=0 && right<s.size() && s[left]==s[right]){
            if(right-left+1>maxlen){
                maxlen=right-left+1;
                strt=left;
            }
            left--;
            right++;
        }
        left = i;
        right =i+1;
        while(left>=0 &&right<s.size() && s[left]==s[right]){
            if(right-left+1>maxlen){
                maxlen=right-left+1;
                strt=left;
            }
            left--;
            right++;
        }
       }
       return s.substr(strt,maxlen);
    }
};