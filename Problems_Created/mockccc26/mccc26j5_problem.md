Problem Link: https://mcpt.ca/problem/mccc26j5
## Mock CCC '26 J5 - Crow Clash
### Mock Canadian Computing Competition: 2026 Junior #5

Researcher Seagull Man is determined to prove, once and for all, that crows are not as intelligent as people claim to be. As part of his highly questionable research, he looks up into the sky and imagines it as a massive 2D grid.

On this grid, Seagull Man observes ~N~ crows, where the ~i^\text{th}~ crow is initially at the **integer** coordinates ~(x_i, y_i)~. The ~i^\text{th}~ crow is flying in one of four directions ~d_i~, and it continues forever in that direction at a constant speed of ~1~ unit per second. The possible directions are:

- `N`: North, where in one second the crow moves to the position ~(x_i, y_i+1)~
- `S`: South, where in one second the crow moves to the position ~(x_i, y_i-1)~
- `E`: East, where in one second the crow moves to the position ~(x_i+1, y_i)~
- `W`: West, where in one second the crow moves to the position ~(x_i-1, y_i)~

Seagull Man defines a clash as the moment when a **pair** of crows occupy the exact same grid coordinate at the exact same time. The crows, being blissfully unaware of Seagull Man's research, do not change direction or behavior after a clash and simply continue flying as if nothing happened.

To strengthen his paper, Seagull Man wants to know: how many total clashes will occur among all the crows?

Given the number of crows, their starting positions, and their directions of movement, determine the total number of clashes that occur over all time.

## Input Specification

The first line contains a single integer ~N~, the number of crows.

The next line ~N~ lines will contain the character ~d_i~, and integers ~x_i~ and ~y_i~, representing the direction of movement and coordinates of the ~i^text{th}~ crow. It is guaranteed that every crow occupies a distinct position initially.

The following table shows how the available 15 marks are distributed.

<table class="table" style="width:auto;">
<thead>
<tr>
  <th>Marks Awarded</th>
  <th>Bounds on ~N~</th>
  <th>Bounds on ~x_i~ and ~y_i~</th>
  <th>Additional Constraints</th>
</tr>
</thead>
<tbody>
<tr>
  <td>~1~ marks</td>
  <td>~2 \le N \le 10^{3}~</td>
  <td>~-10^{3} \le x_i, y_i \le 10^{3}~</td>
  <td>~d_i~ = `E` or `W` <br/>(All crows are flying either east or west) </td>
</tr>
<tr>
  <td>~2~ marks</td>
  <td>~2 \le N \le 10^{5}~</td>
  <td>~-10^{9} \le x_i, y_i \le 10^{9}~</td>
  <td>~d_i~ = `E` or `W` <br/>(All crows are flying either east or west) </td>
</tr>
<tr>
  <td>~3~ marks</td>
  <td>~2 \le N \le 10^{3}~</td>
  <td>~-10^{3} \le x_i, y_i \le 10^{3}~</td>
  <td>None</td>
</tr>

<tr>
  <td>~9~ marks</td>
  <td>~2 \le N \le 10^{5}~</td>
  <td>~-10^{9} \le x_i, y_i \le 10^{9}~</td>
  <td>None</td>
</tr>
</tbody>
</table>

## Output Specification

Output the number of clashes that will occur.

Please note that the answer is not guaranteed to fit in a ~32~-bit integer.

## Sample Input 1
```
2
W 1 1
E -2 1
```

## Output for Sample Input 1
```
1
```

## Explanation of Output for Sample Input 1

Given that the first crow is red and the second crow is green, here is what the initial setup looks like: 
<div style="text-align: center"><img src="https://mcpt.ca/media/martor/d38ef2c9-9ebc-4362-912a-4a28f3abe7e6.png" alt="Example 1 Initial" width="350"/></div>

At time equals ~1.5~ seconds, the two crows will clash at ~(-0.5, 1)~, thus resulting in a total of ~1~ clash. The following diagrams shows the clashes:

<div style="text-align: center"><img src="https://mcpt.ca/media/martor/4b050630-3fbf-4cf6-be0c-133d454b5549.png" alt="Example 1 Clash 1" width="350"/></div>

## Sample Input 2
```
3
E -3 1
N 0 -2
S 0 3 
```

## Output for Sample Input 2
```
2
```

## Explanation of Output for Sample Input 2

Given that the first crow is red, the second crow is green, and the third crow is blue, here is what the initial setup looks like: 
<div style="text-align: center"><img src="https://mcpt.ca/media/martor/b19a6041-1df8-4170-8e5e-5779bfb3f6d9.png" alt="Example 2 Initial" width="350"/></div>

When time equals ~2~ seconds, crow ~2~ and crow ~3~ clash at ~(0,0)~. When time equals ~3~ seconds, crow ~1~ and crow ~2~ clash at ~(0,1)~. Therefore there will be ~2~ clashes in total. The following diagrams shows the clashes:

<div style="text-align: center">
    <img src="https://mcpt.ca/media/martor/f96aaf5a-a671-4252-9818-5117e262337f.png" alt="Example 2 Clash 1" width="350"/>
    <img src="https://mcpt.ca/media/martor/bd37bac3-e124-4d0c-8aaf-b16695aeb977.png" alt="Example 2 Clash 2" width="350"/>
</div>

## Sample Input 3
```
3
E -1 0
N 0 -1
S 0 1 
```

## Output for Sample Input 3
```
3
```

## Explanation of Output for Sample Input 2

All three crows collide at ~(0,0)~. That means there are ~3~ clashes (pairs of crows colliding). The clashes are between crow ~1~ & crow ~2~, crow ~2~ & crow ~3~, and crow ~1~ & crow ~3~.
