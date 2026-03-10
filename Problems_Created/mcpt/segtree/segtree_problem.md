### A Segment Tree Problem

Given an integer array ~A~ of size ~N~, support ~Q~ queries of the following types:

1. `MAX l r` Find the value of the largest element in the array from index ~l~ to index ~r~.
2. `UPD i x` Update the element at index ~i~ to value ~x~.


## Input Specification

The first line contains ~2~ single spaced integers ~N~ and ~Q~, representing the size of the array and the number of queries.

The second line contains ~N~ single spaced integers, ~A_{1}, A_{2}, ..., A_{N}~, the initial elements of ~A~.

The next ~Q~ lines are of one of two forms:

1. String `MAX` and integers ~l~ and ~r~, single spaced.
2. String `UPD` and integers ~i~ and ~x~, single spaced.

## Output Specification

For each query of form ~1~, output the maximum value in the given range on a new line.

## Constraints

~1\le N, Q \le 2\times10^{5}~

~1\le l\le r \le N~

~1\le i \le N~

~1\le A_{i}, x \le 10^{9}~

## Sample Input 1
```
5 4
6 7 4 2 0
MAX 2 4
MAX 2 3
UPD 2 1
MAX 1 2
```
## Output for Sample Input 1
```
7
7
6
```
