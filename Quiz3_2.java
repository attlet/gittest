import java.util.Scanner;

public class Quiz3_2{

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("컴퓨터와 가위 바위 보 게임을 합니다.");
		String myturn;
		String str[] = {"가위" , "바위", "보"};
		int mynum;
		int n;
		while(true) {
			System.out.println("가위 바위 보!>>");
			myturn = scanner.next();
			if(myturn.equals("가위")) {
				mynum = 0;
			}
			else if(myturn.equals("바위")) {
				mynum = 1;
			}
			else if(myturn.equals("보자기")) {
				mynum = 2;
			}
			else if(myturn.equals("그만")){
				System.out.print("게임을 종룝합니다...");
				break;
			}
			else {
				System.out.println("잘못 입력했습니다.");
				continue;
			}
			
			
			n = (int)(Math.random()*3);
			
			
			if(str[n].equals(myturn)) {
				System.out.println("사용자 = " + myturn + "컴퓨터 = " + str[n] + " 비겼습니다.");
			}
			else if((mynum == 0 && n == 1) ||( mynum == 1 && n == 2)||(mynum == 2 && n == 0)) {
				System.out.println("사용자 = " + myturn + "컴퓨터 = " + str[n] + " 졌습니다.");
			}
			else if((mynum == 0 && n == 2) ||( mynum == 1 && n == 0)||(mynum == 2 && n == 1)) {
				System.out.println("사용자 = " + myturn + "컴퓨터 = " + str[n] + " 이겼습니다.");
			}
		}
		scanner.close();
	}
	
}
