// https://dmoj.ca/problem/ccc05j5
import java.io.*;
import java.awt.*;
import java.util.*;
import java.lang.*;

public class ccc05j5 {
    public static String yap (String inQuestion){
        int length = inQuestion.length();
        boolean surfaceLevelCheck = true;
        int BSchecker = 0;
        for (int i = 0; i < length; i++){
            if (inQuestion.charAt(i)=='B'){
                BSchecker++;
            } else if (inQuestion.charAt(i)=='S'){
                BSchecker--;
            } else if (inQuestion.charAt(i)!='A'&&inQuestion.charAt(i)!='N'){
                surfaceLevelCheck = false;
                break;
            }
            if (BSchecker<0){
                surfaceLevelCheck = false;
                break;
            }
        }
        if (surfaceLevelCheck==false){
            return "NO";
        }
        int iterations = 0;
        while (iterations!=1000){
            iterations++;
            inQuestion = inQuestion.replace("ANA", "A");
            inQuestion = inQuestion.replace("BAS","A");
        }
        if (inQuestion.equals("A")){
            return "YES";
        } else {
            return "NO";
        }
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        while (true){
            String checker = s.nextLine();
            if (!checker.equals("X")){
                System.out.println(yap(checker));
            } else {
                break;
            }
        }
    }
}
