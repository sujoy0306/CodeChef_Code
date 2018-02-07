#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
	std::ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int h,w,fl=0;
		cin>>h>>w;
		string str[h];
		for(int i=0;i<h;i++){
			cin>>str[i];
		}
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				//cout<<"B";
				if(str[i][j]=='W'){
					//cout<<"C";
					if(((j==0) || (j==w-1)) || (i==h-1)){
						fl=1;
					//	cout<<"A";
					}
					else if((i<h-1) && (str[i+1][j]=='A'|| str[i][j+1]=='A' || str[i][j-1]=='A')){
						fl=1;
					}
					else if((i>0) && str[i-1][j]=='B'){
						fl=1;
					}
				}
				else if(str[i][j]=='A' && ((i>0) && (str[i-1][j]=='B'))){
					fl=1;
				}
			}
		}
		if(fl)
			cout<<"no"<<endl;
		else
			cout<<"yes"<<endl;
	}
	return(0);
}
