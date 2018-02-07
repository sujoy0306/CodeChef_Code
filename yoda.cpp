#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define MAX 10001
#define ll long long
using namespace std;
/*long long combi(ll n,ll k)
{
    long long ans=1;
    k=k>n-k?n-k:k;
    ll j=1;
    for(;j<=k;j++,n--)
    {
        if(n%j==0)
        {
            ans*=n/j;
        }else
        if(ans%j==0)
        {
            ans=ans/j*n;
        }else
        {
            ans=(ans*n)/j;
        }
    }
    return ans;
}*/
long long triangle[MAX + 1][MAX + 1];

void makeTriangle() {
    int i, j;

    // initialize the first row
    triangle[0][0] = 1; // C(0, 0) = 1

    for(i = 1; i < MAX; i++) {
        triangle[i][0] = 1; // C(i, 0) = 1
        for(j = 1; j <= i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
}

long long C(int n, int r) {
    return triangle[n][r];
}
int main(){
	int t;
	scanf("%d",&t);
	makeTriangle();
	while(t--){
		ll p,k;
		int n,m;
		scanf("%d %d %lld %lld",&n,&m,&p,&k);
		//1s state
		int v1=m*n-1;
		int v2=(m-m/2)*(n-n/2)+(m/2)*(n/2)-1;
	//	cout<<v1<<"   "<<v2<<endl;
		bool st1=(v1%2==1);
		bool st2=(v2%2==1);
		float ans=1.0;
		if(st1 && st2)
			printf("%f\n",ans);
		else if(st1 && !st2){
			ll sum=0;
			for(int i=p;i<=k;i++){
				sum+=triangle[k][i];
			//	cout<<"Sum  "<<sum<<endl;
			}
			//cout<<"Sum  "<<sum<<endl;
			ans=sum/(pow(2,k));
			printf("%f\n",ans);
		}
		else if(!st1 && st2){
			ll sum=0;
			for(int i=p;i<=k;i++){
				sum+=triangle[k][i];
			}
			ans=sum/(pow(2,k));
			ans=1-ans;
			printf("%f\n",ans);
		}
		else{
			ans=0.0;
			printf("%f\n",ans);
		}
	}
	return(0);
}
		
			
