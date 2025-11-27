// 문제: 그림
// 번호: 1926번
// 난이도: 실버 1

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.LinkedList;
import java.util.Queue;

public class day27_1926 {

	static int[][] board;
	static int[][] vis;
	static int n, m;

	static int[] da = {1, -1, 0, 0};
	static int[] db = {0, 0, 1, -1};
    
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		board = new int[n][m];
		vis = new int[n][m];

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		int num = 0;
		int maxSize = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 1 && vis[i][j] == 0) {
					num++;
					int size = bfs(i, j);
					maxSize = Math.max(maxSize, size);
				}
			}
		}

		bw.write(num + "\n");
		bw.write(maxSize + "\n");

		bw.flush();

		br.close();
		bw.close();
	}

	static int bfs(int a, int b) {
		Queue<Pair> que = new LinkedList<>();
		que.add(new Pair(a, b));
		vis[a][b] = 1;

		int size = 1;
		while (!que.isEmpty()) {
			Pair cur = que.poll();

			for (int i = 0; i < 4; i++) {
				int na = cur.first + da[i];
				int nb = cur.second + db[i];

				if (na < 0 || nb < 0 || na >= n || nb >= m) continue ;
				if (vis[na][nb] == 1 || board[na][nb] == 0) continue ;

				vis[na][nb] = 1;
				que.add(new Pair(na, nb));
				size++;
			}
		}
		return size;
	}

	static class Pair {
		int first;
		int second;

		Pair(int first, int second) {
			this.first = first;
			this.second = second;
		}
	}
}

