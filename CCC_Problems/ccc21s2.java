// https://dmoj.ca/problem/ccc21s2
import java.io.*;
import java.util.*;
import java.lang.*;

public class ccc21s2 {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static StringTokenizer st;
  public static void main(String[] args) throws IOException {
      ccc21s2 s = new ccc21s2();
      int m = s.readInt();
      int n = s.readInt();
      int k = s.readInt();
      int gold = 0;
      HashMap<Integer, Integer> r = new HashMap<>(); 
      HashMap<Integer, Integer> c = new HashMap<>(); 
      for (int i = 0; i < k; i++){
        char ch = s.readCharacter();
        int z = s.readInt();
        if (ch == 'R'){
          if (r.containsKey(z)){
            r.put(z, r.get(z)+1);
          } else {
            r.put(z, 1);
          }
        }
        if (ch == 'C'){
          if (c.containsKey(z)){
            c.put(z, c.get(z)+1);
          } else {
            c.put(z, 1);
          }
        }
      }
      int colourrows = 0;
      for (Integer x: r.values()){
        if (x % 2 == 1){
          gold+=n;
          colourrows++;
        }
      }
      for (Integer x: c.values()){
        if (x % 2 == 1){
          gold=gold+m-(colourrows*2);
        }
      }
      System.out.println(gold);
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
