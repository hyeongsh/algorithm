// 문제: 로프
// 번호: 2217번
// 난이도: 실버 4

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.IOException;

public class day01_2217 {
    public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int n = Integer.parseInt(br.readLine());
		int[] ropes = new int[n];
		for (int i = 0; i < n; i++) {
			ropes[i] = Integer.parseInt(br.readLine());
		}
		Arrays.sort(ropes);
		int max = 0;
		for (int i = 0; i < n; i++) {
			int weight = ropes[i] * (n - i);
			if (weight > max) {
				max = weight;
			}
		}
		bw.write(max + "\n");
		bw.flush();
		br.close();
		bw.close();
	}

}

