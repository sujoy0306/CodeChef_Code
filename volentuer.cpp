#include<bits/stdc++.h>
#include<cstdio>
#define mod 4294967295
#define mp make_pair
#define pb push_back
#define sc second
#define fi first
#define ll long long
using namespace std;
bool byX(const pair<int,int> &a, const pair<int,int> &b)
{
	return a.first < b.first;
}

string find_string(int x,int y,int c1,int c2,char a,char b){
        string s= "";
        while (c1> 0 && c2> 0 && c1-c2> x) {
            for (int i = 0; i < x; i++) {
                s.push_back(a);
                c1--;
            }
            s.push_back(b);
            c2--;
        }
        for (int i = 0; i <c2; i++) {
            s.push_back(a);
            c1--;
            s.push_back(b);
        }
        c2= 0;
        while (c1> 0) {
            if (c1> x) {
                for (int i = 0; i < x; i++) {
                    s.push_back(a);
                    c1--;
                }
                s.push_back('*');
            } else {
                for (int i = 0; i <c1; i++) {
                    s.push_back(a);
                }
                c1= 0;
            }
        }
       return s;
}

int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int x,y;
		cin>>x>>y;
		int c1=0,c2=0;
		for(auto it:s){
			if(it=='a')
				c1++;
			else
				c2++;
		}
		//cout<<c2<<endl;
		if(c1>=c2)
			cout<<find_string(x,y,c1,c2,'a','b')<<endl;
		else
			cout<<find_string(y,x,c2,c1,'b','a')<<endl;
		
	}
	return(0);
}


//	while(abs(map['a']-map['b'])>1){
		
