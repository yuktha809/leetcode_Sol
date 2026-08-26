class Solution {
public:
    long long power(long long x,long long n,long long mod){
        if(n==0){
            return 1;
        }
        long long half=power(x,n/2,mod);
        if(n%2==0){
            return (half*half)%mod;
        }
        else{
            return (x* half%mod*half)%mod;
        }
    }
    int countGoodNumbers(long long n) {
        long long mod = 1e9+7;
        long even = (n+1)/2;
        long odd = n/2;
        
        return (power(5,even,mod)*(power(4,odd,mod)))%mod;
    }
};