//chef_and_frnd
#include <iostream>
#include <queue>
using namespace std;
int Gr[1005][1005];
bool bprtite(int source,int V){
    int fr[1005];
    for (int i = 0; i < V; ++i)
        fr[i] = -1;
    
    queue <int> qu;
   for(int i=0;i<V;i++){
    if(fr[i]==-1){
    	qu.push(i);
	fr[i]=1;
    }
    while (!qu.empty()){
        int vrtx= qu.front();
        qu.pop();
        for (int v = 0;v<V; ++v){
            if (Gr[vrtx][v] && fr[v] == -1){
                fr[v] = 1 - fr[vrtx];
                qu.push(v);
            }
            else if (Gr[vrtx][v] && fr[v] == fr[vrtx])
                return false;
        }
    }
  }
    return true;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int test_case;
    cin>>test_case;
    while(test_case--){
    	int i,j,vrtx,edge;
    	cin>>vrtx>>edge;
	/*for(i=0;i<1002;i++){
		for(j=0;j<1002;j++)
			Gr[i][j]=0;
	}*/
    	for(i=0;i<vrtx;i++){
    		for(j=0;j<vrtx;j++){
    			Gr[i][j]=1;
    			if(i==j)
    				Gr[i][j]=0;
		}
	}
    	while(edge--){
    		int f1,f2;
    		cin>>f1>>f2;
    		Gr[f1-1][f2-1]=0;
    		Gr[f2-1][f1-1]=0;
		}
		/*for(i=0;i<vrtx;i++){
			for(j=0;j<vrtx;j++)
				cout<<Gr[i][j]<<" ";
			cout<<endl;
		}*/
		if(bprtite(0,vrtx))
			cout <<"YES\n";
		else
			cout << "NO\n";
	}
    return 0;
}
