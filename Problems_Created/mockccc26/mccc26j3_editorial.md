Rendered Editorial Link: https://mcpt.ca/problem/mccc26j3/editorial
#### Mock CCC '26 J3 - Holy Moly's Wall
---
## Subtask 1

Constraints: ~1 \le N, K \le 10~ and ~-100 \le X_i, Y_i \le 100~

With very few number of holes and small coordinate bounds, this subtask is intended to award pretty much any correct solution, even if it is quite inefficient.

You can completely brute force this subtask any way you would like.

## Subtask 2

Constraints: ~1 \le N, K \le 10^{5}~ and ~-10^{3} \le X_i, Y_i \le 10^{3}~

Since square frames are centered at ~(0,0)~ and axis-aligned (one pair of sides are parallel with the x-axis, and another pair of sides is parallel with the y-axis), let **half** of the side-length of a square frame be ~S~. Then the frame's perimeter is defined by it's:

Top Side: ~\{y=+S, -S \le x \le S\}~

Bottom Side: ~\{y=-S, -S \le x \le S\}~

Left Side: ~\{x=-S, -S \le y \le S\}~

Right Side: ~\{x=+S, -S \le y \le S\}~

If any holes lie at coordinates that satisfy with one of these sides, it lies on the frame's perimeter of when the frame has a side length of ~2S~.  

We can begin our implementation by storing the position of holes in a 2D boolean array that is ~2000\times2000~. All coordinates are added by ~1000~ to account for negative positions (most languages don't allow for negative indices).
Then, we can simply try all possible values of ~S~ within the range ~1~ to ~1000~ to see if a frame of size ~2S~ has enough holes.
To do this we loop over all sides and increment a count when encountering a hole.
If the number of holes on all sides (the perimeter) is ~\ge K~, we know it is valid.
Example of implementation is shown below:
```cpp
for (int s = 1; s <= 1000; s++) { // For every frame half side length
    int count = 0; // Number of holes lying on the specific frame size's perimeter
    for (int x = -s; x <= s; x++) { // Check top side for holes
        if (holes[x+1000][s+1000]) {
            count++;
        }
    }
    for (int x = -s; x <= s; x++) { // Check bottom side for holes
        if (holes[x+1000][-s+1000]) {
            count++;
        }
    }
    for (int y = -s+1; y <= s-1; y++) { // Check left side for holes
        if (holes[-s+1000][y+1000]) {
            count++;
        }
    }
    for (int y = -s+1; y <= s-1; y++) { // Check right side for holes
         if (holes[s+1000][y+1000]) {
            count++;
         }
    }
    if (count >= k) {ans++;} // If there are enough holes on the perimeter, this is a valid frame size that can be used
}
```
Be careful to not double count holes in the corners.

Let ~R~ be the range that coordinates can span. 

Time complexity: ~\mathcal{O}(N + R^2)~

Space Complexity: ~\mathcal{O}(R^2)~

## Subtask 3 and Full Solution

Constraints: ~1 \le N, K \le 10^{5}~ and ~-10^{5} \le X_i, Y_i \le 10^{5}~

A solution using subtask 2's technique will not pass subtask 3. A 2D array can not hold the massive range and will MLE or segfault. Even if you use a map, checking every coordinate on each frame size's perimeter explicitly is too slow. Therefore, we need a more mathematical observation.

We first observe that a point ~(x,y)~ lies on the perimeter of side length ~2S~ if and only if ~\max(|x|, |y|) = S~. The full mathematical proof using the perimeter definitions stated in subtask 2 solution is left as an exercise to the reader, but the observation is quite intuitive.

So instead of iterating over all frame sizes (all ~S~) and checking points along the perimeter, we can reverse this logic. For every hole ~(x,y)~, compute ~S~, and maintain a frequency array ``count[S]`` that counts how many holes lie on the perimeter of the square with half side length ~S~. After processing all ~N~ holes, iterate over each ~S~ and merely check if ``count[S] >= K``.

We don't need to explicitly construct the grid or scan any perimeters.

Let ~R~ be the range that coordinates can span. Since finding what frame size a hole belongs to is as simple as ~\max(|x|, |y|) = S~, each point contributes to ~\mathcal{O}(1)~ time. Only at the end do we go over all ~S~ within the count array to check if its valid. Therefore:

Time complexity: ~\mathcal{O}(N + R)~

Space Complexity: ~\mathcal{O}(R)~
