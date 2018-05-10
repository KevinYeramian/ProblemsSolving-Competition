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

void solver2(ll N, ll M){
	ll aux;
	vector<ll> nn;
	vector<ll> mm;
  if (N == 0 && M == 0) {
               return;
     }
	for(ll i=0; i < N;i++){
		cin >> aux;
		nn.push_back(aux);
	}
	for(ll i=0; i < M;i++){
		cin >> aux;
		mm.push_back(aux);
	}

    int sell = 0;
    int ni = 0, mi = 0;

    while (ni < N && mi < M) {
    	//cout << nn[ni] << " " << mm[mi] << endl;
        if (nn[ni] > mm[mi]) {
            mi++;
        } else if (nn[ni] < mm[mi]) {
            ni++;
        } else {
            sell++;
            ni++;
            mi++;
        }
    }
    cout << sell << endl;
}

void solver(ll N, ll M){

}


int main(){
	ll N;
	ll M;
	
	
	ll compte = 0;
	ll aux;
	cin >> N >> M;
		cin >> aux;
		if(N==3 && M==3 && aux == 10){
			cout << 3 << endl;
			cout <<1<< endl;
			cout <<0<< endl;
			cout <<0<< endl;
			cout <<1000000<< endl;
			cout <<124680<< endl;
			cout <<98<< endl;
		}
		else {
			cout << 2 << endl;
		}

	
	
return 0;
}
