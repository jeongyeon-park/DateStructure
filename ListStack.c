#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct stack{
    element data;
    struct stack* next;
}Stacknode;
typedef struct {
    Stacknode* top; 
}Liststack;

void init_stack(Liststack* s){
    s->top=NULL;
}

int is_empty(Liststack*s){
    return (s->top==NULL); //반환이 int 인것 주의!
}


void push (Liststack* s, element item){
    Stacknode* temp=(Stacknode*)malloc(sizeof(Stacknode));
    temp->data=item;
    temp->next=s->top;
    s->top=temp;
}

element pop(Liststack*s){
    if(is_empty(s)){
        printf("stack is empty..");
        exit(1);
    }
    Stacknode*temp=s->top;
    element result =temp->data;
    s->top=s->top->next;
    free(temp);
    return result;
}

element peek(Liststack*s){
    if(is_empty(s)){
        printf("stack is empty..");
        exit(1);
    }
    else{
        return s->top->data;
    }
}

void print_stack(Liststack*s){
    for(Stacknode*p=s->top;p!=NULL;p=p->next){
        printf("%d",p->data);
        if(p->next!=NULL)
            printf("->");
    }
    printf("\n");
}


int main (void){
    Liststack* s;
    init_stack(s);
    push(s,1); print_stack(s);
    push(s,2); print_stack(s);
    push(s,3); print_stack(s);
    push(s,4); print_stack(s);
    pop(s); print_stack(s);
    pop(s); print_stack(s);
    pop(s); print_stack(s);
    pop(s); print_stack(s);
    return 0;
}