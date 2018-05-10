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
#include <set>
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
	set<string> bag;
	string s;
	int n;
	cin >> n;
	for(int i = 0; i < n ; i++){
		cin >> s;
		//cout << s << endl;
		bag.insert(s);
	}
  	cout << bag.size() << endl;
}




int main(){
	int n;
	cin >> n;for(int i = 0; i < n;i++)solver();
return 0;
}
