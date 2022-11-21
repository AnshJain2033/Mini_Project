import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
     int sum=0;
     int count=0;
     
         Scanner sc= new Scanner(System.in);

            int Avg=0;
            int t;
            String s;
            boolean flag=true;
     while(flag)
     {  
         
         s= sc.next();
         if(s!="-1")
         {if(s=="C"){sum=0;count=0;}
         else if(s=="S"){System.out.println(Avg);}
        else    {sum=sum + Integer.parseInt(s);
                 count++;
                 Avg=sum/count;
        }
         }
         else {System.out.println(sum/count); flag=false;}
     }
    }
};