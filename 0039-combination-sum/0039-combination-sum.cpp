class Solution {
public:
    
    void combos(int index,int target,vector<int>& arr,vector<int>& ds,vector<vector<int>>& ans){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        if(index==arr.size()){
            return;
        }
        if(arr[index]<=target){
            ds.push_back(arr[index]);
            combos(index,target-arr[index],arr,ds,ans);
            ds.pop_back();
        }
         combos(index+1,target,arr,ds,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        combos(0,target,candidates,ds,ans);
        
        return ans;
    }
};