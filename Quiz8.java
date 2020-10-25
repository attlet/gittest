package lib;
import java.io.*;
import java.util.*;

public class Quiz8 {
	private File targetFile = null;
	Vector<String> lineVector = new Vector<String>();
	

	private void readFile(String fileName) {
		targetFile = new File(fileName);
		try {
			Scanner fScanner = new Scanner(new FileReader(targetFile));
			while(fScanner.hasNext()) { // 파일을 라인 단위로 모두 읽기
				String line = fScanner.nextLine(); // 한 라인 읽고
				lineVector.add(line); // 한 라인을 벡터에 저장
			}			
			fScanner.close();
			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
	
	private Vector<Integer> searchWord(String word) { // word가 포함된 라인 번호들을 벡터로 리턴
		Vector<Integer> noVector = new Vector<Integer>();
		for(int i=0; i<lineVector.size(); i++) {
			String line = lineVector.get(i);
			if(line.indexOf(word) != -1) 
				noVector.add(i);
		}
		
		return noVector;
	}

	private void printLines(Vector<Integer> noVector) {
		for(int i=0; i<noVector.size(); i++) {
			int lineNo = noVector.get(i);
			String line = lineVector.get(lineNo);
			System.out.println(lineNo + ":" + line);
		}
	}
	
	public void run() {
		System.out.println("전체 경로명이 아닌 파일 이름만 입력하는 경우, 파일은 프로젝트 폴더에 있어야 합니다.");
		System.out.print("대상 파일명 입력>> ");
		Scanner scanner = new Scanner(System.in);
		String fileName = scanner.nextLine();

		readFile(fileName); // 파일을 라인 단위로 벡터로 읽어들임
		
		while(true) {
			System.out.print("검색할 단어나 문장>> ");
			String line = scanner.nextLine();
			if(line.equals("그만"))
				break; // 프로그램 종료
			Vector<Integer> noVector = searchWord(line); // line의 단어를 포함하는모든 라인 번호 리턴
			printLines(noVector);
		}
		scanner.close();
		System.out.println("프로그램을 종료합니다.");
	}
	public static void main(String[] args) {
		FileReaderEx ws = new FileReaderEx();
		ws.run();
	}
}