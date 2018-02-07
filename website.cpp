#include<bits/stdc++.h>
#define size 26
#define new_node() (node*)malloc(sizeof(struct node))
using namespace std;
vector<string>filter;
struct node{
	bool is_end;
	int prefix_count;
	struct node* child[size];
}*head;

void init(){
	head=new node();
	head->prefix_count=0;
	head->is_end=false;
}

void insert(string word){
	node *current=head;
	current->prefix_count++;
	for(unsigned int i=0;i<word.length();i++){
		int letter=(int)word[i]-(int)'a';
		if(current->child[letter]==NULL)
			current->child[letter]=new node();
		current->child[letter]->prefix_count++;
		current=current->child[letter];
	}
	current->is_end=true;
}

bool search(string word){
	vector<char> chr;
	node *current=head;
	for(unsigned int i=0;i<word.length();i++){
		if(current->child[((int)word[i]-(int)'a')]==NULL){
			//cout<<word[i]<<endl;
			chr.push_back(word[i]);
			//chr.push_back('\0');
			string s(chr.begin(),chr.end());
			filter.push_back(s);
			return false;
		}
		//cout<<word[i];
		chr.push_back(word[i]);
		current=current->child[((int)word[i]-(int)'a')];
	}
	return true;
}
int main(){
	int n;
	cin>>n;
	if(n>2*100000)cout<<-1<<endl;
	vector <pair<string,string> >s;
	long long length=0;
	string s1,s2,s3[n];
	for(int i=0;i<n;i++){
		cin>>s1>>s2;
		s.push_back(make_pair(s1,s2));
		length+=s[i].second.length();
		s3[i]=s2;
	}
	if(length>2*100000){
		cout<<-1<<endl;
		return(0);
	}
	sort(s3,s3+n);
	for(int i=0;i<n;i++){
		if(i<n-1 && s3[i]==s3[i+1]){
			cout<<-1<<endl;
			return(0);
		}
	}
	sort(s.begin(),s.end());
	int in;
	for(int i=0;i<n;i++){
		if(s[i].first=="-"){
			in=i;
			break;
		}
		//cout<<s[i].first<<" "<<s[i].second;
	}
	init();
	string str;
	for(int i=0;i<in;i++){
		str=s[i].second;
		//cout<<str<<endl;
		insert(str);
	}
	int j=0;
	for(int i=in;i<n;i++){
		str=s[i].second;
	//	cout<<str<<endl;
		if(search(str)){
			cout<<-1<<endl;
			return(0);
		}
		j++;	
	}
	sort(filter.begin(),filter.end());
	
		int counter=0;
	for(int i=0;i<n-in;i++){
		if(i<n-in-1 && filter[i]==filter[i+1]){
			counter++;
		}
		//cout<<filter[i]<<endl;
	}
	cout<<n-in-counter<<endl;
	for(int i=0;i<n-in;i++){
		while(i<n-in-1 && filter[i]==filter[i+1])
			i++;
		cout<<filter[i]<<endl;
	}
	return(0);
}
