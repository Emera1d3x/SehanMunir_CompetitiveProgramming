# LCC '25 Contest 3 J2 - Beautiful Snowflakes

Bob is a **snowflakiologist** - a rare kind of scientist who studies and loves snowflakes. He spends his winters catching snowflakes falling on black velvet so he can snap microscopic images of their beautiful patterns.

As a gift, Johnny gives Bob a snowflake with ~N~ sides, where the radius of side ~i~ is ~R_i~. Bob appreciates the gift, but he feels something is off.

Bob finds a snowflake perfect if it has at most ~R~ different radii. To fix Johnny's gift he can trim any side to reduce it's radius to any smaller radius he desires. Each trim counts as one cut.

Bob realizes that he can't just waste hours trimming a snowflake like a psycho, so he wants to finish quickly and asks you this:

Given the initial radii of the snowflake's sides, determine the minimum number of cuts that Bob must make such that the snowflake is perfect in his eyes.


## Input Specification

The first line will contain the two single-spaced integers ~N~ and ~R~ - the number of sides and the number of distinct radii that can exist such that Bob finds the snowflake perfect.

The next line will contain ~N~ single spaced integers ~R_i~ - describing the radius of side ~i~.

## Output Specification

On a single line output the minimum number of cuts Bob must make so the snowflake becomes perfect.

## Constraints

~1\le N, R, R_i \le 10^{5}~

### Subtasks 1 [20%]
~1\le N, R, R_i \le 10^{2}~

### Subtasks 2 [80%]
No additional constraints.

## Sample Input 1
```
6 2
5 3 6 7 5 6
```
## Output for Sample Input 1
```
3
```
## Explanation of Output for Sample Input 1
Bob can trim side ~1~ from radius ~5~ to ~3~, side ~4~ from radius ~7~ to ~6~, and side ~5~ from radius ~5~ to ~3~. This results in ~3~ cuts, and makes the perfect snowflake. The snowflake has ~2~ distinct radii, ~3~ and ~6~.

## Sample Input 2
```
5 3
8 4 8 8 8
```
## Output for Sample Input 2
```
0
```
## Explanation of Output for Sample Input 2
The snowflake given is already perfect.
