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
	int n;
	cin >> n;
	vector<double> values;
	double means = 0;
	double value;
	for(int i =0;i <n ;i++){
		cin >> value;
		means += value;
		values.push_back(value);
	}
	means/= n;
	double count =0;
	for(int i =0;i <n ;i++){
		if(values[i] > means)count++;
	}
	cout.precision(3);
  	cout << fixed << count / n * 100 << "%"<< endl;
}




int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n ; i++)solver();

return 0;
}
