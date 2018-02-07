#include<bits/stdc++.h>
//#define ll long long
using namespace std;
int main(){
	std::ios::sync_with_stdio(false);
	int n,k,p;
	cin>>n>>k>>p;
	int arr[n],f_0,l_0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	string s;
	cin>>s;
	for(int i=0;i<n;i++){
		if(arr[i]==0){
			f_0=i;
		//	cout<<"X";
			break;
		}
	}
	for(int i=n-1;i>=0;i--){
		if(arr[i]==0){
			l_0=i;
			break;
		}
	}
	int counter=0,maxm=0,c=0,i_max,i=f_0+1;
	//cout<<f_0<<" "<<l_0<<endl;
	while(c<n){
		if(arr[i]==1){
			counter++;
		}
		else{
			if(maxm<counter){
				maxm=counter;
			//	cout<<i<<endl;
				i_max=i;
			}
			counter=0;
		}
		//cout<<i<<endl;
		i++;
		i%=n;
		c++;
	}
	maxm=max(maxm,counter);//MAXIMUM NUMBER
	if(maxm==0){
		for(int i=0;i<p;i++){
			if(s[i]=='?')
				cout<<0<<endl;
		}
		return(0);
	}
	int s_indx,f_indx;
	f_indx=i_max-1;//FINAL INDEX
	if(f_indx<0)f_indx+=n;
	i_max=i_max-maxm;
	if(i_max<0)i_max+=n;
	s_indx=i_max;//STARTING INDEX
	
	//cout<<s_indx<<"  "<<f_indx<<"   "<<maxm<<endl;
	int len[maxm];
	// length 
	for(i=0;i<maxm;i++){
		if(i<=maxm/2)
			len[i]=maxm-i;
		else
			len[i]=i;
	//	cout<<len[i]<<" ";
	}
	//cout<<endl;
	
	int max_2=0;
	i_max=0;
	i=f_0+1;
	c=0;
	counter=0;
	while(c<n){
		if(arr[i]==1){
			counter++;
		}
		else{
			i--;
			//cout<<"Counter  "<<counter<<endl;
			if(max_2<counter && i!=f_indx){
				max_2=counter;
				//cout<<counter<<endl;
			//	cout<<i<<endl;
			}
			i++;
			counter=0;
		}
		//cout<<i<<endl;
		i++;
		i%=n;
		c++;
	}	
	max_2=max(max_2,counter);
	//cout<<"MAX_2  "<<max_2<<endl;//max_2
	int length[n];
	for(i=0;i<n;i++){
		if((i<=s_indx && s_indx<=f_indx) || (s_indx<=f_indx && i>f_indx) || (i>f_indx && i<=s_indx)){
			length[i]=min(k,maxm);
		}
		else{
			int val,j;
			if(i<=f_indx && f_indx<s_indx){
				j=f_indx-i;
				j=maxm-1-j;
				val=max(len[j],max_2);
				length[i]=min(val,k);
			}
			else{
				j=i-s_indx;
				val=max(len[j],max_2);
				length[i]=min(k,val);
			}
		}
		cout<<length[i]<<" ";
	}
	int in=0;
	for(i=0;i<p;i++){
		if(s[i]=='?')
			cout<<length[in]<<endl;
		else{
			in--;
			if(in<0)in+=n;
		}
	}
	return(0);
}
	
