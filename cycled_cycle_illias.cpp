#include<iostream>
#include<vector>
using namespace std;
int min(int a,int b)
{
    return a<b?a:b;
}

int dfs(vector<vector< pair<int,int > > > v[],int p1,int vj1,int v1)
{
    int sum1=0;
    if(vj1==v1)
		return sum1;
  //  int p=v[p1][vj1][0].second;
   // cout<<p;
    vector< pair<int,int > >::iterator it;
    int nv;
    //int visited[];
    nv=vj1;
    int rv;
       while(1)
       {
        	rv=nv+1;
        	//cout<<v[p1].size()<<endl;
        	if(rv==(int)v[p1].size())
				rv=0;
        	int nv1=v[p1][nv][1].first;
        	//int nv2=v[p1][nv][0].first;
        	if(nv1==rv){
               	sum1+=v[p1][nv][1].second;
                nv=v[p1][nv][1].first;
        	}
        	else
        	{
        	    sum1+=v[p1][nv][0].second;
                nv=v[p1][nv][0].first;
        	}
           if(nv==v1)
           break;
       }
       int sum2=0;
       nv=vj1;
       while(1)
       {
           rv=nv-1;
           if(rv<0)
           rv=v[p1].size()-1;
           int nv1=v[p1][nv][0].first;
         //  int nv2=v[p1][nv][1].first;
           if(nv1==rv)
           {
	            sum2+=v[p1][nv][0].second;
                nv=v[p1][nv][0].first;
           }
           else
           {
                sum2+=v[p1][nv][1].second;
                nv=v[p1][nv][1].first;
           }
           if(nv==v1)
           break;
       }
    return min(sum1,sum2);
}
int main() {
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
	    int n,q;
	    cin>>n>>q;
	    vector<vector< pair<int,int > > > v[n];
	    for(int j=0;j<n;j++)
	    {
	        int s;
	        cin>>s;
	        vector<vector<pair<int,int> > > vec(s);
	        for(int k=0;k<s;k++)
	        {
	            int w;
	            cin>>w;
	         //   if(w!=1)
	           // fl=0;
	            if(k+1!=s)
	            {
	            vec[k].push_back(make_pair(k+1,w));
	             vec[k+1].push_back(make_pair(k,w));
	            }
	            else
	            {
	            vec[k].push_back(make_pair(0,w));
	            vec[0].push_back(make_pair(k,w));
	            }
	        }
	        v[j]=vec;
	        
	    }
	    int a[n][3];
	    for(int j=0;j<n;j++)
	    {
	        int v1,v2,w;
	        cin>>v1>>v2>>w;
	        a[j][0]=v1-1;
	        a[j][1]=v2-1;
	        a[j][2]=w;
	    }
	    int arr[n];
	       int arr1[n][2];
	       
	       arr1[n-1][1]=0;
	    for(int j=0;j<n;j++)
	    {
	        int d1=j-1;
	        if(d1<0)
				d1=n-1;
	        int d2=j;
	       
	        arr[j]=dfs(v,j,a[d1][1],a[d2][0]);
	        cout<<arr[j]<<endl;
	        arr1[j][0]=arr1[d1][1]+arr[j];
	        arr1[j][1]=arr1[j][0]+a[j][2];
	        cout<<arr1[j][0]<<"  "<<arr1[j][1]<<endl;
	    }
	    for(int j=0;j<q;j++)
	    {
	        
	        int v1,c1,v2,c2;
	        cin>>v1>>c1>>v2>>c2;
	        v1--;c1--;v2--;c2--;
	        int p1,p2;

	        int ans1=0,ans2=0;
	        p1=c1;
	        p2=c2;
	        int vj1=v1;
	        if(c1>c2)
	        {
	        	c1=p2;
	        	c2=p1;
	        	v1=v2;
	        	v2=vj1;
	        }
	        p1=c1;
	        p2=c2;
	         vj1=v1;
	        int v11=v1;
	        
	        
	        vj1=a[p1][0];
	        ans1=dfs(v,p1,vj1,v11);
	        cout<<ans1<<endl;
	        p2=c2-1;
	        if(p2<0)
	        p2=n-1;                                         
	        ans1+=abs(arr1[p2][1]-arr1[p1][0]);
	        cout<<ans1<<endl;
	        vj1=a[p2][1];
	        ans1+=dfs(v,c2,v2,vj1);
	         cout<<ans1<<endl;
	        
	        int p3=c1-1;
	        if(p3<0)
	        p3=n-1;
	        vj1=a[p3][1];                                               
	        ans2=dfs(v,p1,v1,vj1);
	        cout<<ans2<<endl;
	        if(c1!=0)
	        ans2+=abs(arr1[p3][1]-0)+abs(arr1[n-1][1]-arr1[c2][0]);
	        else
	        ans2+=abs(arr1[n-1][1]-arr1[c2][0]);
	        cout<<arr1[n-1][1]<<"  "<<arr1[c2][0]<<endl;
	       // cout<<arr1[n-1][1]<<" "<<arr1[n-1][0]<<" ";
	       cout<<ans2<<endl;
	        vj1=a[c2][0];
	        ans2+=dfs(v,c2,v2,vj1);
	        cout<<ans2<<endl;
	        
	        int ans=min(ans1,ans2);
	        cout<<ans<<endl;
	    }
	    
	}
//	cout<<"ggg";
	return 0;
}
