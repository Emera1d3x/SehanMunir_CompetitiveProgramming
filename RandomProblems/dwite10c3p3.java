// https://dmoj.ca/problem/dwite10c3p3
import java.io.*;
import java.util.*;
import java.lang.*;

public class dwite10c3p3 {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static StringTokenizer st;
  static int[] memo;
  static final int MOD = 1000000;
  public static void main(String[] args) throws IOException {
      dwite10c3p3 s = new dwite10c3p3();
      memo = new int[100];
      for (int i = 0; i < 5; i++){
        int n = s.readInt();
        if (n%2==1){
          memo[n]=1;
          System.out.println(0);
        } else {
          System.out.println(dp(n)%MOD);
        }
      }
  }
  static int dp (int x){
    if (x==1){
      memo[x] = 1;
      return memo[x];
    } else if (x==2){
      memo[x] = 3;
      return memo[x];
    } else if (x==3){
      memo[x] = 1;
      return memo[x];
    } else if (x==4){
      memo[x] = 11;
      return memo[x];
    }
    if (memo[x]!=0){
      return memo[x];
    }
    if (x%2==1){
      memo[x]=1;
      return memo[x];
    } else {
      memo[x]=4*(dp(x-2))-(dp(x-4));
      return memo[x];
    }
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
