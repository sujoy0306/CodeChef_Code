#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int k;
//int max(int a, int b);
 
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
/*
int lcs( string X, string Y, int m, int n )
{
   if (m == 0 || n == 0)
     return 0;
   if (X[m-1] == Y[n-1])
     return 1 + lcs(X, Y, m-1, n-1);
   else
     return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}*/
 
/* Utility function to get max of 2 integers */
/*int max(int a, int b)
{
    return (a > b)? a : b;
}*/
int lcs(string X,string Y, int m, int n )
{
   int L[m+1][n+1];
 
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (int i=0; i<=m; i++)
   {
     for (int j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
      //if(L[i][j]>k)
	//	return INT_MAX;
	}
   }
 
   // Following code is used to print LCS
   return L[m][n];
	
   // Create a character array to store the lcs string
  
 
   // Print the lcs
   //cout << "LCS of " << X << " and " << Y << " is " << lcs;
}
 
/* Driver program to test above function */
int main()
{
  int t;
  cin>>t;
  while(t--){
	string s1,s2;
	int k;
	cin>>s1>>s2>>k;
	int m = s1.length();
	int n = s2.length();
	if(k>=max(m,n))
		cout<<"TO ERR IS HUMAN"<<endl;
	else if(k>=(max(m,n)-lcs(s1,s2,m,n)))
		cout<<"TO ERR IS HUMAN"<<endl;
	else
		cout<<"TO ERR TOO MUCH IS DEVIL"<<endl;
	//printf("Length of LCS is %d\n", lcs( X, Y, m, n ) );
}
  return 0;
}
