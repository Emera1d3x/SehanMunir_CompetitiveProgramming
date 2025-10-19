## Problem Statement Simplified
Given an array of ~N~ numbers, output the position of the second largest number.
## Solution
To find the position of the second largest number, traverse the array while keeping track of both the largest and second largest values along with their respective positions. For each element, update these values if a larger number is encountered, shifting the previous largest to second largest when necessary. After completing the traversal, the stored position of the second largest number is the desired result. This approach ensures a single-pass, efficient solution with no extra memory taken up.

Time Complexity: ~O(N)~

## Java Solution
```java
import java.util.*;

public class Main {
  public static void main(String[] args) {
  
    Scanner s = new Scanner(System.in);
    
    // Reading # of candies
    int N = s.nextInt();
    
    // Keeping track of largest number and it's position, and the second largest number and it's position
    int largestNumber = 0, largestPosition = 0, secondNumber = 0, secondPosition = 0;
    
    // Looping through array
    for (int i = 1; i <= N; i++){
      
      // Reading the next candy's sweetness
      int S = s.nextInt();
      
      // If the sweetness is the greatest thus far, demote the previous greatest to second greatest and replace accordingly
      if (S > largestNumber){
        secondNumber = largestNumber;
        secondPosition = largestPosition;
        largestNumber = S;
        largestPosition = i;
      } else if (S > secondNumber) { // If the sweetness is the second greatest thus far, replace the second sweetest only
        secondNumber = S;
        secondPosition = i;
      }
    }
    
    // Finally, print out your the second sweetest candy's position
    System.out.println(secondPosition);
  }
}

```
