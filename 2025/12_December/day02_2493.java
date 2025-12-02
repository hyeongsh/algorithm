// 문제: 탑
// 번호: 2493번
// 난이도: 골드 5

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Stack;

public class day02_2493 {

	static class Pair {
		int high;
		int index;

		public Pair(int high, int index) {
			this.high = high;
			this.index = index;
		}
	}

    public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		int[] tops = new int[n];
		int[] result = new int[n];
		for (int i = 0; i < n; i++) {
			tops[i] = Integer.parseInt(st.nextToken());
		}
		Stack<Pair> stack = new Stack<>();
		for (int i = 0; i < n; i++) {
			if (!stack.isEmpty() && stack.peek().high <= tops[i]) {
				Pair p = stack.pop();
				if (stack.isEmpty()) {
					result[p.index] = 0;
				} else {
					result[p.index] = stack.peek().index + 1;
				}
				i--;
				continue ;
			}
			stack.add(new Pair(tops[i], i));
		}

		while (!stack.isEmpty()) {
			Pair p = stack.pop();
			if (stack.isEmpty()) {
				result[p.index] = 0;
			} else {
				result[p.index] = stack.peek().index + 1;
			}
		}

		for (int i = 0; i < n; i++) {
			bw.write(result[i] + " ");
		}
		bw.write("\n");
		bw.flush();
		bw.close();
		br.close();
	}
}

