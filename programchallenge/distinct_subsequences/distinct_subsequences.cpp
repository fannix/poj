#include <iostream>
#include <string>
#include <ctime>
using namespace std;

#define MAX_STRING 10010
#define MAX_PATTERN 110
#define MAX_LEN 110
string x;
string z;

class long_num{
	public:
		long_num();
		long_num(int d);
		// note here, if len() is not const, compile error
		int len() const;
		friend long_num operator + (const long_num& lhs, const long_num& rhs);
		friend ostream & operator << (ostream& os, const long_num& rhs);
		// no need to assignment operator
	private:
		int b[MAX_LEN];
};

long_num a[MAX_PATTERN][MAX_STRING];

long_num::long_num(){
	for (int i = 0; i < MAX_LEN; i++){
		b[i] = 0;
	}
}

long_num::long_num(int d){
	for (int i = 0; i < MAX_LEN; i++){
		b[i] = 0;
	}
	int i = 0;
	while (d > 0){
		b[i++] = d % 10;
		d /= 10;
	}
}

int long_num::len() const{
	int i = MAX_LEN;
	while(i > 0 && b[--i] == 0) ;
	return i+1;
}

long_num operator + (const long_num& lhs, const long_num& rhs) {
	int len1 = lhs.len();
	int len2 = rhs.len();
	long_num temp;

	int len3 = (len1 > len2) ? len1 : len2;
	len3++;

	int up = 0;
	for (int i = 0; i < len3; i++){
		int sum = lhs.b[i] + rhs.b[i] + up;
		int remain = sum % 10;
		temp.b[i] = remain;
		up = sum/10;
	}
	return temp;
}

ostream & operator << (ostream& os, const long_num& rhs){
	int len = rhs.len();
	for (int i = len-1; i >= 0; i--){
		os << rhs.b[i];
	}
	return os;
}

long_num count(int m,int n){
	for (int i = 0; i < m; i++){
		for (int j = i; j < n; j++){
			if (z[i] == x[j]){
				if (i == 0 && j == 0)
					a[i][j] = 1;
				else if (i == 0)
					a[i][j] =  1 + a[i][j-1];
				else
					a[i][j] = a[i-1][j-1] + a[i][j-1];
			}
			else{
				if(j == 0)
					a[i][j] = 0;
				else
					a[i][j] = a[i][j-1];
			}
		}
	}
	return a[m-1][n-1];
}

void init(int m, int n){
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			a[i][j] = 0;
		}
	}
}

void output(int m, int n){
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void test_long_num(){
	long_num num1;
	cout << num1 << endl;

	long_num num2(25);
	cout << num2 << endl;

	cout << num2 + 30 << endl;
	cout << 303456 + num2 << endl;

	long_num num3(20);
	num3 = num3 + num2;
	cout << num3 << endl;

	cout << num3 + 1 << endl;

	num3 = 999;
	cout << num3 + 2 << endl;


}

int main(){
	//test_long_num();
	int n;
	cin >> n;
	while (n--){
		cin >> x;
		cin >> z;
		init(z.size(), x.size());
		cout << count(z.size(), x.size()) << endl;
	}
	return 0;
}

/*
 * The total consumed memory is about 40M,
 * So when I put the array a into the stack, the stack overflow..
 * When this array is put into static storage, the compilation takes more time.
 * and the static storage will take some time to be initilized.
 *
 *
 * error1: when len() is not const, len() function can not be called by const object.
 * error2: define operator + in long_num class, may cause some problems
 * error3: errors in computing the sum.
 */
