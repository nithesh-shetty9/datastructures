class Solution {
    void dfs(vector<vector<int>>&image,vector<vector<int>>&visited,
    int row,int col,int old,int newc)
    {
        if(row<0||col<0||row==image.size()||col==image[0].size()||
        visited[row][col]||image[row][col]!=old)
        {
            return;
        }
        image[row][col]=newc;
        visited[row][col]=1;
        dfs(image,visited,row,col+1,old,newc);
         dfs(image,visited,row,col-1,old,newc);
          dfs(image,visited,row-1,col,old,newc);
           dfs(image,visited,row+1,col,old,newc);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldcolor=image[sr][sc];
        int V=image.size();
        int U=image[0].size();
         vector<vector<int>>visited(V,vector<int>(U,0));
        dfs(image,visited,sr,sc,oldcolor,color);
        return image;
    }
};