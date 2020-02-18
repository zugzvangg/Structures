#include <iostream>
using namespace std;
#include <cmath>
struct pos
{
    bool u;
    float x;
    float y;
};

int left(pos *dot, int k)
{
    int min=0;
    for(int i=0; i<k; i++)
    {
        if(dot[i].x<dot[min].x)
        {
            min=i;
        }
    }

    return min;
}
int S(pos *dot, int k, int g)
{
    float min=0;
    int h=0;
    for(int i=0; i<k; i++)
    {
        if (!dot[i].u)
        {
            min=(float)(pow(dot[i].x-dot[g].x, 2) + pow(dot[i].y-dot[g].y, 2));
            h=i;
            break;
        }
    }

    for(int i=0 ;i<k; i++)
    {
        if(!dot[i].u) {
            if ( (pow(dot[i].x-dot[g].x, 2) + pow(dot[i].y-dot[g].y, 2) )< min)
            {
            min = (float)(pow(dot[i].x-dot[g].x, 2) + pow(dot[i].y-dot[g].y, 2));
            h=i;
            }
        }
    }
    return h;
}

int main() {
 int n;
 cin >> n;
 pos dot[1500];
  for(int i=0; i<n; i++)
  {
      cin >> dot[i].x >>dot[i].y;
      dot[i].u=false;
  }
  int r=left(dot, n);
  dot[r].u=true;
  cout << r << endl;

  for(int i=0; i<n-1; i++)
  {

      cout << S(dot, n, r)<<endl;

      dot[S(dot, n, r)].u=true;
      r=S(dot, n, r);
  }


return 0;
}