#include <bits/stdc++.h>
using namespace std;
int arr[300005], b[205];
long long sum[300005], sum1[300005];
int main(){
	int t, n, m;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; i++){
			scanf("%d", &arr[i]);
		}
		for(int i = 0; i < m; i++){
			scanf("%d", &b[i]);
		}
		sum1[0] = 0;
		for(int i = 1; i <= n; i++){
			sum1[i] = sum1[i-1] + arr[i-1];
		}
 
		/*for(int i = 0; i < n; i++){
			sum.push_back(sum[i]);
		}*/
		int c  = 0;
		sum[c++] = sum1[m+b[m-1]-1]-sum1[m-1];
		for(int i = m+1; i <= n-b[m-1]-m+2; i++){
            //cout<<sum[c-1]<<" ";
			sum[c++] = sum1[i+b[m-1]-1]-sum1[i-1];
		}
		//for(int p=0;p<c;p++)cout<<sum[p]<<endl;
		//cout<<sum[c-1]<<" ";
		//cout<<endl;
		int  k;
		n = c;
		//cout<<"c="<<c<<endl;
		for(int i = m-1; i > 0; i--){
			int j;
			if(i > 0){
				k = b[i-1] - b[i] - 1;
			}
			deque<long long> dq;
			for( j = 0; j < k; ++j){
				while((!dq.empty()) && sum[j] >= sum[dq.back()]){
					dq.pop_back();
				}
				dq.push_back(j);
			}
			//deque<long long> dq3;
			c = 0;
			for(; j < n; ++j){
				sum[c++]=sum[dq.front()];
		//		cout<<sum[dq.front()]<<endl;
				while((!dq.empty()) && dq.front() <= j - k){
					dq.pop_front();
				}
				while((!dq.empty()) && sum[j] >= sum[dq.back()]){
					dq.pop_back();
				}
				dq.push_back(j);
			}
			sum[c++] = sum[dq.front()];
		//	cout<<sum[dq.front()]<<endl;
			n = c;
			//cout<<"c="<<c<<endl;
			for(int j = 0; j < c; j++){
				int pos = i+j-1;
 
				sum[j] = sum1[pos+b[i-1]]-sum1[pos] - sum[j];
				//cout<<sum[j]<<" ";
			}
			/*c = 0;
			for(int p = 0; p < n-b[i-1]+1-i; p++){
                sum[c] = sum1[p+b[i-1]] - sum[p]-sum[c];
                ++c;
			}*/
			//cout<<endl;
		}
		long long ans = LLONG_MIN;
		ans = LLONG_MIN;
        for(int i = 0; i < n; i++){
		//	cout<<"sum "<<sum[i]<<endl;
            ans = max(ans, sum[i]);
        }
		printf("%lld\n", ans);
	}
	return 0;
}
