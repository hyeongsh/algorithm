// 문제: 약수의 합 2
// 번호: 17427
// 난이도: 실버 2

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class day04_17427 {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static int n;

    public static void main(String[] args) throws IOException {
        input();
		findAnswer();
        bw.flush();
        bw.close();
        br.close();
    }

    private static void input() throws IOException {
		String line = br.readLine();
		n = Integer.parseInt(line);
    }

	private static void findAnswer() throws IOException {
		long sum = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j += i) {
				sum += i;
			}
		}
		bw.write(sum + "\n");
	}
}