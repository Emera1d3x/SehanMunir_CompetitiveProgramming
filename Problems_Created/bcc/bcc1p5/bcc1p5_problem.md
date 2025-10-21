> *Philetairus socius*, better known as Sociable Weavers, are small, highly social birds that build communal nests in trees. <br>
> <div><img src="https://static.dmoj.ca/media/martor/406d2005-0558-46cb-8a4e-58a6f467a28a.png" alt="Sociable Weaver Nest" width="100"/></div><br>
> These birds construct their nests on the intersection of branches on trees, always seeking the company of their peers for safety and warmth.

We can model a tree as a connected graph with ~N~ nodes, numbered ~1, 2,..,N~. For each ~i\space(1\le i\le N-1)~, the ~i~-th edge connects node ~x_i~ and ~y_i~.

Each node may either hold a nest or be empty. Because of their social nature of these birds, any node that contains a nest must be adjacent to at least one other node that contains a nest.

Determine the number of ways in which the nests may be placed on the tree such that this adjacency rule is satisfied.

Since this number may be very high, output it modulo ~10^9 + 7~.

## Constraints

- All values of input are integers.
- ~1\le N\le 10^5~
- ~1\le x_i,y_i\le N~
- The given graph is a tree

## Input Specification

The first line will contain the integer ~N~.

The next ~N-1~ line will be ~2~ single spaced integers ~x_i~ and ~y_i~.


## Output Specification

Print the number of ways in which nests may be placed on the tree, modulo ~10^9 + 7~.

## Subtasks
### Subtasks 1 [20%]
~N \le 20~
### Subtasks 2 [30%]
~N \le 10^3~
### Subtasks 3 [50%]
~N \le 10^5~

## Sample Input 1
```
3
1 2
1 3
```

## Output for Sample Input 1
```
4
```

## Explanation of Output for Sample Input 1

White nodes are empty nodes and brown ones contain a nest. The 4 ways in which the tree may be configured are as follows: <br>
<div style="text-align:center"><img src="https://static.dmoj.ca/media/martor/886da182-68d0-4a83-a4ba-6b838127f956.png" alt="Possibilities" width="700"/></div>

## Sample Input 2
```
4
1 2
2 3
3 4
```

## Output for Sample Input 2
```
7
```

## Explanation of Output for Sample Input 2
Either the tree may be empty, or nodes ~[1,2]~, ~[2,3]~, ~[3,4]~, ~[1,2,3]~, ~[2,3,4]~, or ~[1,2,3,4]~ contain nests. (Total of ~7~ possibilities).
