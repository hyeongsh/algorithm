// 문제: 회사에 있는 사람
// 번호: 7785번
// 난이도: 실버5

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.TreeMap;

public class day09_7785 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		TreeMap<String, String> map = new TreeMap<String, String>();
		int n = Integer.parseInt(br.readLine());
		while (n-- > 0) {
			String[] str = br.readLine().split(" ");
			if (str[1].equals("enter")) {
				map.put(str[0], str[1]);
			} else if (str[1].equals("leave")) {
				map.remove(str[0]);
			}
		}

		for (String people : map.descendingMap().keySet()) {
			bw.write(people + "\n");
		}
		
		bw.flush();
		bw.close();
		br.close();
	}
}
