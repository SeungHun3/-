#include<iostream>

using namespace std;

class Move
{
public:

	int* P;
	int Count;
	int MaxCount;


};
void Init(Move* Arr)
{	
	Arr->P = (int*)malloc(sizeof(int) * 2);
	Arr->Count = 0;
	Arr->MaxCount = 2;
};

void Pushback(Move* _Arr, int Data)
{	
	
	// 동적할당 조건검사
	if (_Arr->Count >= _Arr->MaxCount)
		{
			int* NewP = (int*)malloc(_Arr->MaxCount * 2);
			for (int i=0; i < _Arr->Count; ++i)
			{
				_Arr->P[i] = NewP[i]; // 데어터 옮기기
			}
			free(_Arr->P);
			_Arr->P = NewP;
			
			_Arr->MaxCount = _Arr->MaxCount * 2;
		}
	else if (_Arr->Count > _Arr->MaxCount) // Count 값과 MaxCount 값이 같을때에도 위의 조건에 걸리지 않고 초과한다면
	{
		printf("데이터 손상위험\n");
	}
	
	_Arr->P[_Arr->Count++] = Data;
};
int main()
{
	Move a;
	Init(&a);
	Pushback(&a, 1);
	Pushback(&a, 2);
	Pushback(&a, 3);
	for (int i = 0; i < a.Count; i++)
	{
		cout << a.P[i] << endl;
	}
	

	return 0;
}

