// 문제: Arno's sleep schedule
// 번호: 29863번
// 난이도: 브론즈5

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.IOException;

public class day28_29863 {
    public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int start = Integer.parseInt(br.readLine());
		int end = Integer.parseInt(br.readLine());

		if (start > end) {
			end += 24;
		}
		bw.write(end - start + "\n");
		bw.flush();
	}
}

