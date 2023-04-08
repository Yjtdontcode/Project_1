#include<iostream>
#include<graphics.h>
#include<conio.h>
using namespace std;

void init();
void title();
void mouseconduct();
void draw();
void changecolor();
void show();
double thick = 4;

int main() 
{
	init();//初始化画板
	title();//改标题
	mouseconduct();//开始画画
	closegraph();
	return 0;
}

void init() {
	initgraph(800, 600,NOCLOSE|NOMINIMIZE|SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();
	setfillcolor(BLACK);
	setlinecolor(BLACK);
	show();
	rectangle(760, 1, 799, 40);
}

void mouseconduct() {
	ExMessage msg;
	while(1)
	{
		if (peekmessage(&msg, EM_MOUSE)) {
			switch (msg.message) {
			case WM_LBUTTONDOWN:
				draw();
				cout << "停止绘画" << endl;
				break;
			case WM_RBUTTONDOWN:
				cout << "a:粉色	 s:红色	 d:黑色   f:橡皮擦\n";
				show();
				changecolor();
				cout << "换色完成\n";
				break;
			case WM_MBUTTONDOWN:
				cleardevice();
				break;
			default:
				break;
			}
		}
	}
}

void title() {
	HWND h = GetHWnd();
	SetWindowText(h, "小猪佩奇");
}

void draw() {
	ExMessage msg;
	cout << "开始绘画" << endl;
	while (1) {
		if(peekmessage(&msg,EM_MOUSE))
			switch (msg.message) {
			case WM_MOUSEMOVE:
				fillcircle(msg.x, msg.y, (int)thick);
				break;
			case WM_RBUTTONDOWN:
				return;
			default:
				break;
			}
	}
}

void changecolor() {
	setlinecolor(WHITE);
	rectangle(680, 1, 720, 40);
	rectangle(720, 1, 760, 40);
	rectangle(760, 1, 799, 40);
	cout << "选择颜色" << endl;
	char ch = _getch();
	switch (ch) {
	case 'a':
		thick = 4;
		setlinecolor(RED);
		rectangle(680, 1, 720, 40);
		setfillcolor(RGB(244, 199, 220));
		setlinecolor(RGB(244, 199, 220));
		break;
	case 's':
		thick = 4;
		/*fillcircle(780, 20, 15);
		outtextxy(770, 9, "s");*/
		setlinecolor(RED);
		rectangle(720, 1, 760, 40);
		setfillcolor(RGB(233, 59, 131));
		setlinecolor(RGB(233, 59, 131));
		break;
	case 'd':
		thick = 4;
		//settextcolor(WHITE);
		//fillcircle(780, 20, 15);
		//outtextxy(770, 9, "d");
		setlinecolor(RED);
		rectangle(760, 1, 799, 40);
		setfillcolor(BLACK);
		setlinecolor(BLACK);
		break;
	case 'f'://橡皮擦
		thick = 12;
		setfillcolor(WHITE);
		setlinecolor(WHITE);
		break;
	default:
		cout << "输入错误" << endl;
		changecolor();
		break;
	}
}

void show() {
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, "console");
	settextcolor(BLACK);

	setfillcolor(RGB(244, 199, 220));
	setlinecolor(RGB(244, 199, 220));
	fillcircle(700, 20, 15);
	outtextxy(690, 7, "a");

	setfillcolor(RGB(233, 59, 131));
	setlinecolor(RGB(233, 59, 131));
	fillcircle(740, 20, 15);
	outtextxy(730, 7, "s");

	settextcolor(WHITE);
	setfillcolor(BLACK);
	setlinecolor(BLACK);
	fillcircle(780, 20, 15);
	outtextxy(770, 7, "d");
}