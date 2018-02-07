#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;
   bool isGood(string str)
    {
        if (str[(str.length() - 2] == '2')
            return false;

        for (int i = 0; i < str.length() - 2; i++)
            if (str.charAt(i) == '2')
                if (str.charAt(i + 1) != '2')
                    return false;
                else if (str.charAt(i + 2) != '1')
                    return false;
                else
                    i += 2;
        return true;

    }
    
     void compute(String a, String b)
    {
        int c = 0,c1=0, i, j;
        vector<int> list;
        for (i = 0; i < a.length(); i++)
            if (a[i] == b[i])
                c++;
            else
                list.push_back[i];
        //System.out.println(list);
        for (i = 0; i <  1<<list.size(); i++){
           // StringBuilder x = new StringBuilder(a);
//StringBuilder y = new StringBuilder(b);
			string x,y;
            for (j = 0; j < list.size(); j++){
                if ((i & (1 << j)) != 0)
                {
                    x.replace(list[j),list.get(j)+1,""+b.charAt(list.get(j)));
                    y.replace(list.get(j),list.get(j)+1,""+a.charAt(list.get(j)));
                }
                else
                {
                    x.replace(list.get(j),list.get(j)+1,""+a.charAt(list.get(j)));
                    y.replace(list.get(j),list.get(j)+1,""+b.charAt(list.get(j)));
                }

            }
           // System.out.println(x+"\t"+y);
           if(isGood(x.toString())&&isGood(y.toString())){
               c1++;
               //System.out.println("Test : "+x+"\t"+y);
           }
        }
        //System.out.println(c1);
        System.out.println(c1*(int)Math.pow(2, c));
    }
int main(){
{

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while ((t--) != 0)
        {
            String a = sc.next();
            String b = sc.next();
            compute(a, b);
        }

}
