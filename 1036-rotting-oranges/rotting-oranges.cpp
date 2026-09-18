class Solution {
public:
 int row[4]={-1,0,1,0};
 int col[4]={0,1,0,-1};
 bool isValid(int i,int j,int m,int n)
 {
     return i>=0&&j>=0&&i<m&&j<n;
 }
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        int fresh=0;
       
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[0].size();++j)
            {
                if(grid[i][j]==1)
                {
                   fresh++;
                }
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        if(fresh==0) return 0;
        int timer=0;
        while(!q.empty())
        {
            int sze=q.size();
            while(sze--)
            {
                 auto it=q.front();
                q.pop();
               int x=it.first;
               int y=it.second;
              for(int k=0;k<4;++k)
             {
                int nx=x+row[k];
                int ny=y+col[k];
                if(isValid(nx,ny,m,n) && grid[nx][ny]==1)
                {
                    grid[nx][ny]=2;
                    q.push({nx,ny});
                    fresh--;
                }
             }
         
            }
            timer++;
        }


       if(fresh>=1) return -1;
       else return timer-1;
     

        
    }
};