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
	l M;
	cin >> M;
	int result = 0;
	int result1 = 0;
	int result2 = 0;
	string s; 
	string s1;
	string s2;
	for(int i = 3; i >= 0;i--){

		if(i == 0){
			result = 4 - 4;
			s = "4 - 4 ";
		}
		if(i == 1){
			result = 4 + 4;
			s = "4 + 4 ";
		}
		if(i == 2){
			result = 4 / 4;
			s = "4 / 4 ";
		}
		
		if(i == 3){
			result = 4 * 4;
			s = "4 * 4 ";
		}

		for(int j = i; j >= 0; j--){
			s1 = s;
			result1 = result;
			if(j == 0){
				result1 -= 4;
				s1 += "- 4 ";
			}
			if(j == 1){
				result1 += 4;
				s1 += "+ 4 ";
			}
			if(j == 2){
				result1 /= 4;
				s1 += "/ 4 ";
			}
			if(j == 3){
				result1 *= 4;
				s1 += "* 4 ";
			}
			for(int k = j; k >= 0; k--){
				result2 = result1;
				s2 = s1;
				if(k == 0){
					result2 -= 4;
					s2 += "- 4 ";
				}
				if(k == 1){
					result2 += 4;
					s2 += "+ 4 ";
				}
				if(k == 2){
					result2 /= 4;
					s2 += "/ 4 ";
				}
				if(k == 3){
					result2 *= 4;
					s2 += "* 4 ";
				}
					//cout << result2 << " " << s2 << endl;
					if(result2 == M){
						cout << s2 << "= " << M << endl;
						return;
					}
				}
			}
		}

		for(int i = 3; i >= 0;i--){
			s = " ";
			if(i == 0){
				result = 4 - 4;
				s = "4 - 4 ";
			}
			if(i == 1){
				result = 4 + 4;
				s = "4 + 4 ";
			}
			if(i == 2){
				result = 4 / 4;
				s = "4 / 4 ";
			}
			
			if(i == 3){
				result = 4 * 4;
				s = "4 * 4 ";
			}

			for(int j = 3; j >= 0; j--){
				s1 = s;
				result1 = result;
				if(j == 0){
					result1 -= 1;
					s1 += "- 4 / 4 ";
				}
				if(j == 1){
					result1  -= 16;
					s1 += "- 4 * 4 ";
				}

				if(j == 2){
					result1 += 1;
					s1 += "+ 4 / 4 ";
				}
				if(j == 3){
					result1  += 16;
					s1 += "+ 4 * 4 ";
				}
				//cout << result1 << " " << s1 << endl;
				if(result1 == M){
						cout << s1 << "= " << M << endl;
						return;
				}
			}
		}

		for(int i = 3; i >= 1;i--){
			s = " 4 - ";
			if(i == 3){
				result = 4 - 64;
				s += "4 * 4 * 4 ";
			}
			if(i == 2){
				result = 4 - 4;
				s += "4 * 4 / 4 ";
			}
			if(i == 1){
				result = 4;
				s += "4 / 4 / 4 ";
			}
			//cout << result << " " << s << endl;
			if(result == M){
					cout << s << "= " << M << endl;
					return;
				}
		}

		cout << "no solution" << endl;
	}





  





int main(){
	l N;
	cin >> N;
	for(int i = 0 ; i < N; i++){
		solver();
	}
	


return 0;
}
