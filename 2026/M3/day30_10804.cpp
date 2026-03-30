/*
제목: 카드 역배치
번호: 10804번
난이도: 브론즈 2

문제 - 정렬
1 ~ 20 까지의 배열에서 a,b가 주어질때마다 a ~ b까지 역순정렬해야함.
*/

// 라이브러리 설정
#include <iostream>

using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

// 전역 변수 선언
int arr[21];
int a, b;

// 함수 선언

// main 함수
int main(void) {
	FASTIO
	for (int i = 1; i < 21; i++) {
		arr[i] = i;
	}
	for (int i = 0; i < 10; i++) {
		cin >> a >> b;
		reverse(arr + a, arr + b + 1);
	}
	for (int i = 1; i < 21; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
