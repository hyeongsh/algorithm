/*
제목: 나는야 포켓몬 마스터 이다솜
번호: 1620번
난이도: 실버 4

문제
포켓몬의 개수 N과 맞춰야 하는 문제 개수 M
N번에 해당하는 포켓몬이 순서대로 나열
문제가 알파벳으로 들어올 경우 숫자, 숫자로 들어올 경우 알파벳을 출력
*/

// 라이브러리 설정
#include <iostream>
#include <vector>
#include <map>

#define FASTIO std::cin.tie(NULL); std::cout.tie(NULL); std::ios::sync_with_stdio(false);
// max값 설정
#define MAX 

// 전역 변수 선언
int N, M;
std::map<int, std::string> pokemonsByInt;
std::map<std::string, int> pokemonsByString;

// 기본 함수
void input();
void findAnswer();

// main 함수
int main(void) {
	FASTIO
	input();
	findAnswer();
}

void input() {
	std::cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		std::string pokemon;
		std::cin >> pokemon;
		pokemonsByInt.insert({i, pokemon});
		pokemonsByString.insert({pokemon, i});
	}	
}

void findAnswer() {
	for (int i = 0; i < M; i++) {
		std::string question;
		std::cin >> question;
		int questionNumber;
		if (question[0] >= '0' && question[0] <= '9') {
			questionNumber = std::stod(question);
			std::cout << pokemonsByInt.find(questionNumber)->second << "\n";
		} else {
			std::cout << pokemonsByString.find(question)->second << "\n";
		}
	}
}
