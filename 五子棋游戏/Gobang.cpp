#include<iostream>
#include<cstdlib>
using namespace std;

void controller();//�ܿ���̨������ͬ������л��͹��ܵĵ���
void menuView();//�˵�����
void init();//��ʼ����Ϸ
void gameView_ShowMap();//��ӡ��Ϸ����
void gameView();//��Ϸʵ��
int playerMove(const int& x, const int& y);//�ж������Ƿ�Ϸ�
int isWin(const int& x, const int& y);//�ж���Ϸ�Ƿ����
void winView();//ʤ������

int flag;//�غ���
int map[19][19];//����
int x, y;
int sign;

int main()
{
	controller();
	return 0;
}

void controller() {
	while (1) {
		switch (sign)
		{
		case 0://��ӡ�˵�
			menuView();
			cin >> sign;
			break;
		case 1://����˵���������Ϸ
			init();
			gameView_ShowMap();
			flag = 1;
			while (flag++) {
				if (flag % 2 == 0) {
					cout << "����غ�,��������������:" << endl;
					cin >> x >> y;
					while (playerMove(x, y) != 1)
					{
						cin >> x >> y;
					}
					if (isWin(x, y)) {
						winView();
						flag = 0;
					}
				}
				else {
					cout << "����غ�,��������������:" << endl;
					cin >> x >> y;
					while (playerMove(x, y) != 1)
					{
						cin >> x >> y;
					}
					if (isWin(x, y)) {
						winView();
						flag = 0;
					}
				}
			}
			break;
		case 2://��������
			system("cls");
			cout << "�����ڴ�����" << endl;
			sign = 0;
			system("pause");
			system("cls");
			break;
		case 3://�˳���Ϸ
			system("cls");
			cout << "��ӭ�´�����" << endl;
			system("pause");
			exit(1);
		default:
			system("cls");
			break;
		}
	}
}

void menuView() {
		cout << "\t1.������Ϸ" << endl;
		cout << "\t2.��������" << endl;
		cout << "\t3.�˳���Ϸ" << endl;
		cout << "������Ҫѡ���ѡ�����֣�";

}

void init() {
	//��ʼ������
	flag = 0;
	for (int i = 0; i < 19; i++)
		for (int j = 0; j < 19; j++)
			map[i][j] = 0;
	system("cls");
}
void gameView_ShowMap() {
	//����ʵ��	δʵ��

}
void gameView() {
	//����ʵ�� δʵ��
}

int playerMove(const int& x, const int& y) {
	if (map[x][y]) {
		cout << "�ô���������,���������" << endl;
		return 0;//����ʧ��
	}
	else {
		map[x][y] = flag % 2 == 0 ? 1 : 2;//�ж�����ӻ��ǰ��Ӳ�ʵ������
		return 1;//���ӳɹ�
	}
}

int isWin(const int& x, const int& y) {
	int s=0;
	//����
	for (int i = 0; i < 5; i++) {
		if (map[x][y + i] == (flag % 2 == 0 ? 1 : 2))
		s += map[x][y + i];
	}
	if (s == 5 * (flag % 2 == 0 ? 1 : 2)) {
		return flag % 2 == 0 ? 1 : 2;
	}
	s = 0;
	//����
	for (int i = 0; i < 5; i++) {
		if (map[x][y - i] == (flag % 2 == 0 ? 1 : 2))
		s += map[x][y - i];
	}
	if (s == 5 * (flag % 2 == 0 ? 1 : 2)) {
		return flag % 2 == 0 ? 1 : 2;
	}
	s = 0;
	//����
	for (int i = 0; i < 5; i++) {
		if (map[x + i][y] == (flag % 2 == 0 ? 1 : 2))
			s += map[x + i][y];
	}
	if (s == 5 * (flag % 2 == 0 ? 1 : 2)) {
		return flag % 2 == 0 ? 1 : 2;
	}
	s = 0;
	//����
	for (int i = 0; i < 5; i++) {
		if (map[x - i][y] == (flag % 2 == 0 ? 1 : 2))
			s += map[x - i][y];
	}
	if (s == 5*(flag % 2 == 0 ? 1 : 2)) {
		return flag % 2 == 0 ? 1 : 2;
	}
	s = 0;
	//����
	for(int i=0;i<5;i++)
	{
		if (s += map[x - i][y + i] == (flag % 2 == 0 ? 1 : 2))
		s += map[x - i][y + i];
	}
	if (s == 5 * (flag % 2 == 0 ? 1 : 2)) {
		return flag % 2 == 0 ? 1 : 2;
	}
	s = 0;
	//����
	for (int i = 0; i < 5; i++)
	{
		if (map[x - i][y - i] == (flag % 2 == 0 ? 1 : 2))
		s += map[x - i][y - i];
	}
	if (s == 5 * (flag % 2 == 0 ? 1 : 2)) {
		return flag % 2 == 0 ? 1 : 2;
	}
	s = 0;
	//����
	for (int i = 0; i < 5; i++)
	{
		if (map[x + i][y + i] == (flag % 2 == 0 ? 1 : 2))
		s += map[x + i][y - i];
	}
	if (s == 5 * (flag % 2 == 0 ? 1 : 2)) {
		return flag % 2 == 0 ? 1 : 2;
	}
	s = 0;
	//����
	for (int i = 0; i < 5; i++)
	{
		if (map[x][y + i] == (flag % 2 == 0 ? 1 : 2))
		s += map[x + i][y + i];
	}
	if (s == 5 * (flag % 2 == 0 ? 1 : 2)) {
		return flag % 2 == 0 ? 1 : 2;
	}
	s = 0;
	return 0;//δ�л�ʤ�ߣ���Ϸ����
	//�ú����кܴ�ȱ��
	//1.���������Ӳ����������ͷβ�����޷��ж�
	//2.û���ж��Ƿ񵽴����̱߽�
	//3.��������
}


void winView() {
	//
	if (flag % 2 /*�����ʤ*/) {
		cout << "��ϲ�����ʤ" << endl;
		system("pause");
		system("cls");
		cout << "���ز˵�������0������һ��������1" << endl;
		cin >> sign;
		while (sign != 1 && sign != 0) {
			cout << "��������,����������" << endl;
			cin >> sign;
		}
	}
	else {
		cout << "��ϲ�����ʤ" << endl;
		system("pause");
		system("cls");
		cout << "���ز˵�������0������һ��������1" << endl;
		cin >> sign;
		while (sign != 1 && sign != 0) {
			cout << "��������,����������" << endl;
			cin >> sign;
		}
	}
	system("cls");
	return;
}
