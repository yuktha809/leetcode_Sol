class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int total = 1 << n;
         vector<vector<int>> ans;
        for(int mask=0;mask<total;mask++){
            vector<int> sub;
            for(int i =0;i<nums.size();i++){
                if(mask & (1<<i)){
                    sub.push_back(nums[i]);
                }
                
            }
            ans.push_back(sub);

        }
        return ans;
    }
};