#pragma once
#include"BaseFunction.h"
#include"ApplyNodeTree.h"



////////////////////////////矩形控件///////////////////////////////
class GUI_Rectangle {
public:
	static signed int Node_Number;
	string Name;//节点名
	Vector4D Area;//响应检测区域
	Vector2D Origin;//布局起点
	Vector2D Border;//布局终点
	Vector2D DrawOrigin;//绘制起点
	Vector2D DrawBorder;//绘制终点
	Vector2D Wid_Hei;//宽高
	bool ShowFill;//是否填充
	Vector3D FillColor;//填充色
	bool ShowBorder;//是否绘制边框
	Vector3D BorderColor;//背景色
	vector<GUI_Rectangle*> SubWidgetList;
	GUI_Rectangle* HighWidget;
	bool ShowHatched;
	byte Mode;

	//构造函数
	GUI_Rectangle(Vector2D Ori, Vector2D Bor,bool Fill, Vector3D FC,bool Border, Vector3D BC); 
	//GUI_Rectangle(GUI_Rectangle& copy) {
	//}
	~GUI_Rectangle() {
		MouseEventList.clear();
		KeyBoardEventList.clear();
	}

	//绘制函数
	virtual void PaintGraphics();
	//Debug
	virtual void PrintList();

	//FlushData()函数是给NodeTree的Modification函数来调用的
	//当NodeTree的Modification函数收到了不属于NodeTree类的属性值时
	//将调用NodeTree节点所保存的控件类型的Modification函数并传入节点的	this→指针
	virtual void FlushData(NodePropertyList* Seek);

	//参数修改函数	
	//当读取的属性值不属于 "载体节点NodeTree"时，会调用此函数，用于修改节点所承载的控件的对象的属性
	virtual bool Modification(byte ValueSeq, string* PropertyName, string* PropertyValue);
	//鼠标事件响应占用表
	static map<MouseEventType, bool> MouseEventOccupyList;
	//事件查找器
	vector<MouseEventType*> MouseEventList;
	bool FindMouseEventEvent(MouseEventType* TYPE) {
		bool Find = FALSE;
		for (auto a : MouseEventList)
		{
			if (*a== *TYPE)
			{
				return TRUE;
			}
		}
		return Find;
	}
	//鼠标事件响应函数
	virtual void MouseResponseManager(MOUSEMSG*, MouseEventType*);
	virtual void Cursor_In(MOUSEMSG* MouseMSG) {cout << "WidgetName\t:\t" << Name << "\t" << "鼠标事件\t:\t" << "Cursor_In" << endl;}
	virtual void Cursor_Leave(MOUSEMSG* MouseMSG){cout << "WidgetName\t:\t" << Name << "\t" << "鼠标事件\t:\t" << "Cursor_Leave" << endl; }
	virtual void MouseWheel(MOUSEMSG* MouseMSG){cout << "WidgetName\t:\t" << Name << "\t" << "鼠标事件\t:\t" << "MouseWheel" << endl; }
	virtual void MouseWheel_Up(MOUSEMSG* MouseMSG);// { cout << "WidgetName\t:\t" << Name << "\t" << "鼠标事件\t:\t" << "MouseWheel_Up" << endl; }
	virtual void MouseWheel_Down(MOUSEMSG* MouseMSG);// { cout << "WidgetName\t:\t" << Name << "\t" << "鼠标事件\t:\t" << "MouseWheel_Down" << endl; }
	virtual void MouseMove(MOUSEMSG* MouseMSG){cout << "WidgetName\t:\t" << Name << "\t" << "鼠标事件\t:\t" << "MouseMove" << endl; }
	virtual void MouseLeftButtomDown(MOUSEMSG* MouseMSG){cout << "WidgetName\t:\t" << Name << "\t" << "鼠标事件\t:\t" << "MouseLeftButtomDown" << endl; }
	virtual void MouseLeftButtomUp(MOUSEMSG* MouseMSG){cout << "WidgetName\t:\t" << Name << "\t" << "鼠标事件\t:\t" << "MouseLeftButtomUp" << endl; }
	virtual void MouseLeftButtomCLK(MOUSEMSG* MouseMSG){cout << "WidgetName\t:\t" << Name << "\t" << "鼠标事件\t:\t" << "MouseLeftButtomCLK" << endl; }
	virtual void MouseRightButtomDown(MOUSEMSG* MouseMSG){cout << "WidgetName\t:\t" << Name << "\t" << "鼠标事件\t:\t" << "MouseRightButtomDown" << endl; }
	virtual void MouseRightButtomUp(MOUSEMSG* MouseMSG){cout << "WidgetName\t:\t" << Name << "\t" << "鼠标事件\t:\t" << "MouseRightButtomUp" << endl; }
	virtual void MouseRightButtomCLK(MOUSEMSG* MouseMSG){cout << "WidgetName\t:\t" << Name << "\t" << "鼠标事件\t:\t" << "MouseRightButtomCLK" << endl; }
	virtual void MouseMiddleButtomDown(MOUSEMSG* MouseMSG) {cout << "WidgetName\t:\t" << Name << "\t" << "鼠标事件\t:\t" << "MouseMiddleButtomDown" << endl; }
	virtual void MouseMiddleButtomUp(MOUSEMSG* MouseMSG){cout << "WidgetName\t:\t" << Name << "\t" << "鼠标事件\t:\t" << "MouseMiddleButtomUp" << endl; }
	virtual void MouseMiddleButtomCLK(MOUSEMSG* MouseMSG){cout << "WidgetName\t:\t" << Name << "\t" << "鼠标事件\t:\t" << "MouseMiddleButtomCLK" << endl; }
	
	//事件查找器
	vector<KeyboardEventType*> KeyBoardEventList;
	bool FindKeyBoardEvent(KeyboardEventType* TYPE) {
		bool Find = FALSE;
		for (auto a : KeyBoardEventList)
		{
			if (*a == *TYPE)
			{
				return TRUE;
			}
		}
		return Find;
	}
	//键盘事件响应函数
	virtual void KeyboardResponseManager(char, KeyboardEventType* );
	virtual void Key_W(char c) { cout<< "WidgetName\t:\t" << Name << "\t" << "键盘事件\t:\tW"<<endl; }
	virtual void Key_S(char c) { cout << "WidgetName\t:\t" << Name << "\t" << "键盘事件\t:\tS" << endl; }
	virtual void Key_A(char c) { cout << "WidgetName\t:\t" << Name << "\t" << "键盘事件\t:\tA" << endl; }
	virtual void Key_D(char c) { cout << "WidgetName\t:\t" << Name << "\t" << "键盘事件\t:\tD" << endl; }
	virtual void Key_F(char c) { cout << "WidgetName\t:\t" << Name << "\t" << "键盘事件\t:\tF" << endl; }
	virtual void Key_ESC(char c) { cout << "WidgetName\t:\t" << Name << "\t" << "键盘事件\t:\tESC" << endl; }
	virtual void Key_LEFT_CTRL(char c) { cout << "WidgetName\t:\t" << Name << "\t" << "键盘事件\t:\tLEFT_CTRL" << endl; }
	virtual void Key_RIGHT_CTRL(char c) { cout << "WidgetName\t:\t" << Name << "\t" << "键盘事件\t:\tRIGHT_CTRL" << endl; }
	virtual void Key_SPACE(char c) { cout << "WidgetName\t:\t" << Name << "\t" << "键盘事件\t:\tSPACE" << endl; }
	virtual void Key_ENTER(char c) { cout << "WidgetName\t:\t" << Name << "\t" << "键盘事件\t:\tENTER" << endl; }
	virtual void Key_LEFT_SHIFT(char c) { cout << "WidgetName\t:\t" << Name << "\t" << "键盘事件\t:\tLEFT_SHIFT\t"<<c << endl; }
	virtual void Key_RIGHT_SHIFT(char c) { cout << "WidgetName\t:\t" << Name << "\t" << "键盘事件\t:\tRIGHT_SHIFT" << endl; }
	virtual void Key_LEFT_ALT(char c) { cout << "WidgetName\t:\t" << Name << "\t" << "键盘事件\t:\tLEFT_ALT" << endl; }
	virtual void Key_RIGHT_ALT(char c) { cout << "WidgetName\t:\t" << Name << "\t" << "键盘事件\t:\tRIGHT_ALT" << endl; }
	virtual void Key_TAB(char c) { cout << "WidgetName\t:\t" << Name << "\t" << "键盘事件\t:\tTAB" << endl; }
	virtual void Key_DELETE(char c) { cout << "WidgetName\t:\t" << Name << "\t" << "键盘事件\t:\tDELETE" << endl; }
	virtual void Key_BACKSPACE(char c) { cout << "WidgetName\t:\t" << Name << "\t" << "键盘事件\t:\tBACKSPACE" << endl; }
	virtual void Key_UP(char c) { cout << "WidgetName\t:\t" << Name << "\t" << "键盘事件\t:\tUP" << endl; }
	virtual void Key_DOWN(char c) { cout << "WidgetName\t:\t" << Name << "\t" << "键盘事件\t:\tDOWN" << endl; }
	virtual void Key_LEFT(char c) { cout << "WidgetName\t:\t" << Name << "\t" << "键盘事件\t:\tLEFT" << endl; }
	virtual void Key_RIGHT(char c) { cout << "WidgetName\t:\t" << Name << "\t" << "键盘事件\t:\tRIGHT" << endl; }

	//收发消息
	virtual void ReceiveMessages(NodeType* Type=NULL, void* Messages1 = NULL, void* Messages2 = NULL) { cout << "WidgetName\t:\t" << Name << "\t" << "收信\t:\tRIGHT" << endl; }
	virtual void SendMessages() { cout << "WidgetName\t:\t" << Name << "\t" << "发信\t:\tRIGHT" << endl; }
};
//GUI_Rectangle 静态成员变量
signed int GUI_Rectangle::Node_Number = 0;
map<MouseEventType, bool> GUI_Rectangle::MouseEventOccupyList;

//构造函数
GUI_Rectangle::GUI_Rectangle(Vector2D Ori = { 0,0 }, Vector2D Bor = { 100,100 },bool Fill = TRUE, Vector3D FC = { 100,100,100 },bool Border = FALSE, Vector3D BC = { 255,255,255 }):Origin(Ori), Border(Bor),DrawOrigin(Ori), DrawBorder(Bor),Area{ (int)Ori.x,(int)Ori.y ,(int)Bor.x,(int)Bor.y },ShowFill(Fill), FillColor(FC),ShowBorder(Border), BorderColor(BC)
{
	Node_Number++;
	string AddNumberToName;
	stringstream tmp; tmp << Node_Number; tmp >> AddNumberToName;
	Name = "Node_Number" + AddNumberToName;

	DrawOrigin = Ori;//用布局起点坐标，初始化绘制起点坐标
	DrawBorder = Bor;//用布局终点坐标，初始化绘制终点坐标

	Wid_Hei = (Bor - Ori);//初始化宽高

	HighWidget = NULL;//默认上级控件未空有复合控件对象负责链接

	ShowHatched = FALSE;//默认填充图案为假
	Mode = 0;//团类型为0，横向线

	MouseEventList.push_back(new MouseEventType(E_E_M_Cursor_In));
	MouseEventList.push_back(new MouseEventType(E_E_M_Cursor_Leave));
	MouseEventList.push_back(new MouseEventType(E_E_M_MouseWheel));
	MouseEventList.push_back(new MouseEventType(E_E_M_MouseWheel_Up));
	MouseEventList.push_back(new MouseEventType(E_E_M_MouseWheel_Down));
	MouseEventList.push_back(new MouseEventType(E_E_M_MouseMove));
	MouseEventList.push_back(new MouseEventType(E_E_M_MouseLeftButtomDown));
	MouseEventList.push_back(new MouseEventType(E_E_M_MouseLeftButtomUp));
	MouseEventList.push_back(new MouseEventType(E_E_M_MouseLeftButtomCLK));
	MouseEventList.push_back(new MouseEventType(E_E_M_MouseRightButtomDown));
	MouseEventList.push_back(new MouseEventType(E_E_M_MouseRightButtomUp));
	MouseEventList.push_back(new MouseEventType(E_E_M_MouseRightButtomCLK));
	MouseEventList.push_back(new MouseEventType(E_E_M_MouseMiddleButtomDown));
	MouseEventList.push_back(new MouseEventType(E_E_M_MouseMiddleButtomUp));
	MouseEventList.push_back(new MouseEventType(E_E_M_MouseMiddleButtomCLK));

	KeyBoardEventList.push_back(new KeyboardEventType(E_E_K_W));
	KeyBoardEventList.push_back(new KeyboardEventType(E_E_K_S));
	KeyBoardEventList.push_back(new KeyboardEventType(E_E_K_A));
	KeyBoardEventList.push_back(new KeyboardEventType(E_E_K_D));
	KeyBoardEventList.push_back(new KeyboardEventType(E_E_K_F));
	KeyBoardEventList.push_back(new KeyboardEventType(E_E_K_ESC));
	KeyBoardEventList.push_back(new KeyboardEventType(E_E_K_LEFT_CTRL));
	KeyBoardEventList.push_back(new KeyboardEventType(E_E_K_RIGHT_CTRL));
	KeyBoardEventList.push_back(new KeyboardEventType(E_E_K_SPACE));
	KeyBoardEventList.push_back(new KeyboardEventType(E_E_K_ENTER));
	KeyBoardEventList.push_back(new KeyboardEventType(E_E_K_LEFT_SHIFT));
	KeyBoardEventList.push_back(new KeyboardEventType(E_E_K_RIGHT_SHIFT));
	KeyBoardEventList.push_back(new KeyboardEventType(E_E_K_LEFT_ALT));
	KeyBoardEventList.push_back(new KeyboardEventType(E_E_K_RIGHT_ALT));
	KeyBoardEventList.push_back(new KeyboardEventType(E_E_K_TAB));
	KeyBoardEventList.push_back(new KeyboardEventType(E_E_K_DELETE));
	KeyBoardEventList.push_back(new KeyboardEventType(E_E_K_BACKSPACE));
	KeyBoardEventList.push_back(new KeyboardEventType(E_E_K_UP));
	KeyBoardEventList.push_back(new KeyboardEventType(E_E_K_DOWN));
	KeyBoardEventList.push_back(new KeyboardEventType(E_E_K_LEFT));
	KeyBoardEventList.push_back(new KeyboardEventType(E_E_K_RIGHT));

	MouseEventOccupyList[E_E_M_Cursor_In] = FALSE;
	MouseEventOccupyList[E_E_M_Cursor_Leave] = FALSE;
	MouseEventOccupyList[E_E_M_MouseWheel] = FALSE;
	MouseEventOccupyList[E_E_M_MouseMove] = FALSE;
	MouseEventOccupyList[E_E_M_MouseLeftButtomDown] = FALSE;
	MouseEventOccupyList[E_E_M_MouseRightButtomDown] = FALSE;
	MouseEventOccupyList[E_E_M_MouseMiddleButtomDown] = FALSE;
}

//
void GUI_Rectangle::PaintGraphics() {

	////如果显示填充为真
	//if (ShowFill) {
	//	setlinestyle(PS_NULL, 0);
	//	setfillstyle(BS_SOLID);
	//	setfillcolor(RGB(FillColor.x, FillColor.y, FillColor.z));
	//	fillrectangle(DrawOrigin.x, DrawOrigin.y, DrawBorder.x, DrawBorder.y);
	//}
	////如果显示边框为真
	//if (ShowBorder) {
	//	setlinestyle(PS_SOLID, 1);
	//	setlinecolor(RGB(BorderColor.x, BorderColor.y, BorderColor.z));
	//	rectangle(DrawOrigin.x, DrawOrigin.y, DrawBorder.x, DrawBorder.y);
	//}
	//else { setlinestyle(PS_NULL, 0); }

	//如果显示填充为真
	if (ShowFill) {
		setlinestyle(PS_NULL, 0);//不画边框

		if (ShowHatched) {
			//如果显示图案为真，设置填充风格为图案填充
			if (Mode == 0) { setfillstyle(BS_HATCHED, HS_HORIZONTAL); }
			else { setfillstyle(BS_HATCHED, HS_VERTICAL); }
			setfillcolor(RGB(0, 0, 0));//图案本身为填充颜色决定
			setbkcolor(RGB(FillColor.x, FillColor.y, FillColor.z));//以图案填充的方式其背景色使用setbkcolor设置
			setbkmode(OPAQUE);
			fillrectangle(DrawOrigin.x, DrawOrigin.y, DrawBorder.x, DrawBorder.y);
		}
		else
		{
			setlinestyle(PS_NULL, 0);
			setfillstyle(BS_SOLID);
			setfillcolor(RGB(FillColor.x, FillColor.y, FillColor.z));
			fillrectangle(DrawOrigin.x, DrawOrigin.y, DrawBorder.x, DrawBorder.y);
		}
		
	}
	//如果显示边框为真
	if (ShowBorder) {
		setlinestyle(PS_SOLID, 1);
		setlinecolor(RGB(BorderColor.x, BorderColor.y, BorderColor.z));
		rectangle(DrawOrigin.x, DrawOrigin.y, DrawBorder.x, DrawBorder.y);
	}
	else { setlinestyle(PS_NULL, 0); }
}

//
void GUI_Rectangle::FlushData(NodePropertyList* Seek = NULL) {
	//当“载体节点”的属性发生修改时调用此函数，用于根据所在节点的最新属性
	//更新本身的属性	Seek  为所在节点的	this→指针

	//更新	起点&终点
	if (Seek != NULL)
	{
		Origin = Seek->origin;
		Border = Seek->border;
	}
	//更新 绘制起点&绘制终点
	DrawOrigin.x = Origin.x;
	DrawOrigin.y = Origin.y;
	DrawBorder.x = Border.x;
	DrawBorder.y = Border.y;

	//更新	宽&高
	Wid_Hei = Border - Origin;

	Area.x1 = Origin.x;
	Area.y1 = Origin.y;
	Area.x2 = Border.x;
	Area.y2 = Border.y;
}

//
bool GUI_Rectangle::Modification(byte ValueSeq, string* PropertyName, string* PropertyValue) {
	//临时布尔指针，存储检测结果->是否为父类公共属性
	bool* IsParantProperty = new bool(TRUE);
	//尝试字符串匹配父类公共属性，将IsParantProperty的指针传入，在内部修改其值
	//若匹配失败则不为父类公共属性，IsParantProperty将被修改为FLASE，此时返回的枚举类型无效
	//若匹配成功则返回对应的“属性枚举”
	GUI_PublicPropertyType TYPE = StringToGUI_PublicPropertyType(PropertyName, IsParantProperty);

	//~~~~~再父类定义的此函数原型必然时匹配成功的
	//如果是父类的公共属性,则直接退出本类的修改函数，并返回假
	if (!*IsParantProperty) {
		return FALSE;
	}

	//否则即为本子类的特有属性	进入“枚举匹配”开关
	switch (TYPE)
	{
	case E_GUI_P_Name://名称
		Name = *PropertyValue;
		return TRUE;
	case E_GUI_P_Origin://布局起点
		Origin.Modification(ValueSeq, PropertyValue);
		return TRUE;
	case E_GUI_P_Border://布局终点
		Border.Modification(ValueSeq, PropertyValue);
		return TRUE;
	case E_GUI_P_DrawOrigin://绘制起点
		DrawOrigin.Modification(ValueSeq, PropertyValue);
		return TRUE;
	case E_GUI_P_DrawBorder://绘制终点
		DrawBorder.Modification(ValueSeq, PropertyValue);
		return TRUE;
	case E_GUI_P_ShowFill://是否填充
		ShowFill = str_to_int(PropertyValue);
		return TRUE;
	case E_GUI_P_FillColor://填充颜色
		FillColor.Modification(ValueSeq, PropertyValue);
		return TRUE;
	case E_GUI_P_ShowBorder://是否描边
		ShowBorder = str_to_int(PropertyValue);
		return TRUE;
	case E_GUI_P_BorderColor://描边颜色
		BorderColor.Modification(ValueSeq, PropertyValue);
		return TRUE;
	default:
		return FALSE;
	}
	//GUI_RectanglePropertyType TYPE = StringToGUI_RectanglePropertyType(PropertyName);
}

//
void GUI_Rectangle::PrintList() {
	cout << "--------------------GUI_PropertyList--------------------" << endl;
	cout << "Name\t:\t" << Name << endl;
	cout << "OriginX\t:\t" << Origin.x << endl;
	cout << "OriginY\t:\t" << Origin.y << endl;
	cout << "BorderX\t:\t" << Border.x << endl;
	cout << "BorderY\t:\t" << Border.y << endl;
	cout << "Width\t:\t" << Wid_Hei.x << endl;
	cout << "Height\t:\t" << Wid_Hei.y << endl;
	cout << "FillColor_R\t:\t" << FillColor.x << endl;
	cout << "FillColor_G\t:\t" << FillColor.y << endl;
	cout << "FillColor_B\t:\t" << FillColor.z << endl;
	cout << "--------------------------------------------------------" << endl;
}

//
void GUI_Rectangle::MouseResponseManager(MOUSEMSG* MouseMSG, MouseEventType* TYPE) {
	switch (*TYPE)
	{
	case E_E_M_Cursor_In:
		Cursor_In(MouseMSG);
		break;
	case E_E_M_Cursor_Leave:
		Cursor_Leave(MouseMSG);
		break;
	case E_E_M_MouseWheel:
		MouseWheel(MouseMSG);
		break;
	case E_E_M_MouseWheel_Up:
		MouseWheel_Up(MouseMSG);
		break;
	case E_E_M_MouseWheel_Down:
		MouseWheel_Down(MouseMSG);
		break;
	case E_E_M_MouseMove:
		MouseMove(MouseMSG);
		break;
	case E_E_M_MouseLeftButtomDown:
		MouseLeftButtomDown(MouseMSG);
		break;
	case E_E_M_MouseLeftButtomUp:
		MouseLeftButtomUp(MouseMSG);
		break;
	case E_E_M_MouseLeftButtomCLK:
		MouseLeftButtomCLK(MouseMSG);
		break;
	case E_E_M_MouseRightButtomDown:
		MouseRightButtomDown(MouseMSG);
		break;
	case E_E_M_MouseRightButtomUp:
		MouseRightButtomUp(MouseMSG);
		break;
	case E_E_M_MouseRightButtomCLK:
		MouseRightButtomCLK(MouseMSG);
		break;
	case E_E_M_MouseMiddleButtomDown:
		MouseMiddleButtomDown(MouseMSG);
		break;
	case E_E_M_MouseMiddleButtomUp:
		MouseMiddleButtomUp(MouseMSG);
		break;
	case E_E_M_MouseMiddleButtomCLK:
		MouseMiddleButtomCLK(MouseMSG);
		break;
	case E_E_M_INVALID:
		cout << "!!!!!!!!\"E_E_M_INVALID\"!!!!!!!!" << endl;
		break;
	default:
		break;
	}
}

//
void GUI_Rectangle::KeyboardResponseManager(char c, KeyboardEventType* TYPE) {
	switch (*TYPE)
	{
	case E_E_K_W:
		Key_W(c);
		break;
	case E_E_K_S:
		Key_S(c);
		break;
	case E_E_K_A:
		Key_A(c);
		break;
	case E_E_K_D:
		Key_D(c);
		break;
	case E_E_K_F:
		Key_F(c);
		break;
	case E_E_K_ESC:
		Key_ESC(c);
		break;
	case E_E_K_LEFT_CTRL:
		Key_LEFT_CTRL(c);
		break;
	case E_E_K_RIGHT_CTRL:
		Key_RIGHT_CTRL(c);
		break;
	case E_E_K_SPACE:
		Key_SPACE(c);
		break;
	case E_E_K_ENTER:
		Key_ENTER(c);
		break;
	case E_E_K_LEFT_SHIFT:
		Key_LEFT_SHIFT(c);
		break;
	case E_E_K_RIGHT_SHIFT:
		Key_RIGHT_SHIFT(c);
		break;
	case E_E_K_LEFT_ALT:
		Key_LEFT_ALT(c);
		break;
	case E_E_K_RIGHT_ALT:
		Key_RIGHT_ALT(c);
		break;
	case E_E_K_TAB:
		Key_TAB(c);
		break;
	case E_E_K_DELETE:
		Key_DELETE(c);
		break;
	case E_E_K_BACKSPACE:
		Key_BACKSPACE(c);
		break;
	case E_E_K_UP:
		Key_UP(c);
		break;
	case E_E_K_DOWN:
		Key_DOWN(c);
		break;
	case E_E_K_LEFT:
		Key_LEFT(c);
		break;
	case E_E_K_RIGHT:
		Key_RIGHT(c);
		break;
	case E_E_K_INVALID:
		cout << "####\"E_E_K_INVALID\"####" << endl;
		break;
	default:
		break;
	}
}

void GUI_Rectangle::MouseWheel_Up(MOUSEMSG* MouseMSG) {
	if (HighWidget != NULL)
	{
		NodeType* MyType = new NodeType(E_MoveButton);
		string* Message = new string("MouseWheel_Up");
		HighWidget->ReceiveMessages(MyType, Message);
		delete MyType, Message;
	}
	return;
}
void GUI_Rectangle::MouseWheel_Down(MOUSEMSG* MouseMSG) {
	if (HighWidget != NULL)
	{
		NodeType* MyType = new NodeType(E_MoveButton);
		string* Message = new string("MouseWheel_Down");
		HighWidget->ReceiveMessages(MyType, Message);
		delete MyType, Message;
	}
	return;
}



////////////////////////////圆角矩形控件///////////////////////////////
class GUI_Roundrect:public GUI_Rectangle
{
public:
	int CutX;
	int CutY;
	//构造函数
	GUI_Roundrect(Vector2D O = { 0,0 }, Vector2D B = {1280,768}, int CtX = 10, int CtY = 10)
		:GUI_Rectangle(O,B),CutX(CtX),CutY(CtY)
	{
		CutX = Wid_Hei.x*0.2f;
		CutY = Wid_Hei.y*0.2f;
		//添加响应事件
		//MouseEventList.push_back(new MouseEventType(E_E_M_Cursor_In));
		//MouseEventList.push_back(new MouseEventType(E_E_M_Cursor_Leave));
		//MouseEventList.push_back(new MouseEventType(E_E_M_MouseLeftButtomDown));
		//MouseEventList.push_back(new MouseEventType(E_E_M_MouseLeftButtomUp));
	}
	//析构函数
	~GUI_Roundrect() {}

public:
	//绘制函数
	void PaintGraphics() {
		if (ShowFill)
		{
			setlinestyle(PS_NULL, 0);
			setfillstyle(BS_SOLID);
			setfillcolor(RGB(FillColor.x, FillColor.y, FillColor.z));
			fillroundrect(DrawOrigin.x, DrawOrigin.y, DrawBorder.x, DrawBorder.y, CutX, CutY);
		}
		if (ShowBorder) {
			setlinestyle(PS_SOLID, 1);
			setlinecolor(RGB(BorderColor.x, BorderColor.y, BorderColor.z));
			roundrect(DrawOrigin.x, DrawOrigin.y, DrawBorder.x, DrawBorder.y, CutX, CutY);
		}

	}
	//继承载体节点属性，刷新本身属性，更新函数
	void FlushData(NodePropertyList* Seek = NULL) {
		GUI_Rectangle::FlushData(Seek);
		CutX = Wid_Hei.x * 0.2f;
		CutY = Wid_Hei.y * 0.2f;
	}

	//修改函数
	bool Modification(byte ValueSeq,string* PropertyName, string* PropertyValue) {
		
		//先调用父类的修改函数，修改公共参数
		bool IsParantProperty = GUI_Rectangle::Modification(ValueSeq,PropertyName, PropertyValue);
		//如果不是父类的属性 再调用本身修改函数，修改特有参数
		if (!IsParantProperty) {
			GUI_RoundrectPropertyType TYPE = StringTo_GUI_RoundrectPropertyType(PropertyName);
			switch (TYPE)
			{
			case E_GUI_Roundrect_CutX:
				CutX = str_to_int(PropertyValue);
				return TRUE;
			case E_GUI_Roundrect_CutY:
				CutY = str_to_int(PropertyValue);
				return TRUE;
			default:
				return FALSE;
			}
		}
		//else {
		//	CutX = Wid_Hei.x * 0.2f;
		//	CutY = Wid_Hei.y * 0.2f;
		//	return TRUE;
		//}
	}
};

////////////////////////////位图控件///////////////////////////////
class GUI_BitMap:public GUI_Rectangle{
public:
	//位图容器类
	Vector2D DrawWid_Hei;//绘制宽高
	IMAGE Image;
	string BitMapAddress;
	Vector2D RelativeCoord;
	Vector2D MouseHitOffset;
	//GUI_Rectangle* Layout;

	Vector2D LayoutOrigin;
	Vector2D LayoutBorder;

	int ScaleRat;

	//带默认值的构造函数，可无参调用
	GUI_BitMap(Vector2D O = {0,0}, Vector2D B = { 1280,768 },
		string Address = ("resource\\image\\Ico\\SOULFLAW.jpg"))
		:GUI_Rectangle(O,B)
	{
		//绘制宽高默认为原始宽高
		DrawWid_Hei = Wid_Hei;
		//位图控件默认填充属性为否
		ShowFill = FALSE;

		//初始化绘制边界
		LayoutOrigin = Origin;
		LayoutBorder = Border;

		BitMapAddress = Address;
		MouseHitOffset = {0,0};
		RelativeCoord = {0,0};

		//默认缩放比例
		ScaleRat = 30;
		//添加响应事件
		//MouseEventList.push_back(new MouseEventType(E_E_M_Cursor_In));
		//MouseEventList.push_back(new MouseEventType(E_E_M_Cursor_Leave));
		//MouseEventList.push_back(new MouseEventType(E_E_M_MouseLeftButtomDown));
		//MouseEventList.push_back(new MouseEventType(E_E_M_MouseLeftButtomUp));
	}

	//析构函数
	~GUI_BitMap() {
		//delete Layout;
	}

	//绘制函数
	void PaintGraphics() {
		//原理上不应在绘图时导入图片，但技术上不允许，因为不再此时重新导入会导致图片无法拉伸以适应绘制区域
		//首先打开地址对应资源
		ifstream ImageData(&(BitMapAddress[0]), ios::in);
		//如果存在指定文件，“打开成功”则不为0
		if (ImageData) {
			//重新导入位图至成员类>>Image
			loadimage(&Image, &(BitMapAddress[0]), Wid_Hei.x, Wid_Hei.y);
		}else	{
			////如果不存在指定文件则导入默认文件
			loadimage(&Image, "resource\\image\\Picture\\img02.jpg",
				Wid_Hei.x, Wid_Hei.y);
		}
		//Image.Resize(Wid_Hei.x, Wid_Hei.y);

		//绘制位图
		putimage(DrawOrigin.x, DrawOrigin.y, Wid_Hei.x, Wid_Hei.y, &Image, RelativeCoord.x, RelativeCoord.y);

		//是否填充
		if (ShowFill) {
			setfillstyle(BS_SOLID);
			setfillcolor(RGB(FillColor.x, FillColor.y, FillColor.z));
			fillrectangle(DrawOrigin.x, DrawOrigin.y, DrawBorder.x, DrawBorder.y);
		}
		//是否描边
		if (ShowBorder) {
			setlinestyle(PS_SOLID, 1);
			setlinecolor(RGB(BorderColor.x, BorderColor.y, BorderColor.z));
			rectangle(DrawOrigin.x, DrawOrigin.y, DrawBorder.x, DrawBorder.y);
		}
	}

	//刷新函数
	void FlushData(NodePropertyList* Seek = NULL) {
		GUI_Rectangle::FlushData(Seek);
		//Layout->FlushData(Seek);
		LayoutOrigin = Origin;
		LayoutBorder = Border;

	}

	//修改函数
	bool Modification(byte ValueSeq,string* PropertyName,string* PropertyValue) {
		//先调用父类的修改函数，修改公共参数
		bool IsParantProperty = GUI_Rectangle::Modification(ValueSeq,PropertyName, PropertyValue);

		//如果不是父类的属性 再调用本身修改函数，修改特有参数
		if (!IsParantProperty) {
			GUI_BitMapPropertyType TYPE = StringTo_GUI_BitMapPropertyType(PropertyName);
			switch (TYPE)
			{
			case E_GUI_BitMap_BitMapAddress:
				BitMapAddress = *RemoveChar(RemoveChar(PropertyValue, ' '), '\"');
				return TRUE;
			default:
				return FALSE;
			}
		}
	}

	void MouseWheel_Up(MOUSEMSG* MouseMSG);
	void MouseWheel_Down(MOUSEMSG* MouseMSG);
	void MouseLeftButtomDown(MOUSEMSG* MouseMSG);

};

// { cout << "WidgetName\t:\t" << Name << "\t" << "鼠标事件\t:\t" << "MouseWheel_Up" << endl; }
void GUI_BitMap::MouseWheel_Up(MOUSEMSG* MouseMSG) {
	if (MouseMSG->wheel<=0){
		return;
	}
	MouseHitOffset.x = (MouseMSG->x - Origin.x) / Wid_Hei.x;
	MouseHitOffset.y = (MouseMSG->y - Origin.y) / Wid_Hei.y;
	

	//Bitmap.Wid_Hei.x = ValueFileter(2000, 100, Bitmap.Wid_Hei.x + ScaleRat);
	//Bitmap.Wid_Hei.y = ValueFileter(2000, 100, Bitmap.Wid_Hei.x + ScaleRat);
	//等比缩放
	int newwidth = Wid_Hei.x + Wid_Hei.x * 0.1f;
	if (newwidth < 1500)
	{
		Wid_Hei.x = newwidth;
		Wid_Hei.y = Wid_Hei.y + Wid_Hei.y * 0.1f;
	}
	else
	{
		return;
	}

	BeginBatchDraw();

	//以背景色擦除当前位置
	setlinestyle(PS_NULL);
	setfillcolor(RGB(FillColor.x, FillColor.y, FillColor.z));
	fillrectangle(LayoutOrigin.x, LayoutOrigin.y, LayoutBorder.x, LayoutBorder.y);



	//放大后的图片原始起点 = 鼠标当前坐标 - （放大前的鼠标在图片中的相对坐标的位置）
	//计算实际起始坐标
	 Origin.x = MouseMSG->x - ( Wid_Hei.x*MouseHitOffset.x);
	 Origin.y = MouseMSG->y - ( Wid_Hei.y*MouseHitOffset.y);

	 Border.x =  Origin.x +  Wid_Hei.x;
	 Border.y =  Origin.y +  Wid_Hei.y;

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//计算相位，图片起点在布局中的相对位置为，图片起点 - 布局起点
	RelativeCoord.x =  Origin.x - LayoutOrigin.x;
	RelativeCoord.y =  Origin.y - LayoutOrigin.y;

	 RelativeCoord.x = RelativeCoord.x > 0 ? 0 : ((RelativeCoord.x)*-1);
	 RelativeCoord.y = RelativeCoord.y > 0 ? 0 : ((RelativeCoord.y)*-1);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//计算绘制起始点,为   原始图像起点 - 超出布局的部分宽高
	//		图像绘制起点		=	（原始起点	-	布局起点）如果大于等于零，即为在布局内部，否则即为出界，则取布局起点
	 DrawOrigin.x = ( Origin.x - LayoutOrigin.x) >= 0 ?  Origin.x : LayoutOrigin.x;
	 DrawOrigin.y = ( Origin.y - LayoutOrigin.y) >= 0 ?  Origin.y : LayoutOrigin.y;

	 DrawBorder.x = ( Border.x - LayoutBorder.x) <= 0 ?  Border.x : LayoutBorder.x;
	 DrawBorder.y = ( Border.y - LayoutBorder.y) <= 0 ?  Border.y : LayoutBorder.y;
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	 //FlushData();
	 DrawWid_Hei = DrawBorder - DrawOrigin;

	 Image.Resize( Wid_Hei.x>=0? Wid_Hei.x:0,  Wid_Hei.y>=0? Wid_Hei.y:0);

	 loadimage(&Image, &(BitMapAddress[0]), Wid_Hei.x, Wid_Hei.y);
	 //绘制位图
	 putimage(DrawOrigin.x, DrawOrigin.y, DrawWid_Hei.x, DrawWid_Hei.y, &Image, RelativeCoord.x, RelativeCoord.y);
	 //PaintGraphics();
	 FlushBatchDraw();
	 //EndBatchDraw();
}
// { cout << "WidgetName\t:\t" << Name << "\t" << "鼠标事件\t:\t" << "MouseWheel_Down" << endl; }
void GUI_BitMap::MouseWheel_Down(MOUSEMSG* MouseMSG) {
	if (MouseMSG->wheel >= 0) {
		return;
	}
	MouseHitOffset.x = (MouseMSG->x - Origin.x) / Wid_Hei.x;
	MouseHitOffset.y = (MouseMSG->y - Origin.y) / Wid_Hei.y;
	int newwidth;

	//Bitmap.Wid_Hei.x = ValueFileter(2000, 100, Bitmap.Wid_Hei.x + ScaleRat);
	//Bitmap.Wid_Hei.y = ValueFileter(2000, 100, Bitmap.Wid_Hei.x + ScaleRat);
	//等比缩放
	newwidth = Wid_Hei.x - Wid_Hei.x * 0.1f;
	if (newwidth > 100)
	{
		Wid_Hei.x = newwidth;
		Wid_Hei.y = Wid_Hei.y - Wid_Hei.y * 0.1f;
	}
	else
	{
		return;
	}

	BeginBatchDraw();

	//以背景色擦除当前位置
	setlinestyle(PS_NULL);
	setfillcolor(RGB(FillColor.x, FillColor.y, FillColor.z));
	fillrectangle(LayoutOrigin.x, LayoutOrigin.y, LayoutBorder.x, LayoutBorder.y);

	//放大后的图片原始起点 = 鼠标当前坐标 - （放大前的鼠标在图片中的相对坐标的位置）
	//计算实际起始坐标
	Origin.x = MouseMSG->x - (Wid_Hei.x*MouseHitOffset.x);
	Origin.y = MouseMSG->y - (Wid_Hei.y*MouseHitOffset.y);

	Border.x = Origin.x + Wid_Hei.x;
	Border.y = Origin.y + Wid_Hei.y;

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//计算相位，图片起点在布局中的相对位置为，图片起点 - 布局起点
	RelativeCoord.x = Origin.x - LayoutOrigin.x;
	RelativeCoord.y = Origin.y - LayoutOrigin.y;

	RelativeCoord.x = RelativeCoord.x > 0 ? 0 : ((RelativeCoord.x)*-1);
	RelativeCoord.y = RelativeCoord.y > 0 ? 0 : ((RelativeCoord.y)*-1);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//计算绘制起始点,为   原始图像起点 - 超出布局的部分宽高
	//		图像绘制起点		=	（原始起点	-	布局起点）如果大于等于零，即为在布局内部，否则即为出界，则取布局起点
	DrawOrigin.x = (Origin.x - LayoutOrigin.x) >= 0 ? Origin.x : LayoutOrigin.x;
	DrawOrigin.y = (Origin.y - LayoutOrigin.y) >= 0 ? Origin.y : LayoutOrigin.y;

	DrawBorder.x = (Border.x - LayoutBorder.x) <= 0 ? Border.x : LayoutBorder.x;
	DrawBorder.y = (Border.y - LayoutBorder.y) <= 0 ? Border.y : LayoutBorder.y;
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	 //FlushData();
	DrawWid_Hei = DrawBorder - DrawOrigin;

	Image.Resize(Wid_Hei.x >= 0 ? Wid_Hei.x : 0, Wid_Hei.y >= 0 ? Wid_Hei.y : 0);

	loadimage(&Image, &(BitMapAddress[0]), Wid_Hei.x, Wid_Hei.y);
	//绘制位图
	putimage(DrawOrigin.x, DrawOrigin.y, DrawWid_Hei.x, DrawWid_Hei.y, &Image, RelativeCoord.x, RelativeCoord.y);
	//PaintGraphics();
	FlushBatchDraw();
	//EndBatchDraw();
}

void GUI_BitMap::MouseLeftButtomDown(MOUSEMSG* MouseMSG) {

	//MOUSEMSG* ms = MouseMSG;
	//获取偏移值
	MouseHitOffset.x = MouseMSG->x - Origin.x;
	MouseHitOffset.y = MouseMSG->y - Origin.y;

	//if (HighWidget!=NULL){
	//	Layout->Origin  = HighWidget->Origin;
	//	Layout->Border = HighWidget->Border;
	//	Layout->FlushData(NULL);
	//}else{
	//	Layout->Origin = Origin;
	//	Layout->Border = Border;
	//	Layout->FlushData(NULL);
	//}


	while (MouseMSG->mkLButton)
	{
		
		BeginBatchDraw();
		//以背景色擦除当前位置
		setfillcolor(RGB(FillColor.x, FillColor.y, FillColor.z));
		fillrectangle(LayoutOrigin.x, LayoutOrigin.y, LayoutBorder.x, LayoutBorder.y);
		
		//setlinestyle(PS_NULL);
		//fillrectangle(
		//	((DrawOrigin.x - LayoutOrigin.x) >= 0 ? DrawOrigin.x : LayoutOrigin.x),
		//	((DrawOrigin.y - LayoutOrigin.y) >= 0 ? DrawOrigin.y : LayoutOrigin.y),
		//	((DrawBorder.x - LayoutBorder.x) <= 0 ? DrawBorder.x : LayoutBorder.x),
		//	((DrawBorder.y - LayoutBorder.y) <= 0 ? DrawBorder.y : LayoutBorder.y)
		//);
		//cleardevice();

		RelativeCoord.x = MouseMSG->x - MouseHitOffset.x - LayoutOrigin.x;
		RelativeCoord.y = MouseMSG->y - MouseHitOffset.y - LayoutOrigin.y;

		cout << "RelativeCoord = [ " << RelativeCoord.x << " , " << RelativeCoord.y << " ]" << endl;
		Origin = LayoutOrigin + RelativeCoord;
		Border =  Origin +  Wid_Hei;

		DrawOrigin.x = (Origin.x - LayoutOrigin.x) >= 0 ? Origin.x : LayoutOrigin.x;
		DrawOrigin.y = (Origin.y - LayoutOrigin.y) >= 0 ? Origin.y : LayoutOrigin.y;

		DrawBorder.x = ( Border.x - LayoutBorder.x) <= 0 ?  Border.x : LayoutBorder.x;
		DrawBorder.y = ( Border.y - LayoutBorder.y) <= 0 ?  Border.y : LayoutBorder.y;

		//FlushData();
		DrawWid_Hei = DrawBorder - DrawOrigin;

		// Image->Resize( DrawWidth_Hight.x,  DrawWidth_Hight.y);
		 RelativeCoord.x = RelativeCoord.x > 0 ? 0 : ((RelativeCoord.x)*-1);
		 RelativeCoord.y = RelativeCoord.y > 0 ? 0 : ((RelativeCoord.y)*-1);

		//PaintGraphics();
		//绘制位图
		putimage(DrawOrigin.x, DrawOrigin.y, DrawWid_Hei.x, DrawWid_Hei.y, &Image, RelativeCoord.x, RelativeCoord.y);
		EndBatchDraw();
		//FlushBatchDraw();

		*MouseMSG = GetMouseMsg();
	}

}




////////////////////////////文本控件///////////////////////////////
class GUI_Text : public GUI_Rectangle
{
public:
	string* Text;//文本内容
	string* TextStyle;//文本样式
	Vector3D TextColor;//文本颜色
	Vector3D TextBkColor;//文本颜色
	RECT OutArea;//输出区域

	int TextHeight;//文字高度
	int HeightBacke;//文字高度备份
	bool  Transparent;//是否透明


	GUI_Text
	(
		Vector2D O = {0,0}, Vector2D B = { 0,0 },
		string* tex = new string("TEXT"),string* Tstyle = new string("微软雅黑"),
		Vector3D color = {255,255,255}, bool Trans = TRUE
	)
		: GUI_Rectangle(O, B), Text(tex), TextStyle(Tstyle), TextColor(color), Transparent(Trans)
	{

		ShowFill = FALSE;
		HeightBacke = TextHeight = Wid_Hei.y*0.9f;
		TextBkColor = {50,50,50};
		OutArea.left = Origin.x;
		OutArea.right = Border.x;
		OutArea.top = Origin.y;
		OutArea.bottom = Border.y;

		//添加响应事件
		//MouseEventList.push_back(new MouseEventType(E_E_M_Cursor_In));
		//MouseEventList.push_back(new MouseEventType(E_E_M_Cursor_Leave));
		//MouseEventList.push_back(new MouseEventType(E_E_M_MouseLeftButtomDown));
		//MouseEventList.push_back(new MouseEventType(E_E_M_MouseLeftButtomUp));
	}
	~GUI_Text() {
		delete Text;
		delete TextStyle;
	}

	//绘制函数
	void PaintGraphics()
	{

		settextstyle(TextHeight, 0, (const char*)(TextStyle));
		settextcolor(RGB(TextColor.x, TextColor.y, TextColor.z));

		LOGFONT f;
		gettextstyle(&f);
		f.lfQuality = ANTIALIASED_QUALITY;
		settextstyle(&f);
		//临时测试注释
		//setbkcolor(RGB(TextBkColor.x, TextBkColor.y, TextBkColor.z));

		if (Transparent) {
			setbkmode(TRANSPARENT);
		}
		else { setbkmode(OPAQUE); }

		drawtext((&((*Text)[0])), &OutArea, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

		//如果显示填充为真
		if (ShowFill) {
			setlinestyle(PS_NULL, 0);
			setfillstyle(BS_SOLID);
			setfillcolor(RGB(FillColor.x, FillColor.y, FillColor.z));
			fillrectangle(DrawOrigin.x, DrawOrigin.y, DrawBorder.x, DrawBorder.y);
		}

		//如果显示边框为真
		if (ShowBorder) {
			setlinestyle(PS_SOLID, 1);
			setlinecolor(RGB(BorderColor.x, BorderColor.y, BorderColor.z));
			rectangle(DrawOrigin.x, DrawOrigin.y, DrawBorder.x, DrawBorder.y);
		}
		else { setlinestyle(PS_NULL, 0); }

	}


	//继承载体节点属性，刷新本身属性，更新函数
	void FlushData(NodePropertyList* Seek = NULL) {
		GUI_Rectangle::FlushData(Seek);

		OutArea.left = DrawOrigin.x;//输出区域
		OutArea.right = DrawBorder.x;
		OutArea.top = DrawOrigin.y;
		OutArea.bottom = DrawBorder.y;

		TextHeight = Wid_Hei.y*0.9f;//文字高度
	}

	//修改函数
	bool Modification(byte ValueSeq, string* PropertyName, string* PropertyValue) {

		//先调用父类的修改函数，修改公共参数
		bool IsParantProperty = GUI_Rectangle::Modification(ValueSeq, PropertyName, PropertyValue);
		//如果不是父类的属性 再调用本身修改函数，修改特有参数
		if (!IsParantProperty) {
			GUI_TextPropertyType TYPE = StringTo_GUI_TextPropertyType(PropertyName);
			switch (TYPE)
			{
			case E_GUI_Text_Text:
				Text = RemoveChar(RemoveChar(PropertyValue,'"'),' ');
				return TRUE;
			case E_GUI_Text_TextStyle:
				TextStyle = RemoveChar(RemoveChar(PropertyValue, '"'), ' ');
				return TRUE;
			case E_GUI_Text_TextColor:
				TextColor.Modification(ValueSeq, PropertyValue);
				return TRUE;
			case E_GUI_Text_TextHeight:
				TextHeight = str_to_int(PropertyValue);
				return TRUE;
			case E_GUI_Text_Transparent:
				Transparent = str_to_int(PropertyValue);
				return TRUE;
			default:
				return FALSE;
			}
		}
	}
};

////////////////////////////音频控件///////////////////////////////
class GUI_Sound :public GUI_Rectangle
{
public:
	string* SoundAddress;
	bool AutoPlay;

	GUI_BitMap* SoundIco;

	GUI_Sound(string* SoundSource);
	~GUI_Sound();
	void Open();
	void Play();
	void Stop();
	void Close();
	void PaintGraphics(); 
	//修改函数
	bool Modification(byte ValueSeq, string* PropertyName, string* PropertyValue);
	//刷新函数
	void FlushData(NodePropertyList* Seek = NULL) {GUI_Rectangle::FlushData(Seek);return;}
};

//CreateFunction
GUI_Sound::GUI_Sound(string* SoundSource = new string("resource\\Sound\\LoveStoryDJ.mp3")) :GUI_Rectangle()
{
	AutoPlay = TRUE;
	SoundAddress = SoundSource;
	Open();
	SoundIco = new GUI_BitMap(Origin, Border);

	//添加响应事件
	//MouseEventList.push_back(new MouseEventType(E_E_M_Cursor_In));
	//MouseEventList.push_back(new MouseEventType(E_E_M_Cursor_Leave));
	//MouseEventList.push_back(new MouseEventType(E_E_M_MouseLeftButtomDown));
	//MouseEventList.push_back(new MouseEventType(E_E_M_MouseLeftButtomUp));
}

GUI_Sound::~GUI_Sound()
{
	Close();
	delete SoundAddress;
}

void GUI_Sound::Open()
{
	string open = "open " + *SoundAddress;
	mciSendString(&(open[0]), NULL, 0, NULL);
}

void GUI_Sound::Play()
{
	string play = "play " + *SoundAddress;
	mciSendString(&(play[0]), NULL, 0, NULL);
}

void GUI_Sound::Stop()
{
	string stop = "stop " + *SoundAddress;
	mciSendString(&(stop[0]), NULL, 0, NULL);
}

void GUI_Sound::Close()
{
	string close = "close " + *SoundAddress;
	mciSendString(&(close[0]), NULL, 0, NULL);
}

void GUI_Sound::PaintGraphics()
{
	if (AutoPlay) { Play(); }
	//如果显示填充为真
	if (ShowFill) {
		setlinestyle(PS_NULL, 0);
		setfillstyle(BS_SOLID);
		setfillcolor(RGB(FillColor.x, FillColor.y, FillColor.z));
		fillrectangle(DrawOrigin.x, DrawOrigin.y, DrawBorder.x, DrawBorder.y);
	}
	//如果显示边框为真
	if (ShowBorder) {
		setlinestyle(PS_SOLID, 1);
		setlinecolor(RGB(BorderColor.x, BorderColor.y, BorderColor.z));
		rectangle(DrawOrigin.x, DrawOrigin.y, DrawBorder.x, DrawBorder.y);
	}
	else { setlinestyle(PS_NULL, 0); }
}

//修改函数
bool GUI_Sound::Modification(byte ValueSeq, string* PropertyName, string* PropertyValue)
{
	//先调用父类的修改函数，修改公共参数
	bool IsParantProperty = GUI_Rectangle::Modification(ValueSeq, PropertyName, PropertyValue);
	//如果不是父类的属性 再调用本身修改函数，修改特有参数
	if (!IsParantProperty) {
		GUI_SoundPropertyType TYPE = StringTo_GUI_SoundPropertyType(PropertyName);
		switch (TYPE)
		{
		case E_SoundAddress:
			//先关闭现有音乐
			Close();
			//更新资源地址
			SoundAddress = PropertyValue;
			//打开新的音乐
			Open();
			break;
		case E_AutoPlay:
			AutoPlay = str_to_int(PropertyValue);
			break;
		default:
			break;
		}
	}
	return TRUE;
}




////////////////////////////////////////////////2选项按钮////////////////////////////////////////////////
class GUI_SelectButtom :public GUI_Rectangle
{
public:
	bool SwitchState;//开关状态
	ButtomStyleType ButtomStyle;//按钮样式
	GUI_Text* ButtomName;//按钮名
	GUI_Text* ButtomExplain;//解释信息

	//图标样式
	GUI_BitMap* ICO_Static_ON;//静止关闭
	GUI_BitMap* ICO_Static_OFF;//静止开启
	GUI_BitMap* ICO_In_ON;//开启状态光标进入
	GUI_BitMap* ICO_In_OFF;//关闭状态光标进入

	//纯色样式
	Vector3D RGB_Static_ON;
	Vector3D RGB_Static_OFF;
	Vector3D RGB_In_ON;
	Vector3D RGB_In_OFF;
	

	GUI_SelectButtom(Vector2D Ori, Vector2D Bor, ButtomStyleType Style);
	~GUI_SelectButtom();

	//加载图标函数
	void LoadIcoSource();
	//绘图函数
	void PaintGraphics();
	//修改函数
	bool Modification(byte ValueSeq, string* PropertyName, string* PropertyValue);
	//刷新函数
	void FlushData(NodePropertyList* Seek);
};



//默认构造函数
GUI_SelectButtom::GUI_SelectButtom(Vector2D Ori = { 0,0 }, Vector2D Bor = { 100,100 }, ButtomStyleType Style = Solid_Buttom):GUI_Rectangle()
{
	Origin = Ori; Border = Bor; Wid_Hei = Bor - Ori;
	//开关默认状态为关闭
	SwitchState = FALSE;
	//初始化样式
	ButtomStyle = Style;

	//根据样式选择是否加载图片，或颜色
	if (ButtomStyle == Image_Buttom){
		//加载图标资源
		LoadIcoSource();
	}
	else{
		//否则为纯色样式，即开启显示填充和边界
		ShowFill = TRUE;
		//ShowBorder = TRUE;
	}


	//始终都初始化4个状态的颜色，当图标文件加载失败时自动启用纯色模式
	//且非指针类型构造时就以申请内存，不初始化也不会节省内存，SO...
	RGB_Static_ON = { 0,50,80 };
	RGB_Static_OFF = { 50,50,50 };
	RGB_In_ON = { 0, 70, 100 };
	RGB_In_OFF = { 80, 80, 80 };

	//初始化默认按钮名称
	ButtomName = new GUI_Text(Origin,Border, new string("SButtom"));
	//初始化默认按钮解释信息
	ButtomExplain = new GUI_Text(Border, Border + Border, new string("Explain Information:\n\tABCDEFGHIJKLMNOPQRSTUVWXYZ"));

	//添加响应事件
	//MouseEventList.push_back(new MouseEventType(E_E_M_Cursor_In));
	//MouseEventList.push_back(new MouseEventType(E_E_M_Cursor_Leave));
	//MouseEventList.push_back(new MouseEventType(E_E_M_MouseLeftButtomDown));
	//MouseEventList.push_back(new MouseEventType(E_E_M_MouseLeftButtomUp));
}
//析构函数
GUI_SelectButtom::~GUI_SelectButtom() {
	delete ButtomName;
	delete ButtomExplain;
	delete ICO_Static_ON;
	delete ICO_Static_OFF;
	delete ICO_In_ON;
	delete ICO_In_OFF;
}

void GUI_SelectButtom::LoadIcoSource() {
	//初始为不填充
	ShowFill = FALSE;
	//初始化4个状态 图标
	ICO_Static_ON = new GUI_BitMap(Origin, Border, "resource\\image\\Buttom\\Buttom_Normal\\ICO_Static_ON.jpg");
	ICO_Static_OFF = new GUI_BitMap(Origin, Border, "resource\\image\\Buttom\\Buttom_Normal\\ICO_Static_OFF.jpg");
	ICO_In_ON = new GUI_BitMap(Origin, Border, "resource\\image\\Buttom\\Buttom_Normal\\ICO_In_ON.jpg");
	ICO_In_OFF = new GUI_BitMap(Origin, Border, "resource\\image\\Buttom\\Buttom_Normal\\ICO_In_OFF.jpg");
}

void GUI_SelectButtom::PaintGraphics() {
	switch (ButtomStyle)
	{
	case Solid_Buttom:
		//如果为纯色样式，则将对应开关状态颜色赋给父类填充色，再执行父类绘制函数（填充和描边）
		if (SwitchState){FillColor = RGB_Static_ON;}
		else { FillColor = RGB_Static_OFF; }
		ShowFill = TRUE;
		break;
	case Image_Buttom:
		//根据开关状态绘制对应图标
		if (SwitchState) { ICO_Static_ON->PaintGraphics(); }
		else { ICO_Static_OFF->PaintGraphics(); }

		break;
	default:
		break;
	}

	//独立的填充于描边，用于测试
	//如果显示填充为真
	if (ShowFill) {
		setlinestyle(PS_NULL, 0);
		setfillstyle(BS_SOLID);
		setfillcolor(RGB(FillColor.x, FillColor.y, FillColor.z));
		fillrectangle(DrawOrigin.x, DrawOrigin.y, DrawBorder.x, DrawBorder.y);
	}
	//如果显示边框为真
	if (ShowBorder) {
		setlinestyle(PS_SOLID, 1);
		setlinecolor(RGB(BorderColor.x, BorderColor.y, BorderColor.z));
		rectangle(DrawOrigin.x, DrawOrigin.y, DrawBorder.x, DrawBorder.y);
	}
	else { setlinestyle(PS_NULL, 0); }
	//绘制按钮名称
	ButtomName->PaintGraphics();
}

bool GUI_SelectButtom::Modification(byte ValueSeq, string* PropertyName, string* PropertyValue) {
	//先调用父类的修改函数，修改公共参数
	bool IsParantProperty = GUI_Rectangle::Modification(ValueSeq, PropertyName, PropertyValue);
	//如果不是父类的属性 再调用本身修改函数，修改特有参数
	if (!IsParantProperty) {
		GUI_SelectButtomPropertyType TYPE = StringTo_GUI_SelectButtomPropertyType(PropertyName);
		switch (TYPE)
		{
		case E_S_SwitchState:
			SwitchState = str_to_int(PropertyValue);
			break;
		case E_S_ButtomStyle:
			ButtomStyle=StringTo_GUI_ButtomStyleType(PropertyValue);
			//如果修改后的样式为图像式，则导入图像资源
			if (ButtomStyle == Image_Buttom) { LoadIcoSource(); }
			break;
		case E_S_ButtomName:
			*ButtomName->Text = *RemoveChar(RemoveChar(PropertyValue,' '),'"');
			break;
		case E_S_ButtomExplain:
			*ButtomExplain->Text = *RemoveChar(RemoveChar(PropertyValue, ' '), '"');
			break;
		case E_S_ICO_Static_ON:
			ICO_Static_ON->BitMapAddress = *PropertyValue;
			break;
		case E_S_ICO_Static_OFF:
			ICO_Static_OFF->BitMapAddress = *PropertyValue;
			break;
		case E_S_ICO_In_ON:
			ICO_In_ON->BitMapAddress = *PropertyValue;
			break;
		case E_S_ICO_In_OFF:
			ICO_In_OFF->BitMapAddress = *PropertyValue;
			break;
		case E_S_RGB_Static_ON:
			RGB_Static_ON.Modification(ValueSeq, PropertyValue);
			break;
		case E_S_RGB_Static_OFF:
			RGB_Static_OFF.Modification(ValueSeq, PropertyValue);
			break;
		case E_S_RGB_In_ON:
			RGB_In_ON.Modification(ValueSeq, PropertyValue);
			break;
		case E_S_RGB_In_OFF:
			RGB_In_OFF.Modification(ValueSeq, PropertyValue);
			break;
		default:
			break;
		}
	}
	return TRUE;
}

void GUI_SelectButtom::FlushData(NodePropertyList* Seek = NULL) {
	//刷新公共属性
	GUI_Rectangle::FlushData(Seek); 
	//刷新内部组件类的属性
	ButtomName->FlushData(Seek);//按钮名
	ButtomExplain->FlushData(Seek);//解释信息

	if (ButtomStyle== Image_Buttom)
	{
		ICO_Static_ON->FlushData(Seek);//静止关闭
		ICO_Static_OFF->FlushData(Seek);//静止开启
		ICO_In_ON->FlushData(Seek);//开启状态光标进入
		ICO_In_OFF->FlushData(Seek);//关闭状态光标进入
	}
	return;
}


////////////////////////////////////////////////////////普通按钮/////////////////////////////////////////////
class GUI_Buttom :public GUI_Rectangle
{
public:
	bool SwitchState;//开关状态
	ButtomStyleType ButtomStyle;//按钮样式
	GUI_Text* ButtomName;//按钮名
	GUI_Text* ButtomExplain;//解释信息

	//图标样式
	GUI_BitMap* ICO_Up;//静止关闭
	GUI_BitMap* ICO_In;//静止开启
	GUI_BitMap* ICO_Down;//开启状态光标进入
	GUI_BitMap* Brush;

	//纯色样式
	Vector3D RGB_Up;
	Vector3D RGB_Down;
	Vector3D RGB_In;

	
	GUI_Buttom(Vector2D Ori, Vector2D Bor, ButtomStyleType Style);
	~GUI_Buttom();

	void LoadIcoSource();
	void PaintGraphics();
	//修改函数
	bool Modification(byte ValueSeq, string* PropertyName, string* PropertyValue);
	//刷新函数
	void FlushData(NodePropertyList* Seek);


	//鼠标事件响应函数
	void Cursor_In(MOUSEMSG* MouseMSG) { 
		//如果事件被占用则直接返回
		if (MouseEventOccupyList.at(E_E_M_Cursor_In)) {
			return;
		}
		//根据风格和开关状态刷新图像
		if (ButtomStyle == Image_Buttom)
		{
			if (SwitchState) {
				Brush = ICO_Down;
			}
			else
			{
				Brush=ICO_In;
			}
		}
		else
		{
			if (SwitchState) {
				FillColor = RGB_Down;
			}
			else
			{
				FillColor = RGB_In;
			}
		}
		PaintGraphics();
	}
	void Cursor_Leave(MOUSEMSG* MouseMSG) { 
		//如果事件被占用则直接返回
		if (MouseEventOccupyList.at(E_E_M_Cursor_Leave)){
			return;
		}
		//根据风格和开关状态刷新图像
		if (ButtomStyle == Image_Buttom){
			if (!SwitchState) {
				Brush = ICO_Up;
				PaintGraphics();
			}
		}else{
			if (!SwitchState) {
				FillColor = RGB_Up;
				PaintGraphics();
			}
		}

	}



	virtual void MouseLeftButtomDown(MOUSEMSG* MouseMSG) {

		//鼠标左键按下时，修改事件占用表
		MouseEventOccupyList[E_E_M_MouseLeftButtomDown] = TRUE;
		MouseEventOccupyList[E_E_M_Cursor_In] = TRUE;
		MouseEventOccupyList[E_E_M_Cursor_Leave] = TRUE;
		//鼠标左键按下，打开开关
		SwitchState = TRUE;
		//根据风格刷新图像
		if (ButtomStyle == Image_Buttom)
		{
			Brush = ICO_Down;
		}
		else
		{
			FillColor = RGB_Down;
		}
		PaintGraphics();

		if (HighWidget!=NULL)
		{
			NodeType* MyType = new NodeType(E_Buttom);
			HighWidget->ReceiveMessages(MyType, this, MouseMSG); delete MyType;
		}
		return;
	}
	void MouseLeftButtomUp(MOUSEMSG* MouseMSG) { 
		//鼠标左键抬起时，修改事件占用表
		MouseEventOccupyList[E_E_M_MouseLeftButtomDown] = FALSE;
		MouseEventOccupyList[E_E_M_Cursor_In] = FALSE;
		MouseEventOccupyList[E_E_M_Cursor_Leave] = FALSE;

		SwitchState = FALSE;
		if (ContainCoord(Area, (*MouseMSG).x, (*MouseMSG).y)) {
			if (ButtomStyle == Image_Buttom)
			{
				Brush = ICO_In;
			}
			else {
				FillColor = RGB_In;
			}
		}
		else
		{
			if (ButtomStyle == Image_Buttom)
			{
				Brush = ICO_Up;
			}
			else {
				FillColor = RGB_Up;
			}
		}
		PaintGraphics();
	}

	//收发消息
	void ReceiveMessages(void* Messages) {}
	void SendMessages() {}
};

//默认构造函数
GUI_Buttom::GUI_Buttom(Vector2D Ori = { 0,0 }, Vector2D Bor = { 100,100 }, ButtomStyleType Style = Solid_Buttom) :GUI_Rectangle(Ori, Bor)
{
	Origin = Ori; Border = Bor; Wid_Hei = Bor - Ori;

	//开关默认状态为关闭
	SwitchState = FALSE;

	//初始化样式
	ButtomStyle = Style;


	//始终都初始化3个状态的颜色，当图标文件加载失败时自动启用纯色模式
	//且非指针类型构造时就以申请内存，不初始化也不会节省内存，SO...
	RGB_Up = { 50,50,50 };
	RGB_Down = { 255,255,255 };
	RGB_In = { 123 ,123, 123 };

	//根据样式选择是否加载图片，或颜色
	if (ButtomStyle == Image_Buttom)
	{
		//加载图标资源
		LoadIcoSource();
		//笔刷默认指向UP图像
		Brush = ICO_Up;
	}
	else
	{
		//否则为纯色样式，即开启显示填充和边界
		ShowFill = TRUE;
		FillColor = RGB_Up;
		//ShowBorder = TRUE;
	}

	//初始化默认按钮名称
	ButtomName = new GUI_Text(Origin, Border, new string("Buttom")); 
	//ButtomName->HighWidget = this;
	//初始化默认按钮解释信息
	ButtomExplain = new GUI_Text(Border, Border + Border, new string("Explain Information:\n\tABCDEFGHIJKLMNOPQRSTUVWXYZ"));
	//ButtomExplain->HighWidget = this;




	//添加响应事件
	MouseEventList.push_back(new MouseEventType(E_E_M_Cursor_In));
	MouseEventList.push_back(new MouseEventType(E_E_M_Cursor_Leave));
	MouseEventList.push_back(new MouseEventType(E_E_M_MouseLeftButtomDown));
	MouseEventList.push_back(new MouseEventType(E_E_M_MouseLeftButtomUp));
}
//析构函数
GUI_Buttom::~GUI_Buttom() {
	cout << "析构函数" << endl;
	system("pause");
	delete ButtomName;
	delete ButtomExplain;
	delete ICO_Up;
	delete ICO_In;
	delete ICO_Down;
}

void GUI_Buttom::LoadIcoSource() {
	//初始为不填充
	ShowFill = FALSE;
	//初始化4个状态 图标
	ICO_Up = new GUI_BitMap(Origin, Border, "resource\\image\\Buttom\\Buttom_Normal\\ICO_Up.jpg");
	ICO_In = new GUI_BitMap(Origin, Border, "resource\\image\\Buttom\\Buttom_Normal\\ICO_In.jpg");
	ICO_Down = new GUI_BitMap(Origin, Border, "resource\\image\\Buttom\\Buttom_Normal\\ICO_Down.jpg");

}

void GUI_Buttom::PaintGraphics() {
	switch (ButtomStyle)
	{
	case Solid_Buttom:
		ShowFill = TRUE;
		break;
	case Image_Buttom:
		Brush->PaintGraphics();
		break;
	default:
		break;
	}

	
	//独立的填充于描边，用于测试
	//如果显示填充为真
	if (ShowFill) {
		setlinestyle(PS_NULL, 0);
		setfillstyle(BS_SOLID);
		setfillcolor(RGB(FillColor.x, FillColor.y, FillColor.z));
		fillrectangle(DrawOrigin.x, DrawOrigin.y, DrawBorder.x, DrawBorder.y);
	}
	//如果显示边框为真
	if (ShowBorder) {
		setlinestyle(PS_SOLID, 1);
		setlinecolor(RGB(BorderColor.x, BorderColor.y, BorderColor.z));
		rectangle(DrawOrigin.x, DrawOrigin.y, DrawBorder.x, DrawBorder.y);
	}

	//绘制按钮名称
	ButtomName->PaintGraphics();
	
}

bool GUI_Buttom::Modification(byte ValueSeq, string* PropertyName, string* PropertyValue) {
	//先调用父类的修改函数，修改公共参数
	bool IsParantProperty = GUI_Rectangle::Modification(ValueSeq, PropertyName, PropertyValue);
	//如果不是父类的属性 再调用本身修改函数，修改特有参数
	if (!IsParantProperty) {
		GUI_ButtomPropertyType TYPE = StringTo_GUI_ButtomPropertyType(PropertyName);
		switch (TYPE)
		{
		case E_SwitchState:
			SwitchState = str_to_int(PropertyValue);
			break;
		case E_ButtomStyle:
			ButtomStyle = StringTo_GUI_ButtomStyleType(PropertyValue);
			//如果修改后的样式为图像式，则导入图像资源
			if (ButtomStyle ==Image_Buttom){	LoadIcoSource();}
			break;
		case E_ButtomName:
			*ButtomName->Text = *RemoveChar(RemoveChar(PropertyValue, ' '), '"');
			break;
		case E_ButtomExplain:
			*ButtomExplain->Text = *RemoveChar(RemoveChar(PropertyValue, ' '), '"');
			break;
		case E_ICO_Up:
			ICO_Up->BitMapAddress = *PropertyValue;
			break;
		case E_ICO_In:
			ICO_In->BitMapAddress = *PropertyValue;
			break;
		case E_ICO_Down:
			ICO_Down->BitMapAddress = *PropertyValue;
			break;
		case E_RGB_Up:
			RGB_Up.Modification(ValueSeq, PropertyValue);
			break;
		case E_RGB_Down:
			RGB_Down.Modification(ValueSeq, PropertyValue);
			break;
		case E_RGB_In:
			RGB_In.Modification(ValueSeq, PropertyValue);
			break;
		default:
			break;
		}
	}
	return TRUE;
}

void GUI_Buttom::FlushData(NodePropertyList* Seek = NULL) {
	//刷新公共属性
	GUI_Rectangle::FlushData(Seek);
	//刷新内部组件类的属性
	ButtomName->FlushData(Seek);//按钮名
	ButtomExplain->FlushData(Seek);//解释信息

	if (ButtomStyle == Image_Buttom)
	{
		ICO_Up->FlushData(Seek);//静止关闭
		ICO_In->FlushData(Seek);//静止开启
		ICO_Down->FlushData(Seek);//开启状态光标进入
	}
	return;
}



///////////////////////////////////////////////////////////////////////////////////////////
class GUI_MoveButton :public GUI_Buttom {
public:

	GUI_MoveButton() :GUI_Buttom() {
		MouseEventList.push_back(new MouseEventType(E_E_M_MouseWheel));
		MouseEventList.push_back(new MouseEventType(E_E_M_MouseWheel_Up));
		MouseEventList.push_back(new MouseEventType(E_E_M_MouseWheel_Down));
	}




	void MouseWheel_Up(MOUSEMSG* MouseMSG) {
		if (HighWidget != NULL)
		{
			NodeType* MyType = new NodeType(E_MoveButton);
			string* Message = new string("MouseWheel_Up");
			HighWidget->ReceiveMessages(MyType, Message); 
			delete MyType, Message;
		}
		return;
	}
	void MouseWheel_Down(MOUSEMSG* MouseMSG) {
		if (HighWidget != NULL)
		{
			NodeType* MyType = new NodeType(E_MoveButton);
			string* Message = new string("MouseWheel_Down");
			HighWidget->ReceiveMessages(MyType, Message); 
			delete MyType, Message;
		}
		return;
	}

	void MouseLeftButtomDown(MOUSEMSG* MouseMSG) {
		//鼠标左键按下时，修改事件占用表
		MouseEventOccupyList[E_E_M_MouseLeftButtomDown] = TRUE;
		MouseEventOccupyList[E_E_M_Cursor_In] = TRUE;
		MouseEventOccupyList[E_E_M_Cursor_Leave] = TRUE;
		//鼠标左键按下，打开开关
		SwitchState = TRUE;
		//根据风格刷新图像
		if (ButtomStyle == Image_Buttom)
		{
			Brush = ICO_Down;
		}
		else
		{
			FillColor = RGB_Down;
		}
		PaintGraphics();
		
		if (HighWidget != NULL) {
			NodeType* MyType = new NodeType(E_MoveButton);
			string* Message= new string("MouseLeftButtomDown");
			HighWidget->ReceiveMessages(MyType, Message); delete MyType, Message;
		}
		
	}

};

//////////////////////////////////////////GUI_滑杆类//////////////////////////////////////////////////
class GUI_Slider :public GUI_Rectangle {
public:
	//byte Mode;//方向，横向/纵向,默认为 0/假 - 横向滑杆,1为纵向，其他为自动分析宽窄确定

	GUI_Rectangle* PathWay;//轨道
	Vector2D Max_Min;//轨道起始值/最大最小值，模拟值
	signed long PathWayValueRange;//轨道航程，模拟值，最大 - 最小
	//bool ShowHatched;//是否以图案填充轨道

	GUI_MoveButton* Rocker;//摇杆
	float LocalValueCapacity;//局部可展示的长度
	float RockerScale;//局部占全部的比例，按钮的长度由，可显示量与未显示量比例决定，模拟值
	signed long Rocker_Value;//摇杆所在值，模拟值

	GUI_Buttom* Buttom_Forward;//向前按钮
	GUI_Buttom* Buttom_backward;//向后按钮


	float SeekScale;
	int RockerLenth;
	int UsableLength;

	GUI_Slider(Vector2D Ori, Vector2D Bor, Vector2D M_m, byte Direction,signed long DefaultValue);
	~GUI_Slider() {
		delete PathWay, Rocker,Buttom_Forward,Buttom_backward;
	}
	//刷新函数
	void FlushData(NodePropertyList* Seek);
	//绘制函数
	void  PaintGraphics();
	//修改函数
	bool Modification(byte ValueSeq, string* PropertyName, string* PropertyValue);
	void CoordCalculate(signed long DefaultValue);

	void ReceiveMessages(NodeType* TypeL, void* Messages1, void* Messages2);
};

//接受信息函数，传入调用此函数的对象的类型和 信息，即可完成通信
void  GUI_Slider::ReceiveMessages(NodeType* Type = NULL, void* Messages1 = NULL, void* Messages2 = NULL) {

	cout <<"WidgetName\t:\t"<<Name<< "\t>>>ReceiveMessages<<<" << endl;
	//判断来信的对象，可根据对象类型，按照对应方法处理消息内容和做出反应
	if (*Type== E_MoveButton)
	{
		if (*((string*)Messages1) == "MouseLeftButtomDown")
		{
			Vector3D FillCol = PathWay->FillColor;
			Vector3D RFillCol = Rocker->FillColor;
			setfillstyle(BS_SOLID);

			MOUSEMSG TMS = GetMouseMsg();
			Vector2D OFFset = { TMS.x - Rocker->Origin.x ,TMS.y - Rocker->Origin.y };
			int length = 0;
			while (TMS.mkLButton)
			{
				BeginBatchDraw();
				//若为横向模式，则	新的按钮坐标 = Valuefilter(Max轨道终点X，Min起点X，鼠标x - 偏移值x)
				if (Mode == 0) {
					////////////////////////////////////////////////////////////////////纯色绘图优化/////////////////////////////////////////////////////////////////////////////////
					//setfillcolor(RGB(FillCol.x, FillCol.y, FillCol.z));
					//fillrectangle(Rocker->Origin.x, Rocker->Origin.y, Rocker->Border.x, Rocker->Border.y);
					////////////////////////////////////////////////////////////////////纯色绘图优化/////////////////////////////////////////////////////////////////////////////////

					Rocker->Area.x1 = Rocker->DrawOrigin.x = Rocker->Origin.x = Valuefilter(PathWay->Border.x - RockerLenth, PathWay->Origin.x, TMS.x - OFFset.x);
					Rocker->Area.x2 = Rocker->DrawBorder.x = Rocker->Border.x = Rocker->Origin.x + Rocker->Wid_Hei.x;
					
					// length为当前按钮所在位置相对于轨道起点的距离
					length = Rocker->Origin.x - PathWay->Origin.x;
					//新的摇杆值为，length 占全轨道长的比例  *  值范围宽度(MAX-MIN)  +  最小值MIN
					Rocker_Value = (((length*1.0f) / UsableLength) *PathWayValueRange) + Max_Min.y;
					cout << "PathWayValueRange : " << PathWayValueRange << "Rocker_Value : " << Rocker_Value << endl;

					////////////////////////////////////////////////////////////////////纯色绘图优化/////////////////////////////////////////////////////////////////////////////////
					//setfillcolor(RGB(RFillCol.x, RFillCol.y, RFillCol.z));
					//fillrectangle(Rocker->Origin.x, Rocker->Origin.y, Rocker->Border.x, Rocker->Border.y);
					////////////////////////////////////////////////////////////////////纯色绘图优化/////////////////////////////////////////////////////////////////////////////////
				}
				else
				{
					//若为纵向模式，则	新的按钮坐标 = Valuefilter(Max轨道终点Y，Min起点Y，鼠标y - 偏移值y)
					////////////////////////////////////////////////////////////////////纯色绘图优化/////////////////////////////////////////////////////////////////////////////////
					//setfillcolor(RGB(FillCol.x, FillCol.y, FillCol.z));
					//fillrectangle(Rocker->Origin.x, Rocker->Origin.y, Rocker->Border.x, Rocker->Border.y);
					////////////////////////////////////////////////////////////////////纯色绘图优化/////////////////////////////////////////////////////////////////////////////////

					Rocker->Area.y1 = Rocker->DrawOrigin.y = Rocker->Origin.y = Valuefilter(PathWay->Border.y - RockerLenth, PathWay->Origin.y, TMS.y - OFFset.y);
					Rocker->Area.y2 = Rocker->DrawBorder.y = Rocker->Border.y = Rocker->Origin.y + Rocker->Wid_Hei.y;

					// length为当前按钮所在位置相对于轨道起点的距离
					length = Rocker->Origin.y - PathWay->Origin.y;
					//新的摇杆值为，length 占全轨道长的比例  *  值范围宽度(MAX-MIN)  +  最小值MIN
					Rocker_Value = (((length*1.0f) / UsableLength) *PathWayValueRange) + Max_Min.y;
					cout << "PathWayValueRange : " << PathWayValueRange << "Rocker_Value : " << Rocker_Value << endl;

					////////////////////////////////////////////////////////////////////纯色绘图优化/////////////////////////////////////////////////////////////////////////////////
					//setfillcolor(RGB(RFillCol.x, RFillCol.y, RFillCol.z));
					//fillrectangle(Rocker->Origin.x, Rocker->Origin.y, Rocker->Border.x, Rocker->Border.y);
					//Rocker->PaintGraphics();
					////////////////////////////////////////////////////////////////////纯色绘图优化/////////////////////////////////////////////////////////////////////////////////

				}
				PathWay->PaintGraphics();
				Rocker->PaintGraphics();
				TMS = GetMouseMsg();
				EndBatchDraw();
			}

			Rocker->MouseLeftButtomUp(&TMS);
			//鼠标左键抬起时，修改事件占用表
			MouseEventOccupyList[E_E_M_MouseLeftButtomDown] = FALSE;
			MouseEventOccupyList[E_E_M_Cursor_In] = FALSE;
			MouseEventOccupyList[E_E_M_Cursor_Leave] = FALSE;
		}
		else if(*((string*)Messages1) == "MouseWheel_Up")
		{
			*Type = E_Buttom;
			ReceiveMessages(Type, Buttom_backward);
			return;
		}
		else if (*((string*)Messages1) == "MouseWheel_Down")
		{
			*Type = E_Buttom;
			ReceiveMessages(Type, Buttom_Forward);
			return;
		}
	}

	if (*Type == E_Buttom) {
		MOUSEMSG TMS =*((MOUSEMSG*)Messages1);
		Vector3D FillCol = PathWay->FillColor;
		Vector3D RFillCol = Rocker->FillColor;
		setfillstyle(BS_SOLID);
		if ((GUI_Buttom*)Messages1 == Buttom_Forward)
		{
			if (Mode ==0)
			{
				BeginBatchDraw();
				//PathWay->PaintGraphics();######################纯色模式绘制优化
				setfillcolor(RGB(FillCol.x, FillCol.y, FillCol.z));
				fillrectangle(Rocker->Origin.x, Rocker->Origin.y, Rocker->Origin.x + (RockerLenth * 0.03f), Rocker->Border.y);

				Rocker->Area.x1 = Rocker->DrawOrigin.x = Rocker->Origin.x = Valuefilter(PathWay->Border.x - RockerLenth, PathWay->Origin.x, Rocker->Origin.x + (RockerLenth * 0.03f));
				Rocker->Area.x2 = Rocker->DrawBorder.x = Rocker->Border.x = Rocker->Origin.x + RockerLenth;
				Rocker_Value = Valuefilter(Max_Min.x, Max_Min.y, Rocker_Value + (RockerLenth * 0.03f));

				//Rocker->PaintGraphics();#######################纯色模式绘制优化
				if (Rocker->ButtomStyle==Solid_Buttom)	{
					setfillcolor(RGB(RFillCol.x, RFillCol.y, RFillCol.z));
					fillrectangle(Rocker->Border.x - (RockerLenth * 0.03f), Rocker->Origin.y, Rocker->Border.x, Rocker->Border.y);
				}else{
					Rocker->PaintGraphics();
				}

				while (TMS.mkLButton)
				{
					EndBatchDraw();
					BeginBatchDraw();
					//PathWay->PaintGraphics();######################纯色模式绘制优化
					setfillcolor(RGB(FillCol.x, FillCol.y, FillCol.z));
					//setfillstyle(BS_SOLID);
					fillrectangle(Rocker->Origin.x, Rocker->Origin.y, Rocker->Origin.x + (RockerLenth * 0.01f), Rocker->Border.y);

					Rocker->Area.x1 = Rocker->DrawOrigin.x = Rocker->Origin.x = Valuefilter(PathWay->Border.x - RockerLenth, PathWay->Origin.x, Rocker->Origin.x + (RockerLenth * 0.01f));
					Rocker->Area.x2 = Rocker->DrawBorder.x = Rocker->Border.x = Rocker->Origin.x + RockerLenth;
					Rocker_Value = Valuefilter(Max_Min.x, Max_Min.y, Rocker_Value + (RockerLenth * 0.01f));

					//Rocker->PaintGraphics();#######################纯色模式绘制优化
					if (Rocker->ButtomStyle == Solid_Buttom) {
						Sleep(5);
						setfillcolor(RGB(RFillCol.x, RFillCol.y, RFillCol.z));
						fillrectangle(Rocker->Border.x - (RockerLenth * 0.01f), Rocker->Origin.y, Rocker->Border.x, Rocker->Border.y);
					}else {
						Rocker->PaintGraphics();
					}

					if (MouseHit())
					{
						TMS = GetMouseMsg();
						if (!TMS.mkLButton)
						{
							EndBatchDraw();
							Buttom_Forward->MouseLeftButtomUp(&TMS);
							return;
						}
					}else if (PathWay->Border.x - RockerLenth == Rocker->Origin.x)
					{
						EndBatchDraw();
						return;
					}

					//EndBatchDraw();
				}
				EndBatchDraw();
				Buttom_Forward->MouseLeftButtomUp(&TMS);
				return;
			}
			else
			{
				BeginBatchDraw();
				//PathWay->PaintGraphics();######################纯色模式绘制优化
				setfillcolor(RGB(FillCol.x, FillCol.y, FillCol.z));
				//setfillstyle(BS_SOLID);
				fillrectangle(Rocker->Origin.x,		Rocker->Origin.y,		Rocker->Border.x ,		Rocker->Origin.y + (RockerLenth * 0.03f));

				Rocker->Area.y1 = Rocker->DrawOrigin.y = Rocker->Origin.y = Valuefilter(PathWay->Border.y - RockerLenth, PathWay->Origin.y, Rocker->Origin.y + (RockerLenth * 0.03f));
				Rocker->Area.y2 = Rocker->DrawBorder.y = Rocker->Border.y = Rocker->Origin.y + RockerLenth;
				Rocker_Value = Valuefilter(Max_Min.x, Max_Min.y, Rocker_Value + (RockerLenth * 0.03f));

				//Rocker->PaintGraphics();#######################纯色模式绘制优化
				if (Rocker->ButtomStyle == Solid_Buttom) {
					setfillcolor(RGB(RFillCol.x, RFillCol.y, RFillCol.z));
					fillrectangle(Rocker->Origin.x,			 Rocker->Border.y- (RockerLenth * 0.03f),			Rocker->Border.x,			Rocker->Border.y);
				}
				else {
					Rocker->PaintGraphics();
				}

				while (TMS.mkLButton)
				{
					EndBatchDraw();
					BeginBatchDraw();
					//PathWay->PaintGraphics();######################纯色模式绘制优化
					setfillcolor(RGB(FillCol.x, FillCol.y, FillCol.z));
					//setfillstyle(BS_SOLID);
					fillrectangle(Rocker->Origin.x, Rocker->Origin.y, Rocker->Border.x, Rocker->Origin.y + (RockerLenth * 0.01f));

					Rocker->Area.y1 = Rocker->DrawOrigin.y = Rocker->Origin.y = Valuefilter(PathWay->Border.y - RockerLenth, PathWay->Origin.y, Rocker->Origin.y + (RockerLenth * 0.01f));
					Rocker->Area.y2 = Rocker->DrawBorder.y = Rocker->Border.y = Rocker->Origin.y + RockerLenth;
					Rocker_Value = Valuefilter(Max_Min.x, Max_Min.y, Rocker_Value + (RockerLenth * 0.01f));

					//Rocker->PaintGraphics();#######################纯色模式绘制优化
					if (Rocker->ButtomStyle == Solid_Buttom) {
						Sleep(5);
						setfillcolor(RGB(RFillCol.x, RFillCol.y, RFillCol.z));
						fillrectangle(Rocker->Origin.x, Rocker->Border.y - (RockerLenth * 0.01f), Rocker->Border.x, Rocker->Border.y);
					}
					else {
						Rocker->PaintGraphics();
					}
					cout << "#############################################################" << endl;
					/************************************************************************************************/
					if (MouseHit()){
						TMS = GetMouseMsg();
						if (!TMS.mkLButton){
							EndBatchDraw();
							Buttom_Forward->MouseLeftButtomUp(&TMS);
							return;
						}
					}
					else if ((PathWay->Border.y - RockerLenth) == Rocker->Origin.y){
						EndBatchDraw();
						return;
					}

					//EndBatchDraw();
					/***********************************************************************************************/
				}
				EndBatchDraw();
				Buttom_Forward->MouseLeftButtomUp(&TMS);
				
				return;
			}
		}
		else if ((GUI_Buttom*)Messages1 == Buttom_backward) 
		{
			if (Mode == 0)
			{
				BeginBatchDraw();
				//PathWay->PaintGraphics();######################纯色模式绘制优化
				setfillcolor(RGB(FillCol.x, FillCol.y, FillCol.z));
				//setfillstyle(BS_SOLID);
				fillrectangle(Rocker->Border.x - (RockerLenth * 0.03f)		, Rocker->Origin.y,		 Rocker->Border.x ,			Rocker->Border.y);

				Rocker->Area.x1 = Rocker->DrawOrigin.x = Rocker->Origin.x = Valuefilter(PathWay->Border.x - RockerLenth, PathWay->Origin.x, Rocker->Origin.x - (RockerLenth * 0.03f));
				Rocker->Area.x2 = Rocker->DrawBorder.x = Rocker->Border.x = Rocker->Origin.x + RockerLenth;
				Rocker_Value = Valuefilter(Max_Min.x, Max_Min.y, Rocker_Value - (RockerLenth * 0.03f));

				//Rocker->PaintGraphics();#######################纯色模式绘制优化
				if (Rocker->ButtomStyle == Solid_Buttom) {
					setfillcolor(RGB(RFillCol.x, RFillCol.y, RFillCol.z));
					fillrectangle(Rocker->Origin.x,				Rocker->Origin.y,				Rocker->Origin.x + (RockerLenth * 0.03f),			Rocker->Border.y);
				}
				else {
					Rocker->PaintGraphics();
				}

				while (TMS.mkLButton)
				{
					EndBatchDraw();
					BeginBatchDraw();
					//PathWay->PaintGraphics();######################纯色模式绘制优化
					setfillcolor(RGB(FillCol.x, FillCol.y, FillCol.z));
					//setfillstyle(BS_SOLID);
					fillrectangle(Rocker->Border.x - (RockerLenth * 0.01f), Rocker->Origin.y, Rocker->Border.x, Rocker->Border.y);

					Rocker->Area.x1 = Rocker->DrawOrigin.x = Rocker->Origin.x = Valuefilter(PathWay->Border.x - RockerLenth, PathWay->Origin.x, Rocker->Origin.x - (RockerLenth * 0.01f));
					Rocker->Area.x2 = Rocker->DrawBorder.x = Rocker->Border.x = Rocker->Origin.x + RockerLenth;
					Rocker_Value = Valuefilter(Max_Min.x, Max_Min.y, Rocker_Value - (RockerLenth * 0.01f));

					//Rocker->PaintGraphics();#######################纯色模式绘制优化
					if (Rocker->ButtomStyle == Solid_Buttom) {
						Sleep(5);
						setfillcolor(RGB(RFillCol.x, RFillCol.y, RFillCol.z));
						fillrectangle(Rocker->Origin.x, Rocker->Origin.y, Rocker->Origin.x + (RockerLenth * 0.01f), Rocker->Border.y);
					}
					else {
						Rocker->PaintGraphics();
					}

					if (MouseHit())
					{
						TMS = GetMouseMsg();
						if (!TMS.mkLButton)
						{
							EndBatchDraw();
							Buttom_backward->MouseLeftButtomUp(&TMS);
							
							return;
						}
					}
					else if (PathWay->Border.x - RockerLenth == Rocker->Origin.x)
					{
						EndBatchDraw();
						return;
					}
					EndBatchDraw();
				}
				EndBatchDraw();
				Buttom_backward->MouseLeftButtomUp(&TMS);
				
				return;
			}
			else
			{
				BeginBatchDraw();
				//PathWay->PaintGraphics();######################纯色模式绘制优化
				setfillcolor(RGB(FillCol.x, FillCol.y, FillCol.z));
				//setfillstyle(BS_SOLID);
				fillrectangle(Rocker->Origin.x,			 Rocker->Border.y- (RockerLenth * 0.03f),				Rocker->Border.x,				Rocker->Border.y);

				Rocker->Area.y1 = Rocker->DrawOrigin.y = Rocker->Origin.y = Valuefilter(PathWay->Border.y - RockerLenth, PathWay->Origin.y, Rocker->Origin.y - (RockerLenth * 0.03f));
				Rocker->Area.y2 = Rocker->DrawBorder.y = Rocker->Border.y = Rocker->Origin.y + RockerLenth;
				Rocker_Value = Valuefilter(Max_Min.x, Max_Min.y, Rocker_Value - (RockerLenth * 0.03f));

				//Rocker->PaintGraphics();#######################纯色模式绘制优化
				if (Rocker->ButtomStyle == Solid_Buttom) {
					setfillcolor(RGB(RFillCol.x, RFillCol.y, RFillCol.z));
					fillrectangle(Rocker->Origin.x,				 Rocker->Origin.y,					Rocker->Border.x,				 Rocker->Origin.y+(RockerLenth * 0.03f));
				}
				else {
					Rocker->PaintGraphics();
				}

				while (TMS.mkLButton) {
					EndBatchDraw();
					BeginBatchDraw();
					//PathWay->PaintGraphics();######################纯色模式绘制优化
					setfillcolor(RGB(FillCol.x, FillCol.y, FillCol.z));
					//setfillstyle(BS_SOLID);
					fillrectangle(Rocker->Origin.x, Rocker->Border.y - (RockerLenth * 0.01f), Rocker->Border.x, Rocker->Border.y);

					Rocker->Area.y1 = Rocker->DrawOrigin.y = Rocker->Origin.y = Valuefilter(PathWay->Border.y - RockerLenth, PathWay->Origin.y, Rocker->Origin.y - (RockerLenth * 0.01f));
					Rocker->Area.y2 = Rocker->DrawBorder.y = Rocker->Border.y = Rocker->Origin.y + RockerLenth;
					Rocker_Value = Valuefilter(Max_Min.x, Max_Min.y, Rocker_Value - (RockerLenth * 0.01f));

					//Rocker->PaintGraphics();#######################纯色模式绘制优化
					if (Rocker->ButtomStyle == Solid_Buttom) {
						Sleep(5);
						setfillcolor(RGB(RFillCol.x, RFillCol.y, RFillCol.z));
						fillrectangle(Rocker->Origin.x, Rocker->Origin.y, Rocker->Border.x, Rocker->Origin.y + (RockerLenth * 0.01f));
					}
					else {
						Rocker->PaintGraphics();
					}
					cout << "#############################################################" << endl;
					/************************************************************************************************/
					if (MouseHit()) {
						TMS = GetMouseMsg();
						if (!TMS.mkLButton) {
							EndBatchDraw();
							Buttom_backward->MouseLeftButtomUp(&TMS);
							
							return;
						}
					}
					else if ((PathWay->Border.y - RockerLenth) == Rocker->Origin.y) {
						EndBatchDraw();
						return;
					}
					/***********************************************************************************************/
				}
				EndBatchDraw();
				Buttom_backward->MouseLeftButtomUp(&TMS);
				
				return;
			}
		}


		//cout << "PathWayValueRange : " << PathWayValueRange << "Rocker_Value : " << Rocker_Value << endl;
		//PathWay->PaintGraphics();
		//Rocker->PaintGraphics();
		return;
	}
	
	
	if (*Type == E_Rectangle)
	{
		if (*((string*)Messages1) == "MouseWheel_Up") {
			*Type = E_Buttom;
			ReceiveMessages(Type, Buttom_backward);
			return;
		}
		else if (*((string*)Messages1) == "MouseWheel_Down") {
			*Type = E_Buttom;
			ReceiveMessages(Type, Buttom_Forward);
			return;
		}
	}
	
	
	return;
}


void GUI_Slider::CoordCalculate(signed long SeekValue=0) {
	//计算局部/全部，比例
	PathWayValueRange =abs( Max_Min.x - Max_Min.y);//total lenght
	RockerScale = LocalValueCapacity / PathWayValueRange;//确定按钮大小比例
	SeekScale = ((Rocker_Value - Max_Min.y) *1.0f/ PathWayValueRange);//确定按钮位置比例
	NodePropertyList Seek;
	//初始化按钮
	//横向模式
	Vector2D B_B_Ori;
	Vector2D B_B_Bor;
	if (!Mode) {
		Mode = 0;
		//按钮默认为方形，宽即为高
		B_B_Ori = Origin;
		B_B_Bor = { (Origin.x + Wid_Hei.y) ,Border.y };
		Seek.origin = B_B_Ori;
		Seek.border = B_B_Bor;
		Buttom_backward->FlushData(&Seek);

		B_B_Ori = { Border.x - Wid_Hei.y,Origin.y };
		Seek.origin = B_B_Ori;
		Seek.border = Border;
		Buttom_Forward->FlushData(&Seek);

		Seek.origin = { Buttom_backward->Border.x, Origin.y };
		Seek.border = { Buttom_Forward->Origin.x, Border.y };
		PathWay->FlushData(&Seek);

		//初始化摇杆按钮
		//摇杆按钮的实际像素(长度/宽度)  = (局部/全部比例) * (布局宽度 - 两个方形按钮的宽度)
		RockerLenth = RockerScale * (Wid_Hei.x - (Wid_Hei.y * 2));

		//实际航程范围计算，实际摇杆可移动的范围是，总布局宽度。减去3个按钮的宽度
		UsableLength = (Wid_Hei.x - (Wid_Hei.y * 2)) - RockerLenth;
		//起点X坐标即为，当前值占总值的比例 * 实际轨道长度
		B_B_Ori = { (Origin.x + Wid_Hei.y) + (SeekScale*UsableLength)  ,  Origin.y };
		//终点X坐标即为，起点X + 按钮长度
		B_B_Bor = { B_B_Ori.x + RockerLenth,Border.y };
		Seek.origin = B_B_Ori;
		Seek.border = B_B_Bor;
		Rocker->FlushData(&Seek);
	}
	//纵向
	else if (Mode == 1) {
		//按钮默认为方形，宽即为高
		B_B_Ori = Origin;
		B_B_Bor = { Border.x ,(Wid_Hei.x + Origin.y) };
		Seek.origin = B_B_Ori;
		Seek.border = B_B_Bor;
		Buttom_backward->FlushData(&Seek);

		B_B_Ori = { Origin.x ,Border.y - Wid_Hei.x };
		Seek.origin = B_B_Ori;
		Seek.border = Border;
		Buttom_Forward->FlushData(&Seek);

		Seek.origin = { Origin.x, Buttom_backward->Border.y };
		Seek.border = { Border.x, Buttom_Forward->Origin.y };
		PathWay->FlushData(&Seek);

		//初始化摇杆按钮
		//摇杆按钮的实际像素(长度/宽度)  = (局部/全部比例) * (布局宽度 - 两个方形按钮的宽度)
		RockerLenth = RockerScale * (Wid_Hei.y - Wid_Hei.x - Wid_Hei.x);

		//实际航程范围计算，实际摇杆可移动的范围是，总布局宽度。减去3个按钮的宽度
		UsableLength = (Wid_Hei.y - Wid_Hei.x - Wid_Hei.x) - RockerLenth;
		//起点X坐标即为，当前值占最大值的比例 * 实际轨道长度
		B_B_Ori = { Origin.x,(SeekScale*UsableLength) + (Origin.y + Wid_Hei.x) };
		//终点X坐标
		B_B_Bor = { Border.x	,B_B_Ori.y + RockerLenth };
		Seek.origin = B_B_Ori;
		Seek.border = B_B_Bor;
		Rocker->FlushData(&Seek);
	}
	//自适应
	else {
		if (Wid_Hei.x > Wid_Hei.y) {
			Mode = 0;
			//按钮默认为方形，宽即为高
			B_B_Ori = Origin;
			B_B_Bor = { (Origin.x + Wid_Hei.y) ,Border.y };
			Seek.origin = B_B_Ori;
			Seek.border = B_B_Bor;
			Buttom_backward->FlushData(&Seek);

			B_B_Ori = { Border.x - Wid_Hei.y,Origin.y };
			Seek.origin = B_B_Ori;
			Seek.border = Border;
			Buttom_Forward->FlushData(&Seek);

			Seek.origin = { Buttom_backward->Border.x, Origin.y };
			Seek.border = { Buttom_Forward->Origin.x, Border.y };
			PathWay->FlushData(&Seek);

			//初始化摇杆按钮
			//摇杆按钮的实际像素(长度/宽度)  = (局部/全部比例) * (布局宽度 - 两个方形按钮的宽度)
			RockerLenth = RockerScale * (Wid_Hei.x - (Wid_Hei.y * 2));

			//实际航程范围计算，实际摇杆可移动的范围是，总布局宽度。减去3个按钮的宽度
			UsableLength = (Wid_Hei.x - (Wid_Hei.y * 2)) - RockerLenth;
			//起点X坐标即为，当前值占总值的比例 * 实际轨道长度
			B_B_Ori = { (Origin.x + Wid_Hei.y) + (SeekScale*UsableLength)  ,  Origin.y };
			//终点X坐标即为，起点X + 按钮长度
			B_B_Bor = { B_B_Ori.x + RockerLenth,Border.y };
			Seek.origin = B_B_Ori;
			Seek.border = B_B_Bor;
			Rocker->FlushData(&Seek);
		}
		else {
			Mode = 1;
			//按钮默认为方形，宽即为高
			B_B_Ori = Origin;
			B_B_Bor = { Border.x ,(Wid_Hei.x + Origin.y) };
			Seek.origin = B_B_Ori;
			Seek.border = B_B_Bor;
			Buttom_backward->FlushData(&Seek);

			B_B_Ori = { Origin.x ,Border.y - Wid_Hei.x };
			Seek.origin = B_B_Ori;
			Seek.border = Border;
			Buttom_Forward->FlushData(&Seek);

			Seek.origin = {Origin.x, Buttom_backward->Border.y};
			Seek.border = {Border.x, Buttom_Forward->Origin.y};
			PathWay->FlushData(&Seek);

			//初始化摇杆按钮
			//摇杆按钮的实际像素(长度/宽度)  = (局部/全部比例) * (布局宽度 - 两个方形按钮的宽度)
			RockerLenth = RockerScale * (Wid_Hei.y - Wid_Hei.x - Wid_Hei.x);

			//实际航程范围计算，实际摇杆可移动的范围是，总布局宽度。减去3个按钮的宽度
			UsableLength = (Wid_Hei.y - Wid_Hei.x - Wid_Hei.x) - RockerLenth;
			//起点X坐标即为，当前值占值域宽的比例 * 实际轨道长度
			B_B_Ori = { Origin.x,(SeekScale*UsableLength) + (Origin.y + Wid_Hei.x) };
			//终点X坐标
			B_B_Bor = { Border.x	,B_B_Ori.y + RockerLenth };
			Seek.origin = B_B_Ori;
			Seek.border = B_B_Bor;
			Rocker->FlushData(&Seek);
		}
	}

	///Buttom_backward->Wid_Hei = Buttom_backward->Border - Buttom_backward->Origin;
	///Buttom_Forward->Wid_Hei = Buttom_Forward->Border - Buttom_Forward->Origin;
	///Rocker->Wid_Hei = Rocker->Border - Rocker->Origin;
}

//默认构造函数
GUI_Slider::GUI_Slider(Vector2D Ori = { 0,0 }, Vector2D Bor = { 100,100 }, Vector2D M_m = { 100,0 }, byte Direction = 3, signed long DefaultValue = 0)
	:GUI_Rectangle(Ori,Bor)
{
	//初始化成员类
	//PathWay = new GUI_Buttom(Origin, Border);//轨道范围同布局范围
	string* tmp = new string(" ");
	Buttom_backward = new GUI_Buttom(Origin, Border, Image_Buttom); Buttom_backward->ButtomName->Text = tmp;
	Buttom_Forward = new GUI_Buttom(Origin, Border, Image_Buttom); Buttom_Forward->ButtomName->Text = tmp;
	Rocker = new GUI_MoveButton(); Rocker->ButtomName->Text = tmp;//Origin, Border, Solid_Buttom
	PathWay = new GUI_Rectangle(Origin, Border);

	Buttom_backward->HighWidget = this;//子对象指向的上一层自己
	Buttom_Forward->HighWidget = this;//子对象指向的上一层自己
	Rocker->HighWidget = this;//子对象指向的上一层自己
	PathWay->HighWidget = this;//子对象指向的上一层自己

	//将子对象的地址添加进入子对象列表
	SubWidgetList.push_back(Buttom_backward);
	SubWidgetList.push_back(Buttom_Forward);
	SubWidgetList.push_back(Rocker);
	SubWidgetList.push_back(PathWay);

	ShowHatched = TRUE;
	ShowFill = TRUE;

	//初始化成员变量
	Mode = Direction;
	Max_Min = M_m;
	PathWayValueRange = M_m.x - M_m.y;//total lenght
	Rocker_Value = DefaultValue;//the current value of Rocker
	LocalValueCapacity = PathWayValueRange * 0.1f;//局部显示能力默认假定为总量的20%
	
	//根据默认索引位置计算各个子控件的生成位置
	//CoordCalculate(DefaultValue);

}

//刷新函数
void GUI_Slider::FlushData(NodePropertyList* Seek = NULL) {
	//刷新公共属性
	GUI_Rectangle::FlushData(Seek);

	//刷新内部组件类的属性
	CoordCalculate(Rocker_Value);
	return;
}

//属性修改函数
bool GUI_Slider::Modification(byte ValueSeq, string* PropertyName, string* PropertyValue) {
	//先调用父类的修改函数，修改公共参数
	bool IsParantProperty = GUI_Rectangle::Modification(ValueSeq, PropertyName, PropertyValue);
	//如果不是父类的属性 再调用本身修改函数，修改特有参数
	if (!IsParantProperty) {
		GUI_SliderPropertyType TYPE = StringTo_GUI_SliderPropertyType(PropertyName);
		switch (TYPE)
		{
		case E_Mode:
			Mode = str_to_int(PropertyValue);
			break;
		case E_PathWay:
			//仅有设置填充颜色的权限
			FillColor.Modification(ValueSeq, PropertyValue);
			break;
		case E_ShowHatched:
			ShowHatched = str_to_int(PropertyValue);
			break;
		case E_Max_Min:
			Max_Min.Modification(ValueSeq, PropertyValue);

			break;
		case E_Rocker:
			//仅有设置填充颜色的权限
			Rocker->FillColor.Modification(ValueSeq, PropertyValue);
			break;
		case E_LocalValueCapacity:
			LocalValueCapacity = str_to_int(PropertyValue);
			break;
		case E_Rocker_Value:
			Rocker_Value = str_to_int(PropertyValue);
			break;
		case E_Buttom_Forward:
			Buttom_Forward->ButtomStyle = StringTo_GUI_ButtomStyleType(PropertyValue);
			break;
		case E_Buttom_backward:
			Buttom_backward->ButtomStyle = StringTo_GUI_ButtomStyleType(PropertyValue);
			break;
		default:
			break;
		}
	}
	return TRUE;
}

//绘制函数
void GUI_Slider::PaintGraphics() {


	PathWay->FillColor = FillColor;
	PathWay->PaintGraphics();
	Rocker->PaintGraphics();
	Buttom_Forward->PaintGraphics();
	Buttom_backward->PaintGraphics();
	
}


//class GUI_ControlButton :public GUI_Buttom {
//public:
//	byte Menue;
//	GUI_ControlButton(Vector2D Ori, Vector2D Bor,byte s,ButtomStyleType Style = Image_Buttom):GUI_Buttom(Ori, Bor, Style), Menue(s)
//	{
//		switch (s)
//		{
//		case 0:
//			//ButtomStyle = Image_Buttom;
//			//*ButtomName->Text =  ("*");
//			break;
//		case 1:
//			//*ButtomName->Text = ("+");
//			//ButtomStyle = Image_Buttom;
//			break;
//		case 2:
//			//*ButtomName->Text =("-");
//			//ButtomStyle = Image_Buttom;
//			break;
//		case 3:
//			//*ButtomName->Text =("--------------------------------------------------------------------------");
//			//ButtomStyle = Image_Buttom;
//			break;
//		default:
//			break;
//		}
//	}
//	void MouseLeftButtomDown(MOUSEMSG* MouseMSG) {
//		GUI_Buttom::MouseLeftButtomDown(MouseMSG);
//		HWND hWnd; hWnd = GetHWnd();
//		RECT rect; GetWindowRect(hWnd, &rect);
//		
//		Vector2D Offset,ADD,ScreenHW;
//		switch (Menue)
//		{
//		case 0:
//			_exit(0);
//			break;
//		case 1:
//			SetWindowPos(hWnd, HWND_TOP, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), SWP_SHOWWINDOW);
//			break;
//		case 2:
//			SetWindowPos(hWnd, HWND_BOTTOM, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), SWP_SHOWWINDOW);
//			break;
//		case 3:
//
//			Offset.x = MouseMSG->x;
//			Offset.y = MouseMSG->y;
//			ScreenHW.x = GetSystemMetrics(SM_CXSCREEN);
//			ScreenHW.x = GetSystemMetrics(SM_CYSCREEN);
//			while (MouseMSG->mkLButton)
//			{
//				ADD.x = (MouseMSG->x - Offset.x);
//				ADD.y = (MouseMSG->y - Offset.y);
//
//				MoveWindow(hWnd, rect.left + ADD.x, rect.top+ ADD.y, ScreenHW.x, ScreenHW.y, TRUE);
//				//SetWindowPos(hWnd, HWND_TOP, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), SWP_SHOWWINDOW);
//				*MouseMSG = GetMouseMsg();
//			}
//		default:
//			break;
//		}
//		return;
//	}
//
//	void FlushData(NodePropertyList* Seek = NULL) {
//		GUI_Rectangle::FlushData(Seek);
//	}
//	void PaintGraphics() {
//		GUI_Buttom::PaintGraphics();
//	}
//};
//
//
//
//class GUI_Titlebar :public GUI_Rectangle {
//public:
//	GUI_ControlButton* EXIT;
//	GUI_ControlButton* MAX;
//	GUI_ControlButton* MIN;
//	GUI_ControlButton* MOVE;
//	GUI_Titlebar(Vector2D Ori = {0,0}, Vector2D Bor = { 0,0 }) :GUI_Rectangle(Ori, Bor) {
//
//		MOVE = new GUI_ControlButton(Ori, Bor, 3);
//
//		Vector2D TMPBorder = { Bor.x - 2,Bor.y - 2 };
//		Vector2D TMPOrigin = { TMPBorder.x - 11,Ori.y + 2 };
//		
//		EXIT = new GUI_ControlButton
//		(
//			TMPOrigin, TMPBorder,0
//		);
//		TMPBorder = { TMPOrigin.x - 2,Bor.y - 2 };
//		TMPOrigin = { TMPBorder.x - 11,Ori.y + 2 };
//		
//		MAX = new GUI_ControlButton
//		(
//			TMPOrigin, TMPBorder, 1
//		);
//		TMPBorder = { TMPOrigin.x - 2,Bor.y - 2 };
//		TMPOrigin = { TMPBorder.x - 11,Ori.y + 2 };
//		MIN = new GUI_ControlButton
//		(
//			TMPOrigin, TMPBorder, 2
//		);
//
//
//		SubWidgetList.push_back(EXIT);
//		SubWidgetList.push_back(MAX);
//		SubWidgetList.push_back(MIN);
//		SubWidgetList.push_back(MOVE);
//	}
//	void PaintGraphics() {
//		MOVE->PaintGraphics();
//		MIN->PaintGraphics();
//		MAX->PaintGraphics();
//		EXIT->PaintGraphics();
//	}
//	void FlushData(NodePropertyList* Seek = NULL) {
//		GUI_Rectangle::FlushData(Seek);
//
//		MOVE->Origin = Origin;
//		MOVE->Border = Border;
//
//		NodePropertyList* tmpSeek = new NodePropertyList;
//		
//		Vector2D TMPBorder = { Border.x - 2,Border.y - 2 };
//		Vector2D TMPOrigin = { TMPBorder.x - 11,Origin.y + 2 };
//		tmpSeek->origin = TMPOrigin;
//		tmpSeek->border = TMPBorder;
//		EXIT->FlushData(tmpSeek);
//
//		TMPBorder = { TMPOrigin.x - 2,Border.y - 2 };
//		TMPOrigin = { TMPBorder.x - 11,Origin.y + 2 };
//		tmpSeek->origin = TMPOrigin;
//		tmpSeek->border = TMPBorder;
//		MAX->FlushData(tmpSeek);
//
//		TMPBorder = { TMPOrigin.x - 2,Border.y - 2 };
//		TMPOrigin = { TMPBorder.x - 11,Origin.y + 2 };
//		tmpSeek->origin = TMPOrigin;
//		tmpSeek->border = TMPBorder;
//		MIN->FlushData(tmpSeek);
//		delete tmpSeek;
//
//	}
//
//	~GUI_Titlebar() {
//		delete EXIT, MAX, MIN, MOVE;
//	}
//};