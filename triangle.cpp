//�O�p�`�̌v�Z

#include <iostream>
#include <math.h>
#define RadToDec 57.29577951f;
#define DecToRad 0.017453293f;
using namespace std;

void showSelection();
void threeline();
void twoline();
void oneline();

double a;
double b;
double c;
double arga;
double argb;
double argc;
double rada;
double radb;
double radc;

int main()
{
	char choice;

	showSelection();
	cin >> choice;

	while (choice != 'q')
	{
		switch (choice)
		{
		case 'a':
			threeline();
			break;
		case 'b':
			twoline();
			break;
		case 'c':
			oneline();
			break;
		default:
			cout << "�I�����ɂ���܂���.������x���͂��Ă�������";
			break;
		}
		showSelection();
		cin >> choice;
	}//end while

	cout << "�I�����܂�\n";
	return 0;
}

//�I����ʍ쐬
void showSelection()
{
	cout << "\n";
	cout << "�O�p�`�̌v�Z\n";
	cout << "������I��ł�������:\n";
	cout << "[a]3�ӂ���3�p�����߂�\n";
	cout << "[b]2�ӂƂ��̊Ԃ̊p���瑼�̕ӂƊp�����߂�\n";
	cout << "[c]1�ӂ�2�̊p���瑼�̕ӂƊp�����߂�\n";
	cout << "[q]�I��\n";
	cout << "\n";
}

//3�ӂ̒l
void threeline()
{
	cout << "3�ӂ����ɓ���\n";
	cin >> a;
	cin >> b;
	cin >> c;

	arga = (double)acos((b * b + c * c - a * a) / (2 * b * c)) * RadToDec;
	argb = (double)acos((c * c + a * a - b * b) / (2 * c * a)) * RadToDec;
	argc = (double)acos((a * a + b * b - c * c) / (2 * a * b)) * RadToDec;

	cout << "3�p�̑傫����" << arga << "," << argb << "," << argc << "�ł��B\n";

}

void twoline()
{
	cout << "2�ӂ����ɓ���\n";
	cin >> a;
	cin >> b;
	cout << "�Ԃ̊p�����";
	cin >> argc;

	radc = argc * DecToRad;

	c = (double)sqrt(a * a + b * b - 2 * a * b * cosf(radc));
	arga = (double)asin(a * sinf(radc) / c) * RadToDec;
	argb = (double)asin(b * sinf(radc) / c) * RadToDec;

	cout << "�c��̕ӂ̒�����" << c << ",�p��" << arga << "," << argb << "�ł��B\n";

}

void oneline()
{
	cout << "1�ӂ����\n";
	cin >> a;
	cout << "���[�̊p����\n";
	cin >> argb;
	cin >> argc;

	arga = 180 - argb - argc;
	rada = arga *  DecToRad;
	radb = argb *  DecToRad;
	radc = argc *  DecToRad;

	b = a * sinf(radb) / sinf(rada);
	c = a * sinf(radc) / sinf(rada);

	cout << "�c��̊p�̑傫����" << arga << ",�ӂ̒�����" << b << "," << c << "�ł��B\n";

}