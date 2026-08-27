class Solution {
    void dfs(vector<vector<int>>& image, int i, int j,int newColor,int 
    oldcolor)
    {
        if(i<0||j<0||i==image.size()||j==image[0].size()||
        image[i][j]==newColor||image[i][j]!=oldcolor)
        {
            return;
        }
        image[i][j]=newColor;
        dfs(image,i-1,j,newColor,oldcolor);
        dfs(image,i+1,j,newColor,oldcolor);
        dfs(image,i,j+1,newColor,oldcolor);
        dfs(image,i,j-1,newColor,oldcolor);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image,sr,sc,color,image[sr][sc]);
        return image;
    }
};