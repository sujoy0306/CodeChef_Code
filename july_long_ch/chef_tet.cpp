    #include <cstdio>
    #include <algorithm>
    #include <cmath>
    using namespace std;
     
    int A[10010], B[10010], used[10010], temp[10010], candidate, N;
     
    bool check()
    {
    	for(int i = 1; i <= N; i++)
    	{
    		if(temp[i] == candidate)
    		{
    			continue;
    		}
    		else if(!used[i - 1] && temp[i] + B[i - 1] == candidate)
    		{
    			temp[i] += B[i - 1];
    			used[i - 1] = 1;
    		}
    		else if(!used[i - 1] && !used[i] && temp[i] + B[i - 1] + B[i] == candidate)
    		{
    			temp[i] += B[i - 1] + B[i];
    			used[i - 1] = used[i] = 1;
    		}
    		else if(!used[i - 1] && !used[i + 1] && temp[i] + B[i - 1] + B[i + 1] == candidate)
    		{
    			temp[i] += B[i - 1] + B[i + 1];
    			used[i - 1] = used[i + 1] = 1;
    		}
    		else if(!used[i] && temp[i] + B[i] == candidate)
    		{
    			temp[i] += B[i];
    			used[i] = 1;
    		}
    		else if(!used[i + 1] && temp[i] + B[i + 1] == candidate)
    		{
    			temp[i] += B[i + 1];
    			used[i + 1] = 1;
    		}
    		else if(!used[i + 1] && !used[i] && temp[i] + B[i + 1] + B[i] == candidate)
    		{
    			temp[i] += B[i + 1] + B[i];
    			used[i + 1] = used[i] = 1;
    		}
    		else if(!used[i - 1] && !used[i + 1] && !used[i] && temp[i] + B[i - 1] + B[i + 1] + B[i] == candidate)
    		{
    			temp[i] += B[i - 1] + B[i + 1] + B[i];
    			used[i - 1] = used[i + 1] = used[i] = 1;
    		}
    		else
    		{
    			break;
    		}
    	}
    	for(int i = 1; i <= N; i++)
    	{
    		if(temp[i] != candidate || !used[i])
    			return false;
    	}
    	return true;
    }
     
    void preprocess()
    {
    	used[0] = used[N + 1] = 1;
    	for(int i = 1; i <= N; i++)
    	{
    		temp[i] = A[i];
    		used[i] = 0;
    	}
    }
     
    int main()
    {
    	int T;
    	scanf("%d", &T);
     
    	while(T--)
    	{
    		scanf("%d", &N);
    		for(int i = 1; i <= N; i++)
    			scanf("%d", &B[i]);
    		for(int i = 1; i <= N; i++)
    			scanf("%d", &A[i]);
     
    		int ans = -1;
     
    		preprocess();
    		temp[1] = candidate = A[1];
    		if(check())
    			ans = max(ans, candidate);
     
    		preprocess();
    		temp[1] = candidate = A[1] + B[1], used[1] = 1;
    		if(check())
    			ans = max(ans, candidate);
     
    		if(N == 1)
    		{
    			printf("%d\n", ans);
    			continue;
    		}
     
    		preprocess();
    		temp[1] = candidate = A[1] + B[2], used[2] = 1;
    		if(check())
    			ans = max(ans, candidate);
     
    		preprocess();
    		temp[1] = candidate = A[1] + B[1] + B[2], used[1] = used[2] = 1;
    		if(check())
    			ans = max(ans, candidate);
     
    		printf("%d\n", ans);
    	}
    	return 0;
    } 
		
