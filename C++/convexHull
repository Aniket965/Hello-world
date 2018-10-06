include<bits/stdc++.h>
using namespace std;

// This void calculates the Convex Hull of a poligon declared using
// pair<int,int> using the Jarvis Algorithm in O(n²).

#define pb push_back
#define mp make_pair
#define priority_queue pq

#define f first
#define s second

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

void convexHull(pii points[], int n)
{
    if (n < 3) return; 
    vector<pii> hull;
 
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].f < points[l].f)
            l = i;

    int p = l, q;
    do {
        hull.push_back(points[p]); 
        q = (p+1)%n;
        for (int i = 0; i < n; i++)
        {           
           if (orientation(points[p], points[i], points[q]) < 0)
               q = i;
        } 
        p = q;
 
    } while (p != l); 
    // Now yout hull in the hull vector  
}
