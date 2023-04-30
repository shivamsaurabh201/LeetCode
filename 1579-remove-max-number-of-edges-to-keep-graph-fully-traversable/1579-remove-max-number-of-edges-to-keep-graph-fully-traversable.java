class Solution {
    public int maxNumEdgesToRemove(int n, int[][] edges) {
        UnionFind auf=new UnionFind(n);
        UnionFind buf=new UnionFind(n);
        int edgesUsed=0;
        for(int[] edge: edges){
            if(edge[0]==3){
                int n1=edge[1]-1, n2=edge[2]-1;
                //both union find should be the same 
                if(auf.union(n1, n2)){
                    buf.union(n1,n2);
                    edgesUsed++;
                }
                //we can break out the loop early if the graph is already connected
                if(auf.isConnected()){
                    break;
                }
            }
        }

        for(int[] edge: edges){
            int n1=edge[1]-1, n2=edge[2]-1;
            if(edge[0]==1){
                if(auf.union(n1,n2)){
                    edgesUsed++;
                }
            } else if(edge[0]==2){
                if(buf.union(n1,n2)){
                    edgesUsed++;
                }
            }
            //we can break out the loop early if the graph is already connected
            if(auf.isConnected() && buf.isConnected()){
                return edges.length-edgesUsed;
            }
        }

        //we know not both graphs are connected if we haven't returned yet
        return -1;
    }
}

class UnionFind{
    int[] parents;
    int[] ranks;
    int components;
    public UnionFind(int n){
        components=n;
        parents=new int[n];
        for(int i=0;i<n;++i){
            parents[i]=i;
        }
        ranks=new int[n];
    }
    public int find(int x){
        if(parents[x]!=x){
            parents[x]=find(parents[x]);
        }
        return parents[x];
    }
    public boolean union(int x, int y){
        int px=find(x);
        int py=find(y);
        if(px==py){
            return false;
        }

        if(ranks[px]>ranks[py]){
            parents[py]=px;
        }else if(ranks[py]>ranks[px]){
            parents[px]=py;
        } else{
            parents[py]=px;
            ranks[px]++;
        }
        components--;
        return true;
    }
    public boolean isConnected(){
        return components==1;
    }
}