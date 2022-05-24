#include <iostream>
#include <vector>
#include<list>
#include<iterator>

using namespace std;

int main() {
 

	// List, iterator ���

	list<int> L;

	for (int i = 0; i < 15; i++)
	{
		L.push_back(i);
	}

	list<int>::iterator L_iter = L.begin();
	list<int>::iterator L_Pos = L.begin();

	for (L_iter = L.begin(); L_iter != L.end(); L_iter++)
	{
		cout << *L_iter << endl;
	}

	printf("advance\n");
	advance(L_Pos, 5); //L_Pos iterator ������ 5ĭ
	advance(L_Pos, -2); // L_Pos iterator �ڷ� 2ĭ

	int a = 3;
	advance(L_Pos, a); // ������ aĭ

	cout << *L_Pos << endl;

	// vector iterator ���


	return 0;
}
