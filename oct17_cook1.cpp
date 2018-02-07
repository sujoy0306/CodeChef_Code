#include<bits/stdc++.h>
#define int long long int
#define init(arr,val) memset(arr,val,sizeof(arr))
#define vec vector<int>
#define pair pair<int,int>
#define pb push_back
#define pf push_front
#define mp make_pair
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopb(i,a,b) for(int i=a;i>=b;i--)
#define vitr vector<int>::iterator
#define sitr set<int>::iterator

using namespace std;

#undef int
int main()
{
#define int long long int
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
	    string a;
	    cin>>a;
	    int n=a.size();
	    int lastseen[n];
	    lastseen[0]=-1;
	    int arr[26];
	    memset(arr,-1,sizeof(arr));
	    arr[(int)(a[0]-'a')]=0;
	    loop(i,1,n)
	    {
	       lastseen[i]=arr[(int)(a[i]-'a')];
	       arr[(int)(a[i]-'a')]=i;
	    }
	    int prefix[n];
	    prefix[0]=1;
	    loop(i,1,n)
	    {
	        if(a[i]==a[i-1])
	        {
	            prefix[i]=prefix[i-1]+1;
	        }
	        else
	        {
	            prefix[i]=1;
	        }
	    }
	    int cnt=0;
	    loopb(i,n-1,1)
	    {
	        if(lastseen[i]!=-1)
	        {
	            int v=lastseen[i];
	            if(v==i-1)
	             cnt++;
                else
                {
                    if(prefix[i-1]==(i-1-v))
                     cnt++;
                }
	        }
	    }
	    loop(i,0,n)
	    {
	        if(prefix[i]>2 and (prefix[i+1]==1 or i==n-1))
	        {
	            int v=prefix[i];
	            v-=2;
	            cnt+=(v*(v+1))/2;
	        }
	    }
	    cout<<cnt<<"\n";

	}
}

