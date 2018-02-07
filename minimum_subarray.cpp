    #include<bits/stdc++.h>
    using namespace std;
    int main()
     {
    	//code
    	int t; cin >>t;
    	while(t--) {
    	    int n, x; cin >> n >> x;
    	    int a , psum[n+1];
    	    memset(psum, 0, sizeof(psum));
    	    for (int i = 1; i <= n; ++i) {
    	        cin >> a;
    	        psum[i] = psum[i-1] + a;
    	    }
    	    priority_queue<pair<int, int> , vector<pair<int, int> > , greater<pair<int, int > > > Q;
    	    Q.push({psum[0], 0});
    	    int best = n+1;
    	    for (int i = 1; i <= n; ++i) {
    	        while(!Q.empty() and psum[i] - Q.top().first > x ) {
    	            best = min(best, i - Q.top().second); Q.pop();
    	        }
    	        Q.push({psum[i], i});
    	    }
    	    cout << best << endl;
    	}
    	return 0;
    }
