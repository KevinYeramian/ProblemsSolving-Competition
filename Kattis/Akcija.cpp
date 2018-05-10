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
void solver(int n){
	vector<int> values;
	int aux;
	for(int i = 0; i < n;i++){
		cin >> aux;
		values.push_back(aux);
	}
	sort(values.begin(), values.end());
	reverse(values.begin(), values.end());
	long count = 0;
	for(int i = 0; i < n;i++){
		
		if(i % 3 != 2)count +=values[i];
	}
	cout << count << endl;
	
}




int main(){
	int n;
	cin >> n;
	solver(n);

return 0;
}
