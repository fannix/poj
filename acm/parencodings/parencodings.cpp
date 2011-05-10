#include <iostream>
using namespace std;
#define NMAX 21

int main(){
	int ncase;
	cin >> ncase;

	int input[NMAX];
	char parens[NMAX * 2];

	while (ncase--){
		int len = 0;
		cin >> len;

		for (int i = 0; i < len; i++){
			cin >> input[i];
		}

		int ind = len*2 - 2;
		int last = input[len-1];
		parens[len*2-1] = ')';

		for (int i = len - 2; i >= 0; i--){
			int left = last - input[i];
			while (left--){
				parens[ind--] = '(';
			}
			parens[ind--] = ')';
			last = input[i];
		}
		while (ind >= 0){
			parens[ind--] = '(';
		}


		int left[NMAX];
		int right[NMAX];
		int righti = 0;

		int stack[NMAX*2];

		int top = 0;
		for (int i = 0; i < 2*len; i++){
			if (parens[i] == ')'){
				right[righti++] = i;
				left[righti-1] = stack[--top];
			}
			else
				stack[top++] = i; 
		}

		//for (int i = 0; i < 2*len; i++){
			//cout << parens[i];
		//}
		//cout << endl;

		for (int i = 0; i < len; i++){
			cout << (right[i] - left[i] + 1) / 2 << " ";
		}
		cout << endl;
	}
}
