import java.util.Scanner;

public class Quiz3_2{

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("��ǻ�Ϳ� ���� ���� �� ������ �մϴ�.");
		String myturn;
		String str[] = {"����" , "����", "��"};
		int mynum;
		int n;
		while(true) {
			System.out.println("���� ���� ��!>>");
			myturn = scanner.next();
			if(myturn.equals("����")) {
				mynum = 0;
			}
			else if(myturn.equals("����")) {
				mynum = 1;
			}
			else if(myturn.equals("���ڱ�")) {
				mynum = 2;
			}
			else if(myturn.equals("�׸�")){
				System.out.print("������ �����մϴ�...");
				break;
			}
			else {
				System.out.println("�߸� �Է��߽��ϴ�.");
				continue;
			}
			
			
			n = (int)(Math.random()*3);
			
			
			if(str[n].equals(myturn)) {
				System.out.println("����� = " + myturn + "��ǻ�� = " + str[n] + " �����ϴ�.");
			}
			else if((mynum == 0 && n == 1) ||( mynum == 1 && n == 2)||(mynum == 2 && n == 0)) {
				System.out.println("����� = " + myturn + "��ǻ�� = " + str[n] + " �����ϴ�.");
			}
			else if((mynum == 0 && n == 2) ||( mynum == 1 && n == 0)||(mynum == 2 && n == 1)) {
				System.out.println("����� = " + myturn + "��ǻ�� = " + str[n] + " �̰���ϴ�.");
			}
		}
		scanner.close();
	}
	
}
