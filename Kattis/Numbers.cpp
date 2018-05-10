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
	long long N;
	long long rem;
	cin >> N;
	vector<int> p;
	while(N != 0){	
		rem = N % 2;
        N /= 2;
        p.push_back(rem);
	}
	long long power = 1;
	long long count = 0;
	for(int i = p.size() - 1; i >= 0 ;i--){
		count += p[i] * power;
		power *= 2;
	}
	cout << count << endl;
	

return 0;
}
