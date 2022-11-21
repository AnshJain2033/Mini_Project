import java.util.*;
public class main{
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        int sum;
        int counter;
        int a=sc.nextInt();
        while(a!=-1){
            sum=sum+a;
            counter=counter+1;
        }
        int c=(sum/counter);
        System.out.prinltn(c);        
    }
}