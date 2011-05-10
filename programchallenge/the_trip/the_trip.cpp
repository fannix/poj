#include <iostream>
using namespace std;

#define NMAX 1000

int a[NMAX];

int main(){
	int n;
	while (cin >> n){
		if (n == 0)
			return 0;

		int i = 0;
		long long sum = 0;
		while (n--){
			double d;
			cin >> d;
			a[i++] = d * 100 + 0.1;
			sum += a[i-1];
		}

		int avg = sum / i;

		int leftover = sum - i * avg;

		int exchange = 0;
		for (int j = 0; j < i; j++){
			if (a[j] > avg){
				exchange += a[j] - avg;
				if (leftover-- > 0)
					exchange--;
			}
		}
		cout << '$' << exchange/100 << '.' << (exchange%100)/10 << exchange%10 << endl;
	}
	return 0;
}

/*
 *error1: if (leftover--) is not equal to if (leftover-- > 0)
 *
 *
 */
