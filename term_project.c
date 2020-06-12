#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTEX 20 /* you can change value 20 */
#define MAX_Q 20
#define False 0
#define True 1

typedef struct Vertex {
	int num; /* vertex number */
	struct Vertex* link; /* link to a next adjacent vertext */
} Vertex;

typedef struct VertexHead {
	short int act; /*정점의 활성화 상태*/
	Vertex* head; /* linked list of all adjacent vertices */
} VertexHead;

typedef struct Graph {
	int vertexnum;
	VertexHead* vlist; /* list of all vertices: vlist[MAX_VERTEX] */
}Graph;

typedef struct queue{    //queue소스, 다중 큐 형태로 구현.
	int data;
	struct queue* link;
}queue;
queue* front = NULL;
queue* rear = NULL;    //큐에서 쓰이는 front와 rear

void createGraph(Graph* h); /* empty graph creation */
void destroyGraph(Graph* h); /* deallocating all allocated memory */
void insertVertex(Graph* h, int v); /* vertex insertion */
void deleteVertex(Graph* h, int key); /* vertex deletion */
void insertEdge(Graph* h, int v, int u); /* new edge creation between two vertices */
void deleteEdge(Graph* h, int v, int u); /* edge removal */
void depthFS(Graph *h, int v); /* depth firt search using stack */
void breadthFS(Graph *h, int v); /* breadth first search using queue */
void printGraph(Graph* h); /* printing graph with vertices and edges */

void addq(int x);
int deleteq();
int q_empty();         //큐 제어 함수


short int visited[MAX_VERTEX];  //방문했는 지 체크

int main() {
	char command;
	int i, key, key2;
	Graph graph;
	graph.vertexnum = 0;
	graph.vlist = NULL;
	
	printf("==========이름:신윤성 학번:2017038015==========");
	do {
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                        term project                            \n");
		printf("----------------------------------------------------------------\n");
		printf(" Create Graph         = z                                       \n");
		printf(" Destroy Graph        = g      Delete Vertex                 = d\n");
		printf(" Insert Vertex        = i      Insert Edge                   = e\n");
		printf(" Delete Edge          = p      Depth First Search            = f\n");
		printf(" Breadth First Search = b      Print Graph                   = r\n");
		printf(" Quit                 = q                                       \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch (command) {
		case 'z': case 'Z':
			createGraph(&graph);
			break;
		case 'g': case 'G':
			destroyGraph(&graph);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteVertex(&graph, key);
			break;
		case 'i': case 'I':
			printf("Your key = ");
			scanf("%d", &key);
			insertVertex(&graph, key);
			break;
		case 'e': case 'E':
			printf("vertex1 and 2 = ");
			scanf("%d%d", &key, &key2);
			insertEdge(&graph, key, key2);
			break;
		case 'p': case 'P':
			printf("delete edge(two vertex input) = ");
			scanf("%d%d", &key, &key2);
			deleteEdge(&graph, key, key2);
			break;
		case 'f': case 'F':
			for (i = 0;i < MAX_VERTEX;i++) {
				visited[i] = False;
			}
			printf("set dfs start = ");
			scanf("%d", &key);
			depthFS(&graph, key);
			break;
		case 'b': case 'B':
			for (i = 0;i < MAX_VERTEX;i++) {
				visited[i] = False;
			}
			printf("set bfs start = ");
			scanf("%d", &key);
			breadthFS(&graph, key);
			break;
		case 'r': case 'R':
			printGraph(&graph);
			break;
		case 'q': case 'Q':
		    destroyGraph(&graph);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	} while (command != 'q' && command != 'Q');

}

void createGraph(Graph* h) {
	int i;
	if (h->vlist != NULL)
		destroyGraph(h);
	h->vlist = (VertexHead*)malloc(sizeof(VertexHead) * MAX_VERTEX); //동적할당으로 vertex 공간들 생성.
	for (i = 0;i < MAX_VERTEX;i++) {
		h->vlist[i].head = NULL;
		h->vlist[i].act = False;    //모든 vertex 비활성화
	}
}                                /* empty graph creation */

void destroyGraph(Graph* h) {
	int i, j;
	Vertex* now;
	Vertex* next;

	for (i = 0; i < MAX_VERTEX;i++) {
		now = h->vlist[i].head;       //0번째 vertex 부터 
		while (now != NULL) {
			next = now->link;
			free(now);
			now = next;               //vertex의 edge들 전부 free
		}
	}
} /* deallocating all allocated memory */

void insertVertex(Graph* h, int v) {
	if ((h->vertexnum) + 1 > MAX_VERTEX) {
		printf("too many vertex\n");
		return;
	}
	h->vertexnum++;           //총 vertex수 증가
	h->vlist[v].act = True;   //v번째 vlist 활성화. 
} /* vertex insertion */

void deleteVertex(Graph* h, int v) {
	int i;
	Vertex* now;
	Vertex* next;
	now = h->vlist[v].head;    //edge정보 저장
	if(h->vlist[v].act == False){
		printf("that vertex is not exist\n");
	}

	while (now != NULL) {
		next = now->link;      //다음 edge로 이동
		free(now);             //할당 해제
		now = next;
	}
	h->vertexnum--;
	h->vlist[v].act = False;  //그 vertex 비활성화
} /* vertex deletion */

void insertEdge(Graph* h, int v, int u) {
	Vertex* node;
	if (v > MAX_VERTEX || u > MAX_VERTEX || !(h->vlist[v].act) || !(h->vlist[u].act)) { //맥스 값을 넘거나 비활성화된 vertex면
		printf("that vertex is not exist\n");  //오류 출력
		return;
	}
	node = (Vertex*)malloc(sizeof(Vertex));  //노드 할당
	if (node == NULL) return;
	node->num = u;                   
	node->link = h->vlist[v].head;
	h->vlist[v].head = node;                 //vertex 바로 옆에 삽입. 
}/* new edge creation between two vertices */

void deleteEdge(Graph* h, int v, int u) {
	if (v > MAX_VERTEX || u > MAX_VERTEX) {
		printf("that vertex is not exist\n");
		return;
	}
	Vertex* ptr = h->vlist[v].head;   //지우고자 하는 위치 저장
	Vertex* temp = NULL;
	while (ptr != NULL) {
		if (ptr->num == u) {        //vertex바로 옆에 값이 지우고자 하는 값이면
			h->vlist[v].head = ptr->link;
			free(ptr);
			return;
		}
		else if (ptr->link->num == u) { //다음값을 비교함
			temp = ptr->link;
			ptr->link = temp->link;
			free(temp);
		}
		else
		    ptr = ptr->link;      //찾을 때까지 이동
	}


} /* edge removal */
void depthFS(Graph *h, int v) {
	int i;
	Vertex* p;
	VertexHead* ptr = h->vlist;

	visited[v] = True;                //첫 노드 방문
	printf(" [%d] ", v);
	for (p = ptr[v].head;p;p = p->link)  //가로로 이동
		if (!visited[p->num])            //방문이 안 되어있다면
			depthFS(h, p->num);        //recursive방식
}  /* depth firt search using stack */

void breadthFS(Graph *h, int v) {

	Vertex* p;
	VertexHead* ptr = h->vlist;   
	front = rear = NULL;
	printf(" [%d] ", v);
	visited[v] = True;       //첫 노드 방문
	addq(v);                 //큐에 저장
	while (front) {  
		v = deleteq();       
		for (p = ptr[v].head;p;p = p->link) {
			if (!visited[p->num]) { //방문이 안 되어있다면
				printf(" [%d] ", p->num);
				addq(p->num);
				visited[p->num] = True;  //방문
			}
		}
	}

} /* breadth first search using queue */
void printGraph(Graph* h) {
	int i, j;
	Vertex* ptr;
	printf("\n");
	for (i = 0;i < MAX_VERTEX;i++) {  

		if (h->vlist[i].act == True) {  //활성화 된 vertex들만 출력하도록 함
			ptr = h->vlist[i].head;
			printf(" [%d] ->", i);

			while (ptr != NULL) {       //vertex랑 연결된 edge들 출력
				printf(" %d ", ptr->num);
				ptr = ptr->link;
			}
			printf("\n\n");
		}
		
	}


} /* printing graph with vertices and edges */

void addq(int x) {
	queue* temp;
	temp = (queue*)malloc(sizeof(queue)); //연결리스트 형태의 큐
	if (temp == NULL) {
		printf("memory error\n");
		return;
	}
	else {
		temp->data = x;
		temp->link = NULL;
		if (q_empty()) {    //큐가 비어있다면
			front = temp;
			rear = temp;    //첫 부분에 삽입
		}
		else {
			rear->link = temp;  //맨 뒤에 삽입
			rear = temp;
		}
	}
}
int deleteq() {
	queue* temp = front;
	int item;
	if (q_empty()) {
		printf("queue is empty\n");
		return 0;
	}
	else {
		item = temp->data;  //front의 정보를 저장
		front = front->link; //front를 이동시킴
		if (front == NULL)
			rear = NULL;  
		free(temp);         
		return item;
	}
}

int q_empty() {
	return(front == NULL); //큐가 비었는지 체크
}
