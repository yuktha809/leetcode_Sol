class Solution {
public:
    void subset(int ind,vector<int>& curr,vector<int>& nums,vector<vector<int>>& ans){
        ans.push_back(curr);
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1])
                continue;
            curr.push_back(nums[i]);
        
        subset(i+1,curr,nums,ans);
        curr.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> curr;
        vector<vector<int>> ans;
        subset(0,curr,nums,ans);
        return ans;
        
    }
};