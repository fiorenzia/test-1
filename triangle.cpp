//三角形の計算

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
			cout << "選択肢にありません.もう一度入力してください";
			break;
		}
		showSelection();
		cin >> choice;
	}//end while

	cout << "終了します\n";
	return 0;
}

//選択画面作成
void showSelection()
{
	cout << "\n";
	cout << "三角形の計算\n";
	cout << "次から選んでください:\n";
	cout << "[a]3辺から3角を求める\n";
	cout << "[b]2辺とその間の角から他の辺と角を求める\n";
	cout << "[c]1辺と2つの角から他の辺と角を求める\n";
	cout << "[q]終了\n";
	cout << "\n";
}

//3辺の値
void threeline()
{
	cout << "3辺を順に入力\n";
	cin >> a;
	cin >> b;
	cin >> c;

	arga = (double)acos((b * b + c * c - a * a) / (2 * b * c)) * RadToDec;
	argb = (double)acos((c * c + a * a - b * b) / (2 * c * a)) * RadToDec;
	argc = (double)acos((a * a + b * b - c * c) / (2 * a * b)) * RadToDec;

	cout << "3角の大きさは" << arga << "," << argb << "," << argc << "です。\n";

}

void twoline()
{
	cout << "2辺を順に入力\n";
	cin >> a;
	cin >> b;
	cout << "間の角を入力";
	cin >> argc;

	radc = argc * DecToRad;

	c = (double)sqrt(a * a + b * b - 2 * a * b * cosf(radc));
	arga = (double)asin(a * sinf(radc) / c) * RadToDec;
	argb = (double)asin(b * sinf(radc) / c) * RadToDec;

	cout << "残りの辺の長さは" << c << ",角は" << arga << "," << argb << "です。\n";

}

void oneline()
{
	cout << "1辺を入力\n";
	cin >> a;
	cout << "両端の角入力\n";
	cin >> argb;
	cin >> argc;

	arga = 180 - argb - argc;
	rada = arga *  DecToRad;
	radb = argb *  DecToRad;
	radc = argc *  DecToRad;

	b = a * sinf(radb) / sinf(rada);
	c = a * sinf(radc) / sinf(rada);

	cout << "残りの角の大きさは" << arga << ",辺の長さは" << b << "," << c << "です。\n";

}