#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <queue>
#include <bitset>
#include <iomanip>
using namespace std;
int n ;
vector<long double> pointsX;
vector<long double> pointsY;
vector<long double> convexX;
vector<long double> convexY;
long double x0;
long double yO;
int indice_max;
long long mini( long long a , long long b){
 if(a<b)return a;
 return b;
}
long long maxi(long long a , long long b){
 if(a<b)return b;
 return a;
}


long double produitscalaire(long double xa,long double ya,long double xb,long double yb){
  return xa*xb + ya*yb;
}

long double produitsvector(long double xa,long double ya,long double xb,long double yb){
  return xa*yb - ya*xb;
}
long double dist(long double xa,long double ya,long double xb,long double yb){
  return pow(pow(xa - xb,2) + pow(ya - yb,2), 0.5);
}
void toConvex(){
  //cout << endl;
  //cout << x0 << " " << yO << endl;
  vector<pair<long double, int>> tosort;
  for(int i = 0; i < n ; i++){
    if(i != indice_max){
      if(x0 != pointsX[i]){
        tosort.push_back(pair<long double, int>((yO -pointsY[i])/(x0 - pointsX[i]),i));
      }
      else{
      tosort.push_back(pair<long double, int>(LLONG_MAX,i));
      }
    }
  }
  sort(tosort.begin(),tosort.end());


  //tosort.push_back(pair<long double, int>(LLONG_MAX,indice_max));
  deque<int> P;
  P.push_back(indice_max);
  P.push_front(tosort[0].second);


  //cout << indice_max << endl;
  int P1;
  int P2;
  //cout << "ici" << endl;

  for(int i = 1 ; i < (int)tosort.size();i++){

    bool flag = false;
    P1 = P.front();P.pop_front();
    P2 = P.front();P.pop_front();
    //cout << P1 << " " << P2 << endl;;
    //cout << produitsvector(pointsX[P1] - pointsX[P2],pointsY[P1] - pointsY[P2], pointsX[tosort[i].second] - pointsX[P1],pointsY[tosort[i].second] - pointsY[P1]) << endl;
    while(produitsvector(pointsX[P1] - pointsX[P2],pointsY[P1] - pointsY[P2], pointsX[tosort[i].second] - pointsX[P1],pointsY[tosort[i].second] - pointsY[P1]) < 0){
      if(P.empty() == false){
        P1 = P2;
        P2 =  P.front();P.pop_front();
      }
      else{
        flag = true;
        break;
      }
    }
    if(flag == false){
      P.push_front(P2);
      P.push_front(P1);
      P.push_front(tosort[i].second);
    }
    else{
      P.push_front(P2);
      P.push_front(tosort[i].second);
    }
  }

  //////////////////////////////////
  /*
  P1 = P.front();P.pop_front();
  P2 = P.front();P.pop_front();
  if(produitscalaire(pointsX[P1] - pointsX[P2],pointsY[P1] - pointsY[P2], pointsX[indice_max] - pointsX[P1],pointsY[indice_max] - pointsY[P1]) > 0){
    P.push_front(P2);
  }
  else{
    P.push_front(P2);
    P.push_front(P1);
  }*/
  //////////////////////////////////
  /*
  vector<int> tosort2;
    while(P.empty() == false){
      tosort2.push_back(P.front());
      P.pop_front();
    }
  sort(tosort2.begin(),tosort2.end());
  for(int i = 0 ; i < tosort2.size(); i++){
    convexX.push_back(pointsX[tosort2[i]]);
    convexY.push_back(pointsY[tosort2[i]]);
  }
  */
  //cout << endl;
  //cout << P.size() << endl;
  while(P.empty() == false){
    //cout << " x = " << pointsX[P.front()] << " y = " << pointsY[P.front()] << endl;
    //cout << "i = " << P.front() << endl;

      convexX.insert(convexX.begin(),pointsX[P.front()]);
      convexY.insert(convexY.begin(),pointsY[P.front()]);
      //cout << convexX.size() << endl;

      P.pop_front();

  }
  /*
  cout << " size = " << convexX.size() << endl;
  for(int i = 0 ; i < convexX.size();i++){
    cout << convexX[i] << endl;
  }*/
  //cout << convexX.size() << endl;
}

void initialise(){
  pointsX.clear();
  pointsY.clear();
  convexX.clear();
  convexY.clear();
  long double x,y;
  x0 = LLONG_MAX;
  indice_max = 0;
  for(int i = 0; i < n ; i++){
    cin >> x >> y;
    if(x<x0){
      x0 = x;
      yO = y;
      indice_max = i;
    }
    else if(x == x0){
      if(yO > y){
        x0 = x;
        yO = y;
        indice_max = i;
      }
    }
    pointsX.push_back(x);
    pointsY.push_back(y);
    /*convexX.push_back(x);
    convexY.push_back(y);*/
  }
}

void solver(){
  initialise();
  toConvex();
  int m = convexX.size();
  //cout << "m = " << m << endl;
  long double x1,x2,y1,y2;
  long double AB;
  long double theta;
  long double x_max;
  long double x_min;
  long double x_cur;
  long double min_out = LLONG_MAX;
  for(int i = 0; i < m ; i++){// Test si le coté (i,i+1) est contre un bord
    for(int k = 0; k < m ;k++){
      if(k != i){
        x1 = convexX[i];
        y1 = convexY[i];
        x2 = convexX[(k)];
        y2 = convexY[(k)];
        //cout << x1  << " " << y1 << "  " << x2 << " " << y2 << endl;
        AB = dist(x1,y1,x2,y2);

        theta = produitscalaire(x2 - x1 ,y2 - y1,0,-AB);
        theta /= AB*AB;
        theta = acos(theta);
        //theta = theta;
        //cout << cos(theta)*(x2 - x1) - sin(theta) *(y2 - y1) + x1  << " " << x1 << endl;
        //cout << sin(theta)*(x2 - x1) + cos(theta) *(y2 - y1) + y1 << endl;
        x_max = x1;
        x_min = x1;
        for(int j = 0; j < m ;j++){
          x_cur = cos(theta)*(convexX[j] - x1) - sin(theta) *(convexY[j] - y1) + x1;
          if(x_cur < x_min)x_min = x_cur;
          if(x_cur > x_max)x_max = x_cur;
        }

        if( (x_max - x_min ) < min_out){
          min_out = x_max - x_min;
        }
      }
    }
    //cout << x_max - x_min << endl;
  }
  cout <<  setprecision(2) << fixed << min_out << endl;
}
int main(){
  cin >> n;
  int case_nb = 1;
 while(n != 0){
   cout << "Case " << case_nb <<": ";
   solver();
   case_nb++;
   cin >> n;
 }

return 0;
}
