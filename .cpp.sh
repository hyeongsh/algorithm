#!/bin/bash

DATE=$1
DAY="day${DATE}"
INDEX=$2
CXX="g++"
CXXFLAGS="-std=c++17 -Wall -Wextra"

SRC=$(ls ${DAY}_${INDEX}_*.cpp 2>/dev/null)
OUT="cpp_algorithm.out"

usage() {
	echo "사용법: $0 [run|clean] or <date> <index>"
	exit 1
}

if [ $# -eq 2 ]; then
	if [ -z "$SRC" ]; then
		echo "소스 파일을 찾을 수 없습니다: ${DAY}_${INDEX}_*.cpp"
		exit 1
	fi
	echo "컴파일 중: $SRC -> $OUT"
	$CXX $CXXFLAGS $SRC -o $OUT
	if [ -z "$OUT" ]; then
		echo "No excute file : $OUT"
		exit 1
	fi
	echo "Excute : $OUT"
	./$OUT
else
	case $1 in
		"clean")
			echo "파일 삭제 중: $OUT"
			rm -f $OUT
			;;
		*)
			usage
			;;
	esac
fi


