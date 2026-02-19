Rendered Editorial Link: https://mcpt.ca/problem/mccc26j5/editorial
#### Mock CCC '26 J5 - Crow Clash
---
For **Subtask 1** and **Subtask 2**, crows only move either east or west.

Notice that since all crows only move horizontally (along the ~x~ axis), their ~y~-coordinate never changes. Therefore, two crows (~i~ and ~j~) only clash if and only if they start on the same ~y~-coordinate (~i_y=j_y~), one is moving east (~i_d~=`E`) and the other is moving west (~j_d~=`W`), and the one moving east is initially west of the crow moving west (~i_x\ltj_x~).

## Subtask 1

**Pair Check Technique**

For every pair of crows, check whether the above requirements hold. If so, increment the number of clashes.

Time Complexity: ~\mathcal{O}(N^2)~ and Memory Complexity: ~\mathcal{O}(N)~

**Key Alternate Technique Applied to a Grid**

Since coordinate bounds are small, we can create a 2D grid (adjusting numbers for negative coordinates of course) and place crows in their respective initial positions along with the direction they are flying. 

Key Technique: For each row ~y~, traverse from left to right in the grid and keep a counter of how many `E` crows have appeared so far in the row. When encountering a `W` crow in the same ~y~, add the number of previously seen `E` crows to the number of clashes. This works because every earlier east-moving crow will eventually collide with this west-moving crow (the east-moving crows satisfy the above).

Where ~R~ is the coordinate range.

Time Complexity: ~\mathcal{O}(R^2)~ and Memory Complexity: ~\mathcal{O}(R^2)~

## Subtask 2

Now the number of crows is too large, so checking each crow pair ~\mathcal{O}(N^2)~ would TLE. Additionally the range of coordinates is also far too large to store and would MLE.

However, the key technique that was described in subtask 1 can be applied here with some adjustments.
Our new approach to account for the massive coordinate range (lets call ~R~) is to:
1. Store all crows in a 1D array. ~\mathcal{O}(N)~ space.
2. Sort them (~\mathcal{O}(N\,\text{log}\,N)~ time) by: 
    1. primarily ~y~ (increasing)
    2. secondarily ~x~ (increasing)
3. Process crows row by row (same ~y~) just like described above (traversing left to right, maintaining counter for east-moving crows and incrementing the answer by the counter when encountering a west-moving crow). ~\mathcal{O}(N)~ time.

This eliminates checking for every single pair directly, and doesn't require a massive 2D array. Thus:

Time Complexity: ~\mathcal{O}(N\,\text{log}\,N)~ and Memory Complexity: ~\mathcal{O}(N)~

---

For **Subtask 3** and **Subtask 4**, crows move in all cardinal directions.

## Subtask 3

For every pair of crows, check whether they clash. If so, increment the number of clashes.

Given direction ~d~, a crow's position at time ~t~ seconds is:

- `N`: ~(x, y+t)~
- `S`: ~(x, y-t)~
- `E`: ~(x+t, y)~
- `W`: ~(x-t, y)~

So if we're checking if crows ~i~ and ~j~ clash, we check if there exists a time ~t \ge 0~ that satisfies the equations ~x_i(t) = x_j(t)~ and ~y_i(t) = y_j(t)~

The actual check for ~t~ is ~\mathcal{O}(1)~. Since ~N \le 1000~, checking all pairs is feasible.

Time Complexity: ~\mathcal{O}(N^2)~ and Memory Complexity: ~\mathcal{O}(N)~

## Subtask 4

As with subtask 2, the number of crows is too large, so checking each crow pair ~\mathcal{O}(N^2)~ would TLE and the range of coordinates is also far too large to store and would MLE.

Our key observation is that clashes occur in specific geometric configurations.

**Horizontal Clashes (`EW`)**

Occurs when same ~y~ and east-moving crow is left of west-moving crow. Group birds by ~y~, sort by ~x~, apply the counting technique. We've already gone over this for subtasks 1 and 2.

**Vertical Clashes (`NS`)**

The technique for horizonal clashes can be applied to vertical ones, just rotated 90 degrees.Occurs when same ~x~ and north-moving crow is south of south-moving crow. Group birds by ~x~, sort by ~y~, and apply the counting technique.

**Diagonal Clashes (`NE`, `NW`, `SE`, `SW`)**

We notice that a clash between a horizontal-moving crow (`E` or `W`) and a vertical-moving crow (`N` or `S`) happens only when they lie on the same diagonal and are facing toward each other in a compatible direction. This works because;
- All crows move at the same speed
- For two crows ~i~ and ~j~ to reach the same point at the same time, their starting positions must satisfy either ~x_i+y_i=x_j+y_j=C~ or ~x_i-y_i=x_j-y_j=C~

We handle these exactly like horizontal and vertical clashes, but grouped by diagonals instead. When grouping by ~x+y~ (diagonal family 1), if you sort them by increasing ~x~, when traversing from left to right, when encountering a `N` crow it clashes with all previous `E` crows and when encountering a `W` crow it clashes with all previous `S` crows. Then grouping by ~x-y~ (diagonal family 2), if you sort them by increasing ~x~, when traversing from left to right, when encountering a `S` crow it clashes with all previous `E` crows and when encountering a `W` crow it clashes with all previous `N` crows. 

By applying adding up the number of clashes that exists using the three checks (horizontal, vertical, and diagonal), we get our answer.


Time Complexity: ~\mathcal{O}(N\,\text{log}\,N)~ and Memory Complexity: ~\mathcal{O}(N)~
