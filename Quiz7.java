package lib;
import java.util.Scanner;
import java.util.Vector;


class Nation{
	String country, capital;
	
	public Nation(String country, String capital) {
		this.country = country;
		this.capital = capital;
	}
}
public class Quiz7 {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		int choice;
		Vector<Nation> n = new Vector<Nation>();
		
		do {
			System.out.println("**** 수도 맞추기 게임을 시작합니다. ****");
			System.out.println("입력: 1, 퀴즈: 2, 종료: 3 >>");
			choice = scanner.nextInt();
			switch(choice) {
			case 1:
				System.out.println("현재 " + n.size() + "개 나라와 수도가 입력되어 있습니다.");
				for(int i = n.size();   ; i++) {
					System.out.println("나라와 수도 입력"+ (i+1) + ">>");
					String country = scanner.next();
					if(country.equals("그만")) break;
					String capital = scanner.next();
					if(n.contains(new Nation(country, capital))) {
						System.out.println(country+ "는 이미 있습니다!");
						i--;
					}
					else
						n.add(new Nation(country, capital));
				}
				break;
			case 2:
				String answer;
				while(true) {
					if(n.size() == 0) {
						System.out.println("입력한 값이 없습니다.");
						break;
					}
					int randomindex = (int)(Math.random()*n.size());
					Nation p = n.get(randomindex);
					System.out.println(p.country + " 의 수도는?");
					answer = scanner.next();
					if(answer.equals("그만")) break;
					
					if(answer.equals(p.capital)) 
						System.out.println("정답!!");
					else
						System.out.println("아닙니다!!");
						
				}
				break;
				
			case 3:
				System.out.print("게임을 종료합니다.");
				break;
			}
		}while(choice != 3);
		
		scanner.close();
		
	}
	
}
