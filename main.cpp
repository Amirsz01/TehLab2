#include <iostream>
#include </Users/Amirsz/source/repos/�������������/�������������2/Queue.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	int callback;
	Queue a;
	Queue* b = nullptr;
	while (true)
	{
		system("CLS");
		cout << "�������� ����� �� ������:" << endl
			<< "1. ����������� �������" << endl
			<< "2. ����/����� �� ������" << endl
			<< "3. �������� ��� �������" << endl
			<< "0. �����" << endl;
		cin >> callback;
		system("CLS");
		switch (callback)
		{
		case 1:
			cout << "�������� ������������� ������� :" << endl
				<< "1. / \n2. /= \n3. +\n4. --()\n5. ()--\n6. ++()\n7. ()++\n8. +=\n9. -=\n10. =\n11. != \n12. ==\n13. >=\n14. <=\n15. >\n16. < " << endl;
			cin >> callback;
			switch (callback)
			{
			case 1:
				cout << a;
				a = a / 2;
				cout << a;
				break;
			case 2:
				cout << a;
				delete b;
				b = new Queue(a.getSize());
				a /= *b;
				cout << a;
				break;
			case 3:
				cout << a;
				a = a + 2;
				cout << a;
				break;
			case 4:
				cout << a;
				cout << --a;
				break;
			case 5:
				cout << a;
				cout << a--;
				cout << a;
				break;
			case 6:
				cout << a;
				cout << ++a;
				break;
			case 7:
				cout << a;
				cout << a++;
				cout << a;
				break;
			case 8:
				cout << a;
				delete b;
				b = new Queue(a.getSize());
				a += *b;
				cout << a;
				break;
			case 9:
				cout << a;
				delete b;
				b = new Queue(a.getSize());
				a -= *b;
				cout << a;
				break;
			case 10:
				cout << a;
				delete b;
				b = new Queue(a.getSize());
				a = *b;
				cout << a;
				break;
			case 11:
				cout << a;
				delete b;
				b = new Queue(a.getSize());
				a != *b;
				cout << a;
				break;
			case 12:
				cout << a;
				delete b;
				b = new Queue(a.getSize());
				a == *b;
				cout << a;
				break;
			case 13:
				cout << a;
				delete b;
				b = new Queue(a.getSize());
				a >= *b;
				cout << a;
				break;
			case 14:
				cout << a;
				delete b;
				b = new Queue(a.getSize());
				a <= *b;
				cout << a;
				break;
			case 15:
				cout << a;
				delete b;
				b = new Queue(a.getSize());
				a > *b;
				cout << a;
				break;
			case 16:
				cout << a;
				delete b;
				b = new Queue(a.getSize());
				a < *b;
				cout << a;
				break;
			default:
				break;
			}
			system("pause");
			break;
		case 2:
			cout << a;
			cin >> a;
			cout << a;
			system("pause");
			break;
		case 3:
			cout << "������� ���������� ������ �������� �� �������: ";
			cin >> callback;
			a.getPod(callback);
			system("pause");
			break;
		case 0:
			return 0;
		default:
			break;
		}
	}
}