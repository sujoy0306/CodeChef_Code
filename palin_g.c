#include<stdio.h>
#include<string.h>

int BinA(int fir[],int sec[]){
	int i;
	for(i=0;i<26;i++)
	{
		if(fir[i]>0 && sec[i]==0)
			return 0;
	}
	return 1;
}

int  repeatedA(int fir[],int sec[])
{
	int i;
	for(i=0;i<26;i++){
		if(fir[i]>1 && sec[i]==0)
			return 1;
	}
	return 0;
}

int check(int fir[],int sec[])
{
	int i;
	int flag=0;
	if(BinA(fir,sec)){
		//printf("%d",BinA(fir,sec));
		return 0;
	}
	else if(repeatedA(fir,sec))
			return 1;
		else {
				for(i=0;i<26;i++)
				{
					if(fir[i]==1 && sec[i]==0)
						flag=1;
				}
				if(flag==1)
				{
					for(i=0;i<26;i++)
					{
						if(sec[i]>0 && fir[i]==0){
						//	printf("K");
							return 0;
						}
					}
					return 1;
				}
				else return 0;
			}
		
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--) {
			char s1[502],s2[502];
			scanf("%s",s1);
			scanf("%s",s2);
			int fir[26],sec[26];
			memset(fir,0,sizeof(fir));
			memset(sec,0,sizeof(sec));
			int l1=strlen(s1),l2=strlen(s2);
			int i;
			
			for(i=0;i<l2;i++)
			{
				sec[s2[i]-'a']++;
			}
			for(i=0;i<l1;i++){
				fir[s1[i]-'a']++;
			}
			int f=check(fir,sec);
			if(f==1)
				printf("A\n");
			else printf("B\n");
	}
	return 0;
}
