// https://dmoj.ca/problem/ioi94p1
import java.io.*;
import java.util.*;
import java.lang.*;

public class ioi94p1 {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static StringTokenizer st;
  static int[][] ar;
  static int[][] memo;
  static boolean[][] done;
  public static void main(String[] args) throws IOException {
      ioi94p1 s = new ioi94p1();
      int n = s.readInt();
      ar = new int[n][n];
      memo = new int[n][n];
      done = new boolean[n][n];
      for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
          ar[i][j] = -1;
        }
      }
      for (int i = 0; i < n; i++){
        for (int j = 0; j < i+1; j++){
          ar[i][j] = s.readInt();
          memo[i][j] = ar[i][j];
        }
      }
      int currentMax = 0;
      for (int i = 0; i < n; i++){
        currentMax = Math.max(max(n-1, i), currentMax);
      }
      System.out.println(currentMax);
  }
  public static int max(int y, int x){
    if (x < 0 || x > y) {
        return 0;
    }
    if (done[y][x]){
    } else if (y==0&&x==0){
      memo[y][x] = ar[y][x];
      done[y][x] = true;
    } else if (y==0){
      memo[y][x] = max(y-1,x)+ar[y][x];
      done[y][x] = true;
    } else if (x==y){
      memo[y][x] = max(y-1,x-1)+ar[y][x];
      done[y][x] = true;
    } else {
      memo[y][x] = Math.max((max(y-1,x)+ar[y][x]),(max(y-1,x-1)+ar[y][x]));
      done[y][x] = true;
    }
    return memo[y][x]; 
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
