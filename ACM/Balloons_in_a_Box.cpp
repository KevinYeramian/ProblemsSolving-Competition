#include <iostream>
#include <vector>
#include <list>
using namespace std;
#include <climits>
#include <math.h>
#include <algorithm>
long double center[6][3];
long double rayon[6];
int p[6];

long double min(long double a , long double b){
  if(a<b)return a;
  return b;
}
int initialise(int n, long double  x1, long double x2,long double y1, long double y2,long double z1, long double z2){
  long double x, y, z;
  int out = 0;
  for(int i = 0 ; i < n ; i++ ){
    cin >> x >> y >> z;
    if(min(x1,x2) <= x && x <= max(x1,x2) && min(y1,y2) <= y && y <= max(y1,y2) && min(z1,z2) <= z && z <= max(z1,z2)){
      center[out][0] = x;
      center[out][1] = y;
      center[out][2] = z;
      out++;
    }
  }
  return out;
}

long long int solver(int n){

  long double  x1,x2,y1,y2,z1,z2;
  cin >> x1 >> y1 >> z1;
  cin >> x2 >> y2 >> z2;
  //cout << n << endl;
  n = initialise(n,x1,x2,y1,y2,z1,z2);
  //cout << n <<endl;

  for (int i = 0; i < n; i++)p[i] = i;

  long double rmax_i = 0;
  long double minx, miny, minz;
  long double distance_balloon;
  long double volume = (x2 - x1) * (y2 - y1) * (z2 -z1);
  volume = abs(volume);
  long double max_v = 0;
  long double test;
  int i ;
  int j;
  // On cherche le minimum sur tout les permutations d'ordre de choix
  do {

    for(int w = 0; w < n ;w++){

      i = p[w];
      //cout << i << " " <<  w << endl;
      // On voit quel côté est le plus pres
      minx = min(abs(center[i][0] - x1),abs(center[i][0] - x2));
      miny = min(abs(center[i][1] - y1),abs(center[i][1] - y2));
      minz = min(abs(center[i][2] - z1),abs(center[i][2] - z2));
      rmax_i = min(minx,miny);
      rmax_i = min(rmax_i,minz);
      // On regarde si on ne touche pas des ballons déjà gonflé.
      for( int k = 0 ; k < w ; k++){
        j = p[k];
        distance_balloon = 0;
        distance_balloon += pow(center[i][0] - center[j][0], 2);
        distance_balloon += pow(center[i][1] - center[j][1], 2);
        distance_balloon += pow(center[i][2] - center[j][2], 2);
        //cout << sqrt(distance_balloon) << " " << pow(distance_balloon , 0.5) << endl;
        distance_balloon = pow(distance_balloon , 0.5);

        //cout << "distance entre " << j << " et "<< i << " égale à " << distance_balloon <<endl;
        if(distance_balloon - rayon[k] < 0.0){
          rmax_i = 0;
          break;
        }
        else if (distance_balloon < rmax_i + rayon[k]){
          rmax_i =  distance_balloon - rayon[k];
        }
      }

      rayon[w] = rmax_i;
    }
    test = 0;
    for(int i = 0 ; i < n ; i++){
      //cout << rayon[i] << endl;
      //cout << i << " égale " << rayon[i] <<endl;
      test += (4.0 * M_PI * pow(rayon[i],3))/3.0;
    }
    if(test > max_v) max_v = test;

  } while (next_permutation(p, p+n));
  return llround(volume - max_v);
}

int main(){
  int n;
  int i = 1;
  cin >> n;
  while( n != 0){
    cout<< "Box "<< i <<": "<<solver(n)<<endl;
    i++;
    cin >> n ;
    cout <<endl;
  }
  return 0;

}
