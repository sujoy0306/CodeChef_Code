#include<bits/stdc++.h>							//
using namespace std;							//
typedef long long LL;							//
typedef long double LF;							//
#define vec vector<int>							//
#define ft first								//
#define sd second								//
#define pb push_back							//
#define MOD 1000000007							//
template <typename T>							//
inline T power(T base, T e){ 					//
	T result = (T)1;							//
    while(e){									//
		if(e&1){								//
			result*=base;						//
			result%=MOD;						//
		}										//
		e>>=1;									//
        base*=base;								//
        base%=MOD;								//
    }											//
    return result;								//
} 												//
//////////////////////////////////////////////////
 
// CODECHEF OCTOBER CHALLENGE
// CHEFTWOS
 
int main(){
	int t, i, len;
	char a[100001], b[100001];
	LL count, ans;
 
	scanf("%d",&t);
	while(t--){
		scanf(" %s %s",a,b);
		i=0; count=1;
		len=strlen(a);
		while(a[i+1]){
			if(a[i]=='1' && b[i]=='1'){
				count++;
				i++;
			}
			else{
				if(!a[i+2] || !a[i+3]){
					count=0;
					break;
				}
 
				// 221 221
				else if(a[i]=='2' && b[i]=='2' && a[i+1]=='2' && b[i+1]=='2' && a[i+2]=='1' && b[i+2]=='1'){
					count+=3;
				}
 
				// 121 211
				else if(a[i]=='1' && b[i]=='2' && a[i+1]=='2' && b[i+1]=='1' && a[i+2]=='1' && b[i+2]=='1'){
					count+=2;
				}
 
				// 211 121
				else if(a[i]=='2' && b[i]=='1' && a[i+1]=='1' && b[i+1]=='2' && a[i+2]=='1' && b[i+2]=='1'){
					count+=2;
				}
 
				// 221 111
				else if(a[i]=='2' && b[i]=='1' && a[i+1]=='2' && b[i+1]=='1' && a[i+2]=='1' && b[i+2]=='1'){
					count+=2;
				}
 
				// 111 221
				else if(a[i]=='1' && b[i]=='2' && a[i+1]=='1' && b[i+1]=='2' && a[i+2]=='1' && b[i+2]=='1'){
					count+=2;
				}
				else{
					count=0;
					break;
				}
				i+=3;
			}
		}
 
		if(count==0) ans=0ll;
		else ans=power(2ll,count);
		//else ans=1>>count;
		printf("%lld\n",ans);
	}
	return 0;
} 
