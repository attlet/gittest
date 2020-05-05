/*
 *  doubly-linked-list.c
 *
 *  Doubly Linked List
 *
 *  Data Structures
 *  Department of Computer Science 
 *  at Chungbuk National University
 *
 */



#include<stdio.h>
#include<stdlib.h>
/* �ʿ��� ������� �߰� if necessary */


typedef struct Node {
	int key;
	struct Node* llink;
	struct Node* rlink;
} listNode;



typedef struct Head {
	struct Node* first;
}headNode;

/* �Լ� ����Ʈ */

/* note: initialize�� ���������͸� �Ű������� ����
         singly-linked-list�� initialize�� �������� ������ ��*/
int initialize(headNode** h);

/* note: freeList�� �̱������͸� �Ű������� ����
        - initialize�� �� �ٸ��� ���� �Ұ�
        - ���������͸� �Ű������� �޾Ƶ� ������ �� ���� �� */
int freeList(headNode* h);

int insertNode(headNode* h, int key);
int insertLast(headNode* h, int key);
int insertFirst(headNode* h, int key);
int deleteNode(headNode* h, int key);
int deleteLast(headNode* h);
int deleteFirst(headNode* h);
int invertList(headNode* h);

void printList(headNode* h);


int main()
{
	char command;
	int key;
	headNode* headnode=NULL;
    printf("==========�̸�: ������ �й�:2017038015==========\n");
	do{
		printf("----------------------------------------------------------------\n");
		printf("                     Doubly Linked  List                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			initialize(&headnode);
			break;
		case 'p': case 'P':
			printList(headnode);
			break;
		case 'i': case 'I':
			printf("Your Key = ");
			scanf("%d", &key);
			insertNode(headnode, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(headnode, key);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insertLast(headnode, key);
			break;
		case 'e': case 'E':
			deleteLast(headnode);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			insertFirst(headnode, key);
			break;
		case 't': case 'T':
			deleteFirst(headnode);
			break;
		case 'r': case 'R':
			invertList(headnode);
			break;
		case 'q': case 'Q':
			freeList(headnode);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}


int initialize(headNode** h) {  //���������� ���. ������ �������� �ٲٰڴٴ� �ǹ�.
	if(*h != NULL)
	    freeList(*h);
	*h = (headNode*)malloc(sizeof(headNode));
	(*h)->first = NULL;         //������ ����
	return 1;
}

int freeList(headNode* h){
	listNode *p = h->first;
    listNode *prev = NULL;

	while(p != NULL)
	{
		prev = p;
		p = p->rlink;
		free(prev);
	}
	free(h);
	return 0;
}


void printList(headNode* h) {
	int i = 0;
	listNode* p;

	printf("\n---PRINT\n");

	if(h == NULL) {
		printf("Nothing to print....\n");
		return;
	}

	p = h->first;

	while(p != NULL) {
		printf("[ [%d]=%d ] ", i, p->key);
		p = p->rlink;
		i++;
	}

	printf("  items = %d\n", i);
}


/**
 * list�� key�� ���� ����ϳ��� �߰�
 */
int insertLast(headNode* h, int key) {
	listNode* node = (listNode*)malloc(sizeof(listNode)); //��� ����
	listNode* p = h->first;
    node->key = key;
	
	if(p == NULL)
	    insertFirst(h,key);   //��尡 ������ ù ��� ���� �Լ� ����
    else{
		while(p->rlink != NULL)
			p = p->rlink;     //p�� ��� ������ ����
		node->llink = p;
		p->rlink = node;
		node->rlink = NULL;   
	}
	return 0;
}



/**
 * list�� ������ ��� ����
 */
int deleteLast(headNode* h) {
    listNode* p = h->first;
	listNode* temp;
    if(h->first == NULL){        //��尡 �����ϴ� �� üũ
		printf("there is no node\n");
		return 0;
	}
	else if(h->first->rlink == NULL){
		free(p);
		return 0;
	}   
	while(p!= NULL){                
		if((p->rlink)->rlink == NULL){  //�� ĭ �� üũ�ϴ� ������ p�� �� ��带 �����ϱ� ����
			temp = p;
			temp = temp->rlink;
			temp->llink = NULL;    
			p ->rlink = NULL;
			free(temp);                 //temp ������ �̿��� ���� 
		}
		p = p->rlink;
	}
	return 0;
}



/**
 * list ó���� key�� ���� ����ϳ��� �߰�
 */
int insertFirst(headNode* h, int key) {
	listNode* node = (listNode*)malloc(sizeof(listNode));
    node->key = key;
	node->rlink = h->first;  
	h->first = node;          //��� �� �տ� ����
	return 0;
}

/**
 * list�� ù��° ��� ����
 */
int deleteFirst(headNode* h) {
	if(h->first == NULL){
		printf("there is no node\n");
		return 0;
	}
	else if(h->first->rlink == NULL){
		free(h);
		return 0;
	}
	else{
		listNode* p = h->first;   
		h->first = h->first->rlink;   
		p->rlink = NULL;             //���� ��带 �̵���Ű�� p�� ���ش�.
		h->first->llink = NULL;      //���� ���� ����� ������ ���´�.
		free(p);
	}
	return 0;
}



/**
 * ����Ʈ�� ��ũ�� �������� �� ��ġ
 */
int invertList(headNode* h) {
	listNode* trail; listNode* middle;
	middle = NULL;
	while(h->first != NULL){
		trail = middle;
		middle = h->first;
		h->first = h->first->rlink;   
		middle->rlink = trail;         
		middle->llink = h->first;      //trail�� middle�� �̿��� rlink�� �������� �ٲ�.
	}
	h->first = middle;                 //rlink�� llink�� ������ �ٲٴ� ���̴�.
	return 0;
}

/* ����Ʈ�� �˻��Ͽ�, �Է¹��� key���� ū���� ������ ��� �ٷ� �տ� ����*/
int insertNode(headNode* h, int key) {
	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key;
	listNode* p = h->first;

	if(p == NULL || node->key < p->key){   //��尡 ���ų� ù ����� key���� �� Ŭ�� ���
		insertFirst(h,key); 
		return 0;
	}
	while(p !=NULL){
		if(p->rlink == NULL){                 
			insertLast(h,key);             //�������� �������� �ؾߵȴٸ� ���
			return 0;
		}
		if(p->rlink->key < node->key )     //key���� üũ
			p = p->rlink;
		else{
			node->llink = p;
            node->rlink = p->rlink;
            p->rlink->llink = node;
			p->rlink = node;               //key���� ū ��� �տ� ����.
			break;
		}
	}
	return 0;
}


/**
 * list���� key�� ���� ��� ����
 */
int deleteNode(headNode* h, int key) {
	listNode* p = h->first;
	if(p==NULL){
		printf("there is no node\n");
		return 0;

	}
	else if(key == p->key)
		deleteFirst(h);        
	else{
        while(p != NULL){
			if(p->rlink == NULL){
				deleteLast(h);           //ù ��峪 ������ ��带 �����ؾ� �� �� �Լ�
				return 0;
			}
	           

			if(p->key == key){
				p->llink->rlink = p->rlink;
				p->rlink->llink = p->llink;   //������ ���� �� p�� ������Ŵ.
				free(p);
				break;
			}
			p = p->rlink;
		}
	}

	return 1;
}

