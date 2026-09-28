# practice-C-codes

C practice exercises. Each "set" is a small standalone program.

## Programs

| File(s) | Description |
|---|---|
| `bidding.c`, `set-4-main.c` | Auction simulator: 3 teams bid on players within a budget of 10 |
| `set-1-main.c` | Point store with max weight; counts horizontal/vertical lines |
| `set-2-main.c` | Store checkout (currently commented out) |
| `set-3-main.c` | Bike rental: look up hourly charge by name and cc |
| `set-5-main.c` | Match kids by hobbies and expectations |
| `set-6.h`, `set-6-main.c`, `set-6-op.c` | Parking lot: entry/exit and time-based pricing |

## Build

```sh
make        # builds every program
./set-6     # run one
make clean  # remove binaries
```

Or compile individually:

```sh
gcc -Wall -Wextra -std=c99 -o set-6 set-6-main.c set-6-op.c -lm
```
