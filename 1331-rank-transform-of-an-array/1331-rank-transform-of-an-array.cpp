class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans = arr;
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        unordered_map<int,int> mp;
        for(int i =0;i<ans.size();i++){
            mp[ans[i]] = i + 1;
        }
        for(int i = 0;i<arr.size();i++){
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};