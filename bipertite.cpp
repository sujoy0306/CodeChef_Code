    #include<bits/stdc++.h>
    #define ll long long int
    using namespace std;
     
    int main()
    {	
    	ll t,n,m,d,D,cnt;
    	cin>>t;
    	while(t--)
    	{
    		cnt=0;
    		scanf("%lld%lld%lld%lld",&n,&m,&d,&D);
    		if(m>=n*d&&m<=n*D)
    		{
    			for(int i=0;i<D;++i)
    			{
    				for(int j=0;j<n;++j)
    				{
    					printf("%lld %lld\n",j+1LL,(j+i)%n+1LL);
    					cnt++;
    					if(cnt==m)
    						break;
    				}
    				if(cnt==m)
    					break;
    			}
    		}
    		else
    		{
    			cout<<-1<<endl;
    		}
    	}
    	return 0;
    }
