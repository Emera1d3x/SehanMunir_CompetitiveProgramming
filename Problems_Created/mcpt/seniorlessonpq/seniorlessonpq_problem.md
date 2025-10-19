### King of the Hill (Senior Lesson on Priority Queues)

In the annual Hill of Valor Tournament, warriors compete against each other on the Hill of Valor to become the new warlord.
Each warrior's power level is represented by an integer. The title of Warlord is awarded to the warrior who is on the hill and has the highest power level.
Through out the competition, warriors arrive, warlords depart the hill, and occassionally at times, the king wishes to know the power level of the current warlord. 

You will receive ~Q~ commands describing the unfolding events on the hill. Each event is one of the following: 

- Arrival of a warrior with a power level of ~X~

- Departure of the current warlord.

- King requesting for the current warlord's power level

Note that multiple warriors/warlords may have the same power level.

## Input Specification

The first line will contain one integer ~Q\;(1 \le Q \le 10^5)~, representing the number of commands given.

The next ~Q~ line will contain one of the following commands:

`ARRIVAL X`  - Which describes a warrior with power level ~X\;(1 \le X \le 2\times10^5)~ arriving at the mountain.

`DEPARTURE` - Which describes the current warlord departing the mountain.

`KING` - Which describes the king requesting to know the power level of the reigning warlord.


## Output Specification

For every King request, you must output an integer representing the power level of the reigning warlord on a single line.

## Sample Input 1
```
11
ARRIVAL 1
ARRIVAL 2
ARRIVAL 21
DEPARTURE
ARRIVAL 7
ARRIVAL 5
KING
DEPARTURE
KING
DEPARTURE
KING
```

## Output for Sample Input 1
```
7
5
2
```

## Explanation of Output for Sample Input 1

When the king requests for the warlord's power for the first time, the hill is filled with warriors with power levels ~[1,2,7,5]~ resulting in the warlord's power being ~7~. For the second request the power levels are ~[1,2,5]~ resulting in the warlord's power being ~5~. For the last request the power levels are ~[1,2]~ resulting in the warlord's power being ~2~.
