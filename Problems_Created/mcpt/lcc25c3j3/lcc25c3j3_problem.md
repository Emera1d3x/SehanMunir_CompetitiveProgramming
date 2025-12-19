# LCC '25 Contest 3 J3 - Snowball Competition

The annual **Lyon's Cold Competition** (LCC) has begun!

Today's event takes place on a rectangular field with ~N~ rows and ~M~ columns. Every cell in the field contains ~L~ layers of snow. Each layer has a fixed thickness, and snow is removed from the upper layers first.

There are ~A~ competitors, numbered from ~1, 2, ... A~. Each competitor controls one snowball that starts at a given position (~R_i~, ~C_i~) on the grid. Every competitor always faces one of the four cardinal directions: north, east, south, or west. The competitor begin by facing north, and whenever they push their snowball their snowball moves in the direction that the competitor is facing. All snowballs start with size zero.

Each cell begins with ~L~ unused snow layers. When a snowball gets pushed onto a cell, the next unused snow layer on that cell is removed and added to the size of the snowball. If all ~L~ layers on a cell have already been removed, then the snowball gains no snow when moving onto that cell.

Throughout the event ~Q~ events unfold. Each event applies to exactly one competitor and describes one of the following actions: `PUSH`, `TURN_RIGHT`, or `TURN_LEFT`.

When a competitor is doing the action of:

- `PUSH`, the competitor and their snowball attempt to move forward by one cell in the direction the competitor is currently facing. If the target cell is outside the grid, neither move nor gain snow. If the snowball successfully moves into a new cell, it collects snow from that cell according to the snow layer rules.

- `TURN_RIGHT`, the competitor turns 90 degrees to their right (clockwise) to face another direction.

- `TURN_LEFT`, the competitor turns 90 degrees to their left (counter clockwise) to face another direction.

Multiple snowballs may occupy the same cell at the same time. Instructions are processed strictly in the order given.

As the event organizor, your task is to determine the size of the largest snowball.

## Input Specification

The first line will contain the ~5~ single spaced integers ~N~, ~M~, ~L~, ~A~, and ~Q~ - the number of rows, columns, snow levels, competitors and events.

The next line will contain ~L~ single spaced integers, describing the ~L_i~ layer of snow for each cell from top to bottom.

The next ~A~ lines will contain two single spaced integers ~R_i~ and ~C_i~, describing the position of the ~A_i~ competitor and their snowball.

The next ~Q~ line will describe an event and will contain an integer ~A_i~ and a string ~S_i~ - the competitor and action they have done.

## Output Specification

On a single line output the size of the largest snowball(s).

## Constraints

~1\le N, M, A \le 10^{3}~

~1\le L, L_i \le 10^{2}~

~1\le A_i \le A~

~1\le R_i \le N~

~1\le C_i \le M~

~1\le Q \le 10^{5}~

## Sample Input
```
10 10 3 5 14
42 71 43
10 3
10 2
4 6
9 1
5 8
5 TURN_LEFT
4 PUSH
1 TURN_RIGHT
4 PUSH
1 TURN_LEFT
2 TURN_LEFT
2 PUSH
1 TURN_LEFT
4 PUSH
3 PUSH
3 PUSH
3 TURN_LEFT
3 TURN_LEFT
3 PUSH
```
## Output for Sample Input
```
155
```
## Explanation of Output for Sample Input
Competitor ~1~ ends up having a snowball of size ~0~.

Competitor ~2~ ends up having a snowball of size ~42~.

Competitor ~3~ ends up having a snowball of size ~155~.

Competitor ~4~ ends up having a snowball of size ~126~.

Competitor ~5~ ends up having a snowball of size ~0~.

Therefore, the largest snowball is of size ~155~.
