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
    printf("==========�̸�:������ �й�:2017038015==========");
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



void inorderTraversal(Node* ptr)   //���� ��ȸ
{
    if(ptr){
    inorderTraversal(ptr->left);
    printf(" %d ", ptr->key);
    inorderTraversal(ptr->right);      //���� ���� ������ �� ����,      
    }                                  //�װ��� �湮�ϰ� ������ ���� �̵�. ������ �� ��� �ڷ� �̵�.
}

void preorderTraversal(Node* ptr)  //���� ��ȸ
{
    if(ptr){ 
    printf(" %d ",ptr->key);
    preorderTraversal(ptr->left);  
    preorderTraversal(ptr->right);     //��带 ����ϸ� ���ʳ��� �̵�
    }                                  //������ �� �� ���������� ��� �ǵ��ư�.
    
}

void postorderTraversal(Node* ptr)  //���� ��ȸ
{
    if(ptr){
        postorderTraversal(ptr->left);  
        postorderTraversal(ptr->right); //���� ������ ��带 ����� �� ���� ��带 ���.
        printf(" %d ",ptr->key);  
    }
}


int insert(Node* head, int key)
{
    Node* ptr; Node* temp = modifiedSearch(head, key); //���� ������ �Լ� ���. �����ϰ��� �ϴ� ����� �θ��� ����

    if(temp || !head->left){                         //�����ϰ��� �ϴ� ���� ��ġ�� key�� �ִ��� Ȯ��
        ptr = (Node*)malloc(sizeof(Node));           //�Ǵ� ��尡 ����� �� Ȯ��
        ptr->key = key;
        ptr -> left = ptr->right = NULL;
        if(head->left){
            if(key < temp->key)
                temp->left = ptr;                    //������� ����
            else
                temp->right = ptr;                   //Ŭ ��� ������
        }
        else
            head->left = ptr;                        //Ʈ���� ��������� ��Ʈ�� ����
    }
}




int deleteLeafNode(Node* head, int key)
{
    if(head->left == NULL){      
        printf("there is no node\n");      
        return 0;
    }
    Node* ptr = head->left; Node* temp = searchIterative(head, key); //�����ϰ��� �ϴ� ��� ��ġ�� ����

    if(!temp || (temp->left != NULL ||temp->right != NULL)){
        printf("there is no key or that node is no leaf node\n");  //key�� ���ų� ������尡 �ƴϸ� ���
        return 0;
    }
    else
    {
        while(ptr){
            if(ptr->left == temp || ptr->right == temp){  //�ڽĳ�带 Ȯ��
                if(ptr->left == temp){   
                    ptr->left = NULL;          //�ڽĳ�� ����Ű�� �����͸� NULL������ ����
                    free(temp);                //�ڽĳ�� ����
                    return 0;
                }
                if(ptr->right == temp){
                    ptr->right = NULL;
                    free(temp);
                    return 0;
                }
            }

            if(key > ptr->key)
                ptr = ptr->right;          //ã�� ������ ������
            else
                ptr = ptr->left;
        }
    }
}

Node* searchRecursive(Node* ptr, int key) //recursive������� ��带 ã�� �Լ�
{
    if(!ptr)
        return NULL;        
    if(key == ptr->key)
        return ptr;
    if(key < ptr->key)
        return searchRecursive(ptr->left, key);  //key���� ũ��� ���� �������� ���ų� ���������� ��
    return searchRecursive(ptr->right, key);
}

Node* modifiedSearch(Node* head, int key)  //���� ������ �Լ�. ��带 ������ �� ����Ѵ�.
{
    Node* ptr = head->left;
    while(ptr){
        if(key == ptr->key)
            return NULL;             //�����Ϸ��� key�� ������ key�߰��ϸ� NULL����
        if(key < ptr->key){
            if(!ptr->left){
                return ptr;          //�����̳� ������ �� ��忡 �����ϸ� �� ������ ����
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
Node* searchIterative(Node* head, int key) //iterative������� ã�� �Լ�
{
    
    if(!head->left)              //Ʈ���� ��������� NULL����
        return NULL;
    Node* ptr = head->left;
    while(ptr){
        if(key == ptr->key)      //key���� ã���� �� ��� ������ ����
            return ptr;
        if(key < ptr->key)
            ptr = ptr->left;
        else
            ptr = ptr->right;    //ã���� ���� ���� �Ǵ� ���������� ������
    }
    return NULL;                 //�� ã���� NULL����
}


int freeBST(Node* head)   //postorder����� �̿�. ��� ���� ������ ������ �����ϰ� �������� ��Ʈ ��� ����
{
    if(!head){
        freeBST(head->left);
        freeBST(head->right);
        free(head);
    }
    
    
}




