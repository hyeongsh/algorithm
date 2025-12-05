// 문제: 과자 나눠주기
// 번호: 16401번
// 난이도: 실버 2

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Arrays;

public class day05_16401 {
	static int M, N;
	static int[] sticks;

    public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		st = new StringTokenizer(br.readLine());
		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());

		sticks = new int[N];
		st = new StringTokenizer(br.readLine());
		int max = 0;
		for (int i = 0; i < N; i++) {
			sticks[i] = Integer.parseInt(st.nextToken());
			if (sticks[i] > max) {
				max = sticks[i];
			}
		}

		int start = 1;
		int end = max;
		int result = 0;
		while (start <= end) {
			int num = 0;
			int mid = (start + end) / 2;
			for (int i = N - 1; i >= 0; i--) {
				if (sticks[i] >= mid) {
					num += sticks[i] / mid;
				}
			}
			if (num < M) {
				end = mid - 1;
			} else {
				if (mid > result) {
					result = mid;
				}
				start = mid + 1;
			}
			// System.out.println("mid/num: " + mid + " / " + num);
		}
		bw.write(result + "\n");
		bw.close();
		br.close();
	}
}

