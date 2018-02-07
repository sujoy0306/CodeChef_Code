#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#define ll long long 
#define pb push_back
using namespace std;
struct Interval
{
	ll start, end;
};
ll compare(ll L,ll R,ll L1,ll R1){
	ll c=0;
	if(R1<L || L1>R)
		c=0;
	else if(L1<=L && R1>=R)
		c=R-L+1;
	else if(L1>L && R1>=R)
		c=R-L1+1;
	else if(L1<=L && R1<R)
		c=R1-L+1;
	else
		c=R1-L1+1;
	//cout<<c<<endl;
	return c;
}
bool compareInterval(Interval i1, Interval i2)
{
	return (i1.start < i2.start);
}


void mergeIntervals(Interval arr[],ll n,ll L,ll R){
	if (n <= 0)
		return;
	stack<Interval> st;
	sort(arr, arr+n, compareInterval);
	st.push(arr[0]);
	for (ll i =1;i<n;i++)
	{
		Interval top1 = st.top();
		if (top1.end < arr[i].start)
			st.push(arr[i]);
		else if (top1.end < arr[i].end)
		{
			top1.end = arr[i].end;
			st.pop();
			st.push(top1);
		}
	}
	ll count=0;
	while (!st.empty())
	{
		Interval t = st.top();
	//	cout << "[" << t.start << "," << t.end << "] ";
		count+=compare(L,R,t.start+1,t.end-1);
		
		st.pop();
	}
	cout<<count<<endl;
	return;
}

int main(){
	vector< ll > val,add,sub;
	ll N,L,R,i;
	scanf("%lld %lld %lld",&N,&L,&R);
	for(i=0;i<N;i++){
		ll v;
		scanf("%lld",&v);
		val.pb(v);
	}
	sort(val.begin(),val.end());
	for(i=0;i<N-1;i++){
		add.pb(val[i+1]+val[i]);
		sub.pb(val[i+1]-val[i]);
	}
	Interval a[N-1];
	for(i=0;i<N-1;i++){
		a[i].start=sub[i];
		a[i].end=add[i];
	}
	mergeIntervals(a,N-1,L,R);
	//count=compare(L,R,L1-1,R1-1);
	return(0);
}
