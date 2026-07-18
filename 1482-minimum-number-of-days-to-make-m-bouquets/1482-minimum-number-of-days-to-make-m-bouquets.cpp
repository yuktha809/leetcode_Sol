class Solution {
public: 
    bool possible(vector<int>& nums,int day,int m,int k){
        int n = nums.size();
        int count = 0,bouq=0;
        for(int i=0;i<n;i++){
            if(nums[i]<=day){
                count++;
                if(count==k){
                    bouq++;
                    count=0;
                }
                
            }
            else{
                    count=0;
                }
        }
        return bouq >=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k > bloomDay.size())
            return -1;
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high) {
            int mid = (low+high)/2;
            if(possible(bloomDay,mid,m,k)){
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        
        return low;
    }
};