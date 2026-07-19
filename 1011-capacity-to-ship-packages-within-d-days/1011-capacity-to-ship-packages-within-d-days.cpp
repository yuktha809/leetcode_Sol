class Solution {
public:
    int Days(vector<int>& weights,int capacity){
        int day =1,currentLoad=0;
        for(int i : weights){
            if(currentLoad+i>capacity){
                day++;
                currentLoad = i;
            }
            else{
                currentLoad +=i;
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            int ans = Days(weights,mid);
            if(ans<=days){
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};