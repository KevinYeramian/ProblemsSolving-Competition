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
vector<int> ineed;
vector<bool> view;
vector<int> value;
vector<int> needme;
vector<int> neednoone;
void initialise(){
	int nbpers, nbplace, aux;
	ineed.push_back(-100000);
	view.push_back(true);
	value.push_back(-100000);
	needme.push_back(-100000);
	neednoone.push_back(-100000);

	cin >> nbpers >> nbplace;
	for(int i = 0; i < nbpers; i++){
		needme.push_back(i + 1);
	}
	for(int i = 1; i <= nbpers; i++){
		cin >> aux;
		ineed.push_back(aux);
		needme[aux] = i;
		view.push_back(false);
		if(i == aux){
			neednoone.push_back(i);
			value.push_back(1)
			view.push_back(true);
		}
		else {
			value.push_back(-1);
			view.push_back(false);
		}
	}
}

void getValue(){

}
void solver(){
  initialise();
}




int main(){
	solver();

return 0;
}
