#include<iostream>
using namespace std;
int main(){
	std::ios:sync_with_stdio(false);
	int tc;
	cin>>tc;
	while(tc--){
		int len,count=0;
		cin>>len;
		string st;
		cin>>st;
		for(int i=0;i<len;i++){
			bool state=false
			for(int j=0;j<len-1;j++){
				if(st[i]=='0' && st[i+1]=='1'){
					if(state==false){
						count++;
