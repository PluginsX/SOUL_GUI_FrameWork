#pragma once
#include"BaseFunction.h"
using namespace std;





//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//class Widget_Base {
//public:
//	static signed int Widget_Base_Number;
//	string Name;
//	Vector4D Area;
//	Vector2D Origin;
//	Vector2D Border;
//	Vector2D DrawOrigin;
//	Vector2D DrawBorder;
//	int Width;
//	int Height;
//
//	//��꽻���¼�
//	virtual void Cursor_In() {
//		cout << '[' << Name << "\t:\tCursor_In" << endl;
//	}
//	virtual void Cursor_Leave() {
//		cout << '[' << Name << "\t:\tCursor_Leave" << endl;
//	}
//	virtual void MouseLeftButtomDown(MOUSEMSG ms) {
//		cout << '[' << Name << "\t:\tMouseLeftButtomDown" << endl;
//	}
//	virtual void MouseLeftButtomUp(MOUSEMSG ms) {
//		cout << '[' << Name << "]\t:\tMouseLeftButtomUp" << endl;
//	}
//	virtual void MouseWheel(MOUSEMSG ms) {
//		cout << '[' << Name << "\t:\tMouseWheel" << endl;
//	}
//	virtual void MouseMove(MOUSEMSG ms) {
//		cout << '[' << Name << "\t:\tMouseMove" << endl;
//	}
//
//	//���ƿؼ�
//	virtual void PaintGraph(byte select = 1)
//	{
//		setlinestyle(PS_NULL, 0);
//		setlinecolor(RED);
//		setfillcolor(BLUE);
//		fillrectangle(Origin.x, Origin.y, Border.x, Border.y);
//	}
//
//public:
//
//	//�޲ι��캯��
//	Widget_Base() :Origin(0, 0), Border(0, 0), Width(0), Height(0), DrawOrigin(0, 0), DrawBorder(0, 0)
//	{
//		//����ǰ�����������ӵ���Ա���� Name �� �˴��õ���ͷ�ļ� <sstream> ���� �ַ��������ֻ���ת������Ӧ��
//		Widget_Base_Number++;
//		string AddNumberToName;
//		stringstream tmp; tmp << Widget_Base_Number; tmp >> AddNumberToName;
//		Name = "Widget_Base_Number" + AddNumberToName;
//
//		//��ʼ��������� RECT Area
//		Area.x1 = Origin.x;
//		Area.x2 = Border.x;
//		Area.y1 = Origin.y;
//		Area.y2 = Border.y;
//
//	}
//
//	//�вι��캯��
//	Widget_Base(Vector2D O, Vector2D B) :Origin(O), Border(B), Width(B.x - O.x), Height(B.y - O.y), DrawOrigin(O.x, O.y), DrawBorder(B.x, B.y)
//	{
//		//ע��ͬ�޲ι��캯��
//		Widget_Base_Number++;
//		string AddNumberToName;
//		stringstream tmp; tmp << Widget_Base_Number; tmp >> AddNumberToName;
//		Name = "Widget_Base_Number" + AddNumberToName;
//
//		Area.x1 = Origin.x;
//		Area.x2 = Border.x;
//		Area.y1 = Origin.y;
//		Area.y2 = Border.y;
//
//	}
//
//	//��������
//	~Widget_Base() {
//		Widget_Base_Number--;
//	}
//};
//
////��̬��Ա����  �������ؼ��ࡱ������ �������ۼ�����ʵ�����������
//int Widget_Base::Widget_Base_Number = 0;
//
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//class W_Text :public Widget_Base {
//public:
//	string Text;
//	string TextStyle;
//	COLORREF TextColor;
//	int TextHeight;
//	int HeightBacke;
//	RECT OutArea;
//	bool  Transparent;
//
//	//��꽻���¼�
//	void MouseWheel(MOUSEMSG ms) {
//		int MAX = HeightBacke * 2;
//		int OFSET = HeightBacke * 0.1f;
//
//		if (ms.wheel > 0) {
//			TextHeight = Valuefilter(MAX, 0, TextHeight + OFSET);
//			clearrectangle(Origin.x, Origin.y, Border.x, Border.y);
//			PaintGraph();
//			cout << "TextHeight" << TextHeight << endl;
//		}
//		else if (ms.wheel < 0) {
//			TextHeight = Valuefilter(MAX, 0, TextHeight - OFSET);
//			clearrectangle(Origin.x, Origin.y, Border.x, Border.y);
//			PaintGraph();
//			cout << "TextHeight" << TextHeight << endl;
//		}
//	}
//
//	void E_MouseLeftButtomDown(MOUSEMSG ms) {
//		TextHeight = HeightBacke;
//		clearrectangle(Origin.x, Origin.y, Border.x, Border.y);
//		PaintGraph();
//	}
//
//
//	void PaintGraph(byte select = 1)
//	{
//		BeginBatchDraw();
//		settextstyle(TextHeight, 0, _T(&TextStyle[0]));
//		settextcolor(TextColor);
//
//		LOGFONT f;
//		gettextstyle(&f);
//		f.lfQuality = ANTIALIASED_QUALITY;
//		settextstyle(&f);
//		setbkcolor(YELLOW);
//
//		if (Transparent) {
//			setbkmode(TRANSPARENT);
//		}
//		else { setbkmode(OPAQUE); }
//		//outtextxy(Origin.x, Origin.y, &Text[0]);
//		drawtext(&(Text[0]), &OutArea, DT_CENTER | DT_VCENTER | DT_WORD_ELLIPSIS);
//		EndBatchDraw();
//	}
//
//	W_Text() :Widget_Base(), Text("TEXT"), TextStyle("΢���ź�"), TextColor(RGB(255, 0, 255)), Transparent(TRUE)
//	{
//		HeightBacke = TextHeight = Height;
//		//OutArea = {
//		//	Origin.x,
//		//	Origin.y,
//		//	Border.x,
//		//	Border.y };
//		OutArea.left = Origin.x;
//		OutArea.right = Border.x;
//		OutArea.top = Origin.y;
//		OutArea.bottom = Border.y;
//	}
//	W_Text(Vector2D O, Vector2D B, string tex = "TEXT",
//		string Tstyle = "΢���ź�", COLORREF color = RGB(255, 0, 255), bool Trans = TRUE)
//		:Widget_Base(O, B), Text(tex), TextStyle(Tstyle), TextColor(color), Transparent(Trans)
//	{
//
//		HeightBacke = TextHeight = Height;
//		//OutArea = { O.x,O.y, B.x, B.y };
//		OutArea.left = Origin.x;
//		OutArea.right = Border.x;
//		OutArea.top = Origin.y;
//		OutArea.bottom = Border.y;
//	}
//	~W_Text() {
//	}
//};
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//class W_ListXY :public Widget_Base {
//public:
//
//	int ColumnsNumber;
//	int LineNumber;
//
//	int ColumnsWidth;
//	int LineHeight;
//
//	int Interval_Columns;
//	int Interval_Line;
//
//	//��꽻���¼�
//	void MouseWheel(MOUSEMSG ms) {
//		if (ms.wheel > 0) {
//			DrawOrigin.y = Valuefilter(Origin.y + Height, Origin.y - Height, DrawOrigin.y + LineHeight);
//			clearrectangle(Origin.x, Origin.y, Border.x, Border.y);
//			PaintGraph();
//		}
//		else if (ms.wheel < 0) {
//			DrawOrigin.y = Valuefilter(Origin.y + Height, Origin.y - Height, DrawOrigin.y - LineHeight);
//			clearrectangle(Origin.x, Origin.y, Border.x, Border.y);
//			PaintGraph();
//		}
//	}
//
//	void PaintGraph(byte select = 1)
//	{
//		BeginBatchDraw();
//		setlinecolor(RED);
//		setlinestyle(PS_NULL, 0);
//		//��ɫ
//		setfillcolor(RGB(100, 100, 100));
//		fillrectangle(Origin.x, Origin.y, Border.x, Border.y);
//		int r = 0, g = 0, b = 0;
//		int ColorAdd = 255 / ColumnsNumber * LineNumber;
//
//
//		for (int y = 0; y < LineNumber; y++) {
//			for (int x = 0; x < ColumnsNumber; x++) {
//				setfillcolor(RGB(r, g, b));
//				r += ColorAdd; b -= ColorAdd;
//				Vector2D Ori(DrawOrigin.x + (x * ColumnsWidth) + Interval_Columns, DrawOrigin.y + (y * LineHeight) + Interval_Line);
//				Vector2D Bor(DrawOrigin.x + ((x + 1) * ColumnsWidth) - Interval_Columns, DrawOrigin.y + ((y + 1) * LineHeight) - Interval_Line);
//				if (Bor.y > Origin.y && Ori.y < Border.y) {
//					fillroundrect(Ori.x, Ori.y, Bor.x, Bor.y, ColumnsWidth*0.2, LineHeight*0.2);
//				}
//			}
//		}
//		EndBatchDraw();
//	}
//	W_ListXY() :Widget_Base()
//	{
//	}
//	W_ListXY(Vector2D O, Vector2D B, int Columns = 10, int line = 10, int Interval_C = 2, int Interval_L = 2) :Widget_Base(O, B), ColumnsNumber(Columns), LineNumber(line)
//	{
//
//		ColumnsWidth = Width / ColumnsNumber;
//		LineHeight = Height / LineNumber;
//		Interval_Columns = Interval_C;
//		Interval_Line = Interval_L;
//		DrawOrigin = Origin;
//		DrawBorder = Border;
//	}
//	~W_ListXY() {}
//};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//class W_Image :public Widget_Base {
//public:
//	IMAGE  Image;
//	int  WidthBack, HeightBack;
//	Vector2D MoveStartCoord;
//	Vector2D MoveEndCoord;
//	Vector2D MoveStartCoord_Offset;
//	bool C_Down, C_Up;
//
//	void MouseLeftButtomDown(MOUSEMSG ms) {
//		cout << "Image : Cursor_Down" << endl;
//		C_Down = TRUE;
//		C_Up = FALSE;
//
//		MoveStartCoord.x = ms.x;
//		MoveStartCoord.y = ms.y;
//		MoveStartCoord_Offset.x = ms.x - DrawOrigin.x;
//		MoveStartCoord_Offset.y = ms.y - DrawOrigin.y;
//
//		while (1) {
//			ms = GetMouseMsg();
//			if (ms.uMsg == WM_LBUTTONUP)
//				break;
//			DrawOrigin.x = Valuefilter(Border.x - Width, Origin.x, ms.x - MoveStartCoord_Offset.x);
//			DrawOrigin.y = Valuefilter(Border.y - Width, Origin.y, ms.y - MoveStartCoord_Offset.y);
//			DrawBorder.x = DrawOrigin.x + Width;
//			DrawBorder.y = DrawOrigin.y + Height;
//
//			clearrectangle(Origin.x, Origin.y, Border.x, Border.y);
//			PaintGraph();
//		}
//
//	}
//	void MouseLeftButtomUp(MOUSEMSG ms) {
//		cout << "Image : Cursor_Up" << endl;
//		C_Down = FALSE;
//		C_Up = TRUE;
//
//	}
//
//	void MouseWheel(MOUSEMSG ms) {
//		int MAX = HeightBack;
//		int OFSET = HeightBack * 0.1f;
//
//		if (ms.wheel > 0) {
//			Height = Valuefilter(MAX, 0, Height + OFSET);
//			Width = Valuefilter(MAX, 0, Width + OFSET);
//
//			clearrectangle(Origin.x, Origin.y, Border.x, Border.y);
//			PaintGraph();
//		}
//		else if (ms.wheel < 0) {
//			Height = Valuefilter(MAX, 0, Height - OFSET);
//			Width = Valuefilter(MAX, 0, Width - OFSET);
//
//			clearrectangle(Origin.x, Origin.y, Border.x, Border.y);
//			PaintGraph();
//		}
//	}
//
//
//	void PaintGraph(byte select = 1) {
//		setlinestyle(PS_NULL, 0);
//		setfillcolor(RGB(0, 200, 255));
//		fillrectangle(DrawOrigin.x, DrawOrigin.y, DrawBorder.x, DrawBorder.y);
//
//		putimage(DrawOrigin.x, DrawOrigin.y, Width, Height, &Image, 0, 0);
//
//		//putimage(x, y, ����ͼ, NOTSRCERASE);
//		//putimage(x, y, ����ͼ, SRCINVERT);
//	}
//
//	W_Image(Vector2D O, Vector2D B, string ImageAccese = "D:\\VSproject\\GraphicInterface\\resource\\image\\Picture\\img01.jpg")
//		:Widget_Base(O, B), C_Down(FALSE), C_Up(FALSE)
//	{
//
//		loadimage(&Image, &ImageAccese[0], Width, Height);
//		WidthBack = Width; HeightBack = Height;
//	}
//	W_Image() :Widget_Base(), C_Down(FALSE), C_Up(FALSE) {
//
//		loadimage(&Image, _T("D:\\VSproject\\GraphicInterface\\resource\\image\\Picture\\img01.jpg"), Width, Height);
//		WidthBack = Width; HeightBack = Height;
//	}
//	~W_Image() {}
//};
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//class W_Buttom2S :public Widget_Base {
//public:
//
//	W_Image* StaticPicture_1;
//	W_Image* StaticPicture_2;
//	W_Image* UpPicture_1;
//	W_Image* UpPicture_2;
//	W_Text* StaticText;
//	//��ť����ֵĬ��Ϊ��
//	bool SwitchValue;
//
//	//��ͼ����
//	void PaintGraph(byte select = 1)
//	{
//		switch (select)
//		{
//		case 1:
//			StaticPicture_1->PaintGraph();
//			break;
//		case 2:
//			StaticPicture_2->PaintGraph();
//			break;
//		case 3:
//			UpPicture_1->PaintGraph();
//			break;
//		case 4:
//			UpPicture_2->PaintGraph();
//			break;
//		default:
//			break;
//		}
//	}
//
//	//��꽻���¼�
//	void Cursor_In() {
//		cout << "Cursor_In()" << endl;
//		if (SwitchValue) {
//			PaintGraph(4);
//		}
//		else
//		{
//			PaintGraph(3);
//		}
//		StaticText->PaintGraph();
//	}
//
//	void MouseLeftButtomDown(MOUSEMSG ms) {
//		cout << "Cursor_Dowm()" << endl;
//		if (SwitchValue) {
//			PaintGraph(1);
//			SwitchValue = FALSE;
//			StaticText->Text = "��";
//		}
//		else
//		{
//			PaintGraph(2);
//			SwitchValue = TRUE;
//			StaticText->Text = "��";
//		}
//	}
//	void MouseLeftButtomUp(MOUSEMSG ms) {
//		cout << "Cursor_Up()" << endl;
//		if (SwitchValue) {
//			PaintGraph(4);
//		}
//		else
//		{
//			PaintGraph(3);
//		}
//	}
//	void Cursor_Leave() {
//		cout << "Cursor_Leave()" << endl;
//		if (SwitchValue) {
//			PaintGraph(2);
//		}
//		else
//		{
//			PaintGraph(1);
//		}
//	}
//
//	//�в� ���캯��
//	W_Buttom2S(Vector2D O, Vector2D D) :Widget_Base(O, D), SwitchValue(FALSE)
//	{
//
//		StaticPicture_1 = new W_Image(Origin, Border, "D:\\VSproject\\GraphicInterface\\resource\\image\\Buttom\\Buttom2S\\Buttom2D_StaticPicture_1.jpg");
//		StaticPicture_2 = new W_Image(Origin, Border, "D:\\VSproject\\GraphicInterface\\resource\\image\\Buttom\\Buttom2S\\Buttom2D_StaticPicture_2.jpg");
//		UpPicture_1 = new W_Image(Origin, Border, "D:\\VSproject\\GraphicInterface\\resource\\image\\Buttom\\Buttom2S\\Buttom2D_UpPicture_1.jpg");
//		UpPicture_2 = new W_Image(Origin, Border, "D:\\VSproject\\GraphicInterface\\resource\\image\\Buttom\\Buttom2S\\Buttom2D_UpPicture_2.jpg");
//
//		StaticText = new W_Text(*(new Vector2D(Origin.x, Border.y*0.3)),
//			*(new Vector2D(Border.x, Border.y*0.7)), "��", "΢���ź�", RGB(0, 200, 255));
//
//	}
//
//	//��������
//	~W_Buttom2S() {
//
//		delete StaticPicture_1;
//		delete StaticPicture_2;
//		delete UpPicture_1;
//		delete UpPicture_2;
//		delete StaticText;
//	}
//};
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////class W_Slide :public Widget_Base {
////public:
////
////
////	void PaintGraph() override{
////	
////	}
////	W_Slide() {}
////	W_Slide() {}
////	~W_Slide() {}
////};
//
