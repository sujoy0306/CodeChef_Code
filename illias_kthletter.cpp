#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    ll l=s.length();
    ll sum=(l*(l+1))/2;
    int q;
    cin>>q;
    while(q--){
        ll n;
        cin>>n;
        if(n>sum){
            cout<<-1<<endl;
         //   continue;
        }
        else{
        vector<ll>arr(l);
        arr[0]=l;
        for(ll i=1;i<l;i++){
            arr[i]=arr[i-1]+(l-i);
        }
        auto it=lower_bound(arr.begin(),arr.end(),n);
        ll in=it-arr.begin();
        cout<<in<<endl;
        ll ans;
        if(in>0)ans=arr[in-1];
        if(in==0)ans=0;
        ans=n-ans;
        cout<<ans<<endl;
        string str=s.substr(in,ans);
        cout<<str<<endl;
        }
    }
    return(0);
}
