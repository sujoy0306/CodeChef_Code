#include<bits/stdc++.h>
using namespace std;
 
int main()
{
     string A;
     int t,i,n,k,flips;
     int cnt1,cnt2;
     cin>>t;
     while(t--) {
          cin>>n>>k;
          cin>>A;
          string t=A;
          int count=0;
          int maxm=0,j;
          char c=A[0];
          for(i=0;i<n;i++){
			if(A[i]==c){
				count++;
			}
			else{
				maxm=max(maxm,count);
				count=1;
				c=A[i];
			}
		  }
		  maxm=max(maxm,count);
		  if(k==0){
			cout<<maxm<<endl;
			//continue;
		  }
		  else{
		  for(j=1;j<=maxm;j++){
			//  cout<<"A";
			A=t;
			if(j==1){
               cnt1=cnt2=0;
               for(i=0;i<n;i++)
               {
                    if(i%2==0){
						if(A[i]=='1')
							cnt2++;
						else
							cnt1++;
 
					}
					else{
						if(A[i]=='0')
							cnt2++;
						else
							cnt1++;
					}
			}
			if(min(cnt1,cnt2)<=k){
				cout<<1<<endl;
				break;
			}
          }
          else
          {
               flips=0;
               count=1;
               for(i=1;i<n;i++)
               {
				 //  cout<<"B";
                    if(A[i]==A[i-1])
                         count++;
                    else
                         count=1;
                    if(count>j)
                    {
                         if(A[i+1]==A[i] && i!=n-1)
                              A[i]=A[i]^1;
                         else
                              A[i-1]=A[i-1]^1;
                         flips++;
                    }
               }
               if(flips<=k){
				   cout<<j<<endl;
				   break;
				}
          }
         }
        }
     }
    return(0);
 }
