// 문제: 스타트링크
// 번호: 5014번
// 난이도: 실버 1

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Queue;
import java.util.LinkedList;

public class day29_5014 {
	static int F, S, G, U, D;
	static int[] vis;
    public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		StringTokenizer st = new StringTokenizer(br.readLine());
		F = Integer.parseInt(st.nextToken());
		S = Integer.parseInt(st.nextToken());
		G = Integer.parseInt(st.nextToken());
		U = Integer.parseInt(st.nextToken());
		D = Integer.parseInt(st.nextToken());

		vis = new int[F + 1];
		int count = bfs();

		if (count == -1) {
			bw.write("use the stairs\n");
		} else {
			bw.write(count + "\n");
		}
		bw.flush();

		br.close();
		bw.close();
	}

	static int bfs() {
		Queue<Integer> que = new LinkedList<>();
		que.add(S);
		vis[S] = 1;
		while (!que.isEmpty()) {
			int curFloor = que.poll();
			int curCount = vis[curFloor];
			if (curFloor == G) {
				return curCount - 1;
			}
			if (curFloor + U <= F && vis[curFloor + U] == 0) {
				vis[curFloor + U] = curCount + 1;
				que.add(curFloor + U);
			}
			if (curFloor - D > 0 && vis[curFloor - D] == 0) {
				vis[curFloor - D] = curCount + 1;
				que.add(curFloor - D);
			}
		}
		return -1;
	}
}

