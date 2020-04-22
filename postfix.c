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

 /* stack ������ �켱����, lparen = 0 ���� ���� */
typedef enum {
	lparen = 0,  /* ( ���� ��ȣ */
	rparen = 9,  /* ) ������ ��ȣ*/
	times = 7,   /* * ���� */
	divide = 6,  /* / ������ */
	plus = 5,    /* + ���� */
	minus = 4,   /* - ���� */
	operand = 1 /* �ǿ����� */
} precedence;


char infixExp[MAX_EXPRESSION_SIZE];   	/* infix expression�� �����ϴ� �迭 */
char postfixExp[MAX_EXPRESSION_SIZE];	/* postfix�� ����� ���ڿ��� �����ϴ� �迭 */
char postfixStack[MAX_STACK_SIZE];	/* postfix�� ��ȯ�� ���� �ʿ��� ���� */
int evalStack[MAX_STACK_SIZE];		/* ����� ���� �ʿ��� ���� */

int postfixStackTop = -1;  /* postfixStack�� top */
int evalStackTop = -1;	   /* evalStack�� top */

int evalResult = 0;	   /* ��� ����� ���� */

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
 * infix expression�� �Է¹޴´�.
 * infixExp���� �Էµ� ���� �����Ѵ�.
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
 * �����ϳ��� ���޹޾� postfixexp�� �߰�
 */
void charCat(char* c)
{
	if (postfixExp == "\0")
		strncpy(postfixExp, c, 1);
	else
		strncat(postfixExp, c, 1);
}

/**
 * infixExp�� ���ڸ� �ϳ��� �о�鼭stack�� �̿��Ͽ� postfix�� �����Ѵ�.
 * ����� postfix�� postFixExp�� ����ȴ�..
 */
void toPostfix()
{
	/* infixExp�� ���� �ϳ����� �б����� ������*/
	char* exp = infixExp;
	char x; /* �����ϳ��� �ӽ÷� �����ϱ� ���� ����*/

	/*exp�� �������Ѱ��鼭, ���ڸ� �а� postfix�� ����*/
	while (*exp != '\0')
	{
		precedence token = getPriority(*exp); //infix���ڿ����� �����ϳ��� token�� �޴´�.
		if (token == operand) {  //�ǿ������� ���
			charCat(exp);        //���ÿ� ���� �ʰ� �ٷ� �迭�� ����.
		}
		else if (token == rparen) { //������ ��ȣ�� ���
			while (getPriority(postfixStack[postfixStackTop]) != lparen) {  //���ʰ�ȣ�� ���ö����� pop��Ų��.
					x = postfixPop();
					charCat(&x);
			}
			postfixPop();  //�� �ڿ� ���� ��ȣ�� ����
		}
		else if (token == lparen) {  //���ʰ�ȣ�� ��� �ٷ� ���ÿ� push�Ѵ�.
			postfixPush(*exp);
		}
		else {
			while ((postfixStackTop >=0)&&getPriority(postfixStack[postfixStackTop]) >= token) { //�������� ���
				x = postfixPop();  //���ÿ� �ִ� �����ڰ� �켱������ ���� ��� top���Ҹ� pop�Ѵ�.
				charCat(&x);       //�� �� �迭�� �ִ´�.
			}
			postfixPush(*exp);     //������ ����ְų�, ������ �켱������ token�� �� ���ٸ� ���ÿ� push�Ѵ�.
		}
		*++exp; //���� ���� �̵�
	}
	while(postfixStackTop != -1){   //���ÿ� �����ִ� �����ڵ��� pop��Ų��.
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

		if (token == operand)  //token�� �ǿ����� ��� push�Ѵ�.
			evalPush(*exp - '0');  //0�� �ƽ�Ű �ڵ尪�� ���� ���ڰ� �ȴ�. 

		else {
			op2 = evalPop();  
			op1 = evalPop();  
			switch (token) {  //������ �� ��� ���� ����
			case plus: evalPush(op1 + op2);
				break;

			case minus: evalPush(op1 - op2);
				break;

			case times: evalPush(op1 * op2);
				break;

			case divide: evalPush(op1 / op2); //evalstack���� �ǿ����ڸ� �����. 
				break;
			}
		}
		*++exp;
	}
	evalResult = evalPop(); //�������� evalstacktop�� ������ �װ� pop��Ų��.


	//evalResult;
	/* postfixExp, evalStack�� �̿��� ���*/
}


int main()
{
	char command;
    printf("-----------------�̸�: ������ �й�:2017038015----------\n");
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