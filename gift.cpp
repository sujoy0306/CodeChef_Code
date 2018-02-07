//Sujoy Kansabanik
//JU CSE 2nd Year
#include<iostream>
#include<cstring>
#define ll long long
#define d 3*1e6
using namespace std;
//ll val=(ll)d;
ll dp[300003],v[300003];
string txt,pat;
ll count(){
	ll p_l=pat.length();
	ll n=txt.length();
	ll mod=(ll)1e9+7;
	if(v[0]==1)dp[0]=1;
	for(ll i=1;i<n;i++){
		if(v[i]==1){
			if(i-p_l>=0)dp[i]=dp[i-p_l]+dp[i-1]+1;
			else dp[i]=dp[i-1]+1;
		}
		else{
			dp[i]=dp[i-1];
		}
		dp[i]%=mod;	
	}
	return dp[n-1];
}
void computeLPSArray(ll M, ll *lps);
 //KMP ALGORITHM
void KMPSearch()
{
    ll M =pat.length();
    ll N =txt.length();
    ll lps[M];
    computeLPSArray(M, lps);
    ll i = 0;  // index for txt[]
    ll j  = 0;  // index for pat[]
    while (i < N){
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
        if (j == M)
        {
            v[i-j]=1;//intial index
            j = lps[j-1];
        }
        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j-1];
            else
                i = i+1;
        }
    }
}
void computeLPSArray(ll M,ll *lpss)
{
    ll len1 = 0;
    lpss[0] = 0; // lps[0] is always 0
    ll i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len1])
        {
            len1++;
            lpss[i] = len1;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            if (len1 != 0)
            {
                len1 = lpss[len1-1];
            }
            else // if (len == 0)
            {
                lpss[i] = 0;
                i++;
            }
        }
    }
}
int main(){
	int test_case;
	cin>>test_case;
	while(test_case--){
		memset(v,0,sizeof(v));
		memset(dp,0,sizeof(dp));
		cin>>txt;
		cin>>pat;
		KMPSearch();
		cout<<count()<<endl;
	}
	return(0);
}
