package lib;
import java.util.Scanner;

class Person{
	String name;
	int a, b, c;
	
	public boolean equals() {
		if((a == b) && (a==c) && (b==c)) {
			return true;
		}
		else
			return false;
	}
	
	public boolean init(String str) {
		
		if(str.equals("Enter")) {
			this.a = (int)(Math.random()*3+1);
			this.b = (int)(Math.random()*3+1);
			this.c = (int)(Math.random()*3+1);
			
			System.out.print(a + " " + b + " " + c + " ");
			if(this.equals()) {
				System.out.print(this.name + "님이 이겼습니다!");
				return false;
			}
			else
				System.out.println(" 아쉽군요!");
		}
		else {
			System.out.println("Enter를 입력하세요.잘못 입력하셨습니다.");
			return true;
		}
		return true;
	}
	
}
public class Quiz6 {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String temp;
		Person p1 = new Person();
		Person p2 = new Person();
		System.out.print("첫 번째 선수 이름>>");
		p1.name = scanner.next();
		System.out.print("두 번째 선수 이름>>");
		p2.name = scanner.next();
	    
		while(true) {
			System.out.print("[" + p1.name + "]: ");
			temp = scanner.next();
			if(!(p1.init(temp)))
				break;
			
			scanner.nextLine();
			System.out.print("[" + p2.name + "]: ");
			temp = scanner.next();
			if(!(p2.init(temp)))
				break;
			
			scanner.nextLine();
		}
		scanner.close();
	}
}
