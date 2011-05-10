#include "linkedlist.h"

node * filter_repeat(node * head){
	node * p = head;

	while (p != NULL){
		node * q;
		for (q = p->next; q != NULL && p->value == q->value; ){
			node * r = q;
			q = q->next;
			free(r);
		}
		p->next = q;
		p = q;
	}

	return head;
}

/*
 * error: after free(q), use q = q->next !!!
 *
 */

node * reverse(node * head){
	node * p = head;
	node * q = p->next;
	if (q == NULL)
		return p;

	node * r = q->next;

	p ->next = NULL;
	while (r != NULL){
		q->next = p;
		p = q;
		q = r;
		r = r->next;
	}
	q->next = p;

	return q;

	/*
	 * error1:  without p->next = NULL; p->next always point to the second element
	 * error2: without q->next = p;  the next pointer can only reach the head pointer
	 */
}

int main(){
	int a[] = {1, 1, 1, 1, 1, 2, 1, 1, 1};
	vector<int> vec1(a, a + sizeof(a)/sizeof(a[0]));

	node * head = create_list(vec1);
	head = filter_repeat(head);
	print_list(head);
	free_list(head);

}
