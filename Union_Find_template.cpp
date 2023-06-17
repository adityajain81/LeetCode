class disjoinset{
  vector<int> rank,parent;
 public:
    disjoinset(int n){
      rank.resize(n+1,0);
      parent.resize(n+1);
      for(int i=0;i<=n;i++){
        parent[i] = i;
      }
    }
  int findupar(int node){
    if(node==parent[node])
        return node;
    return parent[node] = findupar(parent[node]); // this will ensure that each node parent is set to root.
  
  void unionbyrank(int u,int v){
    int paru = findupar(u);
    int parv = findupar(v);
    if(paru==parv)
      return;
    if(rank[paru]<rank[parv]){
      parent[paru] = parv;
    }
    else if (rank[parv]<rank[paru]){
      parent[parv] = paru;
    }
    else{
      parent[parv] = paru;
      rank[paru]++;
    }
  }
 };
          
