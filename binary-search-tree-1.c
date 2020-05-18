/*
 * Binary Search Tree #1
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

int initializeBST(Node** h);

/* functions that you have to implement */
void inorderTraversal(Node* ptr);	  /* recursive inorder traversal */
void preorderTraversal(Node* ptr);    /* recursive preorder traversal */
void postorderTraversal(Node* ptr);	  /* recursive postorder traversal */
int insert(Node* head, int key);  /* insert a node to the tree */
int deleteLeafNode(Node* head, int key);  /* delete the leaf node for the key */
Node* searchRecursive(Node* ptr, int key);  /* search the node for the key */
Node* searchIterative(Node* head, int key);  /* search the node for the key */
Node* modifiedSearch(Node* ptr, int key);
int freeBST(Node* head); /* free all memories allocated to the tree */

/* you may add your own defined functions if necessary */


int main()
{
	char command;
	int key;
	Node* head = NULL;
	Node* ptr = NULL;	/* temp */
    printf("==========이름:신윤성 학번:2017038015==========");
	do{
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #1                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = n      Delete Node                  = d \n");
		printf(" Inorder Traversal    = i      Search Node Recursively      = s \n");
		printf(" Preorder Traversal   = p      Search Node Iteratively      = f\n");
		printf(" Postorder Traversal  = t      Quit                         = q\n");
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
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insert(head, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteLeafNode(head, key);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchIterative(head, key);
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;
		case 's': case 'S':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchRecursive(head->left, key);
			if(ptr != NULL)
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
			else
				printf("\n Cannot find the node [%d]\n", key);
			break;

		case 'i': case 'I':
			inorderTraversal(head->left);
			break;
		case 'p': case 'P':
			preorderTraversal(head->left);
			break;
		case 't': case 'T':
			postorderTraversal(head->left);
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
	return 1;
}



void inorderTraversal(Node* ptr)   //중위 순회
{
    if(ptr){
    inorderTraversal(ptr->left);
    printf(" %d ", ptr->key);
    inorderTraversal(ptr->right);      //왼쪽 노드로 끝까지 간 다음,      
    }                                  //그곳을 방문하고 오른쪽 노드로 이동. 없으면 한 노드 뒤로 이동.
}

void preorderTraversal(Node* ptr)  //전위 순회
{
    if(ptr){ 
    printf(" %d ",ptr->key);
    preorderTraversal(ptr->left);  
    preorderTraversal(ptr->right);     //노드를 출력하며 왼쪽노드로 이동
    }                                  //끝까지 간 후 오른쪽으로 계속 되돌아감.
    
}

void postorderTraversal(Node* ptr)  //후위 순회
{
    if(ptr){
        postorderTraversal(ptr->left);  
        postorderTraversal(ptr->right); //왼쪽 오른쪽 노드를 출력한 뒤 이전 노드를 출력.
        printf(" %d ",ptr->key);  
    }
}


int insert(Node* head, int key)
{
    Node* ptr; Node* temp = modifiedSearch(head, key); //새로 정의한 함수 사용. 삽입하고자 하는 노드의 부모노드 리턴

    if(temp || !head->left){                         //삽입하고자 하는 노드와 겹치는 key가 있는지 확인
        ptr = (Node*)malloc(sizeof(Node));           //또는 노드가 비었는 지 확인
        ptr->key = key;
        ptr -> left = ptr->right = NULL;
        if(head->left){
            if(key < temp->key)
                temp->left = ptr;                    //작을경우 왼쪽
            else
                temp->right = ptr;                   //클 경우 오른쪽
        }
        else
            head->left = ptr;                        //트리가 비어있으면 루트로 넣음
    }
}




int deleteLeafNode(Node* head, int key)
{
    if(head->left == NULL){      
        printf("there is no node\n");      
        return 0;
    }
    Node* ptr = head->left; Node* temp = searchIterative(head, key); //삭제하고자 하는 노드 위치를 받음

    if(!temp || (temp->left != NULL ||temp->right != NULL)){
        printf("there is no key or that node is no leaf node\n");  //key가 없거나 리프노드가 아니면 출력
        return 0;
    }
    else
    {
        while(ptr){
            if(ptr->left == temp || ptr->right == temp){  //자식노드를 확인
                if(ptr->left == temp){   
                    ptr->left = NULL;          //자식노드 가리키는 포인터를 NULL값으로 변경
                    free(temp);                //자식노드 해제
                    return 0;
                }
                if(ptr->right == temp){
                    ptr->right = NULL;
                    free(temp);
                    return 0;
                }
            }

            if(key > ptr->key)
                ptr = ptr->right;          //찾을 때까지 내려감
            else
                ptr = ptr->left;
        }
    }
}

Node* searchRecursive(Node* ptr, int key) //recursive방식으로 노드를 찾는 함수
{
    if(!ptr)
        return NULL;        
    if(key == ptr->key)
        return ptr;
    if(key < ptr->key)
        return searchRecursive(ptr->left, key);  //key값의 크기와 비교해 왼쪽으로 가거나 오른쪽으로 감
    return searchRecursive(ptr->right, key);
}

Node* modifiedSearch(Node* head, int key)  //새로 정의한 함수. 노드를 삽입할 때 사용한다.
{
    Node* ptr = head->left;
    while(ptr){
        if(key == ptr->key)
            return NULL;             //삽입하려는 key와 동일한 key발견하면 NULL리턴
        if(key < ptr->key){
            if(!ptr->left){
                return ptr;          //왼쪽이나 오른쪽 끝 노드에 도달하면 그 포인터 리턴
            }
            else
                ptr = ptr->left;
        }
        else{
            if(!ptr->right){
                return ptr;
            }
            else
                ptr = ptr->right;
        }
    }
    return NULL;                     
}
Node* searchIterative(Node* head, int key) //iterative방식으로 찾는 함수
{
    
    if(!head->left)              //트리가 비어있으면 NULL리턴
        return NULL;
    Node* ptr = head->left;
    while(ptr){
        if(key == ptr->key)      //key값을 찾으면 그 노드 포인터 리턴
            return ptr;
        if(key < ptr->key)
            ptr = ptr->left;
        else
            ptr = ptr->right;    //찾을때 까지 왼쪽 또는 오른쪽으로 내려감
    }
    return NULL;                 //못 찾으면 NULL리턴
}


int freeBST(Node* head)   //postorder방식을 이용. 모든 왼쪽 오른쪽 노드들을 해제하고 마지막에 루트 노드 해제
{
    if(!head){
        freeBST(head->left);
        freeBST(head->right);
        free(head);
    }
    
    
}




