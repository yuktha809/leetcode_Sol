class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for(char ch:s){
            freq[ch]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto i:freq){
            pq.push({i.second,i.first});
        }
        string ans="";
        while(!pq.empty()){
            int count = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            ans.append(count,ch);
        }
        return ans;

    }
};