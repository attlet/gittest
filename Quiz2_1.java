import java.util.Scanner;

public class Quiz2_1 {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("����>>");
		float x = scanner.nextFloat();
		String op = scanner.next();
		float y = scanner.nextFloat();
		
		if(op.equals("+")) {
			System.out.print(x + op + y + "�� ��� �����" + (x+y));
		}
		else if(op.equals("-")) {
			System.out.print(x + op + y + "�� ��� �����" + (x-y));
		}
		else if(op.equals("*")) {
			System.out.print(x + op + y + "�� ��� �����" + (x*y));
		}
		else if(op.equals("/")) {
			if(y == 0) {
				System.out.print("0���� ���� �� �����ϴ�.");
			}
			else {
				System.out.print(x + op + y + "�� ��� �����" + (x/y));
			}
			
		}
		
		
		scanner.close();
	}

}
