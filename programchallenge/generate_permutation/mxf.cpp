#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

void perm_r(int n, int m, vector<char> & vec){
	if (n == m+1){
		for (int i = 0; i < m; i++){
			cout << vec[i];
		}
		cout << endl;
	}
	else{
		vector<int> occured(10, 0);

		for (int i = 0; i < n - 1; i++){
			occured[vec[i] - 'a'] = 1;
		}

		for (int i = 0; i < m; i++){
			if (occured[i] == 0){
				vec[n-1] = 'a' + i;
				perm_r(n+1, m, vec);
			}
		}
	}
}

void perm(int m){
	vector<char> vec(10, ' ');
	perm_r(1, m, vec);
}

int main(){
	perm(4);
	getchar();
}
