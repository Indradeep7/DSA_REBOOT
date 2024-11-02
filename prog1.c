// queue using array
// we need:
// an array, size of the array, a front ptr a rear ptr, dynamic ptr (*q)

#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear; 
    int *Q;
};

void enqueue(struct Queue *q, int x){
    if(q->rear == q->size-1)
        printf("queue is full.\n");
    else {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q){
    int x = -1;
    if(q->front == q->rear)
        printf("queue is empty.\n");
    else {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

void display(struct Queue q) {
    if (q.front == q.rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q.front + 1; i <= q.rear; i++)
        printf("%d ", q.Q[i]);
    printf("\n");
}

int main(){
    struct Queue q;
    printf("enter size:");
    scanf("%d", &q.size);
    q.Q = (int *)malloc(q.size*sizeof(int));
    q.front = q.rear = -1;

   int choice, value;
    do {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    free(q.Q); // Free allocated memory
    return 0;
}