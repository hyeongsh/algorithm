// 문제: 영역 구하기
// 번호: 2583번
// 난이도: 실버 1

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Queue;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;

public class day27_2583 {
	static int m, n, k;
	static int[][] board;
	static int[][] vis;

	static int[] da = {1, -1, 0, 0};
	static int[] db = {0, 0, 1, -1};

	static class Pair {
		int a;
		int b;

		Pair(int a, int b) {
			this.a = a;
			this.b = b;
		}
	}

    public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		StringTokenizer st = new StringTokenizer(br.readLine());
		m = Integer.parseInt(st.nextToken());
		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());

		board = new int[n][m];
		vis = new int[n][m];
		for (int i = 0; i < k; i++) {
			st = new StringTokenizer(br.readLine());
			int leftA = Integer.parseInt(st.nextToken());
			int botB = Integer.parseInt(st.nextToken());
			int rightA = Integer.parseInt(st.nextToken());
			int topB = Integer.parseInt(st.nextToken());
			for (int a = leftA; a < rightA; a++) {
				for (int b = botB; b < topB; b++) {
					board[a][b] = 1;
				}
			}
		}
		int num = 0;
		ArrayList<Integer> areas = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 0 && vis[i][j] == 0) {
					num++;
					vis[i][j] = 1;
					int size = bfs(i, j);
					areas.add(size);
				}
			}
		}
		Collections.sort(areas);
		bw.write(num + "\n");
		for (int area : areas) {
			bw.write(area + " ");
		}
		bw.write("\n");
		bw.flush();
		br.close();
		bw.close();
	}

	private static int bfs(int i, int j) {
		Queue<Pair> que = new LinkedList<>();
		que.add(new Pair(i, j));
		int size = 1;
		while (!que.isEmpty()) {
			Pair cur = que.poll();
			for (int k = 0; k < 4; k++) {
				int na = cur.a + da[k];
				int nb = cur.b + db[k];
				if (na < 0 || nb < 0 || na >= n || nb >= m) continue ;
				if (board[na][nb] == 1 || vis[na][nb] == 1) continue ;
				que.add(new Pair(na, nb));
				vis[na][nb] = 1;
				size++;
			}
		}
		return size;
	}
}

