#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	int test_case;
	cin>>test_case;
	while(test_case--){
		string pal_str,rev_str;
		cin>>pal_str;
		rev_str=pal_str;
		reverse(rev_str.begin(),rev_str.end());
		for(int i=0;i<pal_str.length();i++){
			if(pal_str[i]=='.'){
				if(rev_str[i]=='.')
					pal_str[i]=rev_str[i]='a';
				else{
					char ch=rev_str[i];
					pal_str[i]=ch;
					reverse(rev_str.begin(),rev_str.end());
					rev_str[i]=ch;
					reverse(rev_str.begin(),rev_str.end());
				}
			}
		}
		//cout<<pal_str<<"	"<<rev_str<<endl;
		if(pal_str.compare(rev_str)==0)
			cout<<pal_str<<endl;
		else
			cout<<"-1"<<endl;
	}
	return(0);
}
