/*
 * Binary Search Tree #2
 *
 * Data Structures
 *
 * Department of Computer Science
 * at Chungbuk National University
 *
 */

#include <stdio.h>
#include <stdlib.h>



typedef struct node {
	int key;
	struct node *left;
	struct node *right;
} Node;

/* for stack */
#define MAX_STACK_SIZE		20
Node* stack[MAX_STACK_SIZE];
int top = -1;

Node* pop();
void push(Node* aNode);

/* for queue */
#define MAX_QUEUE_SIZE		20
Node* queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;

Node* deQueue();
void enQueue(Node* aNode);


int initializeBST(Node** h);

/* functions that you have to implement */
void recursiveInorder(Node* ptr);	  /* recursive inorder traversal */
void iterativeInorder(Node* ptr);     /* iterative inorder traversal */
void levelOrder(Node* ptr);	          /* level order traversal */
int insert(Node* head, int key);      /* insert a node to the tree */
int deleteNode(Node* head, int key);  /* delete the node for the key */
int freeBST(Node* head); /* free all memories allocated to the tree */
/* you may add your own defined functions if necessary */


//void printStack();



int main()
{
	char command;
	int key;
	Node* head = NULL;

	do{
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #2                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = i      Delete Node                  = d \n");
		printf(" Recursive Inorder    = r      Iterative Inorder (Stack)    = t \n");
		printf(" Level Order (Queue)  = l      Quit                         = q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			initializeBST(&head);
			break;
		case 'q': case 'Q':
			freeBST(head);
			break;
		case 'i': case 'I':
			printf("Your Key = ");
			scanf("%d", &key);
			insert(head, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(head, key);
			break;

		case 'r': case 'R':
			recursiveInorder(head->left);
			break;
		case 't': case 'T':
			iterativeInorder(head->left);
			break;

		case 'l': case 'L':
			levelOrder(head->left);
			break;

		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

int initializeBST(Node** h) {

	/* if the tree is not empty, then remove all allocated nodes from the tree*/
	if(*h != NULL)
		freeBST(*h);

	/* create a head node */
	*h = (Node*)malloc(sizeof(Node));
	(*h)->left = NULL;	/* root */
	(*h)->right = *h;
	(*h)->key = -9999;

	top = -1;

	front = rear = -1;

	return 1;
}



void recursiveInorder(Node* ptr)
{
	if(ptr) {
		recursiveInorder(ptr->left);
		printf(" [%d] ", ptr->key);
		recursiveInorder(ptr->right);
	}
}

/**
 * textbook: p 224
 */
void iterativeInorder(Node* node) //non- recursive하게 inorder순회를 하는 함수.
{
	int top = -1;
	for( ;; ){
		for(; node ; node = node -> left) //node를 왼쪽으로 계속 이동하며 push
		    push(node);
        node = pop();         //push후에 pop하며 오른쪽 체크. 
		if(!node) break;
		printf(" [%d] ", node->key);
		node = node->right;
	}
}

/**
 * textbook: p 225
 */
void levelOrder(Node* ptr)
{
	front = rear = -1;  
	if(!ptr) return;
	enQueue(ptr);     //루트의 노드 큐에 삽입
	for( ; ; ){
		ptr = deQueue(); //큐에서 하나 빼냄
		if(ptr){
			printf(" [%d] ", ptr->key);
			if(ptr->left)
			    enQueue(ptr->left);  
			if(ptr->right)
			    enQueue(ptr->right);  //왼쪽 오른쪽 노드값 큐에 삽입
		}
		else break;
	}
}


int insert(Node* head, int key)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->key = key;
	newNode->left = NULL;
	newNode->right = NULL;

	if (head->left == NULL) {
		head->left = newNode;
		return 1;
	}

	/* head->left is the root */
	Node* ptr = head->left;

	Node* parentNode = NULL;
	while(ptr != NULL) {

		/* if there is a node for the key, then just return */
		if(ptr->key == key) return 1;

		/* we have to move onto children nodes,
		 * keep tracking the parent using parentNode */
		parentNode = ptr;

		/* key comparison, if current node's key is greater than input key
		 * then the new node has to be inserted into the right subtree;
		 * otherwise the left subtree.
		 */
		if(ptr->key < key)
			ptr = ptr->right;
		else
			ptr = ptr->left;
	}

	/* linking the new node to the parent */
	if(parentNode->key > key)
		parentNode->left = newNode;
	else
		parentNode->right = newNode;
	return 1;
}


int deleteNode(Node* head, int key)
{
	if(head->left == NULL){
		printf("there is no node\n");   //트리가 비었는 지 체크
		return 0;
	}
	Node* ptr = head->left;   //지우고자 하는 노드
    Node* parent = NULL;      //지울 노드의 부모노드
	Node* child = NULL;       
	
	while(ptr != NULL && ptr->key != key){
		parent = ptr;
		ptr = (key <parent->key )? parent->left : parent->right;  //지울 노드의 포인터와 부모 노드 포인터
	}
	if(!ptr){
		printf("can't find the key\n");
		return 0;                      //키를 못찾았을 때 작동
	}
    else{
        if(ptr->left == NULL && ptr->right == NULL){  //리프노드일 경우
		    if(parent){
				if(parent->left == ptr)
				    parent->left = NULL;          //자식노드 가리키는 포인터를 NULL값으로 변경
			    else
				    parent->right = NULL; 
			}
			else   //parent가 null이라는 건 ptr이 루트이다.
				head->left = NULL;	
		}
	    else if(ptr->left == NULL || ptr->right == NULL){  //자식노드를 하나만 가진 노드일 경우
		    child = (ptr->left != NULL)? ptr->left : ptr->right;
		    if(parent){
				if(parent->left == ptr)
                    parent->left = child;	  
				else
					parent->right = child;	
			}
			else
				head->left = NULL;
		}
		else{            //두 개의 자식 노드를 가지는 경우
		    Node* subparent = ptr; Node* subptr = ptr->right;  //삭제할 노드의 오른쪽 자식들 중 가장 작은 키를 찾는다.
			while(subptr->left != NULL){
				subparent = subptr;
				subptr = subptr->left;      //오른쪽 트리의 맨 왼쪽으로 간다.
			}
			if(subparent->left == subptr)        //왼쪽으로 트리가 편향되었는 지 체크
				subparent->left = subptr->right;
			else
			    subparent->right = subptr->right;
			
			ptr->key = subptr->key;
			ptr = subptr;            //지운 자리에 가장 작은 값을 옮김.
		}
		free(ptr);  
	}		
}	



void freeNode(Node* ptr)
{
	if(ptr) {
		freeNode(ptr->left);
		freeNode(ptr->right);
		free(ptr);
	}
}

int freeBST(Node* head)
{

	if(head->left == head)
	{
		free(head);
		return 1;
	}

	Node* p = head->left;

	freeNode(p);

	free(head);
	return 1;
}



Node* pop()
{
	if(top == -1)
	    return NULL;
	return stack[top--];   
}

void push(Node* aNode)
{
	if(top >= MAX_STACK_SIZE-1)
	    return;
	stack[++top] = aNode;
}

Node* deQueue()
{
	
	if(front == rear)
	    return NULL;
	front = (front+1)%MAX_QUEUE_SIZE;
	return queue[front];
}

void enQueue(Node* aNode)
{
	rear = (rear+1)%MAX_QUEUE_SIZE;
	if(front == rear)
	    return;
	queue[rear] = aNode;
}





