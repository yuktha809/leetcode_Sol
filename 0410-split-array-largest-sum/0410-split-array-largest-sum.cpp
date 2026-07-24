class Solution {
public:
    int numPartitions(vector<int>& nums,int maxSum ){
        int partition=1;
        int sum = 0;
        for(int i =0;i<nums.size();i++){
            if(sum +nums[i] <= maxSum){
                sum += nums[i];
            }
            else{
                partition++;
                sum = nums[i];

            }
        }
    return partition;
    }
    int splitArray(vector<int>& nums, int k) {
       
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid = (low+high)/2;
            int ans = numPartitions(nums,mid);
            if(ans > k){
                low = mid+1;
            }

            else{
                high = mid-1;
            }   
            
        }
        return low;
    }
};