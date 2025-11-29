import java.util.*;

public class Main {
  public static void main(String[] args) {

    Scanner s = new Scanner(System.in);

    // Reading # of candies
    int N = s.nextInt();

    // Keeping track of largest number and it's position, and the second largest number and it's position, and the third largest number and it's position
    int largestNumber = 0, largestPosition = 0, secondNumber = 0, secondPosition = 0, thirdNumber = 0, thirdPosition = 0;

    // Looping through array
    for (int i = 1; i <= N; i++){

      // Reading the next candy's sweetness
      int S = s.nextInt();

      // If the sweetness is the greatest thus far, demote the previous greatest to second greatest, and second greatest to third greatest, and replace accordingly
      if (S > largestNumber){
        thirdNumber = secondNumber;
        thirdPosition = secondPosition;
        secondNumber = largestNumber;
        secondPosition = largestPosition;
        largestNumber = S;
        largestPosition = i;
      } else if (S > secondNumber) { // If the sweetness is the second greatest thus far, replace the second sweetest only
        thirdNumber = secondNumber;
        thirdPosition = secondPosition;
        secondNumber = S;
        secondPosition = i;
      } else if (S > thirdNumber) { // If the sweetness is the third greatest thus far, replace the third sweetest only
        thirdNumber = S;
        thirdPosition = i;
      } 
    }

    // Finally, print out your the third sweetest candy's position
    System.out.println(thirdPosition);
  }
}
