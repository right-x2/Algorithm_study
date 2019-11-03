import java.util.Scanner;

public class Main {

   public static void main(String[] args) {
      Scanner scanner = new Scanner(System.in);
      int[] intArr = new int[10];
      for(int i = 0; i < intArr.length; i++) {
         intArr[i] = scanner.nextInt();
         intArr[i] = intArr[i] % 42;
      }
      
      int count = 0;
      int dif = 0;
      
      for(int i = 0; i < intArr.length; i++) {
         for(int j = i + 1; j < intArr.length; j++) {
            if(intArr[i] == intArr[j]) count++;
         }
         if(count == 0) dif++;
         count = 0;
      }      
      System.out.println(dif);
   }
}