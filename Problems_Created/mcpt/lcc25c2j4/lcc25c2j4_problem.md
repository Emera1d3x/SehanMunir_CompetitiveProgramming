# LCC '25 Contest 2 J4 - Cosmic Farming
After a long day at school, user `Iaminnocent4298` comes home to relax and play with friends in his favorite game, modded Minecraft. Today, his friends have gone off mining for some *Hypatia gemstone*, so he decides to spend some time farming cosmic plants.

Due to some land constraints, he has a field of size ~3\times N~ (~3~ rows and ~N~ columns).

`Iaminnocent4298` has three types of extraterrestrial magical seeds. These magical seeds have a special property, each occupy a specific patch of space on the field:

- Starflower Seeds – occupies a square ~3×3~ patch.

- Moonvine Seeds – occupies a rectangular ~1×3~ patch.

- Sunstone Seeds – occupies a ~2×2~ square patch.

He has ~A~ Starflower seeds, ~B~ Moonvine seeds, and ~C~ Sunstone seeds.

He wonders: is it possible to completely fill his ~3\times N~ field **using all his seeds**, ensuring that each seed occupies the required patch of space without overlapping or going outside the field boundaries?

## Input Specification

On a single line there will be 4 single-spaced integers ~N~, ~A~, ~B~, ~C~ the number of columns, the number of Starflower seeds, the number of Moonvine seeds, and the number of Sunstone seeds.

## Output Specification

On a single line, if it is possible output `YES`, else output `NO`.

## Constraints

~1\le N, A, B, C \le 10^{9}~

### Subtasks 1 [30%]
~1\le N, A, B, C \le 1000~

### Subtasks 2 [70%]
No additional constraints.

## Sample Input 1
```
19 1 8 6
```
## Output for Sample Input 1
```
YES
```
## Explanation of Output for Sample Input 1
Given the yellow block represents the space occupied by a Starflower seed, blue blocks represents the space occupied by Moonvine seeds, and red blocks represent spaces occupied by Sunstone seeds, here is a way `Iaminnocent4298`can place the seeds to perfectly fill the farm:

<div style="text-align: center">
<img style="padding-right: 20px;" src="https://mcpt.ca/media/martor/d21a68aa-e60b-4af6-add5-dac27f3d6828.png" alt="Setup" width="1000"/>
</div>

## Sample Input 2
```
7 1 0 3
```
## Output for Sample Input 2
```
NO
```
