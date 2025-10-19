import java.util.*;

public class Main {
  public static void main(String[] args) {
  
    Scanner s = new Scanner(System.in);
    
    // Reading # of candies
    int N = s.nextInt();
    // Reading the initial health point of Johnny
    int K = s.nextInt();
    // Setting Johnny's health point
    int HP = K;
    
    // Looping through candies consumed
    for (int i = 0; i < N; i++){
      // Reading whether the candy boosts or harms
      String candy = s.next();
      // Reading X factor
      int X = s.nextInt();
      
      // Adjusting Johnny's health accordingly
      if (candy.equals("BOOST")){
        HP += X;
      } else {
        HP -= X;
      }
      
      // Exit loop if Johnny has passed
      if (HP <= 0){
        break;
      }
      
    }
    // Print conclusion
    if (HP <= 0){
      System.out.println("Johnny is cooked!"); 
    } else {
      System.out.println("Johnny will return next year!"); 
    }
  }
}
