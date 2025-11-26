// 문제: 수 이어 쓰기 1
// 번호: 1748번
// 난이도: 실버 4

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.io.IOException;

public class day26_1748 {
    public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int n = Integer.parseInt(br.readLine());
		int threshold = 9;
		int digits = 1;
		long num = 0;
		while (true) {
			if (n > threshold) {
				num += (threshold - threshold / 10) * digits;
			} else {
				num += (n - threshold / 10) * digits;
				break ;
			}
			threshold = threshold * 10 + 9;
			digits += 1;
		}
		bw.write(num + "\n");
		bw.flush();
	}
}
