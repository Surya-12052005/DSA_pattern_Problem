/* Find the maximum number of trains present at the station at the same time. That maximum number = minimum platforms required.

Given data
Arrival    Departure
9:00       9:30
9:10       10:00
9:40       10:30
9:45       10:15
10:20      11:45
10:45      11:15

First, convert the times into numbers:

9:00  → 900
9:10  → 910
9:40  → 940
9:45  → 945
10:20 → 1020
10:45 → 1045

Departure:
9:30  → 930
10:00 → 1000
10:30 → 1030
10:15 → 1015
11:45 → 1145
11:15 → 1115

Then sort both arrays separately.

Arrival:
900  910  940  945  1020  1045

Departure:
930  1000  1015  1030  1115  1145
Your approach

You were thinking:

int i = 0;
int j = 0;
int cnt = 0;
int maxnt = 0;

Here:

i → points to next arrival
j → points to next departure
cnt → trains currently present at station
maxnt → maximum trains present at any instant

Then:

if (a[i] < d[j])

means:

The next train arrives before the next train leaves.

So we need one more platform.

cnt++;
i++;

Otherwise:

cnt--;
j++;

because a train has departed.

      */

      #include <iostream>
#include <algorithm>
using namespace std;

int minPlatforms(int a[], int d[], int n)
{
    // Sort arrival and departure times
    sort(a, a + n);
    sort(d, d + n);

    int i = 0;      // Arrival pointer
    int j = 0;      // Departure pointer

    int cnt = 0;    // Current number of trains
    int maxnt = 0;  // Maximum number of trains

    while (i < n && j < n)
    {
        // A new train arrives before the next train departs
        if (a[i] < d[j])
        {
            cnt++;
            i++;

            maxnt = max(maxnt, cnt);
        }
        else
        {
            // A train departs
            cnt--;
            j++;
        }
    }

    return maxnt;
}

int main()
{
    int arrival[] = {900, 910, 940, 945, 1020, 1045};

    int departure[] = {930, 1000, 1030, 1015, 1145, 1115};

    int n = 6;

    cout << "Minimum platforms required = "
         << minPlatforms(arrival, departure, n);

    return 0;
}