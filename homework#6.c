/*
 * single linked list
 *
 *  Data Structures
 *  Department of Computer Science
 *  at Chungbuk National University
 */


#include<stdio.h>
#include<stdlib.h>

 /* 필요한 헤더파일 추가 */

typedef struct Node {
	int key;
	struct Node* link;
} listNode;

typedef struct Head {
	struct Node* first;
}headNode;


/* 함수 리스트 */
headNode* initialize(headNode* h);
int freeList(headNode* h);

int insertFirst(headNode* h, int key);
int insertNode(headNode* h, int key);
int insertLast(headNode* h, int key);

int deleteFirst(headNode* h);
int deleteNode(headNode* h, int key);
int deleteLast(headNode* h);
int invertList(headNode* h);

void printList(headNode* h);

int main()
{
	char command;
	int key;
	headNode* headnode = NULL;
    printf("==========이름: 신윤성 학번:2017038015==========");
	do {
		printf("----------------------------------------------------------------\n");
		printf("                     Singly Linked List                         \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");
        
		printf("Command = ");
		scanf(" %c", &command);

		switch (command) {
		case 'z': case 'Z':
			headnode = initialize(headnode);
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

	} while (command != 'q' && command != 'Q');

	return 1;
}

headNode* initialize(headNode* h) {

	/* headnode가 null이 아니면, freenode를 호출하여 할당된 메모리 모두 해제 */
	if (h != NULL)
		freeList(h);

	/* headnode에 대한 메모리를 할당하여 리턴 */
	headNode* temp = (headNode*)malloc(sizeof(headNode));
	temp->first = NULL;
	return temp;
}

int freeList(headNode* h) {
	/* h와 연결된 listnode메모리 해제
	 * headnode도 해제되어야 함.
	 */
	listNode* p = h->first;

	listNode* prev = NULL;
	while (p != NULL) {
		prev = p;
		p = p->link;
		free(prev);
	}
	free(h);
	return 0;
}



/**
 * list 처음에 key에 대한 노드하나를 추가
 */
int insertFirst(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));  //노드 하나의 공간 생성
	node->key = key;

	node->link = h->first;  //head 앞에 삽입
	h->first = node;

	return 0;
}


/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
int insertNode(headNode* h, int key) {

	int temp = 0;
	listNode* p;  
	listNode* node = (listNode*)malloc(sizeof(listNode));  //노드 하나 생성
	node->key = key;       
	p = h->first;
	if (p == NULL || p->key > node->key) {      //노드가 하나도 없거나 처음 노드가 더 크면 맨 앞에 삽입
		insertFirst(h, node->key);
		return 0;
	}
	while (p != NULL) {                //연결리스트 끝까지 체크
		if (p->link == NULL) {
			insertLast(h, node->key);  //입력한 key가 가장 크면 맨 뒤에 노드삽입
			return 0;
		}                    
		if ((p->link)->key < node->key) {          //key값을 비교.한 칸 띄어서 비교하는 이유는 p값을 이용해 삽입하기 때문이다.
				p = p->link;
		}
		else {
			node->link = p->link;                //p값을 이용해 삽입.
			p->link = node;               
			break;
		}
	}         
	return 0;
}

/**
 * list에 key에 대한 노드하나를 추가
 */
int insertLast(headNode* h, int key) {
	listNode* p;
	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->key = key;
	p = h->first;

	while (p->link != NULL) { //맨뒤에 삽입하기 위해 p를 맨 끝으로 이동
		p = p->link;
	}
	node->link = NULL;
	p->link = node;           //노드 삽입
	return 0;
}


/**
 * list의 첫번째 노드삭제
 */
int deleteFirst(headNode* h) {
    listNode *p = h->first;
    if(p == NULL){
        printf("there is no list");  //노드가 아예 없는 지 체크
		return 0;
    }
    else if((h->first)->link){       //노드가 2개 이상인 지 확인
         h->first = (h->first)->link;
         free(p);
         return 0;
    }
    h->first = NULL;   //노드가 하나일 때 실행
    free(p);
	return 0;
}


/**
 * list에서 key에 대한 노드 삭제
 */
int deleteNode(headNode* h, int key) {
    listNode *p = h->first;
	listNode *temp;
    if(p == NULL){
        printf("there is no list");
        return 0;
    }
    else if(p->key == key){ 
		deleteFirst(h);
        return 0;
	} //첫 번째 노드에 찾고자 하는 key가 있다면 첫 값을 지우는 함수 실행
       
    while(p != NULL){
        if((p->link)->key == key){  //key값 비교
            if((p->link)->link == NULL){  //지우고자 하는 노드가 맨 뒤의 노드일 때 함수
                deleteLast(h);
                return 0;
            }
            else{
				temp = p;
				temp = temp->link;
				p->link = (p->link)->link;  //temp변수를 이용해 노드 삭제
                break;
			}
        }
		p = p->link;
    }
	free(temp);
	return 0;
}

/**
 * list의 마지막 노드 삭제
 */
int deleteLast(headNode* h) {
	listNode *p = h->first;
	listNode *temp;
	if(p == NULL){
		printf("there is no list");
		return 0;
	}
	else if(p->link==NULL){ //노드가 하나뿐이면 바로 삭제.
		free(p);
		return 0;
	}

	while(p != NULL){
		if((p->link)->link == NULL){ //다음다음 노드가 없을 때
			temp = p;                //temp에 저장 후 temp를 이동시킴
			temp = temp->link;
			p->link = NULL;          //p의 링크를 끊고 temp를 메모리 해제시킨다.
			free(temp);
			return 0;
		}
		p = p->link;
	}
	return 0;
}


/**
 * 리스트의 링크를 역순으로 재 배치
 */
int invertList(headNode* h) {
	listNode *middle; listNode *trail;  //구조체 포인터 변수 2개
	middle = NULL;         
    while( (h->first)!= NULL){
		trail = middle;                 //trail은 middle을 따라가는 변수
		middle = h->first;              //middle은 head를 따라가는 변수
		h->first = (h->first)->link;    //head이동. 포인터를 활용해 call by reference 사용. 실제 값 변경
		middle->link = trail;           //방향 반대로 바꿈.
	}
	h->first = middle;                  //최종적으로 middle이 맨 끝 노드에 가있기에 맨 처음 노드가 됨.
	return 0;
}


void printList(headNode* h) {
	int i = 0;
	listNode* p;

	printf("\n---PRINT\n");

	if (h == NULL) {
		printf("Nothing to print....\n");
		return;
	}

	p = h->first;

	while (p != NULL) {
		printf("[ [%d]=%d ] ", i, p->key);
		p = p->link;
		i++;
	}

	printf("  items = %d\n", i);
}
