// https://dmoj.ca/problem/ccc15s3

import java.io.*;
import java.util.*;
import java.lang.*;

public class Main {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static StringTokenizer st;
  public static void main(String[] args) throws IOException {
    Main s = new Main();
    int g = s.readInt();
    int p = s.readInt();
    TreeSet<Integer> gates = new TreeSet<>();
    for (int i = 1; i <= g; i++){
      gates.add(i);
    }
    int ans = 0;
    for (int i = 0; i < p; i++){
      int a = s.readInt();
      Integer z = gates.floor(a);
      if (z != null){
        ans++;
        gates.remove(z);
      } else {
        break;
      }
    }
    System.out.println(ans);
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
