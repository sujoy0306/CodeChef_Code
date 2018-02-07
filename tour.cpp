#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<stack>
#include<utility>
#include<queue>
#define ll long long

using namespace std;
    		
int main(){
    std::ios::sync_with_stdio(false);	
    int V,E;
    cin>>V>>E;
    
    vector<pair<int, int> > adj_list[V + 1];
    pair<int, int> edges[E];
    bool edge_visited[E];
    bool visited[V+1];
    
    for(int i=0;i<E;i++){
		int u,v;
		cin>>u>>v;
		edge[i]=make_pair(u,v);
		adj_list[u].push_back(make_pair(v,i));
		adj_list[v].push_back(make_pair(u,i));
		edge_visited[i]=false;
	}
	bool possible=true;
	for(int i=1;i<=V;i++){
		if(adj_list[i].size()&1){
			possible=false;
			break;
		}
	}
	
	if(possible==false){
		cout<<"NO"<<endl;
	}
	else if(possible==true){
		//connectivity
		
		memset(visited,0,sizeof(visited));
		stack<int> s;
		s.push(1);
		int count=1;
		visited[1]=true;
		while(!s.empty()){
			int u=s.top();
			s.pop();
			for(auto it:adj_list[u]){
				int v=it.first;
				if(!visited[v]){
					s.push(v);
					visited[v]=true;
					count++;
			//		cout<<v<<" ";
				}
			}
		}
		//cout<<count<<endl;
		if(count!=V)
			cout<<"NO"<<endl;
		else{
			memset(visited,0,sizeof(visited));
			
			cout<<"YES"<<endl;
			//route
			
			for(int i=1;i<=V;i++){
				if(!visited[i]){
					int s=i,m=i;
					do{
						visited[m]=true;
						for(auto it:adj_list[m]){
							int vr=it.first,in=it.second;
							if (!edge_visited[in]) {
								edges[in] = make_pair(m, vr);
								edge_visited[in] = true;
								m = vr;
								break;
							}
						}
					} while(m!=s);
				}
			}
			for(int i=0;i<E;i++){
				cout<<edges[i].first<<" "<<edges[i].second<<endl;
			}
			
		}		
	}				
	return(0);
}
     
