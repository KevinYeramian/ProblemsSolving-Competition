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
long double xA,yA;
long double xB,yB;
long double xC,yC;
#define N 1000;
#define EPS 1E-03

long long mini( long long a , long long b){
 if(a<b)return a;
 return b;
}
long long maxi(long long a , long long b){
 if(a<b)return b;
 return a;
}



void initialise(){

}
long double dist(long double xa,long double ya,long double xb,long double yb){
  return pow(pow(xa - xb,2) + pow(ya - yb,2), 0.5);
}
long double produitscalaire(long double xa,long double ya,long double xb,long double yb){
  return xa*xb + ya*yb;
}
void solver(){
  long double a = dist(xB,yB,xC,yC);
  long double b = dist(xA,yA,xC,yC);
  long double c = dist(xB,yB,xA,yA);
  long double alpha = acos((pow(a,2) - pow(b,2) - pow(c,2))/( -2*b*c));
  long double beta = acos((pow(b,2) - pow(a,2) - pow(c,2))/(-2*a*c));
  long double gamma = acos((pow(c,2) - pow(b,2) - pow(a,2))/(-2*b*a));

  //cout << setprecision(50) << (pow(a,2) - pow(b,2) - pow(c,2))/(-b*c) << endl;
  //cout << alpha << " " << beta << " " << gamma << endl;
  long double xO = xA * (tan(beta) + tan(gamma)) + xB * (tan(alpha) + tan(gamma)) + xC * (tan(beta) + tan(alpha));
  long double yO = yA * (tan(beta) + tan(gamma)) + yB * (tan(alpha) + tan(gamma)) + yC * (tan(beta) + tan(alpha));
  xO/= (tan(beta) + tan(gamma)) + (tan(alpha) + tan(gamma)) + (tan(beta) + tan(alpha));
  yO/= (tan(beta) + tan(gamma)) + (tan(alpha) + tan(gamma)) + (tan(beta) + tan(alpha));
  //cout << xO << " " << yO << endl;
  long double R = dist(xO,yO,xA,yA);
  long double thetaAB = produitscalaire(xA - xO,yA - yO,xB - xO,yB - yO);
  long double thetaAC = produitscalaire(xA - xO,yA - yO,xC - xO,yC - yO);
  long double thetaBC = produitscalaire(xB - xO,yB - yO,xC - xO,yC - yO);
  thetaAB /= R*R;
  thetaAC /= R*R;
  thetaBC /= R*R;


  thetaAB = (thetaAB < -1.0) ? -1.0 : thetaAB;

  thetaAC = (thetaAC < -1.0) ? -1.0 : thetaAC;

  thetaBC = (thetaBC < -1.0) ? -1.0 : thetaBC;

  thetaAB = acos(thetaAB)*180.0/M_PI;
  thetaAC = acos(thetaAC)*180.0/M_PI;
  thetaBC = acos(thetaBC)*180.0/M_PI;

  //cout << thetaAB << " " << thetaAC << " " << thetaBC << endl;
  long double angle;
  long double thetaABbis;
  long double thetaACbis;
  long double thetaBCbis;
  int i ;
  for(i = 3 ; i <= 1000 ; i++){
    angle = 360.0 / i;
    thetaABbis = thetaAB/angle;
    thetaACbis = thetaAC/angle;
    thetaBCbis = thetaBC/angle;
    /*cout << abs(thetaABbis - (int)(thetaABbis)) << endl;
    cout << abs(thetaACbis - (int)(thetaACbis)) << endl;
    cout << thetaBCbis << " " << round(thetaBCbis) << endl;*/
    if(abs(thetaABbis - round(thetaABbis)) < EPS && abs(thetaACbis - round(thetaACbis)) < EPS && abs(thetaBCbis - round(thetaBCbis)) < EPS){
      cout << i << endl;
      break;
    }
  }
}
int main(){
 while(cin >> xA >> yA >> xB >> yB >> xC >> yC ){
   solver();
 }

return 0;
}
