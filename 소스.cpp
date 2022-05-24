#include<iostream>

using namespace std;

typedef struct _Move

{
	int* P; // �����迭�� ������ ����뵵
	int Count;
	int MaxCount;
}Move;



/* �����Ҵ� �ƴѰ���̷������� ���������

typedef struct _Move
{
	int P[10] = {1,3,7,6,7};     // �̰� �����ͷ� ��, �迭���� �� null�� �ذſ���
	int Count = 5;
	int MaxCount = 10;
}Move;

=============����ü�迭 �ٸ���================

typedef struct _Game
{
	char name[10] = "Tankshot";
	int gamenameCount = 8 ;
	int PlayDate = 51;
}Game;

*/



// �����Ҵ� �ʱ����
void Init(Move* _Arr);
// ������ ����ֱ�
void PushBack(Move* _Arr, int _data);

int main()
{
	Move a = {}; // ����ü ����
	Init(&a); // �ʱ� �����Լ��� �ּҰ� �ѱ�� -> �Լ����� �����ͷ� �޾ƿ� ����
	PushBack(&a, 2);
	PushBack(&a, 3);
	return 0;
}

void Init(Move* _Arr) // Move ����ü�� &������ �� �����ͷ� �޾ƿ���
{
	_Arr->P = (int*)malloc(sizeof(Move) * 2);
	_Arr->Count = 0;
	_Arr->MaxCount = 2;
}



void PushBack(Move* _Arr, int _Data)

{
	_Arr->P[_Arr->Count++] = _Data;
	if (_Arr->Count == _Arr->MaxCount) // ������ �ְ� ���Ҵ����� �˻�
	{
		// Reallocate �Լ� ����
		int* PNew = (int*)malloc(_Arr->MaxCount) * 2);  // ���� ������ ������� ����� 
// ������ ���Ҵ� malloc (MaxCount) * 2
		for (int i=0; i < _Arr->Count; ++i)
		{
			_Arr->P[i] = PNew[i]; // ������ �ű��
		}
		// ������ �Ű����� ���� malloc�� �޸� ����
		free(_Arr->P);
		// _Arr�� �ּҸ� �ٽ� �޾ƿ���
		_Arr->P = PNew;
	}
	else if (_Arr->Count > _Arr->MaxCount) // Count ���� MaxCount ���� ���������� ���� ���ǿ� �ɸ��� �ʰ� �ʰ��Ѵٸ�
	{
		printf("������ �ջ�����\n");
	}
}