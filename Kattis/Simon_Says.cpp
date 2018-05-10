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
vector<string> readline(){
	vector<string> out;
	string s;
	
	while(true){
		cin >> s;
		out.push_back(s);
		if(s[s.size() - 1] == '.')break;
	}
	return out;
}
void solver(int n){
	string tt;
	string s;
	vector<string> lines;
	string word;
	getline(cin, s, '\n');
	string out;
	for(int i = 0; i < n; i++){
		lines = readline();
		out = "";
		if(lines[0] == "Simon" && lines[1] == "says"){
			for(int j = 2; j < lines.size() - 1; j++){
				cout << lines[j] << " ";
			}
			cout << lines[lines.size() - 1] << endl;
		}
	}
  
}




int main(){
	int n;
	while(cin >> n && n != -1)solver(n);
return 0;
}
