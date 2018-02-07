#include<bits/stdc++.h>
//#define ll long long
using namespace std;
void printKMax(vector<int> &arr, int n, int k,int length[])
{
	int j=0;
	std::deque<int> Qi(k);
	int i;
	for (i = 0; i < k; ++i)
	{
		while ( (!Qi.empty()) && arr[i] >= arr[Qi.back()])
			Qi.pop_back();
			
		Qi.push_back(i);
	}
	for ( ; i < n; ++i)
	{
		length[j]=arr[Qi.front()];
	//	cout<<j<<"  "<<length[j]<<endl;
		j++;
		while ( (!Qi.empty()) && Qi.front() <= i - k)
			Qi.pop_front();
		while ( (!Qi.empty()) && arr[i] >= arr[Qi.back()])
			Qi.pop_back();
		Qi.push_back(i);
	}
	length[j]=arr[Qi.front()];
	//cout<<j<<"  "<<length[j]<<endl;;
}
int main(){
	std::ios::sync_with_stdio(false);
	int n,k,p;
	cin>>n>>k>>p;
	int arr[2*n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		arr[i+n]=arr[i];
	}
	string s;
	cin>>s;
	if(k>n)k=n;
	vector<int> sum_wn;
	int sum=0;
	for(int i=0;i<k;i++){
		sum+=arr[i];
	}
	sum_wn.push_back(sum);
	for(int i=k;i<2*n;i++){
		sum=sum-arr[i-k]+arr[i];
		sum_wn.push_back(sum);
	}
	int ln=sum_wn.size();
	int length[n];
	k=n-k+1;
	//cout<<"K "<<k<<endl;
	printKMax(sum_wn,ln,k,length);
	int in=0;
	for(int i=0;i<p;i++){
		if(s[i]=='?')
			cout<<length[in]<<endl;
		else{
			in--;
			if(in<0)in+=n;
		}
	}
	return(0);
}
	
