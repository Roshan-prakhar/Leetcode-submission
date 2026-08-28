class Solution {
public:
    bool isValid(int i,int j,int m,int n)
    {
        return i>=0&&i<m&&j>=0&&j<n;
    }

    bool solve(int rows,int cols,vector<vector<int>>& cells,int mid)
    {
        vector<vector<int>>grid(rows,vector<int>(cols,0));

        for(int i=0;i<mid;++i)
        {
            int x=cells[i][0]-1;
            int y=cells[i][1]-1;
            grid[x][y]=1;
        }

        queue<pair<int,int>>q;
        vector<vector<int>>vis(rows,vector<int>(cols,0));

        for(int j=0;j<cols;++j)
        {
            if(grid[0][j]==0)
            {
                q.push({0,j});
                vis[0][j]=1;
            }
        }

        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};

        while(!q.empty())
        {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();

            if(i==rows-1) return true;

            for(int k=0;k<4;++k)
            {
                int ni=i+dr[k];
                int nj=j+dc[k];

                if(isValid(ni,nj,rows,cols) &&
                   grid[ni][nj]==0 &&
                   vis[ni][nj]==0)
                {
                    vis[ni][nj]=1;
                    q.push({ni,nj});
                }
            }
        }

        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        // I dont need to do bfs afdter evyer day 
        // I am doing B.S. so only O(Log(m*n)) days are tested
        int low=0;
        int high=cells.size();
        int ans=0;

        while(low<=high)
        {
            int mid=(low+high)>>1;

            if(solve(row,col,cells,mid))
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }

        return ans;
    }
};