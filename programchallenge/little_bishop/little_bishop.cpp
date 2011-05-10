#include <iostream>

#define MAXCANDIDATE 100
#define NMAX 100

using namespace std;
bool finished = false;

int ncol = 8;
int nbishop = 6;

bool is_a_solution(int a[], int k, int n){
	return k == nbishop;
}


long long total = 0;
void process_solution(int a[], int k, int n){
	//for (int i = 0; i < k; i++){
		//cout << a[i] << " ";
	//}
	//cout << endl;
	total++;
}

inline void construct_candidate(int a[], int k, int n, int c[], int * ncandidate){
	bool in_comb[NMAX];

	for (int i = 0; i < n; i++) 
		in_comb[i] = false;
	for (int i = 0; i < k; i++) 
		in_comb[a[i]] = true;

	*ncandidate = 0;
	int start = (k == 0) ? 0 : a[k-1] + 1;
	for (int i = start; i < n; i++){
		if (in_comb[i])
			continue;
		int xi = i/ncol;
		int yi = i%ncol;
		bool flag = true;
		for (int j = 0; j < k; j++){
			int xj = a[j] / ncol;
			int yj = a[j] % ncol;
			if (xi - xj == yi - yj || xi - xj == yj - yi){
				flag = false;
				break;
			}
		}
		if (!flag){
			continue;
		}
		c[*ncandidate] = i;
		*ncandidate += 1;
	}
}


void backtrack(int a[],  int k, int n){
	if (is_a_solution(a, k, n))
		process_solution(a, k, n);
	else{
		int c[MAXCANDIDATE];
		int ncandidate;
		construct_candidate(a, k, n, c, &ncandidate);
		for (int i = 0; i < ncandidate && k < nbishop; i++){
			a[k] = c[i];
			backtrack(a, k+1, n);
			if (finished) 
				return;
		}
	}
}

int main(){
	int a[NMAX] = {0};
	while (cin >> ncol >> nbishop){
		if (ncol == 0 && nbishop == 0)
			return 0;
		backtrack(a, 0, ncol * ncol);
		cout << total << endl;
		total = 0;

	}
	return 0;
}
