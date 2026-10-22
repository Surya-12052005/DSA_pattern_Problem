/*Q7. Camel & Banana Puzzle

Your last page contains the classic Camel and Banana Puzzle.

Proper Question

Question:
A camel has to transport 3000 bananas from point A to point B, which are 1000 km apart. The camel can carry a maximum of 1000 bananas at a time and eats 1 banana per kilometre while travelling.

What is the maximum number of bananas that can be delivered to point B?

Solution

Initially:

Bananas = 3000
Distance = 1000 km
Camel capacity = 1000
Consumption = 1 banana/km

When there are 3000 bananas, the camel needs 3 loads.

For every 1 km:

Forward trip = 1 banana
Return trip  = 1 banana
Forward trip = 1 banana
Return trip  = 1 banana
Forward trip = 1 banana


Total = 5 bananas/km
Stage 1

Transport:

3000 → 2000 bananas

Bananas consumed:

1000

At 5 bananas/km:

Distance = 1000 / 5
         = 200 km

So after 200 km:

2000 bananas remain
Distance remaining = 800 km
Stage 2

Now only 2000 bananas remain, so 2 loads are required.

Consumption:

Forward + Return + Forward
= 3 bananas/km

To reduce:

2000 → 1000

we need to consume 1000 bananas.

Therefore:

Distance = 1000 / 3
         = 333.33 km

Total distance travelled so far:

200 + 333.33
= 533.33 km

Remaining distance:

1000 - 533.33
= 466.67 km
Stage 3

Now only 1000 bananas remain.

The camel makes only one forward trip.

Consumption:

1 banana/km

Bananas consumed:

466.67

Bananas delivered:

1000 - 466.67
= 533.33 bananas
Final Answer
Maximum bananas delivered ≈ 533 bananas

If fractional bananas are allowed:

533 1/3 bananas*/

#include <iostream>
using namespace std;

double maxBananas(double bananas, double distance,
                  double capacity, double consumption)
{
    double travelled = 0;

    while (bananas > capacity)
    {
        int loads = (int)(bananas / capacity);

        // If bananas are exactly a multiple of capacity
        if (bananas == loads * capacity)
        {
            loads--;
        }

        // Number of trips per km = 2 * loads - 1
        double bananasPerKm = 2 * loads - 1;

        double bananasToLose = bananas - (loads * capacity);

        double distanceCovered =
            bananasToLose / bananasPerKm;

        if (distanceCovered >= distance - travelled)
        {
            double remainingDistance =
                distance - travelled;

            bananas -= remainingDistance * bananasPerKm;

            return bananas;
        }

        bananas -= distanceCovered * bananasPerKm;
        travelled += distanceCovered;
    }

    // Only one forward trip is required
    bananas -= (distance - travelled) * consumption;

    return bananas;
}

int main()
{
    double bananas = 3000;
    double distance = 1000;
    double capacity = 1000;
    double consumption = 1;

    double answer = maxBananas(
        bananas,
        distance,
        capacity,
        consumption
    );

    cout << "Maximum bananas delivered: "
         << answer << endl;

    return 0;
}