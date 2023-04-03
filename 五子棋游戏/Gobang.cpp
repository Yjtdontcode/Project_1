#include<iostream>
#include<cstdlib>
using namespace std;

void controller();//总控制台，负责不同界面的切换和功能的调用
void menuView();//菜单界面
void init();//初始化游戏
void gameView_ShowMap();//打印游戏界面
void gameView();//游戏实现
int playerMove(const int& x, const int& y);//判断落子是否合法
int isWin(const int& x, const int& y);//判断游戏是否结束
void winView();//胜利界面

int flag;//回合数
int map[19][19];//棋盘
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
		case 0://打印菜单
			menuView();
			cin >> sign;
			break;
		case 1://清初菜单，进入游戏
			init();
			gameView_ShowMap();
			flag = 1;
			while (flag++) {
				if (flag % 2 == 0) {
					cout << "黑棋回合,请输入棋子坐标:" << endl;
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
					cout << "白棋回合,请输入棋子坐标:" << endl;
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
		case 2://进入设置
			system("cls");
			cout << "敬请期待……" << endl;
			sign = 0;
			system("pause");
			system("cls");
			break;
		case 3://退出游戏
			system("cls");
			cout << "欢迎下次游玩" << endl;
			system("pause");
			exit(1);
		default:
			system("cls");
			break;
		}
	}
}

void menuView() {
		cout << "\t1.进入游戏" << endl;
		cout << "\t2.进入设置" << endl;
		cout << "\t3.退出游戏" << endl;
		cout << "请输入要选择的选项数字：";

}

void init() {
	//初始化棋盘
	flag = 0;
	for (int i = 0; i < 19; i++)
		for (int j = 0; j < 19; j++)
			map[i][j] = 0;
	system("cls");
}
void gameView_ShowMap() {
	//代码实现	未实现

}
void gameView() {
	//代码实现 未实现
}

int playerMove(const int& x, const int& y) {
	if (map[x][y]) {
		cout << "该处已有棋子,请更换坐标" << endl;
		return 0;//落子失败
	}
	else {
		map[x][y] = flag % 2 == 0 ? 1 : 2;//判断落黑子还是白子并实现落子
		return 1;//落子成功
	}
}

int isWin(const int& x, const int& y) {
	int s=0;
	//向上
	for (int i = 0; i < 5; i++) {
		if (map[x][y + i] == (flag % 2 == 0 ? 1 : 2))
		s += map[x][y + i];
	}
	if (s == 5 * (flag % 2 == 0 ? 1 : 2)) {
		return flag % 2 == 0 ? 1 : 2;
	}
	s = 0;
	//向下
	for (int i = 0; i < 5; i++) {
		if (map[x][y - i] == (flag % 2 == 0 ? 1 : 2))
		s += map[x][y - i];
	}
	if (s == 5 * (flag % 2 == 0 ? 1 : 2)) {
		return flag % 2 == 0 ? 1 : 2;
	}
	s = 0;
	//向右
	for (int i = 0; i < 5; i++) {
		if (map[x + i][y] == (flag % 2 == 0 ? 1 : 2))
			s += map[x + i][y];
	}
	if (s == 5 * (flag % 2 == 0 ? 1 : 2)) {
		return flag % 2 == 0 ? 1 : 2;
	}
	s = 0;
	//向左
	for (int i = 0; i < 5; i++) {
		if (map[x - i][y] == (flag % 2 == 0 ? 1 : 2))
			s += map[x - i][y];
	}
	if (s == 5*(flag % 2 == 0 ? 1 : 2)) {
		return flag % 2 == 0 ? 1 : 2;
	}
	s = 0;
	//左上
	for(int i=0;i<5;i++)
	{
		if (s += map[x - i][y + i] == (flag % 2 == 0 ? 1 : 2))
		s += map[x - i][y + i];
	}
	if (s == 5 * (flag % 2 == 0 ? 1 : 2)) {
		return flag % 2 == 0 ? 1 : 2;
	}
	s = 0;
	//左下
	for (int i = 0; i < 5; i++)
	{
		if (map[x - i][y - i] == (flag % 2 == 0 ? 1 : 2))
		s += map[x - i][y - i];
	}
	if (s == 5 * (flag % 2 == 0 ? 1 : 2)) {
		return flag % 2 == 0 ? 1 : 2;
	}
	s = 0;
	//右下
	for (int i = 0; i < 5; i++)
	{
		if (map[x + i][y + i] == (flag % 2 == 0 ? 1 : 2))
		s += map[x + i][y - i];
	}
	if (s == 5 * (flag % 2 == 0 ? 1 : 2)) {
		return flag % 2 == 0 ? 1 : 2;
	}
	s = 0;
	//右上
	for (int i = 0; i < 5; i++)
	{
		if (map[x][y + i] == (flag % 2 == 0 ? 1 : 2))
		s += map[x + i][y + i];
	}
	if (s == 5 * (flag % 2 == 0 ? 1 : 2)) {
		return flag % 2 == 0 ? 1 : 2;
	}
	s = 0;
	return 0;//未有获胜者，游戏继续
	//该函数有很大缺陷
	//1.如果最后落子不是五连珠的头尾，则无法判定
	//2.没有判断是否到达棋盘边界
	//3.代码冗余
}


void winView() {
	//
	if (flag % 2 /*白棋获胜*/) {
		cout << "恭喜白棋获胜" << endl;
		system("pause");
		system("cls");
		cout << "返回菜单请输入0，再来一局请输入1" << endl;
		cin >> sign;
		while (sign != 1 && sign != 0) {
			cout << "输入有误,请重新输入" << endl;
			cin >> sign;
		}
	}
	else {
		cout << "恭喜黑棋获胜" << endl;
		system("pause");
		system("cls");
		cout << "返回菜单请输入0，再来一局请输入1" << endl;
		cin >> sign;
		while (sign != 1 && sign != 0) {
			cout << "输入有误,请重新输入" << endl;
			cin >> sign;
		}
	}
	system("cls");
	return;
}
