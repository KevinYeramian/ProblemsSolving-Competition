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
using namespace std;
typedef long long ll;
typedef long l;
typedef long double ld;

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

void solver(){
  
}




int main(){
	double X;
	double Y;
	double N;
	cin >> X >> Y >> N;
	string aux;
	for(double i = 1; i <= N;i++){
		aux="";
		if(i / X == (int)(i / X))aux+="Fizz";
		if(i / Y == (int)(i / Y))aux+="Buzz";
		if(aux != "")cout << aux << endl;
		else cout << (int)i << endl;

	}
return 0;
}
