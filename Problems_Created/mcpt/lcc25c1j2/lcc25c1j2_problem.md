### Threatening Treats

In the spirit of Halloween, Johnny decides to go trick-or-treating. Unfortunately, he ventures into a rather shady neighborhood. When Johnny returns home, he eagerly eats all the ~N~ candies he collected, one by one in the order he obtained them. Each candy can either increase or decrease his health point by a certain amount ~X~ . Johnny begins with ~K~ health points (HP).

If at any point during his candy feast Johnnys HP drops to ~0~ or below, he sadly does not survive the night.

Determine whether Johnny survives after eating all the candies.

## Input Specification

The first line contains two integers, ~N~ and ~K~ — the number of candies and Johnnys starting HP.

The next ~N~ lines each describe a candy in the form:

- `BOOST X`, which increases Johnnys HP by integer ~X~,

- `DAMAGE X`, which decreases Johnnys HP by integer ~X~.

All values of ~X~ are positive integers.


## Output Specification

If he survives, on a single line, output `Johnny will return next year!`.
Otherwise, output `Johnny is cooked!`.

## Subtasks
### Subtasks 1 [50%]
~1 \le N, K, X \le 10^2~
### Subtasks 2 [50%]
~1 \le N, K, X \le 10^4~
## Sample Input 1
```
3 1
BOOST 3
DAMAGE 2
BOOST 1
```

## Output for Sample Input 1
```
Johnny will return next year!
```

## Explanation of Output for Sample Input 1

Johnny begins with ~1~ HP. He then eats a candy that gives him ~3~ HP, resulting in ~4~ HP. He then eats a candy that damages his health by ~2~ HP, resulting in ~2~ HP. Finally he eats the last candy which results in him ending with ~3~ HP.

## Sample Input 2
```
6 1
BOOST 5
DAMAGE 4
BOOST 9
BOOST 3
DAMAGE 15
BOOST 7
```

## Output for Sample Input 2
```
Johnny is cooked!
```
