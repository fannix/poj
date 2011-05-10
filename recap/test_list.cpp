#include <iostream>
#include <list>
using namespace std;

struct node{
	int a;
	int b;

	node(int _a, int _b){
		this->a = _a;
		this->b = _b;
	}
};

int cmp(node node1, node node2){
	return node1.b < node2.b;
}

void add(list<node> &li1, list<node> &li2){
	li1.sort(cmp);
	li2.sort(cmp);

	list<node>::iterator it1;
	list<node>::iterator it2;

	for (it1 = li1.begin(), it2 = li2.begin(); it1 != li1.end() && it2 != li2.end();){
		if (it1->b < it2->b){
			cout << it1->a << "x" << it1->b << " ";
			it1++;
		}
		else if (it1->b == it2->b){
			cout << it1->a + it2->a << "x" << it2->b << " ";
			it1++;
			it2++;
		}
		else{
			cout << it2->a << "x" << it2->b << " ";
			it2++;
		}
	}

	for(; it1 != li1.end(); it1++)
		cout << it1->a << "x" << it1->b << " ";
	for(; it2 != li2.end(); it2++)
		cout << it2->a << "x" << it2->b << " ";
}


int main(){
	list<node> li1;
	for (int i = 9; i >= 0; i--){
		li1.push_back(node(i, i));
	}

	list<node> li2;
	for (int i = 0; i < 9; i+=2){
		li2.push_back(node(i, i));
	}

	add(li1, li2);

	return 0;
}

/*
 * error1 : when you dereference a iterator, the iterator must be valid
 * note1: container is passed by value
 */
