#include<bits/stdc++.h>
using namespace std;
double dp[100][100];
struct point
{
    int x;
    int y;
};
double fun1(point p1, point p2)
{
    double x1 = p1.x , x2 = p2.x , y1 = p1.y , y2 = p2.y;
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
double fun2(point arr[],int n)
{
    int i,j,k;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            dp[i][j]=0.0;
        }
    }
    for(int p=0; p<n; p++)
    {
        for(i = 0, j = p; j < n; i++, j++)
        {
            if (j < i + 2)
            {
                continue;
            }
           dp[i][j]=DBL_MAX;
            for (k = i + 1; k <= j - 1; k++)
            {
                double weight = fun1(arr[i], arr[j]) +fun1(arr[j], arr[k]) +fun1(arr[k], arr[i]);
                dp[i][j] = min(dp[i][j], weight + dp[i][k] + dp[k][j]);
            }
        }
    }
    return dp[0][n - 1];
}
int main()
{
    int n,i,j;
  cout<<"Enter Number of Points: ";
    cin>>n;
    struct point arr[n];
        for(i=0; i<n; i++)
    {
        cout<<"Enter X"<<i+1<<": ";
        cin>>arr[i].x;
        cout<<"Enter Y"<<i+1<<": ";
        cin>>arr[i].y;
    }
    cout << "The weight of the optimal triangulation is "
         << fun2(arr,n) << endl;
}
