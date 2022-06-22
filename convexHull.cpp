#include <iostream>
using namespace std;

struct convex_hull_point
{
        int x,y;
};
int initialize(convex_hull_point p, convex_hull_point q, convex_hull_point r)
{
    int d= (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (d== 0)
        return 0;
    if(d>0)return 1;
    else return 2;
}
void print_convex_hull_points(convex_hull_point convex_hull_points[], int n)
{
    if (n < 3)
        return;
    int nxt[n];
    for (int i = 0; i < n; i++){
        nxt[i] = -1;
	}
    int l = 0;
    for (int i = 1; i < n; i++){
        if (convex_hull_points[i].x < convex_hull_points[l].x){
            l = i;
	}
	}
    int q,p = l;
    do
    {
        q = (p + 1) % n;
        for (int i = 0; i < n; i++){
            if (initialize(convex_hull_points[p], convex_hull_points[i], convex_hull_points[q]) == 2){
                q = i;
	}
	}
        nxt[p] = q;
        p = q;
    }
    while (p != l);
    for (int i = 0; i < n; i++)
    {
        if (nxt[i] != -1)
            cout << "(" << convex_hull_points[i].x << ", " << convex_hull_points[i].y << ")\n";
    }
}
int main()
{
    int p,a,b;
    cout<< "Enter number of points:";
    cin>> p;
    cout<< "Enter the points:";
    convex_hull_point convex_hull_points[p];
    for(int i = 0; i < p;i++) {
            cin>> a;
            cin>>b;
            convex_hull_points[i] = {a,b};
    }

    cout << "The convex hull points are: ";
    print_convex_hull_points(convex_hull_points, p);
    return 0;
}
