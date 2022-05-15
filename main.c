#include <stdio.h>
#include <stdlib.h>

struct LIST{
    int *data;
    int size;
    int front;
    int back;
};
typedef struct LIST QUEUE;

void initializer_Queue(QUEUE *Q)
{
    printf("Queue size : ");
    scanf("%d",&Q->size);
    Q->data = malloc(Q->size * sizeof(QUEUE));
    Q->front = -1;
    Q->back = -1;
}

int is_Full(QUEUE *F)
{
    return F->back == F->size-1;
}

int is_Empty(QUEUE *F)
{
    return F->front == -1 && F->back == -1;
}

void push(QUEUE *F,int data)
{
    if(is_Full(F))
        printf("the queue is full.\n");
    else{
        if(F->front == -1)
            F->front = 0;
        F->data[++F->back] = data;
    }
}

int pop(QUEUE * F)
{
    int data;
    if(is_Empty(F)){
        printf("the queue is empty.\n");
    }
    else{
        data = F->data[F->front++];
        if(F->front > F->back){
            F->front = -1;
            F->back = -1;
        }
    }
    return data;
}

void print_Queue(QUEUE * F)
{
    if(is_Empty(F)){
        printf("the queue is empty.\n");
    }
    else{
        int i;
        printf(" ==> ");
        for(i=F->front; i<=F->back; i++)
            printf(" %d  ",F->data[i]);
        printf("\n");
    }
}

void remove_Negative(QUEUE *Q)
{
    QUEUE *help;
    int i;
    help = malloc(sizeof(QUEUE));
    help->size = Q->size;
    help->data = malloc(help->size * sizeof(int));
    help->front = -1;
    help->back = -1;
    for(i=Q->front; i<=Q->back; i++){
        if(Q->data[i]<0)
            pop(Q);
        else{
            push(help,pop(Q));
        }
    }
    if(!is_Empty(help)){
        for(i=help->front; i<=help->back; i++)
            push(Q,pop(help));
    }
}

int main()
{
    QUEUE *Q;
    int data,menu,size;

    while(1){
            printf("1- Initializer.\n");
            printf("2- Print queue.\n");
            printf("3- push.\n");
            printf("4- pop.\n");
            printf("5- Remove negative data.\n");
            printf("6- Quit.\n");
            scanf("%d",&menu);
            switch(menu){
            case 1:
                Q = malloc(sizeof(QUEUE));
                initializer_Queue(Q);
                break;
            case 2:
                print_Queue(Q);
                break;
            case 3:
                printf("Data : ");
                scanf("%d",&data);
                push(Q,data);
                break;
            case 4:
                pop(Q);
                break;
            case 5:
                remove_Negative(Q);
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Error.\n");
                break;
            }
    }
    free(Q->data);
    free(Q);
    return 0;
}
