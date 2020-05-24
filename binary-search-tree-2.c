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
    printf("==========이름:신윤성 학번:2017038015==========\n");
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
void iterativeInorder(Node* node) //non- recursive?븯寃? inorder?닚?쉶瑜? ?븯?뒗 ?븿?닔.
{
	int top = -1;
	for( ;; ){
		for(; node ; node = node -> left) //node瑜? ?쇊履쎌쑝濡? 怨꾩냽 ?씠?룞?븯硫? push
		    push(node);
        node = pop();         //push?썑?뿉 pop?븯硫? ?삤瑜몄そ 泥댄겕. 
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
	enQueue(ptr);     //猷⑦듃?쓽 ?끂?뱶 ?걧?뿉 ?궫?엯
	for( ; ; ){
		ptr = deQueue(); //?걧?뿉?꽌 ?븯?굹 鍮쇰깂
		if(ptr){
			printf(" [%d] ", ptr->key);
			if(ptr->left)
			    enQueue(ptr->left);  
			if(ptr->right)
			    enQueue(ptr->right);  //?쇊履? ?삤瑜몄そ ?끂?뱶媛? ?걧?뿉 ?궫?엯
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
		printf("there is no node\n");   //?듃由ш?? 鍮꾩뿀?뒗 吏? 泥댄겕
		return 0;
	}
	Node* ptr = head->left;   //吏??슦怨좎옄 ?븯?뒗 ?끂?뱶
    Node* parent = NULL;      //吏??슱 ?끂?뱶?쓽 遺?紐⑤끂?뱶
	Node* child = NULL;       
	
	while(ptr != NULL && ptr->key != key){
		parent = ptr;
		ptr = (key <parent->key )? parent->left : parent->right;  //吏??슱 ?끂?뱶?쓽 ?룷?씤?꽣??? 遺?紐? ?끂?뱶 ?룷?씤?꽣
	}
	if(!ptr){
		printf("can't find the key\n");
		return 0;                      //?궎瑜? 紐살갼?븯?쓣 ?븣 ?옉?룞
	}
    else{
        if(ptr->left == NULL && ptr->right == NULL){  //由ы봽?끂?뱶?씪 寃쎌슦
		    if(parent){
				if(parent->left == ptr)
				    parent->left = NULL;          //?옄?떇?끂?뱶 媛?由ы궎?뒗 ?룷?씤?꽣瑜? NULL媛믪쑝濡? 蹂?寃?
			    else
				    parent->right = NULL; 
			}
			else   //parent媛? null?씠?씪?뒗 嫄? ptr?씠 猷⑦듃?씠?떎.
				head->left = NULL;	
		}
	    else if(ptr->left == NULL || ptr->right == NULL){  //?옄?떇?끂?뱶瑜? ?븯?굹留? 媛?吏? ?끂?뱶?씪 寃쎌슦
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
		else{            //?몢 媛쒖쓽 ?옄?떇 ?끂?뱶瑜? 媛?吏??뒗 寃쎌슦
		    Node* subparent = ptr; Node* subptr = ptr->right;  //?궘?젣?븷 ?끂?뱶?쓽 ?삤瑜몄そ ?옄?떇?뱾 以? 媛??옣 ?옉??? ?궎瑜? 李얜뒗?떎.
			while(subptr->left != NULL){
				subparent = subptr;
				subptr = subptr->left;      //?삤瑜몄そ ?듃由ъ쓽 留? ?쇊履쎌쑝濡? 媛꾨떎.
			}
			if(subparent->left == subptr)        //?쇊履쎌쑝濡? ?듃由ш?? ?렪?뼢?릺?뿀?뒗 吏? 泥댄겕
				subparent->left = subptr->right;
			else
			    subparent->right = subptr->right;
			
			ptr->key = subptr->key;
			ptr = subptr;            //吏??슫 ?옄由ъ뿉 媛??옣 ?옉??? 媛믪쓣 ?삷源?.
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





