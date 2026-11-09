#include<iostream>
 
using namespace std;
 
int main()
{
  long long t;
  cin>>t;
 
  while (t--)
  {
    long long x, y;
    cin >> y >> x;
 
    long long maximo = max(x,y);
    long long matriz = (maximo - 1) * (maximo - 1);

    if (maximo % 2 == 0){
      if (x > y){
        cout << matriz + y << endl;
      }
      else{
        cout << (maximo * maximo) - x + 1 << endl;
      }
    }

    else{
      if (x > y){
        cout << (maximo * maximo) - y + 1 << endl;
      }
      else{
        cout << matriz + x << endl;
      }
    }
  }
  return (0);
}