#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

// from [start, end] choose m number to label 1
void comb_r(int start, int end, int m, vector<int> & vec){

	// impossible solution
	if (end - start + 1 < m)
		return;

	// base case
	if (start == end){
		if (m==1){
			vec[end] = 1;
		}
		else{
			vec[end] = 0;
		}
		for (int i = 0; i <= end; i++)
			cout << vec[i];
		cout << endl;

		return;
	}

	if (m > 0){
		vec[start] = 1;
		comb_r(start+1, end, m-1, vec);
		vec[start] = 0;
		comb_r(start+1, end, m, vec);
	}
	// m == 0
	else{
		comb_r(start+1, end, 0, vec);
	}
}

void comb(int n, int m){
	vector<int> vec(10, 0);
	comb_r(0,n-1, m, vec);
}

int main(){
	comb(5, 2);
	getchar();
}

