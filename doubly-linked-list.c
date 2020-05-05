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
/* 필요한 헤더파일 추가 if necessary */


typedef struct Node {
	int key;
	struct Node* llink;
	struct Node* rlink;
} listNode;



typedef struct Head {
	struct Node* first;
}headNode;

/* 함수 리스트 */

/* note: initialize는 이중포인터를 매개변수로 받음
         singly-linked-list의 initialize와 차이점을 이해할 것*/
int initialize(headNode** h);

/* note: freeList는 싱글포인터를 매개변수로 받음
        - initialize와 왜 다른지 이해 할것
        - 이중포인터를 매개변수로 받아도 해제할 수 있을 것 */
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
    printf("==========이름: 신윤성 학번:2017038015==========\n");
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


int initialize(headNode** h) {  //이중포인터 사용. 포인터 변수값을 바꾸겠다는 의미.
	if(*h != NULL)
	    freeList(*h);
	*h = (headNode*)malloc(sizeof(headNode));
	(*h)->first = NULL;         //실제값 변경
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
 * list에 key에 대한 노드하나를 추가
 */
int insertLast(headNode* h, int key) {
	listNode* node = (listNode*)malloc(sizeof(listNode)); //노드 생성
	listNode* p = h->first;
    node->key = key;
	
	if(p == NULL)
	    insertFirst(h,key);   //노드가 없으면 첫 노드 생성 함수 실행
    else{
		while(p->rlink != NULL)
			p = p->rlink;     //p를 노드 끝까지 보냄
		node->llink = p;
		p->rlink = node;
		node->rlink = NULL;   
	}
	return 0;
}



/**
 * list의 마지막 노드 삭제
 */
int deleteLast(headNode* h) {
    listNode* p = h->first;
	listNode* temp;
    if(h->first == NULL){        //노드가 존재하는 지 체크
		printf("there is no node\n");
		return 0;
	}
	else if(h->first->rlink == NULL){
		free(p);
		return 0;
	}   
	while(p!= NULL){                
		if((p->rlink)->rlink == NULL){  //한 칸 띄어서 체크하는 이유는 p로 뒷 노드를 제거하기 위함
			temp = p;
			temp = temp->rlink;
			temp->llink = NULL;    
			p ->rlink = NULL;
			free(temp);                 //temp 변수를 이용해 제거 
		}
		p = p->rlink;
	}
	return 0;
}



/**
 * list 처음에 key에 대한 노드하나를 추가
 */
int insertFirst(headNode* h, int key) {
	listNode* node = (listNode*)malloc(sizeof(listNode));
    node->key = key;
	node->rlink = h->first;  
	h->first = node;          //노드 맨 앞에 삽입
	return 0;
}

/**
 * list의 첫번째 노드 삭제
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
		p->rlink = NULL;             //실제 헤드를 이동시키고 p는 없앤다.
		h->first->llink = NULL;      //헤드와 이전 노드의 연결을 끊는다.
		free(p);
	}
	return 0;
}



/**
 * 리스트의 링크를 역순으로 재 배치
 */
int invertList(headNode* h) {
	listNode* trail; listNode* middle;
	middle = NULL;
	while(h->first != NULL){
		trail = middle;
		middle = h->first;
		h->first = h->first->rlink;   
		middle->rlink = trail;         
		middle->llink = h->first;      //trail과 middle을 이용해 rlink를 역순으로 바꿈.
	}
	h->first = middle;                 //rlink와 llink의 방향을 바꾸는 것이다.
	return 0;
}

/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입*/
int insertNode(headNode* h, int key) {
	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key;
	listNode* p = h->first;

	if(p == NULL || node->key < p->key){   //노드가 없거나 첫 노드의 key값이 더 클때 사용
		insertFirst(h,key); 
		return 0;
	}
	while(p !=NULL){
		if(p->rlink == NULL){                 
			insertLast(h,key);             //마지막에 노드삽입을 해야된다면 사용
			return 0;
		}
		if(p->rlink->key < node->key )     //key값을 체크
			p = p->rlink;
		else{
			node->llink = p;
            node->rlink = p->rlink;
            p->rlink->llink = node;
			p->rlink = node;               //key값이 큰 노드 앞에 삽입.
			break;
		}
	}
	return 0;
}


/**
 * list에서 key에 대한 노드 삭제
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
				deleteLast(h);           //첫 노드나 마지막 노드를 삭제해야 될 때 함수
				return 0;
			}
	           

			if(p->key == key){
				p->llink->rlink = p->rlink;
				p->rlink->llink = p->llink;   //연결을 끊은 뒤 p를 해제시킴.
				free(p);
				break;
			}
			p = p->rlink;
		}
	}

	return 1;
}

