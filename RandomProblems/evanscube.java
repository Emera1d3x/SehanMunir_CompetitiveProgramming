// https://dmoj.ca/problem/evanscube
import java.io.*;
import java.util.*;
import java.lang.*;

public class evanscube {
  static String uC;
  static String[][] u = new String[3][3];
  static String dC;
  static String[][] d = new String[3][3];
  static String fC;
  static String[][] f = new String[3][3];
  static String bC;
  static String[][] b = new String[3][3];
  static String rC;
  static String[][] r = new String[3][3];
  static String lC;
  static String[][] l = new String[3][3];
 
  public static void uTurn(int amount){
    for (int i = 0; i < amount; i++){
      String bufferCorner = u[0][0];
      String bufferEdge = u[0][1];
      u[0][0] = u[2][0];
      u[2][0] = u[2][2];
      u[2][2] = u[0][2];
      u[0][2] = bufferCorner;
      u[0][1] = u[1][0];
      u[1][0] = u[2][1];
      u[2][1] = u[1][2];
      u[1][2] = bufferEdge;
     
      bufferCorner = f[0][0];
      f[0][0] = r[0][0];
      r[0][0] = b[0][0];
      b[0][0] = l[0][0];
      l[0][0] = bufferCorner;
     
      bufferCorner = f[0][2];
      f[0][2] = r[0][2];
      r[0][2] = b[0][2];
      b[0][2] = l[0][2];
      l[0][2] = bufferCorner;
     
      bufferEdge = f[0][1];
      f[0][1] = r[0][1];
      r[0][1] = b[0][1];
      b[0][1] = l[0][1];
      l[0][1] = bufferEdge;
    }
  }
  public static void dTurn(int amount){
    for (int i = 0; i < amount; i++){
      String bufferCorner = d[0][0];
      String bufferEdge = d[0][1];
      d[0][0] = d[2][0];
      d[2][0] = d[2][2];
      d[2][2] = d[0][2];
      d[0][2] = bufferCorner;
      d[0][1] = d[1][0];
      d[1][0] = d[2][1];
      d[2][1] = d[1][2];
      d[1][2] = bufferEdge;
     
      bufferCorner = f[2][0];
      f[2][0] = l[2][0];
      l[2][0] = b[2][0];
      b[2][0] = r[2][0];
      r[2][0] = bufferCorner;
     
      bufferCorner = f[2][2];
      f[2][2] = l[2][2];
      l[2][2] = b[2][2];
      b[2][2] = r[2][2];
      r[2][2] = bufferCorner;
     
      bufferEdge = f[2][1];
      f[2][1] = l[2][1];
      l[2][1] = b[2][1];
      b[2][1] = r[2][1];
      r[2][1] = bufferEdge;
    }
  }
  public static void rTurn(int amount){
    for (int i = 0; i < amount; i++){
      String bufferCorner = r[0][0];
      String bufferEdge = r[0][1];
      r[0][0] = r[2][0];
      r[2][0] = r[2][2];
      r[2][2] = r[0][2];
      r[0][2] = bufferCorner;
      r[0][1] = r[1][0];
      r[1][0] = r[2][1];
      r[2][1] = r[1][2];
      r[1][2] = bufferEdge;
     
      bufferCorner = f[0][2];
      f[0][2] = d[0][2];
      d[0][2] = b[2][0];
      b[2][0] = u[0][2];
      u[0][2] = bufferCorner;
     
      bufferCorner = f[2][2];
      f[2][2] = d[2][2];
      d[2][2] = b[0][0];
      b[0][0] = u[2][2];
      u[2][2] = bufferCorner;
     
      bufferEdge = f[1][2];
      f[1][2] = d[1][2];
      d[1][2] = b[1][0];
      b[1][0] = u[1][2];
      u[1][2] = bufferEdge;
    }
  }
  public static void lTurn(int amount){
    for (int i = 0; i < amount; i++){
      String bufferCorner = l[0][0];
      String bufferEdge = l[0][1];
      l[0][0] = l[2][0];
      l[2][0] = l[2][2];
      l[2][2] = l[0][2];
      l[0][2] = bufferCorner;
      l[0][1] = l[1][0];
      l[1][0] = l[2][1];
      l[2][1] = l[1][2];
      l[1][2] = bufferEdge;
     
      bufferCorner = f[0][0];
      f[0][0] = u[0][0];
      u[0][0] = b[2][2];
      b[2][2] = d[0][0];
      d[0][0] = bufferCorner;
     
      bufferCorner = f[2][0];
      f[2][0] = u[2][0];
      u[2][0] = b[0][2];
      b[0][2] = d[2][0];
      d[2][0] = bufferCorner;
     
      bufferEdge = f[1][0];
      f[1][0] = u[1][0];
      u[1][0] = b[1][2];
      b[1][2] = d[1][0];
      d[1][0] = bufferEdge;
    }
  }
  public static void fTurn(int amount){
    for (int i = 0; i < amount; i++){
      String bufferCorner = f[0][0];
      String bufferEdge = f[0][1];
      f[0][0] = f[2][0];
      f[2][0] = f[2][2];
      f[2][2] = f[0][2];
      f[0][2] = bufferCorner;
      f[0][1] = f[1][0];
      f[1][0] = f[2][1];
      f[2][1] = f[1][2];
      f[1][2] = bufferEdge;
     
      bufferCorner = u[2][0];
      u[2][0] = l[2][2];
      l[2][2] = d[0][2];
      d[0][2] = r[0][0];
      r[0][0] = bufferCorner;
     
      bufferCorner = u[2][2];
      u[2][2] = l[0][2];
      l[0][2] = d[0][0];
      d[0][0] = r[2][0];
      r[2][0] = bufferCorner;
     
      bufferEdge = u[2][1];
      u[2][1] = l[1][2];
      l[1][2] = d[0][1];
      d[0][1] = r[1][0];
      r[1][0] = bufferEdge;
    }
  }
  public static void bTurn(int amount){
    for (int i = 0; i < amount; i++){
      String bufferCorner = b[0][0];
      String bufferEdge = b[0][1];
      b[0][0] = b[2][0];
      b[2][0] = b[2][2];
      b[2][2] = b[0][2];
      b[0][2] = bufferCorner;
      b[0][1] = b[1][0];
      b[1][0] = b[2][1];
      b[2][1] = b[1][2];
      b[1][2] = bufferEdge;
     
      bufferCorner = u[0][2];
      u[0][2] = r[2][2];
      r[2][2] = d[2][0];
      d[2][0] = l[0][0];
      l[0][0] = bufferCorner;
     
      bufferCorner = u[0][0];
      u[0][0] = r[0][2];
      r[0][2] = d[2][2];
      d[2][2] = l[2][0];
      l[2][0] = bufferCorner;
     
      bufferEdge = u[0][1];
      u[0][1] = r[1][2];
      r[1][2] = d[2][1];
      d[2][1] = l[1][0];
      l[1][0] = bufferEdge;
    }
  }
  public static String yesNo(){
    if (
fC.equals(f[0][0]) &&
fC.equals(f[0][1]) &&
fC.equals(f[0][2]) &&
fC.equals(f[1][0]) &&
fC.equals(f[1][2]) &&
fC.equals(f[2][0]) &&
fC.equals(f[2][1]) &&
fC.equals(f[2][2]) &&

bC.equals(b[0][0]) &&
bC.equals(b[0][1]) &&
bC.equals(b[0][2]) &&
bC.equals(b[1][0]) &&
bC.equals(b[1][2]) &&
bC.equals(b[2][0]) &&
bC.equals(b[2][1]) &&
bC.equals(b[2][2]) &&

dC.equals(d[0][0]) &&
dC.equals(d[0][1]) &&
dC.equals(d[0][2]) &&
dC.equals(d[1][0]) &&
dC.equals(d[1][2]) &&
dC.equals(d[2][0]) &&
dC.equals(d[2][1]) &&
dC.equals(d[2][2]) &&

uC.equals(u[0][0]) &&
uC.equals(u[0][1]) &&
uC.equals(u[0][2]) &&
uC.equals(u[1][0]) &&
uC.equals(u[1][2]) &&
uC.equals(u[2][0]) &&
uC.equals(u[2][1]) &&
uC.equals(u[2][2]) &&

rC.equals(r[0][0]) &&
rC.equals(r[0][1]) &&
rC.equals(r[0][2]) &&
rC.equals(r[1][0]) &&
rC.equals(r[1][2]) &&
rC.equals(r[2][0]) &&
rC.equals(r[2][1]) &&
rC.equals(r[2][2]) &&

lC.equals(l[0][0]) &&
lC.equals(l[0][1]) &&
lC.equals(l[0][2]) &&
lC.equals(l[1][0]) &&
lC.equals(l[1][2]) &&
lC.equals(l[2][0]) &&
lC.equals(l[2][1]) &&
lC.equals(l[2][2])
        ){
          return "Solved!";
        }
        return "Boo!";
  }
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    evanscube z = new evanscube();
    String reader = s.next();
    f[0][0] = String.valueOf(reader.charAt(0));
    f[0][1] = String.valueOf(reader.charAt(1));
    f[0][2] = String.valueOf(reader.charAt(2));
    reader = s.next();
    f[1][0] = String.valueOf(reader.charAt(0));
    f[1][1] = String.valueOf(reader.charAt(1));
    fC = f[1][1];
    f[1][2] = String.valueOf(reader.charAt(2));
    reader = s.next();
    f[2][0] = String.valueOf(reader.charAt(0));
    f[2][1] = String.valueOf(reader.charAt(1));
    f[2][2] = String.valueOf(reader.charAt(2));
   
    reader = s.next();
    l[0][0] = String.valueOf(reader.charAt(0));
    l[0][1] = String.valueOf(reader.charAt(1));
    l[0][2] = String.valueOf(reader.charAt(2));
    reader = s.next();
    l[1][0] = String.valueOf(reader.charAt(0));
    l[1][1] = String.valueOf(reader.charAt(1));
    lC = l[1][1];
    l[1][2] = String.valueOf(reader.charAt(2));
    reader = s.next();
    l[2][0] = String.valueOf(reader.charAt(0));
    l[2][1] = String.valueOf(reader.charAt(1));
    l[2][2] = String.valueOf(reader.charAt(2));
   
    reader = s.next();
    b[0][0] = String.valueOf(reader.charAt(0));
    b[0][1] = String.valueOf(reader.charAt(1));
    b[0][2] = String.valueOf(reader.charAt(2));
    reader = s.next();
    b[1][0] = String.valueOf(reader.charAt(0));
    b[1][1] = String.valueOf(reader.charAt(1));
    bC = b[1][1];
    b[1][2] = String.valueOf(reader.charAt(2));
    reader = s.next();
    b[2][0] = String.valueOf(reader.charAt(0));
    b[2][1] = String.valueOf(reader.charAt(1));
    b[2][2] = String.valueOf(reader.charAt(2));
   
    reader = s.next();
    r[0][0] = String.valueOf(reader.charAt(0));
    r[0][1] = String.valueOf(reader.charAt(1));
    r[0][2] = String.valueOf(reader.charAt(2));
    reader = s.next();
    r[1][0] = String.valueOf(reader.charAt(0));
    r[1][1] = String.valueOf(reader.charAt(1));
    rC = r[1][1];
    r[1][2] = String.valueOf(reader.charAt(2));
    reader = s.next();
    r[2][0] = String.valueOf(reader.charAt(0));
    r[2][1] = String.valueOf(reader.charAt(1));
    r[2][2] = String.valueOf(reader.charAt(2));
   
    reader = s.next();
    d[0][0] = String.valueOf(reader.charAt(0));
    d[0][1] = String.valueOf(reader.charAt(1));
    d[0][2] = String.valueOf(reader.charAt(2));
    reader = s.next();
    d[1][0] = String.valueOf(reader.charAt(0));
    d[1][1] = String.valueOf(reader.charAt(1));
    dC = d[1][1];
    d[1][2] = String.valueOf(reader.charAt(2));
    reader = s.next();
    d[2][0] = String.valueOf(reader.charAt(0));
    d[2][1] = String.valueOf(reader.charAt(1));
    d[2][2] = String.valueOf(reader.charAt(2));
   
    reader = s.next();
    u[2][2] = String.valueOf(reader.charAt(0));
    u[2][1] = String.valueOf(reader.charAt(1));
    u[2][0] = String.valueOf(reader.charAt(2));
    reader = s.next();
    u[1][2] = String.valueOf(reader.charAt(0));
    u[1][1] = String.valueOf(reader.charAt(1));
    uC = u[1][1];
    u[1][0] = String.valueOf(reader.charAt(2));
    reader = s.next();
    u[0][2] = String.valueOf(reader.charAt(0));
    u[0][1] = String.valueOf(reader.charAt(1));
    u[0][0] = String.valueOf(reader.charAt(2));
    int queries = s.nextInt();
    for (int i = 0; i < queries; i++){
      String cur = s.next();
      int amount;
      if (cur.charAt(1)=='C'){
        amount = 1;
      } else {
        amount = 3;
      }
      if (cur.charAt(0)=='1'){
        z.fTurn(amount);
      } else if (cur.charAt(0)=='2'){
        z.lTurn(amount);
      } else if (cur.charAt(0)=='3'){
        z.bTurn(amount);
      } else if (cur.charAt(0)=='4'){
        z.rTurn(amount);
      } else if (cur.charAt(0)=='5'){
        z.dTurn(amount);
      } else if (cur.charAt(0)=='6'){
        z.uTurn(amount);
      }
    }
    System.out.println(z.yesNo());
  }
}
