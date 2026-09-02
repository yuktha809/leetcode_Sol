class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;
        if(dividend>0 && (divisor==1)) return dividend;
        bool neg=(dividend<0)^(divisor<0);
        long long a = dividend;
        long long b = divisor;
        a = abs(a);
        b = abs(b);
        long long q=0;
        while(a>=b){
            long long temp=b;
            long long count =1;
            while((temp<<1)<=a){
                temp<<=1;
                count<<=1;
           }
            a =a-temp;
            q=q+count;
        }
        if(neg){
            q = -q;
        }
        if (q > INT_MAX)
            return INT_MAX;

        if (q < INT_MIN)
            return INT_MIN;

        return (int)q;
    }
};