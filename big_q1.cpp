#include<iostream>
#include<algorithm>
#include<climits>
typedef long long ll;
using namespace std;
struct factor{
	ll cnt_2,cnt_5;
};
ll arr[100001],inf = INT_MAX,lft,rght;

factor tree[400000];
long long count_5(long long n){
	long long count=0;
	while(n%5==0 && n){
		count++;
		n/=5;
	}
	//cout<<count<<endl;
	return count;
}
long long count_2(long long n){
	long long count=0;
	while(n && n%2==0){
		count++;
		n/=2;
	}
	//cout<<count<<endl;
	return count;
}
void buildTree(ll node,ll l,ll r) {
	if(l > r)
		return;
 
	if(l == r) {
		tree[node].cnt_2 = count_2(arr[l]);
		tree[node].cnt_5=count_5(arr[l]);
		return;
	}
 
	buildTree(2 * node, l, (l + r) / 2);
	buildTree(2 * node + 1, (l + r) / 2 + 1, r);
 
	tree[node].cnt_2 = (tree[2 * node].cnt_2+tree[2 * node + 1].cnt_2);
	tree[node].cnt_5= (tree[2 * node].cnt_5+tree[2 * node + 1].cnt_5);
}
factor queryTree(ll node,ll l,ll r,ll i,ll j) {
	if(l > r || l > j || r < i){
		factor x;
		x.cnt_2=x.cnt_5=0;
		return x;
	}
	if(l >= i && r <= j){
		factor tmp;
		tmp.cnt_2=tree[node].cnt_2;
		tmp.cnt_5=tree[node].cnt_5;
		return tmp;
	}	
	factor q1 = queryTree(2 * node, l, (l + r) / 2, i, j);
	factor q2 = queryTree(2 * node + 1, (l + r) / 2 + 1, r, i, j);
 
	factor t;
	t.cnt_2=q1.cnt_2+q2.cnt_2;
	t.cnt_5=q1.cnt_5+q2.cnt_5;
	return t;
}
void updateTree_1(ll node,ll l,ll r,ll i,ll j,ll x) {
	if(l > r || l > j || r < i)
		return;
 
	if(l == r) {
		tree[node].cnt_2+=count_2(x);
		tree[node].cnt_5+=count_5(x);
		return;
	}
	
	//if(tree[node] == 1)
	//	return;
 
	updateTree_1(2*node,l,(l + r)/2, i, j,x);
	updateTree_1(2*node +1, (l + r) / 2 + 1,r,i,j,x);
 
	tree[node].cnt_2 = (tree[2 * node].cnt_2+tree[2 * node + 1].cnt_2);
	tree[node].cnt_5= (tree[2 * node].cnt_5+tree[2 * node + 1].cnt_5);
}
void updateTree_2(ll node,ll l,ll r,ll i,ll j,ll x) {
	if(l > r || l > j || r < i)
		return;
 
	if(l == r) {
		tree[node].cnt_2 =count_2(x*(i-l+1));
		tree[node].cnt_5=count_5(x*(i-l+1));
		return;
	}
	
	//if(tree[node] == 1)
	//	return;
 
	updateTree_2(2*node,l,(l + r)/2,i,j,x);
	updateTree_2 (2*node+1,(l + r)/ 2 + 1, r, i, j,x);
 
	tree[node].cnt_2 = (tree[2 * node].cnt_2+tree[2 * node + 1].cnt_2);
	tree[node].cnt_5= (tree[2 * node].cnt_5+tree[2 * node + 1].cnt_5);
}
int main(){
	std::ios::sync_with_stdio(false);
	int test_case;
	cin>>test_case;
	while(test_case--){
		ll n,q,i,sum=0;
		cin>>n>>q;
		for(i=0;i<n;i++){
			cin>>arr[i];
		}
		buildTree(1,0,n-1);
		while(q--){
			ll op,l,r,pro;
			cin>>op>>l>>r;
			if(op!=3)
				cin>>pro;
			if(op==3){
				factor X;
				X=queryTree(1, 0, n- 1, l - 1, r - 1);
				sum+=min(X.cnt_2,X.cnt_5);
			}
			else if(op==1)
				updateTree_1(1, 0, n- 1, l - 1, r - 1,pro);
			else{
				lft=l-1;
				rght=r-1;
				updateTree_2(1,0,n- 1, l - 1, r - 1,pro);
			}
		}
		cout<<sum<<endl;
	}
	return(0);
}			
