class Solution {
public:
    int largestRectangle(vector<int> heights){
        int maxArea = 0;
        stack<int> st;
        for(int i =0;i<=heights.size();i++){
            int curr;
            if(i==heights.size()){
                curr = 0;
            }
            else{
                curr = heights[i];
            }
            while(!st.empty() && curr < heights[st.top()]){
                int height = heights[st.top()];
                st.pop();
                int width;
                if(st.empty()){
                    width = i;
                }
                else{
                    width = i-st.top()-1;
                }
                int area;
                area = height*width;
                maxArea = max(maxArea,area);
            }
            if(i<heights.size())
                st.push(i);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = 0;
        if(matrix.empty()) return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
         vector<int> heights(cols,0);
        for(int i =0;i<rows;i++){
            for(int j =0;j<cols;j++){
                if(matrix[i][j]=='1'){
                    heights[j]++;
                }
                else{
                heights[j]=0;
                }
            }

            maxArea = max(maxArea,largestRectangle(heights));
       
        }
        return maxArea;
    }
};