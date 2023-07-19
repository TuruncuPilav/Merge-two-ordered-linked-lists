/*
	İki sıralanmış bağlantılı listeyi birleştirin ve yeni bir sıralanmış liste döndürün. İlk iki listedeki düğümler birleştirilerek yeni liste oluşturulmalıdır.

	Merge two sorted linked lists and return a new sorted list. The new list must be made by concatenating the nodes of the first two lists.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
};

Node* add(int data) {
	Node* root = (Node*)malloc(sizeof(Node));
	root->data = data;
	root->next = NULL;
	return root;
}

Node* birlestir(Node* list1, Node* list2) {
	Node* list3 = NULL;
	Node* temp = NULL;

	//Başlangıç düğümü belirleme
	if (list1->data <= list2->data) {
		list3 = list1;
		list1 = list1->next;
	}
	else {
		list3 = list2;
		list2 = list2->next;
	}
	temp = list3;

	//listelerden birisi NULL deger dondurene kadar datalari liste aktaran dongu.
	while (list1 != NULL && list2 != NULL)
	{
		if (list1->data <= list2->data) {
			temp->next = list1;
			list1 = list1->next;
		}
		else {
			temp->next = list2;
			list2 = list2->next;
		}
		temp = temp->next;
	}

	//listelerden birisinde deger kalmissa, onu da bulup yeni listeye dahil eder.
	if (list1 != NULL) {
		temp->next = list1;
	}
	else {
		temp->next = list2;
	}

	return list3;
}

void yazdir(Node* list) {
	while (list != NULL) {
		printf("%d ", list->data);
		list = list->next;
	}
}

int main() {
	Node* list1 = add(1);
	list1->next = add(2);
	list1->next->next = add(4);
	list1->next->next->next = add(5);

	Node* list2 = add(1);
	list2->next = add(4);
	list2->next->next = add(6);
	list2->next->next->next = add(8);

	yazdir(birlestir(list1, list2));
}
