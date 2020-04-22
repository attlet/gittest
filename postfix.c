/*
 * postfix.c
 *
 *  2020 Data Structures, Homework #5
 *  Department of Computer Science at Chungbuk National University
 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STACK_SIZE 10
#define MAX_EXPRESSION_SIZE 20

 /* stack 내에서 우선순위, lparen = 0 가장 낮음 */
typedef enum {
	lparen = 0,  /* ( 왼쪽 괄호 */
	rparen = 9,  /* ) 오른쪽 괄호*/
	times = 7,   /* * 곱셈 */
	divide = 6,  /* / 나눗셈 */
	plus = 5,    /* + 덧셈 */
	minus = 4,   /* - 뺄셈 */
	operand = 1 /* 피연산자 */
} precedence;


char infixExp[MAX_EXPRESSION_SIZE];   	/* infix expression을 저장하는 배열 */
char postfixExp[MAX_EXPRESSION_SIZE];	/* postfix로 변경된 문자열을 저장하는 배열 */
char postfixStack[MAX_STACK_SIZE];	/* postfix로 변환을 위해 필요한 스택 */
int evalStack[MAX_STACK_SIZE];		/* 계산을 위해 필요한 스택 */

int postfixStackTop = -1;  /* postfixStack용 top */
int evalStackTop = -1;	   /* evalStack용 top */

int evalResult = 0;	   /* 계산 결과를 저장 */

void postfixPush(char x)
{
	postfixStack[++postfixStackTop] = x;
}

char postfixPop()
{
	char x;
	if (postfixStackTop == -1)
		return '\0';
	else {
		x = postfixStack[postfixStackTop--];
	}
	return x;
}


void evalPush(int x)
{
	evalStack[++evalStackTop] = x;
}

int evalPop()
{
	if (evalStackTop == -1)
		return -1;
	else
		return evalStack[evalStackTop--];
}


/**
 * infix expression을 입력받는다.
 * infixExp에는 입력된 값을 저장한다.
 */
void getInfix()
{
	printf("Type the expression >>> ");
	scanf("%s", infixExp);
}

precedence getToken(char symbol)
{
	switch (symbol) {
	case '(': return lparen;
	case ')': return rparen;
	case '+': return plus;
	case '-': return minus;
	case '/': return divide;
	case '*': return times;
	default: return operand;
	}

}

precedence getPriority(char x)
{
	return getToken(x);
}

/**
 * 문자하나를 전달받아 postfixexp에 추가
 */
void charCat(char* c)
{
	if (postfixExp == "\0")
		strncpy(postfixExp, c, 1);
	else
		strncat(postfixExp, c, 1);
}

/**
 * infixExp의 문자를 하나씩 읽어가면서stack을 이용하여 postfix로 변경한다.
 * 변경된 postfix는 postFixExp에 저장된다..
 */
void toPostfix()
{
	/* infixExp의 문자 하나씩을 읽기위한 포인터*/
	char* exp = infixExp;
	char x; /* 문자하나를 임시로 저장하기 위한 변수*/

	/*exp를 증가시켜가면서, 문자를 읽고 postfix로 변경*/
	while (*exp != '\0')
	{
		precedence token = getPriority(*exp); //infix문자열에서 문자하나를 token에 받는다.
		if (token == operand) {  //피연산자일 경우
			charCat(exp);        //스택에 넣지 않고 바로 배열로 들어간다.
		}
		else if (token == rparen) { //오른쪽 괄호일 경우
			while (getPriority(postfixStack[postfixStackTop]) != lparen) {  //왼쪽괄호가 나올때까지 pop시킨다.
					x = postfixPop();
					charCat(&x);
			}
			postfixPop();  //그 뒤에 왼쪽 괄호도 삭제
		}
		else if (token == lparen) {  //왼쪽괄호일 경우 바로 스택에 push한다.
			postfixPush(*exp);
		}
		else {
			while ((postfixStackTop >=0)&&getPriority(postfixStack[postfixStackTop]) >= token) { //연산자일 경우
				x = postfixPop();  //스택에 있는 연산자가 우선순위가 높을 경우 top원소를 pop한다.
				charCat(&x);       //그 뒤 배열에 넣는다.
			}
			postfixPush(*exp);     //스택이 비어있거나, 연산자 우선순위가 token이 더 높다면 스택에 push한다.
		}
		*++exp; //다음 문자 이동
	}
	while(postfixStackTop != -1){   //스택에 남아있는 연산자들을 pop시킨다.
		x = postfixPop();
        charCat(&x);
	}
}
void debug()
{
	printf("\n---DEBUG\n");
	printf("infixExp =  %s\n", infixExp);
	printf("postExp =  %s\n", postfixExp);
	printf("eval result = %d\n", evalResult);

	printf("postfixStack : ");
	for (int i = 0; i < MAX_STACK_SIZE; i++)
		printf("%c  ", postfixStack[i]);

	printf("\n");

}

void reset()
{
	infixExp[0] = '\0';
	postfixExp[0] = '\0';

	for (int i = 0; i < MAX_STACK_SIZE; i++)
		postfixStack[i] = '\0';

	postfixStackTop = -1;
	evalStackTop = -1;
	evalResult = 0;
}

void evaluation()
{
	int op1, op2;
	char* exp = postfixExp;
	while (*exp != '\0') {
		precedence token = getPriority(*exp);  

		if (token == operand)  //token이 피연산자 라면 push한다.
			evalPush(*exp - '0');  //0의 아스키 코드값을 빼면 숫자가 된다. 

		else {
			op2 = evalPop();  
			op1 = evalPop();  
			switch (token) {  //연산자 일 경우 연산 실행
			case plus: evalPush(op1 + op2);
				break;

			case minus: evalPush(op1 - op2);
				break;

			case times: evalPush(op1 * op2);
				break;

			case divide: evalPush(op1 / op2); //evalstack에는 피연산자만 저장됨. 
				break;
			}
		}
		*++exp;
	}
	evalResult = evalPop(); //연산결과가 evalstacktop에 있으니 그걸 pop시킨다.


	//evalResult;
	/* postfixExp, evalStack을 이용한 계산*/
}


int main()
{
	char command;
    printf("-----------------이름: 신윤성 학번:2017038015----------\n");
	do {
		printf("----------------------------------------------------------------\n");
		printf("               Infix to Postfix, then Evaluation               \n");
		printf("----------------------------------------------------------------\n");
		printf(" Infix=i,   Postfix=p,  Eval=e,   Debug=d,   Reset=r,   Quit=q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch (command) {
		case 'i': case 'I':
			getInfix();
			break;
		case 'p': case 'P':
			toPostfix();
			break;
		case 'e': case 'E':
			evaluation();
			break;
		case 'd': case 'D':
			debug();
			break;
		case 'r': case 'R':
			reset();
			break;
		case 'q': case 'Q':
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	} while (command != 'q' && command != 'Q');

	return 0;


}