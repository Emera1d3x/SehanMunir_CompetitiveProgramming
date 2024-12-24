// https://dmoj.ca/problem/fur5
import java.io.*;import java.util.*;import java.lang.*;public class fur5 {static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));static StringTokenizer st;
public static void main(String[] args) throws IOException {fur5 s = new fur5();int n = s.readInt();
      Stack<Integer> a = new Stack<>();Stack<Integer> b = new Stack<>();Stack<Integer> c = new Stack<>();
      int aL = n;int bL = 0;int cL = 0;
      for (int i = n; i >= 1; i--){a.push(i);}
      int step = 1;int tempA = 0;int tempB = 0;int tempC = 0;
      if(n%2==0){
      while (true){
        if (step%3==1){
          if (aL==0){a.push(b.pop());aL++;bL--;System.out.println("BA");
          } else if (bL==0){b.push(a.pop());bL++;aL--;System.out.println("AB");
          } else {tempA = a.pop();tempB = b.pop();
            if (tempA>tempB){a.push(tempA);a.push(tempB);aL++;bL--;
              System.out.println("BA");}
            else {b.push(tempB);b.push(tempA);bL++;aL--;
              System.out.println("AB");}
          }
        } else if (step%3==2){
          if (aL==0){a.push(c.pop());aL++;cL--;System.out.println("CA");
          } else if (cL==0){c.push(a.pop());cL++;aL--;System.out.println("AC");
          } else {tempA = a.pop();tempC = c.pop();
            if (tempA>tempC){a.push(tempA);a.push(tempC);aL++;cL--;
              System.out.println("CA");}
            else {c.push(tempC);c.push(tempA);cL++;aL--;
              System.out.println("AC");}
          }
        } else if (step%3==0){
          if (bL==0){b.push(c.pop());bL++;cL--;System.out.println("CB");
          } else if (cL==0){c.push(b.pop());cL++;bL--;System.out.println("BC");
          } else {tempB = b.pop();tempC = c.pop();
            if (tempB>tempC){b.push(tempB);b.push(tempC);bL++;cL--;
              System.out.println("CB");}
            else {c.push(tempC);c.push(tempB);cL++;bL--;
              System.out.println("BC");}
          }
        }
        step++;if (cL == n){break;}
      }} else if(n%2==1){
      while (true){
        if (step%3==1){
          if (aL==0){a.push(b.pop());aL++;bL--;System.out.println("CA");
          } else if (bL==0){b.push(a.pop());bL++;aL--;System.out.println("AC");
          } else {tempA = a.pop();tempB = b.pop();
            if (tempA>tempB){a.push(tempA);a.push(tempB);aL++;bL--;
              System.out.println("CA");}
            else {b.push(tempB);b.push(tempA);bL++;aL--;
              System.out.println("AC");}
          }
        } else if (step%3==2){
          if (aL==0){a.push(c.pop());aL++;cL--;System.out.println("BA");
          } else if (cL==0){c.push(a.pop());cL++;aL--;System.out.println("AB");
          } else {tempA = a.pop();tempC = c.pop();
            if (tempA>tempC){a.push(tempA);a.push(tempC);aL++;cL--;
              System.out.println("BA");}
            else {c.push(tempC);c.push(tempA);cL++;aL--;
              System.out.println("AB");}
          }
        } else if (step%3==0){
          if (bL==0){b.push(c.pop());bL++;cL--;System.out.println("BC");
          } else if (cL==0){c.push(b.pop());cL++;bL--;System.out.println("CB");
          } else {tempB = b.pop();tempC = c.pop();
            if (tempB>tempC){b.push(tempB);b.push(tempC);bL++;cL--;
              System.out.println("BC");}
            else {c.push(tempC);c.push(tempB);cL++;bL--;
              System.out.println("CB");}
          }
        }
        step++;if (bL == n){break;}
      }
      }
}
static String next() throws IOException {while (st == null || !st.hasMoreTokens())st = new StringTokenizer(br.readLine().trim());return st.nextToken();}
static long readLong() throws IOException {return Long.parseLong(next());}
static int readInt() throws IOException {return Integer.parseInt(next());}
static double readDouble() throws IOException {return Double.parseDouble(next());}
static char readCharacter() throws IOException {return next().charAt(0);}
static String readLine() throws IOException {return br.readLine().trim();}}
