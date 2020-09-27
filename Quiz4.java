import java.util.Scanner;
import java.util.InputMismatchException;

class Seat{
	static String S[] = { "---", "---", "---" , "---", "---", "---","---", "---", "---", "---"};
	static String A[] = { "---", "---", "---" , "---", "---", "---","---", "---", "---", "---"};
	static String B[] = { "---", "---", "---" , "---", "---", "---","---", "---", "---", "---"};
	
	static int Printseat(int n){
		String T[];
		char j = ' ';
		switch(n) {
		case 1:
			T = S;
			j = 'S'; break;
		case 2:
			T = A; 
			j = 'A'; break;
		case 3:
			T = B;
			j = 'B'; break;
		default:
			System.out.println("�߸� �Է��߽��ϴ�.");  return 0;
		}
		System.out.print(j + ">>");
		for(int i = 0;i<10 ; i++) {
			System.out.print(T[i]+" ");
		}
		System.out.print("\n");
		return 1;
	}
	
	static void reserving(int seat1, int seat2, String name) {
		String T[];
		switch(seat1) {
		case 1:
			T = S;  break;
		case 2:
			T = A;  break;
		case 3:
			T = B;  break;
		default:
			System.out.println("�߸� �Է��߽��ϴ�.");  return;
		}
		
		for(int i = 0; i < 10 ;i++) {
			if((i+1) == seat2) {
				T[i] = name;
			}
		}
	}
	
	static void printallseat() {
		for(int i = 0; i<3 ; i++) {
			if(i == 0) {
				System.out.print("S>> ");
				for(int j = 0 ;j<10 ; j++) 
					System.out.print(S[j]+" ");
				System.out.print("\n");
			}
			else if(i == 1) {
				System.out.print("A>> ");
				for(int j = 0 ;j<10 ; j++) 
					System.out.print(A[j]+" ");
				System.out.print("\n");
			}
			else {
				System.out.print("B>> ");
				for(int j = 0 ;j<10 ; j++) 
					System.out.print(B[j]+" ");
				System.out.print("\n");
			}
		}
		
		System.out.println("��ȸ�� �Ϸ��߽��ϴ�.");
	}
	
	static void deletereserve(int n, String name) {
		String T[];
		switch(n) {
		case 1:
			T = S;  break;
		case 2:
			T = A;  break;
		case 3:
			T = B;  break;
		default:
			System.out.println("�߸� �Է��߽��ϴ�.");  return;
		}
		
		for(int i = 0 ;i<10 ; i++) {
			if(T[i].equals(name)) {
				T[i] = "---";
				return;
			}
		}
		
		System.out.println("����� �̸��� �����ϴ�.");
		return;
	}
}


public class Quiz4{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int choice_menu;
		int choice_seat;
		String name;
		int seatnum;
		
		System.out.println("��ǰ�ܼ�ƮȦ ���� �ý����Դϴ�.");
		while(true) {
			System.out.print("����:1   ��ȸ:2   ���:3   ������4>>");
			choice_menu = scanner.nextInt();
			switch(choice_menu) {
			case 1:
				System.out.print("�¼����� S(1), A(2), B(3)>>");
				choice_seat = scanner.nextInt();
				
				if(Seat.Printseat(choice_seat) == 0) {
					continue;
				}
				else {
					System.out.print("�̸�>>");
				    name = scanner.next();
				    System.out.print("��ȣ>>");
				    seatnum = scanner.nextInt();
				    Seat.reserving(choice_seat, seatnum, name);	
				}
				
				break;
			case 2:
				Seat.printallseat(); break;
			case 3:
				System.out.print("�¼����� S(1), A(2), B(3)>>");
				choice_seat = scanner.nextInt();
				if(Seat.Printseat(choice_seat) == 0) {
					continue;
				}
				else {
					System.out.print("�̸�>>");
				    name = scanner.next();
				    Seat.deletereserve(choice_seat,name);
				}
				break;
			case 4:
				System.out.print("�ý����� �����մϴ�.");
				return;
			default:
				System.out.println("���� �޴��Դϴ�.");
			}
			
		}
	
	}
}
