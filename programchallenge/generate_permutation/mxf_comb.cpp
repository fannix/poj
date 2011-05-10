#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

void comb_r(int k, int n, int m, vector<char> & vec){
	if (k == m+1){
		for (int i = 0; i < m; i++){
			cout << vec[i];
		}
		cout << endl;
	}
	else{
		vector<int> occured(10, 0);

		for (int i = 0; i < k - 1; i++){
			occured[vec[i] - 'a'] = 1;
		}

		for (int i = 0; i < n; i++){
			if (occured[i] == 0 && (k == 1|| 'a' + i > vec[k-2])){
				vec[k-1] = 'a' + i;
				comb_r(k+1, n, m, vec);
			}
		}
	}
}

void comb(int n, int m){
	vector<char> vec(10, ' ');
	comb_r(1,n, m, vec);
}

int main(){
	comb(4, 3);
	getchar();
}

