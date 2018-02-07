#include<bits/stdc++.h>
#include<cstdio>
#define mod 4294967295
#define mp make_pair
#define pb push_back
#define sc second
#define fi first
#define ll long long
#define loop(i,a,b)for(int i=a;i<b;i++)
using namespace std;
const ll N = 1000100;

char d[]={'u','d','r','l'};
string dir;
int m;
int find(int rw,int c,int n,string s[]){
	for(unsigned int i=0;i<dir.size();i++){
		if(d[dir[i]-'0']=='u')rw--;
		else if(d[dir[i]-'0']=='d')rw++;
		else if(d[dir[i]-'0']=='r')c++;
		else if(d[dir[i]-'0']=='l')c--;
		
		if(s[rw][c]=='E')return 1;
		if(s[rw][c]=='#' or rw<0 or rw>=n or c<0 or c>=m)return 0;
	}
}
		
	
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin>>n>>m;
    string s[n];
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	
	cin>>dir;
//	cout<<dir<<endl;
	int rw=-1,c=-1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i][j]=='S'){
				rw=i;c=j;
			}
		}
	}
	sort(d,d+4);
	int count=0;
	do{
		count+=find(rw,c,n,s);
	}while(next_permutation(d,d+4) );
	cout<<count<<endl;
	return(0);
}


