// https://dmoj.ca/problem/cco16p4
import java.io.*;
import java.util.*;
import java.lang.*;

public class cco16p4 {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static StringTokenizer st;
  public static void main(String[] args) throws IOException {
      cco16p4 s = new cco16p4();
      HashMap<String, Integer> stuff = new HashMap<>();
      int n = s.readInt();
      int g = s.readInt();
      char[][] curGrid = new char[n][n];
      String code = "";
      int comb = 0;
      for (int z = 0; z < g; z++){
        for (int i = 0; i < n; i++){
          String cur = s.readLine();
          for (int j = 0; j < n; j++){
            curGrid[i][j] = cur.charAt(j);
          }
        }
        for (int i = 0; i < n-1; i++){
          for (int j = 0; j < n-1; j++){
            if (curGrid[i][j]=='W'){
              curGrid[i][j]='R';
              if (curGrid[i][j+1]=='R'){
                curGrid[i][j+1]='W';
              } else {
                curGrid[i][j+1]='R';
              }
              if (curGrid[i+1][j]=='R'){
                curGrid[i+1][j]='W';
              } else {
                curGrid[i+1][j]='R';
              }
              if (curGrid[i+1][j+1]=='R'){
                curGrid[i+1][j+1]='W';
              } else {
                curGrid[i+1][j+1]='R';
              }
            }
          }
        }
        for (int i = 0; i < n; i++){
          code = code + Character.toString(curGrid[i][n-1]);
        }
        for (int i = n-2; i >= 0; i--){
          code = code + Character.toString(curGrid[n-1][i]);
        }
        if (stuff.containsKey(code)){
          stuff.put(code,stuff.get(code)+1);
        } else {
          stuff.put(code, 1);
        }
        code = "";
      }
      for (Map.Entry<String, Integer> entry : stuff.entrySet()) {
        comb += (entry.getValue())*((entry.getValue())-1)/2;
      }
      System.out.println(comb);
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
