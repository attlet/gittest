import java.util.Scanner;

public class Quiz2 {

	public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
		
		System.out.print("연산>>");
		float x = scanner.nextFloat();
		String op = scanner.next();
		float y = scanner.nextFloat();
		
		switch(op) {
		case "+":
			System.out.print(x + op + y + "의 계산 결과는" + (x+y)); break;
		case "-":
			System.out.print(x + op + y + "의 계산 결과는" + (x-y)); break;
		case "*":
			System.out.print(x + op + y + "의 계산 결과는" + (x*y)); break;
		case "/":
			if(y == 0) {
				System.out.print("0으로 나눌 수 없습니다.");
			}
			else {
				System.out.print(x + op + y + "의 계산 결과는" + (x/y));
			}
			break;
		}
	
		scanner.close();
	}

}
