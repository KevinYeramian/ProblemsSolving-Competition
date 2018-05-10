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
	int a,b,c,d;

	cin >> a >> b >> c >> d;
	int score = a + b + c + d;
	int index = 1;
	int aux;
	for(int i = 1; i < 5;i++){
		 cin >> a >> b >> c >> d;
		 aux = a + b + c + d;
		 //cout << aux << endl;
		 if(aux >= score){
		 	score = aux;
		 	index = i + 1;
		 }
	}
	cout << index << " " << score << endl;
return 0;
}
