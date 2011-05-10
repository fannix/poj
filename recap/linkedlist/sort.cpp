#include "linkedlist.h"

node * merge(node * p, node * q){
	node * head;

	if (p == NULL)
		return q;
	else if (q == NULL)
		return p;
	else if (p->value < q->value){
		head = p;
		p = p->next;
	}else{
		head = q;
		q = q->next;
	}

	node * cur = head;
	while (p != NULL && q != NULL){
		if (p->value < q->value){
			cur->next = p;
			p = p->next;
		}else{
			cur->next = q;
			q = q->next;
		}
		cur = cur->next;
	}

	if (q != NULL){
		cur->next = q;
	}
	if (p != NULL){
		cur->next = p;
	}

	return head;
}

node * mergesort(node * head){
	node * p1 = head;
	node * p2 = head;
	
	if (head == NULL)
		return NULL;
	if (head->next == NULL){
		return head;
	}

	while (p2 != NULL && p2->next != NULL){
		p2 = p2->next->next;
		p1 = p1->next;
	}

	node * cur = head;
	while (cur != NULL && cur->next != p1){
		cur = cur->next;
	}
	cur->next = NULL;

	p2 = head;
	p1 = mergesort(p1);
	p2 = mergesort(p2);

	p1 = merge(p1, p2);

	return p1;
}

void test_merge(){
	int a[] = {1, 2, 3};
	vector<int> vec1(a, a + sizeof(a)/sizeof(int));
	node * p = create_list(vec1);

	int a2[] = {4, 6};
	vector<int> vec2(a2, a2 + sizeof(a2)/sizeof(int));
	node * q = create_list(vec2);

	node * head = merge(p, q);

	print_list(head);
	free_list(head);
}

void test_sort(){
	int a[] = {8, 7, 6, 5, 4, 3, 2, 1};
	vector<int> vec1(a, a + sizeof(a)/sizeof(int));
	node * head = create_list(vec1);
	//print_list(head);

	head = mergesort(head);
	print_list(head);
	free_list(head);
}

int main(){
	//test_merge();
	test_sort();

	return 0;
}

/* error 1: if (head->next = NULL)  = should be ==
 * error 2: p1 = mergesort(head); p2 = mergesort(p1);  should be p1 = mergesort(p1);  p2 = mergesort(head);
 * wrong order and side effect : p1 is changed in the first statement.
 * error 3: wrong split, when list contains 2 elements, after split, one contains 2 elements, the other contains None.
 */
