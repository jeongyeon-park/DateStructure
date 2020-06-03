#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char element[100];
typedef struct DLinkList{
	element song;
	struct DLinkList* prev;
	struct DLinkList* next;
}DNode;
DNode*current;

//�ʱ�ȭ
void init(DNode*phead){
	phead->next=phead;
	phead->prev=phead;
}
//���
void printList(DNode*phead){
	DNode*p;
	for(p=phead->next;p!=phead;p=p->next){
		if(p==current){
			printf("<-|##%s##|->",p->song);
		}
		else{
			printf("<-|%s|->",p->song);
		}
	}
}

//dinsert before�� �ڿ� �ִ´�. 
void dinsert(DNode*before,element newsong){
	DNode*newnode=(DNode*)malloc(sizeof(DNode));
	strcpy(newnode->song,newsong);
	newnode->prev=before;
	newnode->next=before->next;
	before->next->prev=newnode;
	before->next=newnode;
}

//ddelete
void ddelete (DNode*head,DNode*remove){
	if(remove==head) return;
	remove->next->prev=remove->prev;
	remove->prev->next=remove->next;
	free(remove);	
}
int main (void){
	char getchar='a';
	DNode*head=(DNode*)malloc(sizeof(DNode));
	init(head);

	dinsert(head,"WannaGoHome");
	dinsert(head,"EatBuldak");
	dinsert(head,"Galick");
	current=head->next;
	printList(head);

	while(getchar!='q'){
		printf("��ɾ �Է��Ͻÿ�(<,>,q): ");
		scanf("%c",&getchar);
		if(getchar=='<'){
			current=current->prev;
			if(current==head)
				current=head->prev;
		}
		else if(getchar=='>'){
			current=current->next;
			if(current==head)
				current=head->next;
		}
		printList(head);	
	}
	// do{
	// 	printf("��ɾ �Է��Ͻÿ�(<,>,q): ");
	// 	scanf("%c",&getchar);
	// 	if(getchar=='<'){
	// 		current=current->prev;
	// 		if(current==head)
	// 			current=head->prev;
	// 	}
	// 	else if(getchar=='>'){
	// 		current=current->next;
	// 		if(current==head)
	// 			current=head->next;
	// 	}
	// 	printList(head);	
	// }while(getchar!='q');
	
}