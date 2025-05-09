// 문제: 슈퍼 마리오
// 번호: 2851번
// 난이도: 브론즈 1

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class day07_2851 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int sum = 0;

		for (int i = 0; i < 10; i++) {
			int newSum = sum + Integer.parseInt(br.readLine());
			if (Math.abs(newSum - 100) <= Math.abs(sum - 100)) {
				sum = newSum;
			} else {
				break ;
			}
		}
		bw.write(Integer.toString(sum) + "\n");

		bw.flush();
		bw.close();
		br.close();
	}
}