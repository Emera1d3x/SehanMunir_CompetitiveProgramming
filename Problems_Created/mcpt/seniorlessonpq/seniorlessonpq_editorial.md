## Problem Statement Simplified
Essentially at any given moment you have a set of numbers. Queries will either make you remove a maximum number (there may be multiples), output the maximum number, or add another number to the set.
## Solution
In order to solve this problem, you must use a sorted structure.
Due to time constraints, insertions should take approximately ~\mathcal{O}(log(N))~, deletions should take at least ~\mathcal{O}(log(N))~, and getting the maximum should be near-instant, around ~\mathcal{O}(1)~.

A priority queue, balanced binary search tree, or multiset can all be used to achieve these requirements efficiently.

**Time Complexity:** ~\mathcal{O}(Q \cdot log(N))~
