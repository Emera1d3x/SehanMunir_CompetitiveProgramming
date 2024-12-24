// https://dmoj.ca/problem/ccc23j5
import java.io.*;
import java.util.*;
import java.lang.*;

public class ccc23j5 {
    static int total = 0;
    static String[][] thingGlobal;
    
    public void checker(String w, int i, int y, int x, int cx, int cy, int r, int c, boolean turned){
      if (y < 0 || y >= r || x < 0 || x >= c)
        return;
      
      if (!(thingGlobal[y][x].charAt(0) == w.charAt(i))){
        return;
      }
      
      if (i == w.length()-1){
        total++;
        return;
      }
      
      
      if (thingGlobal[y][x].charAt(0) == w.charAt(i)){
        checker(w, i+1, y + cy, x + cx, cx, cy, r, c, turned);
        if (!turned&&i>=1){
        if ((cx==1&&cy==0)||(cx==-1&&cy==0)){
            checker(w, i+1, y+1, x, 0, 1, r, c, true);
            checker(w, i+1, y-1, x, 0, -1, r, c, true);
          } else if ((cx==0&&cy==1)||(cx==0&&cy==-1)){
            checker(w, i+1, y, x+1, 1, 0, r, c, true);
            checker(w, i+1, y, x-1, -1, 0, r, c, true);
          } else if ((cx==1&&cy==1)||(cx==-1&&cy==-1)){
            checker(w, i+1, y-1, x+1, 1, -1, r, c, true);
            checker(w, i+1, y+1, x-1, -1, 1, r, c, true);
          } else {
            checker(w, i+1, y+1, x+1, 1, 1, r, c, true);
            checker(w, i+1, y-1, x-1, -1, -1, r, c, true);
          }
        }
      }
      return;
    }
    
    public static void main(String[] args) {
        ccc23j5 z = new ccc23j5();
        Scanner s = new Scanner(System.in);
        String word = s.next();
        int wordL = word.length();
        int n = s.nextInt();
        int m = s.nextInt();
        String[][] thing = new String[n][m];
        
        for (int i = 0; i < n; i++){
          for (int j = 0; j < m; j++){
            thing[i][j] = s.next();
          }
        }
        thingGlobal = thing;
        
        for (int i = 0; i < n; i++){
          for (int j = 0; j < m; j++){
            if (thing[i][j].charAt(0) == word.charAt(0)){
              z.checker(word, 0, i, j, 1, 0, n, m, false); // right
              z.checker(word, 0, i, j, -1, 0, n, m, false); // left
              z.checker(word, 0, i, j, 0, -1, n, m, false); // up
              z.checker(word, 0, i, j, 0, 1, n, m, false); // down
              
              
              z.checker(word, 0, i, j, 1, -1, n, m, false); // down- left
              z.checker(word, 0, i, j, -1, -1, n, m, false); // up- left
              z.checker(word, 0, i, j, 1, 1, n, m, false); // down-right
              z.checker(word, 0, i, j, -1, 1, n, m, false); // up-left
            }
          }
        }
        System.out.println(total);
        
    }
}
