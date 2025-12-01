// 문제: 스타트와 링크
// 번호: 14889번
// 난이도: 실버 1

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
	static int n;
	static int[][] arr;
	static int[] totalSet;
	static int min = 2147483647;
    public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		n = Integer.parseInt(br.readLine());
		arr = new int[n][n];
		for (int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		totalSet = new int[n];
		totalSet[0] = 1;
		dfs(1, 1);
		bw.write(min + "\n");
		br.close();
		bw.close();
	}

	private static void dfs(int cur, int dep) {
		if (dep == n / 2) {
			int subPoint = calPoint();
			if (subPoint < min) {
				min = subPoint;
			}
			return ;
		}
		for (int i = cur; i < n; i++) {
			totalSet[i] = 1;
			dfs(i + 1, dep + 1);
			totalSet[i] = 0;
		}
	}

	private static int calPoint() {
		int start = 0;
		int link = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (totalSet[i] == 1 && totalSet[j] == 1) {
					start += arr[i][j] + arr[j][i];
				} else if (totalSet[i] == 0 && totalSet[j] == 0) {
					link += arr[i][j] + arr[j][i];
				}
			}
		}
		return Math.abs(start - link);
	}
}


