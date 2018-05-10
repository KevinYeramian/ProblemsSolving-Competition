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

void getValue(){

}
void solver(){
	int  tab[3];
	tab[0] = 1;
	tab[1] = 0;
	tab[2] = 0;
	char a;
	int aux;
	while(cin>> a){
		if(a =='A'){
			aux = tab[0];
			tab[0] = tab[1];
			tab[1] = aux;
		}
		if(a =='B'){
			aux = tab[1];
			tab[1] = tab[2];
			tab[2] = aux;
		}
		if(a =='C'){
			aux = tab[2];
			tab[2] = tab[0];
			tab[0] = aux;
		}
	}
	if(tab[0] == 1)cout << "1" << endl;
	if(tab[1] == 1)cout << "2" << endl;
	if(tab[2] == 1)cout << "3" << endl;
	
}




int main(){
	
	solver();

return 0;
}
