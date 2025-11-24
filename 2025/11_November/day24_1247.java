// 부호 (1247) - 브론즈 3

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger;

public class day24_1247 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		for (int i = 0 ; i < 3; i++) {
			int n = Integer.parseInt(br.readLine());
			BigInteger s = new BigInteger("0");
			for (int j = 0; j < n; j++) {
				BigInteger ns = new BigInteger(br.readLine());
				s = s.add(ns);
			}
			int result = s.compareTo(new BigInteger("0"));
			if (result == 1) {
				bw.write("+\n");
			} else if (result == -1) {
				bw.write("-\n");
			} else {
				bw.write("0\n");
			}
		}
		bw.flush();
	}
}