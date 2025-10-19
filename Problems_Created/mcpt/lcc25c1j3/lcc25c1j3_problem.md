### Candyman

Candyman, president of MCPT (Mackenzie Candy Producing Team), wants to impress the CCC (Candy Considering Competition) by sending the organizers the **second** sweetest candy the team has produced. (The sweetest candy is reserved for the cookie monster).

The team has made ~N~ candies, each with a certain sweetness level. These candies are stored in boxes labeled from ~1~ to ~N~. You are given an array of integers, where the ~i^{\text th}~ element represents ~S_i~, the sweetness of the candy in the box. 

Your task is to determine the box number of the second sweetest candy.

It is guaranteed that the sweetness of each candy is different (no two candies are made the same).

## Input Specification

The first line will contain one integer ~N\;(1 \le N \le 10^5)~.

The second line will contain ~N~ spaced integers ~S_i\;(1 \le S_i \le 2\times10^5)~, representing the sweetness of the candies.


## Output Specification

Output the box number of the second sweetest candy.

## Subtasks
### Subtasks 1 [20%]
~N \le 10^2~
### Subtasks 2 [30%]
~N \le 10^3~
### Subtasks 3 [50%]
~N \le 10^5~
## Sample Input 1
```
6
9 2 6 7 3 12
```

## Output for Sample Input 1
```
1
```

## Explanation of Output for Sample Input 1

At box number 1, the candy sweetness is the second greatest.

## Sample Input 2
```
15
21 72 38 44 67 60 35 78 90 97 86 11 1 5 102
```

## Output for Sample Input 2
```
10
```
