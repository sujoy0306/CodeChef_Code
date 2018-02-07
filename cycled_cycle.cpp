#include<bits/stdc++.h>
#include<cstdio>
#define mod 4294967295
#define mp make_pair
#define pb push_back
#define sc second
#define fi first
#define ll long long
using namespace std;
const ll N = 1000100;
bool byX(const pair<int,int> &a, const pair<int,int> &b)
{
	return a.first < b.first;
}
int min(int a,int b)
{
    return a<b?a:b;
}
int max(int a,int b){
	return a>b?a:b;
}
inline void scanint(int &x)

{
    register  int c = getchar();

    x = 0;

    int neg = 0;

    for(;((c<48 || c>57) && c != '-');c = getchar());

    if(c=='-') {neg=1;c=getchar();}

    for(;c>47 && c<58;c = getchar()) {x = (x<<1) + (x<<3) + c - 48;}

    if(neg) x=-x;

}
/*
int clock_wise(vector<vector< pair<int,int > > > gr,int st,int end){
	int sum1=0;
	int x=st;
    int y;
      while(1){
        	y=x+1;
        	if(y==(int)gr.size())
				y=0;
        	int x1=gr[x][1].first;
        	if(x1==y){
               	sum1+=gr[x][1].second;
                x=gr[x][1].first;
        	}
        	else
        	{
        	    sum1+=gr[x][0].second;
                x=gr[x][0].first;
        	}
        	if(x==end)
				break;
       }
	return sum1;
}
int anti_clock_wise(vector<vector< pair<int,int > > > gr,int st,int end){
	 int sum2=0;
      int x=st,y;
       while(1){
           y=x-1;
           if(y<0)
				y=gr.size()-1;
           int x1=gr[x][0].first;
           if(x1==y)
           {
	            sum2+=gr[x][0].second;
                x=gr[x][0].first;
           }
           else
           {
                sum2+=gr[x][1].second;
                x=gr[x][1].first;
           }
           if(x==end)
           break;
       }
	return sum2;
}*/
int shortest_path(vector<vector< pair<int,int > > > gr,int st,int end){
    int sum1=0;
    if(st==end)
		return sum1;
    
   // int sum1=0;
	int x=st;
    int y;
      while(1){
        	y=x+1;
        	if(y==(int)gr.size())
				y=0;
        	int x1=gr[x][1].first;
        	if(x1==y){
               	sum1+=gr[x][1].second;
                x=gr[x][1].first;
        	}
        	else
        	{
        	    sum1+=gr[x][0].second;
                x=gr[x][0].first;
        	}
        	if(x==end)
				break;
       }
	//return sum1;
   //  sum1=clock_wise(gr,st,end);
     
     // int sum2;
      int sum2=0;
       x=st;
      // int y;
       while(1){
           y=x-1;
           if(y<0)
				y=gr.size()-1;
           int x1=gr[x][0].first;
           if(x1==y)
           {
	            sum2+=gr[x][0].second;
                x=gr[x][0].first;
           }
           else
           {
                sum2+=gr[x][1].second;
                x=gr[x][1].first;
           }
           if(x==end)
           break;
       }
//	return sum2;
    return min(sum1,sum2);
}

int shortest_path1(vector<vector< pair<int,int > > > gr,int st,int end){
    int sum1=0;
    if(st==end)
		return sum1;
    int m=max(st,end);
    int n=min(st,end);
    
    return min(abs(m-n),abs((int)gr.size()-m+n));
}

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	scanint(t);
	while(t--){
		int n,q;
		scanint(n);scanint(q);
		vector<vector<pair<int,int> > >gr[n];
		int fl=1;
		for(int i=0;i<n;i++){
			int m,val;
			scanint(m);
			vector<vector<pair<int,int> > >vec(m);
			for(int j=0;j<m;j++){
				scanint(val);
				if(val!=1)
					fl=0;
				vec[j].pb(mp((j+1)%m,val));
				vec[(j+1)%m].pb(mp(j,val));
			}
			gr[i]=vec;
		}
		vector<int> arr[n];
		int v1,v2,w;
		for(int i=0;i<n;i++){
			scanint(v1);scanint(v2);scanint(w);
			arr[i].pb(v1-1);
			arr[i].pb(v2-1);
			arr[i].pb(w);
			if(w!=1)
				fl=0;
		}
		 int dist[n];
	     int arr1[n][2];
	     arr1[n-1][1]=0; 
	     for(int i=0;i<n;i++){
			 int d=(i-1);
			 if(d<0)d+=n;
			 dist[i]=shortest_path(gr[i],arr[d][1],arr[i][0]);
			 arr1[i][0]=arr1[d][1]+dist[i];
			 arr1[i][1]=arr1[i][0]+arr[i][2];
		}
		//query
		int ver1,ver2,cyc1,cyc2;
		while(q--){
			scanint(ver1);scanint(cyc1);scanint(ver2);scanint(cyc2);
			ver1--;ver2--;cyc1--;cyc2--;
			if(cyc1>cyc2){
				swap(ver1,ver2);
				swap(cyc1,cyc2);
			}
			int st=ver1,end=arr[cyc1][0];
			int d1=0;
			if(fl==0)
				d1+=shortest_path(gr[cyc1],st,end);
			else
				d1+=shortest_path1(gr[cyc1],st,end);
		//	cout<<d1<<endl;
			int p=cyc2-1;
			if(p<0)p=n-1;
			d1+=abs(arr1[p][1]-arr1[cyc1][0]);
		//	cout<<d1<<endl;
			st=ver2;end=arr[p][1];
			if(fl==0)
				d1+=shortest_path(gr[cyc2],st,end);
			else
				d1+=shortest_path1(gr[cyc2],st,end);
		//	cout<<d1<<endl;
			
			p=cyc1-1;
	        if(p<0)p=n-1;
	        end=arr[p][1];st=ver1; 
	        int d2=0;
	       if(fl==0)                                           
				 d2=shortest_path(gr[cyc1],st,end);
			else
				d2+=shortest_path1(gr[cyc1],st,end);
	      //  cout<<d2<<endl;
	        
	        if(cyc1!=0)
				d2+=arr1[p][1]+abs(arr1[n-1][1]-arr1[cyc2][0]);
	        else
				d2+=abs(arr1[n-1][1]-arr1[cyc2][0]);
	       //cout<<d2<<endl;
	        end=arr[cyc2][0];
	        if(fl==0)
				d2+=shortest_path(gr[cyc2],ver2,end);
			else
				d2+=shortest_path1(gr[cyc2],ver2,end);
	       // cout<<d2<<endl;
	        cout<<min(d1,d2)<<endl;
		}
	}	
	return(0);
}


