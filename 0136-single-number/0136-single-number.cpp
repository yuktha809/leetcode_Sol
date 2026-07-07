class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sing=0;
        for(int val:nums){
            sing=sing^val;
        }
       return sing; 
    }
};