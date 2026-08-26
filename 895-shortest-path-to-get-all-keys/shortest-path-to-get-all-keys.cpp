class Solution {
public:
    bool isValid(int i,int j,int m,int n)
    {
        return i>=0 && j>=0 && i<m && j<n;
    }

    int row[4]={-1,0,1,0}; 
    int col[4]={0,1,0,-1};

    int shortestPathAllKeys(vector<string>& grid) {
        int sx=0,sy=0,keys=0;
        // when i am landing on a cell i should know mere pas kon kon sa key hai, I cannot make a generic VISITED
        // TO mark a cell visitd I must which keys i have right now
        //Proper visited state is required 
        // visited [x][ny][keys] --> keys == Mask  -> "000000" 
        // just count of keys while visiting is not enough

        vector<char>r;
        vector<vector<char>>mat;

        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[i].size();++j)
            {
                r.push_back(grid[i][j]);
            }
            mat.push_back(r);
            r.clear();
        }

        int m=mat.size();
        int n=mat[0].size();

        for(int i=0;i<mat.size();++i)
        {
            for(int j=0;j<mat[i].size();++j)
            {
                if(mat[i][j]=='@')
                {
                    sx=i;
                    sy=j;
                }

                if(mat[i][j]>='a' && mat[i][j]<='f')
                {
                    keys++;
                }
            }
        }

        queue<pair<string,pair<int,pair<int,int>>>>q;

        vector<vector<set<string>>>visited(
            m,vector<set<string>>(n)
        );

        string mask="000000";

        q.push({mask,{0,{sx,sy}}});

        while(!q.empty())
        {
            auto it=q.front();
            q.pop();

            string mask=it.first;
            int moves=it.second.first;
            int x=it.second.second.first;
            int y=it.second.second.second;

            if(visited[x][y].count(mask))
                continue;

            visited[x][y].insert(mask);

            for(int k=0;k<4;++k)
            {
                int nx=x+row[k];
                int ny=y+col[k];

                if(!isValid(nx,ny,m,n))
                    continue;

                if(mat[nx][ny]=='#') //wall
                    continue;

                string newMask=mask;

                if(mat[nx][ny]>='A' && mat[nx][ny]<='F')
                {
                    int idx=mat[nx][ny]-'A';

                    if(mask[idx]=='0')
                        continue;
                }

                if(mat[nx][ny]>='a' && mat[nx][ny]<='f')
                {
                    int idx=mat[nx][ny]-'a';

                    newMask[idx]='1';

                    int cnt=0;

                    for(char ch:newMask)
                    {
                        if(ch=='1')
                            cnt++;
                    }

                    if(cnt==keys)
                        return moves+1;
                }

                if(!visited[nx][ny].count(newMask))
                {
                    q.push({newMask,{moves+1,{nx,ny}}});
                }
            }
        }

        return -1;
    }
};