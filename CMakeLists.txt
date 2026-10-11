#include <stdio.h>

#define SIZE 5
int iarray[SIZE];

// 배열에 값 저장 함수
void store(int i, int item) {
//코드 작성
iarray[i] = item;
}

// 배열에서 값 추출 함수
int retrieve(int i) {
//코드 작성
return iarray[i];
}

int main() {
//코드 작성
//입력
//store 함수를 활용하여 입력값을 배열에 값 저장
// retrieve 함수를 활용하여 배열에서 값 추출하여 합 계산
// 결과 출력
int N; // 처음에 입력받을 숫자의 개수
int sum = 0; // 다 더한 값을 저장할 통 (꼭 0으로 비워둬야 함!)
int num; // 임시로 숫자를 입력받을 변수

// 1. 처음에 몇 개의 숫자를 넣을지 입력받아요.
scanf("%d", &N);

// 2. N번만큼 반복하면서 숫자를 입력받고 배열에 저장해요.
for (int i = 0; i < N; i = i + 1) { // i++ 대신 초보 느낌으로 i = i + 1
scanf("%d", &num);
store(i, num); // 함수를 써서 배열에 저장!
}

// 3. 다시 0번 방부터 N-1번 방까지 열어보면서 값을 더해요.
for (int i = 0; i < N; i = i + 1) {
// retrieve 함수로 값을 꺼내서 sum에 계속 더해줍니다.
// sum += retrieve(i); 라고 써도 되지만 풀어 썼습니다.
sum = sum + retrieve(i);
}.
printf("%d\n", sum);
return 0;
}