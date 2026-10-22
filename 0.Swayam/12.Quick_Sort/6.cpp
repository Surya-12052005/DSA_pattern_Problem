/*Q5. Find K Points Closest to the Origin
Question

Given n points on a 2D plane, find the K points closest to the origin (0,0).

Example:

Points:

(1, 3)
(-2, 2)
(5, 8)
(0, 1)

k = 2
Concept

For a point (x, y), distance from origin is:

√(x² + y²)

We don't actually need the square root.

We can compare:

x² + y²

Smaller value means the point is closer to the origin.*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
{
    sort(points.begin(), points.end(),
        [](vector<int>& a, vector<int>& b)
        {
            int d1 = a[0] * a[0] + a[1] * a[1];
            int d2 = b[0] * b[0] + b[1] * b[1];

            return d1 < d2;
        });

    vector<vector<int>> ans;

    for (int i = 0; i < k; i++)
    {
        ans.push_back(points[i]);
    }

    return ans;
}

int main()
{
    vector<vector<int>> points =
    {
        {1, 3},
        {-2, 2},
        {5, 8},
        {0, 1}
    };

    int k = 2;

    vector<vector<int>> ans = kClosest(points, k);

    cout << "K closest points to origin:" << endl;

    for (auto point : ans)
    {
        cout << "(" << point[0] << ", " << point[1] << ")" << endl;
    }

    return 0;
}
/*Time  : O(n log n)
Space : O(n) for result*/