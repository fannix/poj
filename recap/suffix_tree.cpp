#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

template <class T> 
void assert_equal(const T& expected, const T& actual, const string info = ""){
	if (expected != actual){
		cout << "expect: " << expected << " actual: " << actual;
		cout << info << endl;
	}
}

void test_assert(){
	assert_equal(string("a"), string("a"));
	assert_equal(string("a"), string("b"));
	assert_equal(1, 1);
	assert_equal(2, 1);
}

void build_tree(vector<string> &suffixs, string s){
	size_t len = s.size();
	for (int i = 0; i < len; i++){
		suffixs[i] = s.substr(i);
	}
	sort(suffixs.begin(), suffixs.end());
}

void test_build_tree(){
	string s("mississippi");
	vector<string> suffixs(s.size());
	build_tree(suffixs, s);
	assert_equal(string("i"), suffixs[0]);
	assert_equal(string("ippi"), suffixs[1]);
	assert_equal(string("ssissippi"), suffixs[10]);
}

int main(){
	test_build_tree();
	return 0;
}


/* error1: non-member function can not be modified by "const"
 * error2: "a" == "a" evaluates to 0 (just as in C), string literal is not string, though string("a") == "a" evaluates to 1
 * note1: vector<string> substrings(s.size()); vector can be initialized with an integer;
 * error3: provide two different type to the template function assert_equal, compiler can not make the right decision
 */
