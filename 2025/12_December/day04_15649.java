// 문제: N과 M (1)
// 번호: 15649번
// 난이도: 실버 3

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class day04_15649 {
	static BufferedWriter bw;
	static BufferedReader br;
	static int n, m;
	static int[] arr;
	static int[] vis;
    public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		bw = new BufferedWriter(new OutputStreamWriter(System.out));

		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		arr = new int[m];
		vis = new int[n];
		backTracking(0);
		bw.flush();
		bw.close();
		br.close();
	}

	private static void backTracking(int size) throws IOException {
		if (size == m) {
			for (int i = 0; i < m; i++) {
				bw.write(arr[i] + " ");
			}
			bw.write("\n");
			return ;
		}
		for (int i = 0; i < n; i++) {
			if (vis[i] == 0) {
				arr[size] = i + 1;
				vis[i] = size + 1;
				backTracking(size + 1);
				vis[i] = 0;
			}
		}
	}
}

