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
bool byX(const pair<int,int> &a, const pair<int,int> &b)
{
	return a.first < b.first;
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
string str2[26];
vector<string> temp[26],temp1[26];
ll freq[26];
ll q,p,m,k;

void check(ll index){
	
	 if(temp1[index].size()<=0){
		 
        for(unsigned ll j=0;j<temp[index].size();j++)
        {
            for(unsigned ll l=1;l<=temp[index][j].size();l++)
            {
                    string st=temp[index][j].substr(0,l);
                    temp1[index].push_back(st);
            }
        }
        sort(temp1[index].begin(),temp1[index].end());
        for(unsigned ll l=0;l<temp1[index].size();l++)
        {
            str2[index]+=temp1[index][l];
        }
        }
}
void calculate(ll &g){
	
	cin>>p>>m;
	k=((p%m)*(g%m))%m+1;
        ll si=0,index=0,ind=0;
        for(ll i=0;i<26;i++)
        {
            ind=si;
            si+=freq[i];
            if(si>=k)
            {
                ind=k-ind;
                index=i;
                break;
            }
        }
       check(index);
        cout<<str2[index][ind-1]<<endl;
        g+=(ll)(str2[index][ind-1]);
}
void gen_substr(string s){
	memset(freq,0,sizeof(freq));
	for(unsigned int i=0;i<s.size();i++){
		temp[s[i]-'a'].pb(s.substr(i,s.size()-i));
		int n=s.substr(i,s.size()-i).size();
		freq[s[i]-'a']+=((n*(n+1))/2);
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    string s;
    cin>>s;
    gen_substr(s);
    
    cin>>q;
    ll g=0;
    vector<string> temp;
    while(q--){
		calculate(g);
	}
	return(0);
}


