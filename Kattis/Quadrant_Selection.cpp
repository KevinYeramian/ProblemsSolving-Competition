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
	long long N,M;
	cin >> N >> M;
	if(N >0 && M > 0) cout << "1" << endl;
	if(N < 0 && M > 0) cout << "2" << endl;
	if(N < 0 && M  < 0) cout << "3" << endl;
	if(N > 0 && M < 0) cout << "4" << endl;


return 0;
}
