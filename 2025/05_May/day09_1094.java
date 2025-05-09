// 문제: 막대기
// 번호: 1094번
// 난이도: 실버5

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class day09_1094 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int x = Integer.parseInt(br.readLine());
		int total = 128;
		int sticks = 0;
		while (x != 0) {
			total /= 2;
			if (total <= x) {
				sticks++;
				x -= total;
			}
		}
		bw.write(sticks + "\n");
		bw.flush();
		bw.close();
		br.close();
	}
}
