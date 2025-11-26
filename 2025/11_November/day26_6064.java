// 문제: 카잉 달력
// 번호: 6064번
// 난이도: 실버 1

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class day26_6064 {
    public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int t = Integer.parseInt(br.readLine());
		for (int i = 0; i < t; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int m = Integer.parseInt(st.nextToken());
			int n = Integer.parseInt(st.nextToken());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			ArrayList<Integer> candidate = new ArrayList<>();
			int k = 0;
			while (m * k == 0 || m * k % n != 0) {
				// System.out.println("input: " + (m * k + x));
				candidate.add(m * k + x);
				k += 1;
			}
			k = 0;
			while (candidate.get(candidate.size() - 1) > n * k + y) {
				// System.out.println("contains: " + (n * k + y));
				if (candidate.contains(n * k + y)) {
					bw.write(n * k + y + "\n");
					break ;
				}
				k += 1;
			}
			if (candidate.get(candidate.size() - 1) < n * k + y) {
				bw.write("-1\n");
			}
		}
		bw.flush();
	}
}

