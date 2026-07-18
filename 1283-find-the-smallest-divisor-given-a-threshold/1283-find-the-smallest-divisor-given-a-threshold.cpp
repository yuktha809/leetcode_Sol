class Solution {
public:
    int sums(vector<int>& nums,int n){
        
        int thre = 0;
        for(int i:nums){
            thre += ceil((double)i/n);
        }
        return thre;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        if(nums.size() > threshold) return -1;
        int low = 1,high = *max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid = (low+high)/2;
            if(sums(nums,mid)<=threshold){
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};