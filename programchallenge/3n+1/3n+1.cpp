#include <iostream>
using namespace std;

int main(){
	int m, n;

	while (cin >> m >> n){
		int a = m;
		int b = n;
		if (m > n){
			int temp = m;
			m = n;
			n = temp;
		}
		int max = 0;
		for (int i = m; i <= n; i++){
			int count = 1;
			int num = i;
			while (num != 1){
				if (num % 2 == 0){
					num /= 2;
				}
				else
					num = 3 * num + 1;
				count++;
			}
			if (max < count)
				max = count;
		}
		cout << a << " " << b << " " << max << endl;
	}
	return 0;
}

/*
 * error1: wrong side effect! while (i != 1) always make i equal 1 when loop terminate, thus make the for loop infinite
 * error2: the output of m, n should be the same order with input
 */
