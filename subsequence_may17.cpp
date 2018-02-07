    #include <bits/stdc++.h>
    #define ll long long
    #define ull unsigned long long 
    using namespace std;
     
    vector< vector<ull> > get_subsets(vector<ull> set)
    {
        vector< vector<ull> > sub;
        vector<ull> e;
        sub.push_back(e);
        for (unsigned int i = 0; i < set.size(); i++) {
            vector< vector<ull> > t = sub;
            ull sz1=t.size();
            for (ull j = 0; j < sz1; j++)
                t[j].push_back( set[i] );
                
            sz1=t.size();
            for (ull j = 0; j <sz1; j++)
                sub.push_back(t[j] );
        }
        return sub;
    }

    int main() {
    	std::ios::sync_with_stdio(false);
    	vector< vector<ull> > sub,sub1;
    	vector<ull> set,set1;
    	int n;
    	cin>>n;
    	ull count=0,c=0,val,k;
    	cin>>k;
    	for(int i=0;i<n;i++){
    		cin>>val;
    		if(val==1)
				c++;
    		else if(i<=n/2){
    			set1.push_back(val);
    		}
    		else{
				set.push_back(val);
			}
    	}
  
    	sort(set.begin(),set.end());
    	
    	sort(set1.begin(),set1.end());
    	
    	sub=get_subsets(set);
    	sub1=get_subsets(set1);
    	ull sz1=sub.size(),sz2=sub1.size();
    	vector<ull> pro1,pro2;
    	ull p=1;
    	for(ull i=0;i<sz1;i++)
    	{
			p=1;
    		vector<ull> x=sub[i];
    		ull sz3=x.size();
    		for(ull j=0;j<sz3;j++)
    		{
    			//p*=x[j];
    			ull a=p;
    			p=a*x[j];
    			if (p/a!=x[j]) {
					p=k+1;
					count++;
					break;
				}
    			if(p>k){
    				count++;		
    				break;
    			}
    		}
    		if(x.size()>0){
	//			cout<<"Product1  "<<p<<endl;
				pro1.push_back(p);
			}
    		
    	}
   // 	cout<<count<<endl;
    	for(ull i=0;i<sz2;i++)
    	{
			p=1;
    		vector<ull> x=sub1[i];
    		ull sz3=x.size();
    		for(ull j=0;j<sz3;j++)
    		{
				ull a=p;
    			p=a*x[j];
    			if ( p/a!=x[j]) {
					p=k+1;
					count++;
					break;
				}
    			if(p>k){
    				count++;
    				break;
    			}
    		}
    		if(x.size()>0){
	//			cout<<"Product2  "<<p<<endl;
				pro2.push_back(p);
			}
    		p=1;
    	}
    //	cout<<count<<endl;
    	
	
    	sort(pro1.begin(),pro1.end());
    	sort(pro2.begin(),pro2.end());
   
		
    	ull m=pro1.size();
    	ull n1=pro2.size();
		for(ull i=0;i<m;i++){
			for(ull j=0;j<n1;j++){
				ull a=pro1[i]*pro2[j];
    			if ( a/pro1[i]!= pro2[j]) {
					count+=(n1-j);
					break;
				}
				else if(a>k){
					count+=(n1-j);
					break;
				}
				
			}
		}
		
		count+=(count*c);
		//cout<<count<<endl;
    	cout<<(1<<n)-(count+1)<<endl;
    	return 0;
    } 
