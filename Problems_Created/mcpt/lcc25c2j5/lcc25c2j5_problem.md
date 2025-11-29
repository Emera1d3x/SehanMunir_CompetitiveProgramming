# LCC '25 Contest 2 J5 - Running Roosters
Farmer Eric has a particularly mischievous rooster that has decided to cause trouble again.

He keeps his animals inside a large rectangular enclosure, fenced into an ~N~ by ~M~ arrangement of smaller pens (~N~ rows, ~M~ columns). Each pen has gates connecting it to its neighboring pens in all eight directions: north, south, east, west, as well as northeast, northwest, southeast, and southwest. In this enclosure lives Farmer Eric's most troublesome rooster, who has once again slipped out of reach and is darting around causing chaos.

At the start of the chase, the rooster is located in a specific pen at row ~A_r~ and column ~A_c~, and Farmer Eric is standing at row ~B_r~ and column ~B_c~. They may move through a single gate into any one of the eight adjacent pens if they would like to.

The chase proceeds in rounds. In a single round, the rooster moves first and may move into one adjacent pen. Farmer Eric then takes his move; because he is quicker, he may move through up to two adjacent pens in the same round, one step at a time, also using any of the eight directions.

Both the rooster and Farmer Eric act optimally. The rooster tries to prolong the chase for as long as possible, while Farmer Eric does everything he can to catch the rooster as quickly as possible. Farmer Eric succeeds on the round in which he reaches the same pen as the rooster.

Given their starting positions and assuming both play perfectly, determine the exact round at which Farmer Eric will inevitably catch the rooster.

## Input Specification

On a single line there will be ~2~ single spaced integers ~N~, and ~M~, representing number of rows and columns of pens.

The next line will contain ~2~ single spaced integers ~A_r~, and ~A_c~, representing the exact pen the rooster is in initially.

The final line will contain ~2~ single spaced integers ~B_r~, and ~B_c~, representing the exact pen Farmer Eric is in initially.

## Output Specification

On a single line, output the round when Farmer Eric catches the rooster.

## Constraints

~1\le N, M\le 10^{8}~
 
~1\le A_r, B_r\le N~

~1\le A_c, B_c\le M~

### Subtasks 1 [10%]
~1\le N, M \le 10~

### Subtasks 2 [20%]
~1\le N, M \le 100~

### Subtasks 3 [70%]
No additional constraints.

## Sample Input 1
```
6 7
2 5
1 7
```
## Output for Sample Input 1
```
2
```
## Explanation of Output for Sample Input 1
Given the rooster is in the red pen and the Farmer Eric is in the green pen, here is an image showing what the initial setup looks like:

<div><img src="https://mcpt.ca/media/martor/029be358-5fcd-4ed9-b05e-692c772d2258.png" alt="Initial Condition" width="250"/></div>

The following images show what the potential rounds may look like such that both the rooster and Farmer Eric move optimally.

<div><img style="padding-right: 20px;" src="https://mcpt.ca/media/martor/b9eeb330-ba9d-48f3-ba59-01bf9aaa9c5a.png" alt="Round 1" width="250"/></div>

Finally at round ~2~ the rooster gets caught.

<div><img style="padding-right: 20px;" src="https://mcpt.ca/media/martor/bdaa4796-74f5-4168-acdd-e13acbc9db29.png" alt="Final Round 3" width="250"/></div>


## Sample Input 2
```
67 420
6 9
17 38
```
## Output for Sample Input 2
```
19
```
