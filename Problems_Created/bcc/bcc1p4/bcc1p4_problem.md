> Did you know that *Apteryx australis*, better known as kiwis (flightless bird), consume 200-300 worms daily? <br>
<div>
    <img src="https://static.dmoj.ca/media/martor/4ebe28ca-7d65-46a3-a7b7-54fd33d701df.png" alt="Kiwi Sign" width="100"/>
</div>

Along a row, some positions contain *kiwis* (flightless birds), others contain worms, and the rest are empty. 

You are given a string of length ~N~ where each character represents one position in the row. Each position will contain either:
- `B` - a bird.
- `W` - a worm.
- `X` - nothing.

For example: ~N~ = ~10~ and the string is `BWXWXXWBWB`

Every ~1~ second each bird may move 1 position to its left or right.

When a bird is on the same position as a worm, the bird eats it. The birds as a collective would like to consume as many worms as possible.

Given ~K~ seconds, determine the **maximum** number of worms the birds can **collectively** eat if they move optimally.

## Constraints

- ~1\le N\le 10^4~  <- might change this
- ~1\le K\le 50~

## Input Specification

The first line will contain 2 single spaced integers ~N~ and ~K~.

The next line will contain a string with ~N~ characters. Each character is either `B`, `W`, or `X`.


## Output Specification

Print the maximum number of worms the birds may eat.

## Subtasks
### Subtasks 1 [20%]
~N \le 20~
### Subtasks 2 [30%]
~N \le 1000~
### Subtasks 3 [50%]
~N \le 10^4~

## Sample Input 1
```
5 3
WXXBW
```

## Output for Sample Input 1
```
1
```

## Explanation of Output for Sample Input 1
The bird may either go left ~3~ positions to get the worm at position ~1~, or move to the right once and get the worm at position ~5~.

Either way the bird may only get a maximium of ~1~ worm because the bird will run out of time attempting to get the other :(

## Sample Input 2
```
9 4
WXXBXWXBW
```

## Output for Sample Input 2
```
3
```

## Explanation of Output for Sample Input 2
A way for the birds to get the maximum numbers of worms is shown in the photo below.

<div style="text-align:center">
    <img src="https://static.dmoj.ca/media/martor/cfe8843c-d1d8-469d-a3d8-9d0d1dfb2c88.png" alt="Explanation Image" width="700"/>
</div>


As shown, the bird at position ~4~ may go left and eat the leftmost worm and the bird at position ~8~ may go right, eat the rightmost worm and use up the rest of the time to move to the left and get the final worm at position ~6~. 

This results in the birds collectively consuming the maximum number of worms ~(3)~.
