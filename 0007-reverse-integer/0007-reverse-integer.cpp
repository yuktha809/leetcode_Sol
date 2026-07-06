class Solution {
public:
    int reverse(int x) {
        
        int revN=0;
        while(x!=0){
            int digit = x % 10;
            x = x/10;
           if (revN > INT_MAX / 10 || (revN == INT_MAX / 10 && digit > 7))
                return 0;

            
            if (revN < INT_MIN / 10 || (revN == INT_MIN / 10 && digit < -8))
                return 0;
            revN = (revN*10)+digit;
            
        }
        return revN;
    }
};