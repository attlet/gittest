import java.util.Scanner;

public class Quiz2 {

	public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
		
		System.out.print("����>>");
		float x = scanner.nextFloat();
		String op = scanner.next();
		float y = scanner.nextFloat();
		
		switch(op) {
		case "+":
			System.out.print(x + op + y + "�� ��� �����" + (x+y)); break;
		case "-":
			System.out.print(x + op + y + "�� ��� �����" + (x-y)); break;
		case "*":
			System.out.print(x + op + y + "�� ��� �����" + (x*y)); break;
		case "/":
			if(y == 0) {
				System.out.print("0���� ���� �� �����ϴ�.");
			}
			else {
				System.out.print(x + op + y + "�� ��� �����" + (x/y));
			}
			break;
		}
	
		scanner.close();
	}

}
