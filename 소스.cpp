#include<iostream>

using namespace std;

typedef struct _Move

{
	int* P; // 가변배열로 데이터 저장용도
	int Count;
	int MaxCount;
}Move;



/* 동적할당 아닌경우이런식으로 만들어진다

typedef struct _Move
{
	int P[10] = {1,3,7,6,7};     // 이걸 포인터로 값, 배열갯수 를 null로 준거였다
	int Count = 5;
	int MaxCount = 10;
}Move;

=============구조체배열 다른예================

typedef struct _Game
{
	char name[10] = "Tankshot";
	int gamenameCount = 8 ;
	int PlayDate = 51;
}Game;

*/



// 동적할당 초기셋팅
void Init(Move* _Arr);
// 데이터 집어넣기
void PushBack(Move* _Arr, int _data);

int main()
{
	Move a = {}; // 구조체 선언
	Init(&a); // 초기 셋팅함수에 주소값 넘기기 -> 함수에서 포인터로 받아올 예정
	PushBack(&a, 2);
	PushBack(&a, 3);
	return 0;
}

void Init(Move* _Arr) // Move 구조체의 &변수명 은 포인터로 받아오기
{
	_Arr->P = (int*)malloc(sizeof(Move) * 2);
	_Arr->Count = 0;
	_Arr->MaxCount = 2;
}



void PushBack(Move* _Arr, int _Data)

{
	_Arr->P[_Arr->Count++] = _Data;
	if (_Arr->Count == _Arr->MaxCount) // 데이터 넣고 재할당조건 검사
	{
		// Reallocate 함수 구현
		int* PNew = (int*)malloc(_Arr->MaxCount) * 2);  // 기존 데이터 저장공간 만들고 
// 데이터 재할당 malloc (MaxCount) * 2
		for (int i=0; i < _Arr->Count; ++i)
		{
			_Arr->P[i] = PNew[i]; // 데어터 옮기기
		}
		// 데이터 옮겼으면 기존 malloc값 메모리 해제
		free(_Arr->P);
		// _Arr의 주소를 다시 받아오기
		_Arr->P = PNew;
	}
	else if (_Arr->Count > _Arr->MaxCount) // Count 값과 MaxCount 값이 같을때에도 위의 조건에 걸리지 않고 초과한다면
	{
		printf("데이터 손상위험\n");
	}
}