
Problem Link: 

  https://www.codingninjas.com/codestudio/problems/ninja-and-his-friends_3125885?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1


int rec(int i,int j,int j1,int n,int m,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp)
{
    if(i==n-1)
    {
        if(j==j1)
        {
            return grid[i][j];
        }
        else{
            return grid[i][j]+grid[i][j1]; 
        }
    }
    if(j<0 || j>=m || j1<0 || j1>=m)
    {
        return -100001;
    }
    if(dp[i][j][j1]!=-1)
    {
        return dp[i][j][j1];
    }
    vector<int>dy{1,0,-1};
    int mx=-100001;
    for(int x=0;x<dy.size();x++)
    {
        for(int y=0;y<dy.size();y++)
        {
            if(j==j1)
            {
                dp[i][j][j1]=mx=max(mx,grid[i][j]+rec(i+1,j+dy[x],j1+dy[y],n,m,grid,dp));
            }
            else{
                 dp[i][j][j1]=mx=max(mx,grid[i][j]+grid[i][j1]+rec(i+1,j+dy[x],j1+dy[y],n,m,grid,dp));
            }
        }
    }
    return dp[i][j][j1];
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) 
{
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
    return rec(0,0,m-1,n,m,grid,dp);
}
