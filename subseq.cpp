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
    	long long p=1,count=0,c=0,val,k;
    	cin>>k;
    	for(int i=0;i<n;i++){
    		cin>>val;
    		if(val==1)
				c++;
			else
				set.push_back(val);
    	}
    	sort(set.begin(),set.end());
    	sub=get_subsets(set);
    	for(unsigned int i=0;i<sub.size();i++)
    	{
    		vector<ll> x=sub[i];
    		for(unsigned int j=0;j<x.size() && x.size();j++)
    		{
    			if(x[j]>k){
    				count++;
    				break;
    			}
    			p*=x[j];
    			if(p>k){
    				count++;
    				break;
    			}
    		}
    	//	cout<<"Product"<<p<<endl;
    		p=1;
    	}
    	
    	//cout<<count<<endl;
    	count+=(count*c);
    	//cout<<g<<endl;
    	cout<<(1<<n)-(count+1)<<endl;
    	return 0;
    } 
