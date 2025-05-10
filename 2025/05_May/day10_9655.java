// 문제: 돌 게임
// 번호: 9655번
// 난이도: 실버5

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class day10_9655 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine()) % 4;
		if (n == 1 || n == 3) {
			bw.write("SK\n");
		} else if (n == 0 || n == 2) {
			bw.write("CY\n");
		}
		bw.flush();
		bw.close();
		br.close();
	}
}
