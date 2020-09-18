import java.util.Scanner;
import java.util.InputMismatchException;



public class Quiz3_1{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		int n = 0;
		int m = 0;
		while(true) {
			System.out.print("���ϰ��� �ϴ� �� �� �Է�>>");
			try {
				n = scanner.nextInt();
		        m = scanner.nextInt();
			}
			catch(InputMismatchException e){
				System.out.println("�Ǽ��� �Է��ϸ� �ȵ˴ϴ�.");
				scanner.nextLine();
				continue;
			}
			System.out.println(n + "X" + m + "=" + n*m);
			break;
		}
		scanner.close();
	}
}
