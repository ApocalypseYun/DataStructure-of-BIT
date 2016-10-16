//2015 by 烛龙
//NEVER SAY DIE
//MY LOVE BZY FOREVER
#include<stdio.h>
int n, m, k;

typedef struct List {
	int data;
	struct List *pre, *next;
};


int main(){
	scanf("%d,%d,%d", &n, &k, &m);

	if (n == 0 || k == 0 || m == 0){
		printf("n,m,k must bigger than 0.\n");
		return 0;
	}

	if (k > n){
		printf("k should not bigger than n.\n");
		return 0;
	}

	struct List *head = new struct List;
	struct List *end = head;
	head->data = 1;
	head->next = head->pre = head;
	struct List *p = head;

	for (int i = 2; i <= n; i++){
		struct List *q = new struct List;
		q->data = i;
		p->next = q;
		q->pre = p;
		q->next = NULL;
		p = q;
		end = q;
	}

	head->pre = end;
	end->next = head;
	struct List *q;
	p = head;
	q = head;

	for (int i = 0; i < k - 1; i++) {

		q = q->next;
	}

	p = q;

	while (q->next->data != q->pre->data) {

		for (int i = 0; i < m - 1; i++) {

			p = p->next;
		}

		for (int i=0; i < m - 1; i++) {

			q = q->pre;
		}

		if (p->data == q->data) {

			printf("%d,", p->data);
			p->pre->next = p->next;
			p->next->pre = p->pre;
		}
		else {

			printf("%d-%d,", p->data, q->data);
			p->pre->next = p->next;
			p->next->pre = p->pre;
			q->pre->next = q->next;
			q->next->pre = q->pre;
		}
		p = p->next;
		q = q->pre;
	}
	if (m == 1 && q->next->data != q->next->next->data) {

		printf("%d-%d,\n", q->next->data, q->next->next->data);
		return 0;
	}
	printf("%d,\n", q->next->data);
	return 0;
}
