class Dsu{
    
    public:
    vector<int>parent,size;
    Dsu(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
    }
    int findParent(int u){
        if(parent[u]==u){
            return u;
        }
        return parent[u]=findParent(parent[u]);

    }
    void connect(int u,int v){
        int pu=findParent(u);
        int pv=findParent(v);
        if(pu==pv){
            return;
        }
        if(size[pu]>size[pv]){
            size[pu]+=size[pv];
            parent[pv]=pu;
        }
        else{
            size[pv]+=size[pu];
            parent[pu]=pv;
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size();
        int n=row*col;
        int maxi=0;
        Dsu d(n);
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    int u=((i*col)+j+1);
                    if((i+1)<row && grid[i+1][j]==1){
                        d.connect(u,((i+1)*col)+j+1);
                        
                    }
                    if((i-1)>=0 && grid[i-1][j]==1){
                        d.connect(u,((i-1)*col)+j+1);
                    }
                    if((j-1)>=0 && grid[i][j-1]==1){
                        d.connect(u,(i*col)+(j-1)+1);
                    }
                    if((j+1)<col && grid[i][j+1]==1){
                        d.connect(u,(i*col)+(j+1)+1);
                    }
                    int pa=d.findParent(u);
                    maxi=max(maxi,d.size[pa]);
                }
            }
        }
        unordered_set<int>st;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==0){
                    st.clear();
                    int total=0;
                    if((i+1)<row && grid[i+1][j]==1){
                        st.insert(d.findParent(((i+1)*col)+j+1));
                        
                    
                    }
                    if((i-1)>=0 && grid[i-1][j]==1){
                        st.insert(d.findParent(((i-1)*col)+j+1));
                        
                    }
                    if((j-1)>=0 && grid[i][j-1]==1){
                        st.insert(d.findParent(((i*col)+(j-1)+1)));
                    }
                    if((j+1)<col && grid[i][j+1]==1){
                         st.insert(d.findParent(((i*col)+(j+1)+1)));
                    }
                    for(auto it:st){
                        total+=d.size[it];
                    }
                    
                    maxi=max(maxi,total+1);
                }
            }
        }
        return maxi;
    }
};
