// 문제: 트럭
// 번호: 13335번
// 난이도: 실버 1

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class day30_13335 {
	static int n, w, l;
	static int[][] trucks;
    public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		w = Integer.parseInt(st.nextToken());
		l = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(br.readLine());
		trucks = new int[n][2];
		for (int i = 0; i < n; i++) {
			trucks[i][0] = Integer.parseInt(st.nextToken());
		}
		int cur = 0;
		int out = 0;
		int time = 0;
		while (cur < n) {
			// for (int i = 0; i < n; i++) {
			// 	System.out.print(trucks[i][1] + " ");
			// }
			// System.out.println("time: " + time);
			if (l >= trucks[cur][0]) {
				for (int i = 0; i <= cur; i++) {
					trucks[i][1]++;
				}
				if (trucks[out][1] > w) {
					l += trucks[out][0];
					out++;
				}
				l -= trucks[cur][0];
				cur++;
				time++;
			} else {
				int k = w - trucks[out][1];
				for (int i = 0; i < cur; i++) {
					trucks[i][1] += k;
				}
				l += trucks[out][0];
				out++;
				time += k;
			}
		}
		bw.write(time + w + "\n");
		bw.flush();
		bw.close();
		br.close();
	}
}

