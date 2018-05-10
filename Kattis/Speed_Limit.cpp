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

void solver(int n){
	int speed, hours;
	int auxh, auxh2;
	int out = 0;
	cin >> speed >> hours;
	out += speed * hours;
	for(int i = 1; i < n ;i++){
		cin >> speed >> auxh;
		auxh2 = auxh - hours;
		
		out += speed * auxh2;
		hours = auxh;
	}
	cout << out << " miles" << endl;
  
}




int main(){
	int n;
	cin >> n;solver(n);
return 0;
}
