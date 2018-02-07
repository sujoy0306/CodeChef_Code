import java.util.*;


class Squares
{
    private ArrayList<Integer> ar;
    private int k;
    Squares(int k){
      this.k=k;
      ar=new ArrayList<>();
      for(int i=1;i<=k;i++)
          ar.add(i);
    }
    public String generate(){
        String s="";
        String s1="";
        for(int i=k/2;i<k;i++){
            s=s+"\n"+ar;
            ar.add(ar.remove(0));
        }
        s=s.trim();
        for(int i=0;i<k/2;i++){
            s1=s1+"\n"+ar;
            ar.add(ar.remove(0));
        }
        s1=s1.trim();
        s=s1+"\n"+s;
        s=s.replace(",","").replace("[","").replace("]","");
        return s;
    }
 public static void main(String args[]){
     Scanner sc=new Scanner(System.in);
     int t=sc.nextInt();
     while(t--!=0){
    Squares ob=new Squares(sc.nextInt());
    System.out.println(ob.generate());
     }
 }   
}
