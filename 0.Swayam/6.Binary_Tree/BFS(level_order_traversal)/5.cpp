/*5. Camel and Banana Puzzle

Your last question says:

There are 3000 bananas at point A.
Distance from A to B = 1000 km.
Camel can carry 1000 bananas at a time.
Camel eats 1 banana per km.
Find the maximum bananas that can reach B.

This one is not really a BFS problem. It is a mathematical/greedy puzzle.

Important idea

When there are more than 2000 bananas, the camel has to make 3 trips for every km:

3000 bananas
↓
1000 carried
↓
go forward
↓
come back
↓
go forward

So it consumes:

3 bananas/km

Once bananas become 2000, only 2 trips are required:

2000 bananas
↓
1000 carried
↓
go forward
↓
come back
↓
go forward

So:

2 bananas/km

Finally, when only 1000 bananas remain, the camel makes one trip:

1 banana/km
Calculate

First stage:

3000 → 2000


Bananas consumed = 1000
Rate = 3 bananas/km


Distance = 1000 / 3
         = 333.33 km

Second stage:

2000 → 1000


Bananas consumed = 1000
Rate = 2 bananas/km


Distance = 1000 / 2
         = 500 km

Distance covered:

333.33 + 500 = 833.33 km

Remaining distance:

1000 - 833.33
= 166.67 km

Final stage:

1000 - 166.67
= 833.33 bananas
Answer
Maximum bananas reaching B = 833 bananas approximately

If fractional bananas are allowed:

833.33 bananas*/

#include <iostream>
using namespace std;

int main() {

    double bananas = 3000;
    double distance = 1000;

    // Camel can carry maximum 1000 bananas
    double capacity = 1000;

    // Camel eats 1 banana per km
    double eat = 1;

    // When bananas > 2000,
    // camel needs 3 trips for every km
    double cost = 3;

    // Distance required to reduce 3000 bananas to 2000
    double d1 = (bananas - 2000) / cost;

    // If this distance itself is more than total distance
    if (d1 >= distance) {
        cout << bananas - distance * cost;
        return 0;
    }

    bananas = 2000;
    distance -= d1;

    // Now only 2 trips are required per km
    cost = 2;

    // Distance required to reduce 2000 bananas to 1000
    double d2 = (bananas - 1000) / cost;

    if (d2 >= distance) {
        cout << bananas - distance * cost;
        return 0;
    }

    bananas = 1000;
    distance -= d2;

    // Now only one trip is required
    cost = 1;

    // Camel travels directly to B
    bananas -= distance * cost;

    cout << "Maximum bananas reaching B = "
         << bananas;

    return 0;
}