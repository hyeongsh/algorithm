// 코끼리 15마리가 앞으로 돌진하면 어떻게 막을 건데 (34760) - 브론즈 1

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class day25_34760 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		StringTokenizer st = new StringTokenizer(br.readLine());

		int max = 0;
		int flag = 1;
		for (int i = 0; i < 15; i++) {
			int a = Integer.parseInt(st.nextToken());
			if (i == 14 && max < a) {
				flag = 0;
			}
			if (max < a) {
				max = a;
			}
		}
		bw.write(max + flag + "\n");
		bw.flush();
	}
}
