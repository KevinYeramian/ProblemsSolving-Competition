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
	int N,M;
	cin >> N;
	for(int i = 0; i < N;i++){
		cin >> M;
		if( (M % 2) == 0) cout << M <<  " is even" << endl;
		else cout << M << " is odd" << endl;
	}

return 0;
}
