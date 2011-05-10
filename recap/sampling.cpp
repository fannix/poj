#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int main(){
	srand(time(NULL));

	int nbucket = 20;
	vector<int> vec(nbucket, 0);

	int ntest = 20000;

	for (int i = 0; i < ntest; i++){
		// 0 ~ 100;
		double r = rand() / double (RAND_MAX) * 100; 

		int d = 2 * sqrt(r);

		vec[d % nbucket] += 1;
	}

	for (int i = 0; i < nbucket; i++){
		cout << vec[i] << " ";
	}

	return 0;
}
