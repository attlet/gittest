package lib;
import java.util.Scanner;
import java.util.Vector;
import java.util.HashMap;
import java.util.Set;
import java.util.Iterator;

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
		HashMap<String, String> map = new HashMap<>();
		Vector<Nation> n = new Vector<Nation>();
		
		do {
			System.out.println("**** 수도 맞추기 게임을 시작합니다. ****");
			System.out.println("입력: 1, 퀴즈: 2, 종료: 3 >>");
			choice = scanner.nextInt();
			switch(choice) {
			case 1:
				System.out.println("현재 " + map.size() + "개 나라와 수도가 입력되어 있습니다.");
				for(int i = map.size();   ; i++) {
					System.out.println("나라와 수도 입력"+ (i+1) + ">>");
					String country = scanner.next();
					if(country.equals("그만")) break;
					if(map.containsKey(country)) {
						System.out.println(country+ "는 이미 있습니다!");
						i--;
					}
					String capital = scanner.next();
					map.put(country, capital);
				    
						
				}
				break;
			case 2:
				String answer;
				Set<String> keys = map.keySet();
				Iterator<String> it = keys.iterator();
				
				while(it.hasNext()) {
					String key = it.next();
					if(map.isEmpty()) {
						System.out.println("입력한 값이 없습니다.");
						break;
					}
					System.out.println(key + " 의 수도는?");
					answer = scanner.next();
					if(answer.equals("그만")) break;
					
					if(answer.equals(map.get(key))) 
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
