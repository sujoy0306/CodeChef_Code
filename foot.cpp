#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
   // ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n;
	    cin>>n;
	    if(n==0) cout<<"Draw\n";
	   if(n==1)
	    {
	        string s3;
	        cin>>s3;
	        cout<<s3<<"\n";
	    }
	    else
	    {
    	    string s[n];
    	    string s1="",s2="";
    	    int i;
    	    for(i=0;i<n;i++){
				cin>>s[i];
			}	
    	    s1=s1+s[0];
    	    for(i=1;i<n;i++)
    	    {
    	        if(s[i]!=s1)
    	        {
    	            s2=s2+s[i];
    	            break;
    	        }
    	    }
    	    ll count1=0,count2=0;
    	    for(i=0;i<n;i++)
    	    {
    	        if(s[i]==s1)
    	        count1++;
    	        else count2++;
    	    }
    	    if(count1==count2)
    	    cout<<"Draw\n";
    	    else if(count1>count2)
    	    cout<<s1<<"\n";
    	    else cout<<s2<<"\n";
	    }
	}
	

    
    return 0;

}
