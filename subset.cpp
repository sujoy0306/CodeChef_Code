#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector< vector<ll> > get_subsets(vector<ll> set)
{
    vector< vector<ll> > sub;
    vector<ll> e;
    sub.push_back(e);
    for (unsigned int i = 0; i < set.size(); i++) {
        vector< vector<ll> > t = sub;
        for (unsigned int j = 0; j < t.size(); j++)
            t[j].push_back( set[i] );
        for (unsigned int j = 0; j < t.size(); j++)
            sub.push_back(t[j] );
    }
    return sub;
}

int main() {
	std::ios::sync_with_stdio(false);
	vector< vector<ll> > sub;
	vector<ll> set;
	int n;
	cin>>n;
	long long p=1,count=0,val,k;
	cin>>k;
	for(int i=0;i<n;i++){
		cin>>val;
		set.push_back(val);
	}
	sort(set.begin(),set.end());
	sub=get_subsets(set);
	for(unsigned int i=0;i<sub.size();i++)
	{
		vector<ll> x=sub[i];
		for(unsigned int j=0;j<x.size();j++)
		{
			p*=x[i];
			if(p>k || x[i]>k){
				count++;
				break;
			}
		}
		p=1;
	}
	cout<<(1<<n)-(count+1)<<endl;
	return 0;
}

