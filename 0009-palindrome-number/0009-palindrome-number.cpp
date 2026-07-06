class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int rev = 0;
        int num = x;
        while(x > 0){
            int rem = x % 10;
            if(rev > INT_MAX/10 || (rev == INT_MAX/10 && rem > 7)){
                return false;
            }
            rev = (rev*10)+rem;
            x=x/10;
        }
        if(num == rev){
            return true;
        }
        else{
            return false;
        }
    }
};