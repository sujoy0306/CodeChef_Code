#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int test_case;
	cin>>test_case;
	while(test_case--){
		string digit;
		cin>>digit;
		int len=digit.length();
		int sum=0,i;
		for(i=0;i<len;i++){
			sum+=(int)(digit[i]-'0');
		}
		//cout<<sum;
		if(sum==len-1 || sum==1)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return(0);
}
