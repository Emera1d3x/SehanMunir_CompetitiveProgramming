// https://dmoj.ca/problem/dpp
import java.io.*;
import java.util.*;
import java.lang.*;

public class dpp {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static HashMap<Integer, ArrayList<Integer>> adjList = new HashMap<>();
    static long[][] m;
    public static void main(String[] args) throws IOException {
        dpp s = new dpp();
        int n = s.readInt();
        m = new long[n + 1][2];
        for (int i = 0; i <= n; i++) {
            m[i][0] = -1;
            m[i][1] = -1;
        }
        for (int i = 0; i < n - 1; i++) {
            int a = s.readInt();
            int b = s.readInt();
            adjList.computeIfAbsent(a, k -> new ArrayList<>()).add(b);
            adjList.computeIfAbsent(b, k -> new ArrayList<>()).add(a);
        }
        if (n == 1){
          System.out.println("2");
        } else {
          long ans = s.dp(0, 1, true)+s.dp(0, 1, false);
          System.out.println(ans % 1000000007);
        }
    }

    public static long dp(int prev, int node, boolean colour) {
        long combinations = 0;
        if (colour){
            if (m[node][0] != -1) {
                return m[node][0];
            }
        } else {
            if (m[node][1] != -1) {
                return m[node][1];
            }
        }
        if (node == 1 || adjList.get(node).size() != 1) {
            if (colour) {
                combinations = 1;
                for (int i = 0; i < adjList.get(node).size(); i++) {
                    if (adjList.get(node).get(i)!=prev){
                        combinations = combinations*(dp(node, adjList.get(node).get(i), true)% 1000000007 + dp(node, adjList.get(node).get(i), false)% 1000000007)% 1000000007;
                    }
                }
                m[node][0] = combinations;
                return combinations;
            } else {
                combinations = 1;
                for (int i = 0; i < adjList.get(node).size(); i++) {
                    if (adjList.get(node).get(i)!=prev){
                        combinations = combinations*(dp(node, adjList.get(node).get(i), true)% 1000000007)% 1000000007;
                    }
                }
                m[node][1] = combinations;
                return combinations;
            }
        } else {
          m[node][0] = 1;
          m[node][1] = 1;
          return 1;
        }
    }

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }

    static long readLong() throws IOException {
        return Long.parseLong(next());
    }

    static int readInt() throws IOException {
        return Integer.parseInt(next());
    }

    static double readDouble() throws IOException {
        return Double.parseDouble(next());
    }

    static char readCharacter() throws IOException {
        return next().charAt(0);
    }

    static String readLine() throws IOException {
        return br.readLine().trim();
    }
}
