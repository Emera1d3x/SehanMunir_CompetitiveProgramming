// https://dmoj.ca/problem/ioi14pp1
import java.io.*;
import java.util.*;
import java.lang.*;

public class ioi14pp1 {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static StringTokenizer st;
  static int[][] array;
  static boolean[][] solved;
  static int n = 0;
  public static void main(String[] args) throws IOException {
      ioi14pp1 s = new ioi14pp1();
      n = s.readInt();
      array = new int[n][n];
      solved = new boolean[n][n];
      for (int r = 0; r < n; r++){
        for (int c = 0; c < n; c++){
          int num = s.readInt();
          array[r][c] = num;
          if (num == 0){
            solved[r][c] = true;
          }
        }
      }
      int amount = 0;
      int max = 0;
      for (int r = 0; r < n; r++){
        for (int c = 0; c < n; c++){
          array[r][c] = s.sizeFinder(r,c);
          if (array[r][c]>max){
            max = array[r][c];
            amount = 1;
          } else if (array[r][c]==max){
            amount++;
          }
        }
      }
      System.out.println(max*amount);
  }
  public static int sizeFinder (int r, int c){
    int size;
    if (solved[r][c]==true){
      return array[r][c];
    } else {
      if ((r == n-1 || c == n-1)&& array[r][c] == 0){
        solved[r][c] = true;
        array[r][c] = 0;
        return 0;
      } else if ((r == n-1 || c == n-1)&& array[r][c] == 1){
        solved[r][c] = true;
        array[r][c] = 1;
        return 1;
      } else {
        int right = sizeFinder(r, c+1);
        int down = sizeFinder(r+1, c);
        int rightdown = sizeFinder(r+1, c+1);
        if (right == 0 || down == 0 || rightdown == 0){
          solved[r][c] = true;
          array[r][c] = 1;
          return 1;
        } else if (right==down){
          solved[r][c] = true;
          array[r][c] = right;
          if (array[r+right][c+right]!=0){
            array[r][c]+=1;
            return right+1;
          }
          return right;
        } else if (right < down) {
          solved[r][c] = true;
          array[r][c] = right+1;
          return right+1;
        } else if (right > down){
          solved[r][c] = true;
          array[r][c] = down+1;
          return down+1;
        }
      }
    }
    return 0;
  }
  static String next() throws IOException {
    while (st == null || !st.hasMoreTokens())
      st = new StringTokenizer(br.readLine().trim());
    return st.nextToken();
  }
  static long readLong() throws IOException {return Long.parseLong(next());}
  static int readInt() throws IOException {return Integer.parseInt(next());}
  static double readDouble() throws IOException {return Double.parseDouble(next());}
  static char readCharacter() throws IOException {return next().charAt(0);}
  static String readLine() throws IOException {return br.readLine().trim();}
}
