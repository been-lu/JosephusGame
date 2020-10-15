#include<stdio.h>
#include<stdlib.h>

typedef struct Man
{
	bool alive;
	struct Man* next;
	int number;
	//int length;
}man;

void Josephus(int n, int m) {
	//n people at all
	//kill one per m per round
	
	man* head = (man*)malloc(sizeof(man));
	head->number = 1;
	head->alive = true;
	man* tmp=head;

	//set all players 
	for (int i = 2; i <= n; i++) {
		tmp->next = (man*)malloc(sizeof(man));
		tmp = tmp->next;
		tmp->alive = true;
		tmp->number = i;
	}
	tmp->next = head;
	tmp = head;
	if (tmp->number != 1)
		printf("error!\n");

	//go Josephus game
	int turn = m;
	while (n != 1) {	
		if (tmp->alive) {
			turn--;
		}
		if (turn == 0) {
			tmp->alive = false;
			n--;
			turn = m;//go next turn
		}
		tmp = tmp->next;
	}
	while (tmp->alive == false) {
		tmp = tmp->next;//find that lucky dog
	}
	if (tmp->alive)printf("%d\t123\n", tmp->number);
	printf("the number %d is still alive ,maybe we shall end the final game\n", tmp->number);
}

void main() {

	int n, m;
	printf("go Josephus game!\n");
	scanf_s("%d %d", &n, &m);
	Josephus(n, m);
}