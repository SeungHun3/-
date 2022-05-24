#include <iostream>
#include <vector>
#include<list>
#include<iterator>

using namespace std;

int main() {
 

	// List, iterator »ç¿ë

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
	advance(L_Pos, 5); //L_Pos iterator ¾ÕÀ¸·Î 5Ä­
	advance(L_Pos, -2); // L_Pos iterator µÚ·Î 2Ä­

	int a = 3;
	advance(L_Pos, a); // ¾ÕÀ¸·Î aÄ­

	cout << *L_Pos << endl;

	// vector iterator »ç¿ë


	return 0;
}
