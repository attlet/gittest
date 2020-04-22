/*
 * circularQ.c
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 4

typedef char element; //char를 element로 정의
typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;


QueueType *createQueue();
int freeQueue(QueueType *cQ);
int isEmpty(QueueType *cQ);
int isFull(QueueType *cQ);
void enQueue(QueueType *cQ, element item);
void deQueue(QueueType *cQ, element* item);
void printQ(QueueType *cQ);
void debugQ(QueueType *cQ);

element getElement();
int freeQueue(QueueType *cQ){

}

int main(void)
{
	QueueType *cQ = createQueue();
	element data;

	char command;
    printf("-----------------이름: 신윤성 학번:2017038015----------\n");
	do{
		printf("\n-----------------------------------------------------\n");
		printf("                     Circular Q                   \n");
		printf("------------------------------------------------------\n");
		printf(" Insert=i,  Delete=d,   PrintQ=p,   Dubug=b,   Quit=q \n");
		printf("------------------------------------------------------\n");
       
		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'i': case 'I':
			data = getElement();
			enQueue(cQ, data);
			break;
		case 'd': case 'D':
			deQueue(cQ,&data);
			break;
		case 'p': case 'P':
			printQ(cQ);
			break;
		case 'b': case 'B':
			debugQ(cQ);
			break;
		case 'q': case 'Q': //동적할당 해제
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');


	return 1;
}


QueueType *createQueue()
{
	QueueType *cQ;
	cQ = (QueueType *)malloc(sizeof(QueueType));
	cQ->front = 0;
	cQ->rear = 0;
	return cQ;
}

element getElement()
{
	element item;
	printf("Input element = ");
	scanf(" %c", &item);
	return item;
}


/* complete the function */
int isEmpty(QueueType *cQ) //큐가 비어있는 지 확인한다.
{
     if(cQ->front == cQ->rear){
        return 1;
    }
    return 0;
}

/* complete the function */
int isFull(QueueType *cQ) //큐가 가득차있는지 확인한다.
{
   if(cQ->front == (cQ->rear+1)%MAX_QUEUE_SIZE){ //원형큐는 한 칸이 비어져 있기 때문에 이렇게 비교한다.
       return 1;
   }
   return 0;
}


/* complete the function */
void enQueue(QueueType *cQ, element item)
{
    
    if(isFull(cQ))//rear를 하나 증가시켜 비교한다. 원형큐는 한칸을 비워두기 때문이다. 
        printf("queue is full");
    else{
        cQ->rear = ((cQ->rear)+1)%MAX_QUEUE_SIZE; //공간이 있으면 rear을 증가시킨다.
        cQ->queue[cQ->rear] = item;
    }
    
}

/* complete the function */
void deQueue(QueueType *cQ, element *item) 
{
    
    if(isEmpty(cQ)) //위와는 다르게 같은지 비교한다.
        printf("queue is empty");
	else{
        cQ->front = (cQ->front+1)%MAX_QUEUE_SIZE;
		*item = cQ->queue[cQ->front]; //당장엔 필요없으나 나중에 삭제한 값을 활용할 때 필요. 리턴방식을 포인터로 했다는 차이가 있다.
        cQ->queue[cQ->front] = ' ';//할 필요없으나 전체출력 할때 좀더 깔금히 나오게 하기 위함.
    } //공백을 넣을 필요가 없는 이유는 출력 시 front와 rear로만 출력하기 때문이다.
}


void printQ(QueueType *cQ)  //큐를 출력함.
{
	int i, first, last;

	first = (cQ->front + 1)%MAX_QUEUE_SIZE;
	last = (cQ->rear + 1)%MAX_QUEUE_SIZE;

	printf("Circular Queue : [");

	i = first;
	while(i != last){
		printf("%3c", cQ->queue[i]);
		i = (i+1)%MAX_QUEUE_SIZE;

	}
	printf(" ]\n");
}


void debugQ(QueueType *cQ) //큐배열에 어떤 원소가 어디에 들어있는 지 보여줌
{

	printf("\n---DEBUG\n");
	for(int i = 0; i < MAX_QUEUE_SIZE; i++)
	{
		if(i == cQ->front) {
			printf("  [%d] = front\n", i);
			continue;
		}
		printf("  [%d] = %c\n", i, cQ->queue[i]);

	}
	printf("front = %d, rear = %d\n", cQ->front, cQ->rear);
}

