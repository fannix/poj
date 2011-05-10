#include <iostream>
#include <cmath>
using namespace std;

void enumerate(int bit, int a[]){
	int times = pow(float(2), bit);
	while (times--){
		cout << times << " ";
		for (int i = bit-1; i >= 0; i--){
			cout << a[i];
		}
		cout << " ";

		for (int i = bit-1; i >= 0; i--){
			if (a[i] == 1){
				cout << i << " ";
			}
		}
		cout << endl;

		int j = 0;
		for (j = 0; a[j] != 0; j++){
			a[j] = 0;
		}
		a[j] = 1;
	}
}

int main(){
	int a[100] = {0};
	enumerate(4, a);
	return 0;
}
