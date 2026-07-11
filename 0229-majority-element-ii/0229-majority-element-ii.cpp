class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cs1=0,cs2=0;
        int n = nums.size();
        int el1=INT_MIN,el2=INT_MIN;
        for(int i =0;i<n;i++){
            if(cs1==0 && el2!=nums[i]){
                cs1++;
                el1=nums[i];
            }
            else if(cs2==0 && el1!=nums[i]){
                cs2++;
                el2=nums[i];
            }
            else if(nums[i]==el1){
                cs1++;
            }
            else if(nums[i]==el2){
                cs2++;
            }
            else{
                cs1--;
                cs2--;
            }
            
        }
         cs1 = 0,cs2 =0;
        for(int i =0;i<n;i++){
            if(nums[i]==el1){
                cs1++;
            }
            if(nums[i]==el2){
                cs2++;
            }
        }
        int freq = (n/3);
        vector<int> ans;
        if(cs1> freq){
            ans.push_back(el1);
        }
        if(cs2>freq){
            ans.push_back(el2);
        }
        return ans;
    }
};