#pragma once
#include"BaseFunction.h"
#include"ApplyNodeTree.h"



////////////////////////////���οؼ�///////////////////////////////
class GUI_Rectangle {
public:
	static signed int Node_Number;
	string Name;//�ڵ���
	Vector4D Area;//��Ӧ�������
	Vector2D Origin;//�������
	Vector2D Border;//�����յ�
	Vector2D DrawOrigin;//�������
	Vector2D DrawBorder;//�����յ�
	Vector2D Wid_Hei;//���
	bool ShowFill;//�Ƿ����
	Vector3D FillColor;//���ɫ
	bool ShowBorder;//�Ƿ���Ʊ߿�
	Vector3D BorderColor;//����ɫ
	vector<GUI_Rectangle*> SubWidgetList;
	GUI_Rectangle* HighWidget;
	bool ShowHatched;
	byte Mode;

	//���캯��
	GUI_Rectangle(Vector2D Ori, Vector2D Bor,bool Fill, Vector3D FC,bool Border, Vector3D BC); 
	//GUI_Rectangle(GUI_Rectangle& copy) {
	//}
	~GUI_Rectangle() {
		MouseEventList.clear();
		KeyBoardEventList.clear();
	}

	//���ƺ���
	virtual void PaintGraphics();
	//Debug
	virtual void PrintList();

	//FlushData()�����Ǹ�NodeTree��Modification���������õ�
	//��NodeTree��Modification�����յ��˲�����NodeTree�������ֵʱ
	//������NodeTree�ڵ�������Ŀؼ����͵�Modification����������ڵ��	this��ָ��
	virtual void FlushData(NodePropertyList* Seek);

	//�����޸ĺ���	
	//����ȡ������ֵ������ "����ڵ�NodeTree"ʱ������ô˺����������޸Ľڵ������صĿؼ��Ķ��������
	virtual bool Modification(byte ValueSeq, string* PropertyName, string* PropertyValue);
	//����¼���Ӧռ�ñ�
	static map<MouseEventType, bool> MouseEventOccupyList;
	//�¼�������
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
	//����¼���Ӧ����
	virtual void MouseResponseManager(MOUSEMSG*, MouseEventType*);
	virtual void Cursor_In(MOUSEMSG* MouseMSG) {cout << "WidgetName\t:\t" << Name << "\t" << "����¼�\t:\t" << "Cursor_In" << endl;}
	virtual void Cursor_Leave(MOUSEMSG* MouseMSG){cout << "WidgetName\t:\t" << Name << "\t" << "����¼�\t:\t" << "Cursor_Leave" << endl; }
	virtual void MouseWheel(MOUSEMSG* MouseMSG){cout << "WidgetName\t:\t" << Name << "\t" << "����¼�\t:\t" << "MouseWheel" << endl; }
	virtual void MouseWheel_Up(MOUSEMSG* MouseMSG);// { cout << "WidgetName\t:\t" << Name << "\t" << "����¼�\t:\t" << "MouseWheel_Up" << endl; }
	virtual void MouseWheel_Down(MOUSEMSG* MouseMSG);// { cout << "WidgetName\t:\t" << Name << "\t" << "����¼�\t:\t" << "MouseWheel_Down" << endl; }
	virtual void MouseMove(MOUSEMSG* MouseMSG){cout << "WidgetName\t:\t" << Name << "\t" << "����¼�\t:\t" << "MouseMove" << endl; }
	virtual void MouseLeftButtomDown(MOUSEMSG* MouseMSG){cout << "WidgetName\t:\t" << Name << "\t" << "����¼�\t:\t" << "MouseLeftButtomDown" << endl; }
	virtual void MouseLeftButtomUp(MOUSEMSG* MouseMSG){cout << "WidgetName\t:\t" << Name << "\t" << "����¼�\t:\t" << "MouseLeftButtomUp" << endl; }
	virtual void MouseLeftButtomCLK(MOUSEMSG* MouseMSG){cout << "WidgetName\t:\t" << Name << "\t" << "����¼�\t:\t" << "MouseLeftButtomCLK" << endl; }
	virtual void MouseRightButtomDown(MOUSEMSG* MouseMSG){cout << "WidgetName\t:\t" << Name << "\t" << "����¼�\t:\t" << "MouseRightButtomDown" << endl; }
	virtual void MouseRightButtomUp(MOUSEMSG* MouseMSG){cout << "WidgetName\t:\t" << Name << "\t" << "����¼�\t:\t" << "MouseRightButtomUp" << endl; }
	virtual void MouseRightButtomCLK(MOUSEMSG* MouseMSG){cout << "WidgetName\t:\t" << Name << "\t" << "����¼�\t:\t" << "MouseRightButtomCLK" << endl; }
	virtual void MouseMiddleButtomDown(MOUSEMSG* MouseMSG) {cout << "WidgetName\t:\t" << Name << "\t" << "����¼�\t:\t" << "MouseMiddleButtomDown" << endl; }
	virtual void MouseMiddleButtomUp(MOUSEMSG* MouseMSG){cout << "WidgetName\t:\t" << Name << "\t" << "����¼�\t:\t" << "MouseMiddleButtomUp" << endl; }
	virtual void MouseMiddleButtomCLK(MOUSEMSG* MouseMSG){cout << "WidgetName\t:\t" << Name << "\t" << "����¼�\t:\t" << "MouseMiddleButtomCLK" << endl; }
	
	//�¼�������
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
	//�����¼���Ӧ����
	virtual void KeyboardResponseManager(char, KeyboardEventType* );
	virtual void Key_W(char c) { cout<< "WidgetName\t:\t" << Name << "\t" << "�����¼�\t:\tW"<<endl; }
	virtual void Key_S(char c) { cout << "WidgetName\t:\t" << Name << "\t" << "�����¼�\t:\tS" << endl; }
	virtual void Key_A(char c) { cout << "WidgetName\t:\t" << Name << "\t" << "�����¼�\t:\tA" << endl; }
	virtual void Key_D(char c) { cout << "WidgetName\t:\t" << Name << "\t" << "�����¼�\t:\tD" << endl; }
	virtual void Key_F(char c) { cout << "WidgetName\t:\t" << Name << "\t" << "�����¼�\t:\tF" << endl; }
	virtual void Key_ESC(char c) { cout << "WidgetName\t:\t" << Name << "\t" << "�����¼�\t:\tESC" << endl; }
	virtual void Key_LEFT_CTRL(char c) { cout << "WidgetName\t:\t" << Name << "\t" << "�����¼�\t:\tLEFT_CTRL" << endl; }
	virtual void Key_RIGHT_CTRL(char c) { cout << "WidgetName\t:\t" << Name << "\t" << "�����¼�\t:\tRIGHT_CTRL" << endl; }
	virtual void Key_SPACE(char c) { cout << "WidgetName\t:\t" << Name << "\t" << "�����¼�\t:\tSPACE" << endl; }
	virtual void Key_ENTER(char c) { cout << "WidgetName\t:\t" << Name << "\t" << "�����¼�\t:\tENTER" << endl; }
	virtual void Key_LEFT_SHIFT(char c) { cout << "WidgetName\t:\t" << Name << "\t" << "�����¼�\t:\tLEFT_SHIFT\t"<<c << endl; }
	virtual void Key_RIGHT_SHIFT(char c) { cout << "WidgetName\t:\t" << Name << "\t" << "�����¼�\t:\tRIGHT_SHIFT" << endl; }
	virtual void Key_LEFT_ALT(char c) { cout << "WidgetName\t:\t" << Name << "\t" << "�����¼�\t:\tLEFT_ALT" << endl; }
	virtual void Key_RIGHT_ALT(char c) { cout << "WidgetName\t:\t" << Name << "\t" << "�����¼�\t:\tRIGHT_ALT" << endl; }
	virtual void Key_TAB(char c) { cout << "WidgetName\t:\t" << Name << "\t" << "�����¼�\t:\tTAB" << endl; }
	virtual void Key_DELETE(char c) { cout << "WidgetName\t:\t" << Name << "\t" << "�����¼�\t:\tDELETE" << endl; }
	virtual void Key_BACKSPACE(char c) { cout << "WidgetName\t:\t" << Name << "\t" << "�����¼�\t:\tBACKSPACE" << endl; }
	virtual void Key_UP(char c) { cout << "WidgetName\t:\t" << Name << "\t" << "�����¼�\t:\tUP" << endl; }
	virtual void Key_DOWN(char c) { cout << "WidgetName\t:\t" << Name << "\t" << "�����¼�\t:\tDOWN" << endl; }
	virtual void Key_LEFT(char c) { cout << "WidgetName\t:\t" << Name << "\t" << "�����¼�\t:\tLEFT" << endl; }
	virtual void Key_RIGHT(char c) { cout << "WidgetName\t:\t" << Name << "\t" << "�����¼�\t:\tRIGHT" << endl; }

	//�շ���Ϣ
	virtual void ReceiveMessages(NodeType* Type=NULL, void* Messages1 = NULL, void* Messages2 = NULL) { cout << "WidgetName\t:\t" << Name << "\t" << "����\t:\tRIGHT" << endl; }
	virtual void SendMessages() { cout << "WidgetName\t:\t" << Name << "\t" << "����\t:\tRIGHT" << endl; }
};
//GUI_Rectangle ��̬��Ա����
signed int GUI_Rectangle::Node_Number = 0;
map<MouseEventType, bool> GUI_Rectangle::MouseEventOccupyList;

//���캯��
GUI_Rectangle::GUI_Rectangle(Vector2D Ori = { 0,0 }, Vector2D Bor = { 100,100 },bool Fill = TRUE, Vector3D FC = { 100,100,100 },bool Border = FALSE, Vector3D BC = { 255,255,255 }):Origin(Ori), Border(Bor),DrawOrigin(Ori), DrawBorder(Bor),Area{ (int)Ori.x,(int)Ori.y ,(int)Bor.x,(int)Bor.y },ShowFill(Fill), FillColor(FC),ShowBorder(Border), BorderColor(BC)
{
	Node_Number++;
	string AddNumberToName;
	stringstream tmp; tmp << Node_Number; tmp >> AddNumberToName;
	Name = "Node_Number" + AddNumberToName;

	DrawOrigin = Ori;//�ò���������꣬��ʼ�������������
	DrawBorder = Bor;//�ò����յ����꣬��ʼ�������յ�����

	Wid_Hei = (Bor - Ori);//��ʼ�����

	HighWidget = NULL;//Ĭ���ϼ��ؼ�δ���и��Ͽؼ�����������

	ShowHatched = FALSE;//Ĭ�����ͼ��Ϊ��
	Mode = 0;//������Ϊ0��������

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

	////�����ʾ���Ϊ��
	//if (ShowFill) {
	//	setlinestyle(PS_NULL, 0);
	//	setfillstyle(BS_SOLID);
	//	setfillcolor(RGB(FillColor.x, FillColor.y, FillColor.z));
	//	fillrectangle(DrawOrigin.x, DrawOrigin.y, DrawBorder.x, DrawBorder.y);
	//}
	////�����ʾ�߿�Ϊ��
	//if (ShowBorder) {
	//	setlinestyle(PS_SOLID, 1);
	//	setlinecolor(RGB(BorderColor.x, BorderColor.y, BorderColor.z));
	//	rectangle(DrawOrigin.x, DrawOrigin.y, DrawBorder.x, DrawBorder.y);
	//}
	//else { setlinestyle(PS_NULL, 0); }

	//�����ʾ���Ϊ��
	if (ShowFill) {
		setlinestyle(PS_NULL, 0);//�����߿�

		if (ShowHatched) {
			//�����ʾͼ��Ϊ�棬���������Ϊͼ�����
			if (Mode == 0) { setfillstyle(BS_HATCHED, HS_HORIZONTAL); }
			else { setfillstyle(BS_HATCHED, HS_VERTICAL); }
			setfillcolor(RGB(0, 0, 0));//ͼ������Ϊ�����ɫ����
			setbkcolor(RGB(FillColor.x, FillColor.y, FillColor.z));//��ͼ�����ķ�ʽ�䱳��ɫʹ��setbkcolor����
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
	//�����ʾ�߿�Ϊ��
	if (ShowBorder) {
		setlinestyle(PS_SOLID, 1);
		setlinecolor(RGB(BorderColor.x, BorderColor.y, BorderColor.z));
		rectangle(DrawOrigin.x, DrawOrigin.y, DrawBorder.x, DrawBorder.y);
	}
	else { setlinestyle(PS_NULL, 0); }
}

//
void GUI_Rectangle::FlushData(NodePropertyList* Seek = NULL) {
	//��������ڵ㡱�����Է����޸�ʱ���ô˺��������ڸ������ڽڵ����������
	//���±��������	Seek  Ϊ���ڽڵ��	this��ָ��

	//����	���&�յ�
	if (Seek != NULL)
	{
		Origin = Seek->origin;
		Border = Seek->border;
	}
	//���� �������&�����յ�
	DrawOrigin.x = Origin.x;
	DrawOrigin.y = Origin.y;
	DrawBorder.x = Border.x;
	DrawBorder.y = Border.y;

	//����	��&��
	Wid_Hei = Border - Origin;

	Area.x1 = Origin.x;
	Area.y1 = Origin.y;
	Area.x2 = Border.x;
	Area.y2 = Border.y;
}

//
bool GUI_Rectangle::Modification(byte ValueSeq, string* PropertyName, string* PropertyValue) {
	//��ʱ����ָ�룬�洢�����->�Ƿ�Ϊ���๫������
	bool* IsParantProperty = new bool(TRUE);
	//�����ַ���ƥ�丸�๫�����ԣ���IsParantProperty��ָ�봫�룬���ڲ��޸���ֵ
	//��ƥ��ʧ����Ϊ���๫�����ԣ�IsParantProperty�����޸�ΪFLASE����ʱ���ص�ö��������Ч
	//��ƥ��ɹ��򷵻ض�Ӧ�ġ�����ö�١�
	GUI_PublicPropertyType TYPE = StringToGUI_PublicPropertyType(PropertyName, IsParantProperty);

	//~~~~~�ٸ��ඨ��Ĵ˺���ԭ�ͱ�Ȼʱƥ��ɹ���
	//����Ǹ���Ĺ�������,��ֱ���˳�������޸ĺ����������ؼ�
	if (!*IsParantProperty) {
		return FALSE;
	}

	//����Ϊ���������������	���롰ö��ƥ�䡱����
	switch (TYPE)
	{
	case E_GUI_P_Name://����
		Name = *PropertyValue;
		return TRUE;
	case E_GUI_P_Origin://�������
		Origin.Modification(ValueSeq, PropertyValue);
		return TRUE;
	case E_GUI_P_Border://�����յ�
		Border.Modification(ValueSeq, PropertyValue);
		return TRUE;
	case E_GUI_P_DrawOrigin://�������
		DrawOrigin.Modification(ValueSeq, PropertyValue);
		return TRUE;
	case E_GUI_P_DrawBorder://�����յ�
		DrawBorder.Modification(ValueSeq, PropertyValue);
		return TRUE;
	case E_GUI_P_ShowFill://�Ƿ����
		ShowFill = str_to_int(PropertyValue);
		return TRUE;
	case E_GUI_P_FillColor://�����ɫ
		FillColor.Modification(ValueSeq, PropertyValue);
		return TRUE;
	case E_GUI_P_ShowBorder://�Ƿ����
		ShowBorder = str_to_int(PropertyValue);
		return TRUE;
	case E_GUI_P_BorderColor://�����ɫ
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



////////////////////////////Բ�Ǿ��οؼ�///////////////////////////////
class GUI_Roundrect:public GUI_Rectangle
{
public:
	int CutX;
	int CutY;
	//���캯��
	GUI_Roundrect(Vector2D O = { 0,0 }, Vector2D B = {1280,768}, int CtX = 10, int CtY = 10)
		:GUI_Rectangle(O,B),CutX(CtX),CutY(CtY)
	{
		CutX = Wid_Hei.x*0.2f;
		CutY = Wid_Hei.y*0.2f;
		//�����Ӧ�¼�
		//MouseEventList.push_back(new MouseEventType(E_E_M_Cursor_In));
		//MouseEventList.push_back(new MouseEventType(E_E_M_Cursor_Leave));
		//MouseEventList.push_back(new MouseEventType(E_E_M_MouseLeftButtomDown));
		//MouseEventList.push_back(new MouseEventType(E_E_M_MouseLeftButtomUp));
	}
	//��������
	~GUI_Roundrect() {}

public:
	//���ƺ���
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
	//�̳�����ڵ����ԣ�ˢ�±������ԣ����º���
	void FlushData(NodePropertyList* Seek = NULL) {
		GUI_Rectangle::FlushData(Seek);
		CutX = Wid_Hei.x * 0.2f;
		CutY = Wid_Hei.y * 0.2f;
	}

	//�޸ĺ���
	bool Modification(byte ValueSeq,string* PropertyName, string* PropertyValue) {
		
		//�ȵ��ø�����޸ĺ������޸Ĺ�������
		bool IsParantProperty = GUI_Rectangle::Modification(ValueSeq,PropertyName, PropertyValue);
		//������Ǹ�������� �ٵ��ñ����޸ĺ������޸����в���
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

////////////////////////////λͼ�ؼ�///////////////////////////////
class GUI_BitMap:public GUI_Rectangle{
public:
	//λͼ������
	Vector2D DrawWid_Hei;//���ƿ��
	IMAGE Image;
	string BitMapAddress;
	Vector2D RelativeCoord;
	Vector2D MouseHitOffset;
	//GUI_Rectangle* Layout;

	Vector2D LayoutOrigin;
	Vector2D LayoutBorder;

	int ScaleRat;

	//��Ĭ��ֵ�Ĺ��캯�������޲ε���
	GUI_BitMap(Vector2D O = {0,0}, Vector2D B = { 1280,768 },
		string Address = ("resource\\image\\Ico\\SOULFLAW.jpg"))
		:GUI_Rectangle(O,B)
	{
		//���ƿ��Ĭ��Ϊԭʼ���
		DrawWid_Hei = Wid_Hei;
		//λͼ�ؼ�Ĭ���������Ϊ��
		ShowFill = FALSE;

		//��ʼ�����Ʊ߽�
		LayoutOrigin = Origin;
		LayoutBorder = Border;

		BitMapAddress = Address;
		MouseHitOffset = {0,0};
		RelativeCoord = {0,0};

		//Ĭ�����ű���
		ScaleRat = 30;
		//�����Ӧ�¼�
		//MouseEventList.push_back(new MouseEventType(E_E_M_Cursor_In));
		//MouseEventList.push_back(new MouseEventType(E_E_M_Cursor_Leave));
		//MouseEventList.push_back(new MouseEventType(E_E_M_MouseLeftButtomDown));
		//MouseEventList.push_back(new MouseEventType(E_E_M_MouseLeftButtomUp));
	}

	//��������
	~GUI_BitMap() {
		//delete Layout;
	}

	//���ƺ���
	void PaintGraphics() {
		//ԭ���ϲ�Ӧ�ڻ�ͼʱ����ͼƬ���������ϲ�������Ϊ���ٴ�ʱ���µ���ᵼ��ͼƬ�޷���������Ӧ��������
		//���ȴ򿪵�ַ��Ӧ��Դ
		ifstream ImageData(&(BitMapAddress[0]), ios::in);
		//�������ָ���ļ������򿪳ɹ�����Ϊ0
		if (ImageData) {
			//���µ���λͼ����Ա��>>Image
			loadimage(&Image, &(BitMapAddress[0]), Wid_Hei.x, Wid_Hei.y);
		}else	{
			////���������ָ���ļ�����Ĭ���ļ�
			loadimage(&Image, "resource\\image\\Picture\\img02.jpg",
				Wid_Hei.x, Wid_Hei.y);
		}
		//Image.Resize(Wid_Hei.x, Wid_Hei.y);

		//����λͼ
		putimage(DrawOrigin.x, DrawOrigin.y, Wid_Hei.x, Wid_Hei.y, &Image, RelativeCoord.x, RelativeCoord.y);

		//�Ƿ����
		if (ShowFill) {
			setfillstyle(BS_SOLID);
			setfillcolor(RGB(FillColor.x, FillColor.y, FillColor.z));
			fillrectangle(DrawOrigin.x, DrawOrigin.y, DrawBorder.x, DrawBorder.y);
		}
		//�Ƿ����
		if (ShowBorder) {
			setlinestyle(PS_SOLID, 1);
			setlinecolor(RGB(BorderColor.x, BorderColor.y, BorderColor.z));
			rectangle(DrawOrigin.x, DrawOrigin.y, DrawBorder.x, DrawBorder.y);
		}
	}

	//ˢ�º���
	void FlushData(NodePropertyList* Seek = NULL) {
		GUI_Rectangle::FlushData(Seek);
		//Layout->FlushData(Seek);
		LayoutOrigin = Origin;
		LayoutBorder = Border;

	}

	//�޸ĺ���
	bool Modification(byte ValueSeq,string* PropertyName,string* PropertyValue) {
		//�ȵ��ø�����޸ĺ������޸Ĺ�������
		bool IsParantProperty = GUI_Rectangle::Modification(ValueSeq,PropertyName, PropertyValue);

		//������Ǹ�������� �ٵ��ñ����޸ĺ������޸����в���
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

// { cout << "WidgetName\t:\t" << Name << "\t" << "����¼�\t:\t" << "MouseWheel_Up" << endl; }
void GUI_BitMap::MouseWheel_Up(MOUSEMSG* MouseMSG) {
	if (MouseMSG->wheel<=0){
		return;
	}
	MouseHitOffset.x = (MouseMSG->x - Origin.x) / Wid_Hei.x;
	MouseHitOffset.y = (MouseMSG->y - Origin.y) / Wid_Hei.y;
	

	//Bitmap.Wid_Hei.x = ValueFileter(2000, 100, Bitmap.Wid_Hei.x + ScaleRat);
	//Bitmap.Wid_Hei.y = ValueFileter(2000, 100, Bitmap.Wid_Hei.x + ScaleRat);
	//�ȱ�����
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

	//�Ա���ɫ������ǰλ��
	setlinestyle(PS_NULL);
	setfillcolor(RGB(FillColor.x, FillColor.y, FillColor.z));
	fillrectangle(LayoutOrigin.x, LayoutOrigin.y, LayoutBorder.x, LayoutBorder.y);



	//�Ŵ���ͼƬԭʼ��� = ��굱ǰ���� - ���Ŵ�ǰ�������ͼƬ�е���������λ�ã�
	//����ʵ����ʼ����
	 Origin.x = MouseMSG->x - ( Wid_Hei.x*MouseHitOffset.x);
	 Origin.y = MouseMSG->y - ( Wid_Hei.y*MouseHitOffset.y);

	 Border.x =  Origin.x +  Wid_Hei.x;
	 Border.y =  Origin.y +  Wid_Hei.y;

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//������λ��ͼƬ����ڲ����е����λ��Ϊ��ͼƬ��� - �������
	RelativeCoord.x =  Origin.x - LayoutOrigin.x;
	RelativeCoord.y =  Origin.y - LayoutOrigin.y;

	 RelativeCoord.x = RelativeCoord.x > 0 ? 0 : ((RelativeCoord.x)*-1);
	 RelativeCoord.y = RelativeCoord.y > 0 ? 0 : ((RelativeCoord.y)*-1);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//���������ʼ��,Ϊ   ԭʼͼ����� - �������ֵĲ��ֿ��
	//		ͼ��������		=	��ԭʼ���	-	������㣩������ڵ����㣬��Ϊ�ڲ����ڲ�������Ϊ���磬��ȡ�������
	 DrawOrigin.x = ( Origin.x - LayoutOrigin.x) >= 0 ?  Origin.x : LayoutOrigin.x;
	 DrawOrigin.y = ( Origin.y - LayoutOrigin.y) >= 0 ?  Origin.y : LayoutOrigin.y;

	 DrawBorder.x = ( Border.x - LayoutBorder.x) <= 0 ?  Border.x : LayoutBorder.x;
	 DrawBorder.y = ( Border.y - LayoutBorder.y) <= 0 ?  Border.y : LayoutBorder.y;
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	 //FlushData();
	 DrawWid_Hei = DrawBorder - DrawOrigin;

	 Image.Resize( Wid_Hei.x>=0? Wid_Hei.x:0,  Wid_Hei.y>=0? Wid_Hei.y:0);

	 loadimage(&Image, &(BitMapAddress[0]), Wid_Hei.x, Wid_Hei.y);
	 //����λͼ
	 putimage(DrawOrigin.x, DrawOrigin.y, DrawWid_Hei.x, DrawWid_Hei.y, &Image, RelativeCoord.x, RelativeCoord.y);
	 //PaintGraphics();
	 FlushBatchDraw();
	 //EndBatchDraw();
}
// { cout << "WidgetName\t:\t" << Name << "\t" << "����¼�\t:\t" << "MouseWheel_Down" << endl; }
void GUI_BitMap::MouseWheel_Down(MOUSEMSG* MouseMSG) {
	if (MouseMSG->wheel >= 0) {
		return;
	}
	MouseHitOffset.x = (MouseMSG->x - Origin.x) / Wid_Hei.x;
	MouseHitOffset.y = (MouseMSG->y - Origin.y) / Wid_Hei.y;
	int newwidth;

	//Bitmap.Wid_Hei.x = ValueFileter(2000, 100, Bitmap.Wid_Hei.x + ScaleRat);
	//Bitmap.Wid_Hei.y = ValueFileter(2000, 100, Bitmap.Wid_Hei.x + ScaleRat);
	//�ȱ�����
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

	//�Ա���ɫ������ǰλ��
	setlinestyle(PS_NULL);
	setfillcolor(RGB(FillColor.x, FillColor.y, FillColor.z));
	fillrectangle(LayoutOrigin.x, LayoutOrigin.y, LayoutBorder.x, LayoutBorder.y);

	//�Ŵ���ͼƬԭʼ��� = ��굱ǰ���� - ���Ŵ�ǰ�������ͼƬ�е���������λ�ã�
	//����ʵ����ʼ����
	Origin.x = MouseMSG->x - (Wid_Hei.x*MouseHitOffset.x);
	Origin.y = MouseMSG->y - (Wid_Hei.y*MouseHitOffset.y);

	Border.x = Origin.x + Wid_Hei.x;
	Border.y = Origin.y + Wid_Hei.y;

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//������λ��ͼƬ����ڲ����е����λ��Ϊ��ͼƬ��� - �������
	RelativeCoord.x = Origin.x - LayoutOrigin.x;
	RelativeCoord.y = Origin.y - LayoutOrigin.y;

	RelativeCoord.x = RelativeCoord.x > 0 ? 0 : ((RelativeCoord.x)*-1);
	RelativeCoord.y = RelativeCoord.y > 0 ? 0 : ((RelativeCoord.y)*-1);
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//���������ʼ��,Ϊ   ԭʼͼ����� - �������ֵĲ��ֿ��
	//		ͼ��������		=	��ԭʼ���	-	������㣩������ڵ����㣬��Ϊ�ڲ����ڲ�������Ϊ���磬��ȡ�������
	DrawOrigin.x = (Origin.x - LayoutOrigin.x) >= 0 ? Origin.x : LayoutOrigin.x;
	DrawOrigin.y = (Origin.y - LayoutOrigin.y) >= 0 ? Origin.y : LayoutOrigin.y;

	DrawBorder.x = (Border.x - LayoutBorder.x) <= 0 ? Border.x : LayoutBorder.x;
	DrawBorder.y = (Border.y - LayoutBorder.y) <= 0 ? Border.y : LayoutBorder.y;
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	 //FlushData();
	DrawWid_Hei = DrawBorder - DrawOrigin;

	Image.Resize(Wid_Hei.x >= 0 ? Wid_Hei.x : 0, Wid_Hei.y >= 0 ? Wid_Hei.y : 0);

	loadimage(&Image, &(BitMapAddress[0]), Wid_Hei.x, Wid_Hei.y);
	//����λͼ
	putimage(DrawOrigin.x, DrawOrigin.y, DrawWid_Hei.x, DrawWid_Hei.y, &Image, RelativeCoord.x, RelativeCoord.y);
	//PaintGraphics();
	FlushBatchDraw();
	//EndBatchDraw();
}

void GUI_BitMap::MouseLeftButtomDown(MOUSEMSG* MouseMSG) {

	//MOUSEMSG* ms = MouseMSG;
	//��ȡƫ��ֵ
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
		//�Ա���ɫ������ǰλ��
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
		//����λͼ
		putimage(DrawOrigin.x, DrawOrigin.y, DrawWid_Hei.x, DrawWid_Hei.y, &Image, RelativeCoord.x, RelativeCoord.y);
		EndBatchDraw();
		//FlushBatchDraw();

		*MouseMSG = GetMouseMsg();
	}

}




////////////////////////////�ı��ؼ�///////////////////////////////
class GUI_Text : public GUI_Rectangle
{
public:
	string* Text;//�ı�����
	string* TextStyle;//�ı���ʽ
	Vector3D TextColor;//�ı���ɫ
	Vector3D TextBkColor;//�ı���ɫ
	RECT OutArea;//�������

	int TextHeight;//���ָ߶�
	int HeightBacke;//���ָ߶ȱ���
	bool  Transparent;//�Ƿ�͸��


	GUI_Text
	(
		Vector2D O = {0,0}, Vector2D B = { 0,0 },
		string* tex = new string("TEXT"),string* Tstyle = new string("΢���ź�"),
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

		//�����Ӧ�¼�
		//MouseEventList.push_back(new MouseEventType(E_E_M_Cursor_In));
		//MouseEventList.push_back(new MouseEventType(E_E_M_Cursor_Leave));
		//MouseEventList.push_back(new MouseEventType(E_E_M_MouseLeftButtomDown));
		//MouseEventList.push_back(new MouseEventType(E_E_M_MouseLeftButtomUp));
	}
	~GUI_Text() {
		delete Text;
		delete TextStyle;
	}

	//���ƺ���
	void PaintGraphics()
	{

		settextstyle(TextHeight, 0, (const char*)(TextStyle));
		settextcolor(RGB(TextColor.x, TextColor.y, TextColor.z));

		LOGFONT f;
		gettextstyle(&f);
		f.lfQuality = ANTIALIASED_QUALITY;
		settextstyle(&f);
		//��ʱ����ע��
		//setbkcolor(RGB(TextBkColor.x, TextBkColor.y, TextBkColor.z));

		if (Transparent) {
			setbkmode(TRANSPARENT);
		}
		else { setbkmode(OPAQUE); }

		drawtext((&((*Text)[0])), &OutArea, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

		//�����ʾ���Ϊ��
		if (ShowFill) {
			setlinestyle(PS_NULL, 0);
			setfillstyle(BS_SOLID);
			setfillcolor(RGB(FillColor.x, FillColor.y, FillColor.z));
			fillrectangle(DrawOrigin.x, DrawOrigin.y, DrawBorder.x, DrawBorder.y);
		}

		//�����ʾ�߿�Ϊ��
		if (ShowBorder) {
			setlinestyle(PS_SOLID, 1);
			setlinecolor(RGB(BorderColor.x, BorderColor.y, BorderColor.z));
			rectangle(DrawOrigin.x, DrawOrigin.y, DrawBorder.x, DrawBorder.y);
		}
		else { setlinestyle(PS_NULL, 0); }

	}


	//�̳�����ڵ����ԣ�ˢ�±������ԣ����º���
	void FlushData(NodePropertyList* Seek = NULL) {
		GUI_Rectangle::FlushData(Seek);

		OutArea.left = DrawOrigin.x;//�������
		OutArea.right = DrawBorder.x;
		OutArea.top = DrawOrigin.y;
		OutArea.bottom = DrawBorder.y;

		TextHeight = Wid_Hei.y*0.9f;//���ָ߶�
	}

	//�޸ĺ���
	bool Modification(byte ValueSeq, string* PropertyName, string* PropertyValue) {

		//�ȵ��ø�����޸ĺ������޸Ĺ�������
		bool IsParantProperty = GUI_Rectangle::Modification(ValueSeq, PropertyName, PropertyValue);
		//������Ǹ�������� �ٵ��ñ����޸ĺ������޸����в���
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

////////////////////////////��Ƶ�ؼ�///////////////////////////////
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
	//�޸ĺ���
	bool Modification(byte ValueSeq, string* PropertyName, string* PropertyValue);
	//ˢ�º���
	void FlushData(NodePropertyList* Seek = NULL) {GUI_Rectangle::FlushData(Seek);return;}
};

//CreateFunction
GUI_Sound::GUI_Sound(string* SoundSource = new string("resource\\Sound\\LoveStoryDJ.mp3")) :GUI_Rectangle()
{
	AutoPlay = TRUE;
	SoundAddress = SoundSource;
	Open();
	SoundIco = new GUI_BitMap(Origin, Border);

	//�����Ӧ�¼�
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
	//�����ʾ���Ϊ��
	if (ShowFill) {
		setlinestyle(PS_NULL, 0);
		setfillstyle(BS_SOLID);
		setfillcolor(RGB(FillColor.x, FillColor.y, FillColor.z));
		fillrectangle(DrawOrigin.x, DrawOrigin.y, DrawBorder.x, DrawBorder.y);
	}
	//�����ʾ�߿�Ϊ��
	if (ShowBorder) {
		setlinestyle(PS_SOLID, 1);
		setlinecolor(RGB(BorderColor.x, BorderColor.y, BorderColor.z));
		rectangle(DrawOrigin.x, DrawOrigin.y, DrawBorder.x, DrawBorder.y);
	}
	else { setlinestyle(PS_NULL, 0); }
}

//�޸ĺ���
bool GUI_Sound::Modification(byte ValueSeq, string* PropertyName, string* PropertyValue)
{
	//�ȵ��ø�����޸ĺ������޸Ĺ�������
	bool IsParantProperty = GUI_Rectangle::Modification(ValueSeq, PropertyName, PropertyValue);
	//������Ǹ�������� �ٵ��ñ����޸ĺ������޸����в���
	if (!IsParantProperty) {
		GUI_SoundPropertyType TYPE = StringTo_GUI_SoundPropertyType(PropertyName);
		switch (TYPE)
		{
		case E_SoundAddress:
			//�ȹر���������
			Close();
			//������Դ��ַ
			SoundAddress = PropertyValue;
			//���µ�����
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




////////////////////////////////////////////////2ѡ�ť////////////////////////////////////////////////
class GUI_SelectButtom :public GUI_Rectangle
{
public:
	bool SwitchState;//����״̬
	ButtomStyleType ButtomStyle;//��ť��ʽ
	GUI_Text* ButtomName;//��ť��
	GUI_Text* ButtomExplain;//������Ϣ

	//ͼ����ʽ
	GUI_BitMap* ICO_Static_ON;//��ֹ�ر�
	GUI_BitMap* ICO_Static_OFF;//��ֹ����
	GUI_BitMap* ICO_In_ON;//����״̬������
	GUI_BitMap* ICO_In_OFF;//�ر�״̬������

	//��ɫ��ʽ
	Vector3D RGB_Static_ON;
	Vector3D RGB_Static_OFF;
	Vector3D RGB_In_ON;
	Vector3D RGB_In_OFF;
	

	GUI_SelectButtom(Vector2D Ori, Vector2D Bor, ButtomStyleType Style);
	~GUI_SelectButtom();

	//����ͼ�꺯��
	void LoadIcoSource();
	//��ͼ����
	void PaintGraphics();
	//�޸ĺ���
	bool Modification(byte ValueSeq, string* PropertyName, string* PropertyValue);
	//ˢ�º���
	void FlushData(NodePropertyList* Seek);
};



//Ĭ�Ϲ��캯��
GUI_SelectButtom::GUI_SelectButtom(Vector2D Ori = { 0,0 }, Vector2D Bor = { 100,100 }, ButtomStyleType Style = Solid_Buttom):GUI_Rectangle()
{
	Origin = Ori; Border = Bor; Wid_Hei = Bor - Ori;
	//����Ĭ��״̬Ϊ�ر�
	SwitchState = FALSE;
	//��ʼ����ʽ
	ButtomStyle = Style;

	//������ʽѡ���Ƿ����ͼƬ������ɫ
	if (ButtomStyle == Image_Buttom){
		//����ͼ����Դ
		LoadIcoSource();
	}
	else{
		//����Ϊ��ɫ��ʽ����������ʾ���ͱ߽�
		ShowFill = TRUE;
		//ShowBorder = TRUE;
	}


	//ʼ�ն���ʼ��4��״̬����ɫ����ͼ���ļ�����ʧ��ʱ�Զ����ô�ɫģʽ
	//�ҷ�ָ�����͹���ʱ���������ڴ棬����ʼ��Ҳ�����ʡ�ڴ棬SO...
	RGB_Static_ON = { 0,50,80 };
	RGB_Static_OFF = { 50,50,50 };
	RGB_In_ON = { 0, 70, 100 };
	RGB_In_OFF = { 80, 80, 80 };

	//��ʼ��Ĭ�ϰ�ť����
	ButtomName = new GUI_Text(Origin,Border, new string("SButtom"));
	//��ʼ��Ĭ�ϰ�ť������Ϣ
	ButtomExplain = new GUI_Text(Border, Border + Border, new string("Explain Information:\n\tABCDEFGHIJKLMNOPQRSTUVWXYZ"));

	//�����Ӧ�¼�
	//MouseEventList.push_back(new MouseEventType(E_E_M_Cursor_In));
	//MouseEventList.push_back(new MouseEventType(E_E_M_Cursor_Leave));
	//MouseEventList.push_back(new MouseEventType(E_E_M_MouseLeftButtomDown));
	//MouseEventList.push_back(new MouseEventType(E_E_M_MouseLeftButtomUp));
}
//��������
GUI_SelectButtom::~GUI_SelectButtom() {
	delete ButtomName;
	delete ButtomExplain;
	delete ICO_Static_ON;
	delete ICO_Static_OFF;
	delete ICO_In_ON;
	delete ICO_In_OFF;
}

void GUI_SelectButtom::LoadIcoSource() {
	//��ʼΪ�����
	ShowFill = FALSE;
	//��ʼ��4��״̬ ͼ��
	ICO_Static_ON = new GUI_BitMap(Origin, Border, "resource\\image\\Buttom\\Buttom_Normal\\ICO_Static_ON.jpg");
	ICO_Static_OFF = new GUI_BitMap(Origin, Border, "resource\\image\\Buttom\\Buttom_Normal\\ICO_Static_OFF.jpg");
	ICO_In_ON = new GUI_BitMap(Origin, Border, "resource\\image\\Buttom\\Buttom_Normal\\ICO_In_ON.jpg");
	ICO_In_OFF = new GUI_BitMap(Origin, Border, "resource\\image\\Buttom\\Buttom_Normal\\ICO_In_OFF.jpg");
}

void GUI_SelectButtom::PaintGraphics() {
	switch (ButtomStyle)
	{
	case Solid_Buttom:
		//���Ϊ��ɫ��ʽ���򽫶�Ӧ����״̬��ɫ�����������ɫ����ִ�и�����ƺ�����������ߣ�
		if (SwitchState){FillColor = RGB_Static_ON;}
		else { FillColor = RGB_Static_OFF; }
		ShowFill = TRUE;
		break;
	case Image_Buttom:
		//���ݿ���״̬���ƶ�Ӧͼ��
		if (SwitchState) { ICO_Static_ON->PaintGraphics(); }
		else { ICO_Static_OFF->PaintGraphics(); }

		break;
	default:
		break;
	}

	//�������������ߣ����ڲ���
	//�����ʾ���Ϊ��
	if (ShowFill) {
		setlinestyle(PS_NULL, 0);
		setfillstyle(BS_SOLID);
		setfillcolor(RGB(FillColor.x, FillColor.y, FillColor.z));
		fillrectangle(DrawOrigin.x, DrawOrigin.y, DrawBorder.x, DrawBorder.y);
	}
	//�����ʾ�߿�Ϊ��
	if (ShowBorder) {
		setlinestyle(PS_SOLID, 1);
		setlinecolor(RGB(BorderColor.x, BorderColor.y, BorderColor.z));
		rectangle(DrawOrigin.x, DrawOrigin.y, DrawBorder.x, DrawBorder.y);
	}
	else { setlinestyle(PS_NULL, 0); }
	//���ư�ť����
	ButtomName->PaintGraphics();
}

bool GUI_SelectButtom::Modification(byte ValueSeq, string* PropertyName, string* PropertyValue) {
	//�ȵ��ø�����޸ĺ������޸Ĺ�������
	bool IsParantProperty = GUI_Rectangle::Modification(ValueSeq, PropertyName, PropertyValue);
	//������Ǹ�������� �ٵ��ñ����޸ĺ������޸����в���
	if (!IsParantProperty) {
		GUI_SelectButtomPropertyType TYPE = StringTo_GUI_SelectButtomPropertyType(PropertyName);
		switch (TYPE)
		{
		case E_S_SwitchState:
			SwitchState = str_to_int(PropertyValue);
			break;
		case E_S_ButtomStyle:
			ButtomStyle=StringTo_GUI_ButtomStyleType(PropertyValue);
			//����޸ĺ����ʽΪͼ��ʽ������ͼ����Դ
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
	//ˢ�¹�������
	GUI_Rectangle::FlushData(Seek); 
	//ˢ���ڲ�����������
	ButtomName->FlushData(Seek);//��ť��
	ButtomExplain->FlushData(Seek);//������Ϣ

	if (ButtomStyle== Image_Buttom)
	{
		ICO_Static_ON->FlushData(Seek);//��ֹ�ر�
		ICO_Static_OFF->FlushData(Seek);//��ֹ����
		ICO_In_ON->FlushData(Seek);//����״̬������
		ICO_In_OFF->FlushData(Seek);//�ر�״̬������
	}
	return;
}


////////////////////////////////////////////////////////��ͨ��ť/////////////////////////////////////////////
class GUI_Buttom :public GUI_Rectangle
{
public:
	bool SwitchState;//����״̬
	ButtomStyleType ButtomStyle;//��ť��ʽ
	GUI_Text* ButtomName;//��ť��
	GUI_Text* ButtomExplain;//������Ϣ

	//ͼ����ʽ
	GUI_BitMap* ICO_Up;//��ֹ�ر�
	GUI_BitMap* ICO_In;//��ֹ����
	GUI_BitMap* ICO_Down;//����״̬������
	GUI_BitMap* Brush;

	//��ɫ��ʽ
	Vector3D RGB_Up;
	Vector3D RGB_Down;
	Vector3D RGB_In;

	
	GUI_Buttom(Vector2D Ori, Vector2D Bor, ButtomStyleType Style);
	~GUI_Buttom();

	void LoadIcoSource();
	void PaintGraphics();
	//�޸ĺ���
	bool Modification(byte ValueSeq, string* PropertyName, string* PropertyValue);
	//ˢ�º���
	void FlushData(NodePropertyList* Seek);


	//����¼���Ӧ����
	void Cursor_In(MOUSEMSG* MouseMSG) { 
		//����¼���ռ����ֱ�ӷ���
		if (MouseEventOccupyList.at(E_E_M_Cursor_In)) {
			return;
		}
		//���ݷ��Ϳ���״̬ˢ��ͼ��
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
		//����¼���ռ����ֱ�ӷ���
		if (MouseEventOccupyList.at(E_E_M_Cursor_Leave)){
			return;
		}
		//���ݷ��Ϳ���״̬ˢ��ͼ��
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

		//����������ʱ���޸��¼�ռ�ñ�
		MouseEventOccupyList[E_E_M_MouseLeftButtomDown] = TRUE;
		MouseEventOccupyList[E_E_M_Cursor_In] = TRUE;
		MouseEventOccupyList[E_E_M_Cursor_Leave] = TRUE;
		//���������£��򿪿���
		SwitchState = TRUE;
		//���ݷ��ˢ��ͼ��
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
		//������̧��ʱ���޸��¼�ռ�ñ�
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

	//�շ���Ϣ
	void ReceiveMessages(void* Messages) {}
	void SendMessages() {}
};

//Ĭ�Ϲ��캯��
GUI_Buttom::GUI_Buttom(Vector2D Ori = { 0,0 }, Vector2D Bor = { 100,100 }, ButtomStyleType Style = Solid_Buttom) :GUI_Rectangle(Ori, Bor)
{
	Origin = Ori; Border = Bor; Wid_Hei = Bor - Ori;

	//����Ĭ��״̬Ϊ�ر�
	SwitchState = FALSE;

	//��ʼ����ʽ
	ButtomStyle = Style;


	//ʼ�ն���ʼ��3��״̬����ɫ����ͼ���ļ�����ʧ��ʱ�Զ����ô�ɫģʽ
	//�ҷ�ָ�����͹���ʱ���������ڴ棬����ʼ��Ҳ�����ʡ�ڴ棬SO...
	RGB_Up = { 50,50,50 };
	RGB_Down = { 255,255,255 };
	RGB_In = { 123 ,123, 123 };

	//������ʽѡ���Ƿ����ͼƬ������ɫ
	if (ButtomStyle == Image_Buttom)
	{
		//����ͼ����Դ
		LoadIcoSource();
		//��ˢĬ��ָ��UPͼ��
		Brush = ICO_Up;
	}
	else
	{
		//����Ϊ��ɫ��ʽ����������ʾ���ͱ߽�
		ShowFill = TRUE;
		FillColor = RGB_Up;
		//ShowBorder = TRUE;
	}

	//��ʼ��Ĭ�ϰ�ť����
	ButtomName = new GUI_Text(Origin, Border, new string("Buttom")); 
	//ButtomName->HighWidget = this;
	//��ʼ��Ĭ�ϰ�ť������Ϣ
	ButtomExplain = new GUI_Text(Border, Border + Border, new string("Explain Information:\n\tABCDEFGHIJKLMNOPQRSTUVWXYZ"));
	//ButtomExplain->HighWidget = this;




	//�����Ӧ�¼�
	MouseEventList.push_back(new MouseEventType(E_E_M_Cursor_In));
	MouseEventList.push_back(new MouseEventType(E_E_M_Cursor_Leave));
	MouseEventList.push_back(new MouseEventType(E_E_M_MouseLeftButtomDown));
	MouseEventList.push_back(new MouseEventType(E_E_M_MouseLeftButtomUp));
}
//��������
GUI_Buttom::~GUI_Buttom() {
	cout << "��������" << endl;
	system("pause");
	delete ButtomName;
	delete ButtomExplain;
	delete ICO_Up;
	delete ICO_In;
	delete ICO_Down;
}

void GUI_Buttom::LoadIcoSource() {
	//��ʼΪ�����
	ShowFill = FALSE;
	//��ʼ��4��״̬ ͼ��
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

	
	//�������������ߣ����ڲ���
	//�����ʾ���Ϊ��
	if (ShowFill) {
		setlinestyle(PS_NULL, 0);
		setfillstyle(BS_SOLID);
		setfillcolor(RGB(FillColor.x, FillColor.y, FillColor.z));
		fillrectangle(DrawOrigin.x, DrawOrigin.y, DrawBorder.x, DrawBorder.y);
	}
	//�����ʾ�߿�Ϊ��
	if (ShowBorder) {
		setlinestyle(PS_SOLID, 1);
		setlinecolor(RGB(BorderColor.x, BorderColor.y, BorderColor.z));
		rectangle(DrawOrigin.x, DrawOrigin.y, DrawBorder.x, DrawBorder.y);
	}

	//���ư�ť����
	ButtomName->PaintGraphics();
	
}

bool GUI_Buttom::Modification(byte ValueSeq, string* PropertyName, string* PropertyValue) {
	//�ȵ��ø�����޸ĺ������޸Ĺ�������
	bool IsParantProperty = GUI_Rectangle::Modification(ValueSeq, PropertyName, PropertyValue);
	//������Ǹ�������� �ٵ��ñ����޸ĺ������޸����в���
	if (!IsParantProperty) {
		GUI_ButtomPropertyType TYPE = StringTo_GUI_ButtomPropertyType(PropertyName);
		switch (TYPE)
		{
		case E_SwitchState:
			SwitchState = str_to_int(PropertyValue);
			break;
		case E_ButtomStyle:
			ButtomStyle = StringTo_GUI_ButtomStyleType(PropertyValue);
			//����޸ĺ����ʽΪͼ��ʽ������ͼ����Դ
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
	//ˢ�¹�������
	GUI_Rectangle::FlushData(Seek);
	//ˢ���ڲ�����������
	ButtomName->FlushData(Seek);//��ť��
	ButtomExplain->FlushData(Seek);//������Ϣ

	if (ButtomStyle == Image_Buttom)
	{
		ICO_Up->FlushData(Seek);//��ֹ�ر�
		ICO_In->FlushData(Seek);//��ֹ����
		ICO_Down->FlushData(Seek);//����״̬������
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
		//����������ʱ���޸��¼�ռ�ñ�
		MouseEventOccupyList[E_E_M_MouseLeftButtomDown] = TRUE;
		MouseEventOccupyList[E_E_M_Cursor_In] = TRUE;
		MouseEventOccupyList[E_E_M_Cursor_Leave] = TRUE;
		//���������£��򿪿���
		SwitchState = TRUE;
		//���ݷ��ˢ��ͼ��
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

//////////////////////////////////////////GUI_������//////////////////////////////////////////////////
class GUI_Slider :public GUI_Rectangle {
public:
	//byte Mode;//���򣬺���/����,Ĭ��Ϊ 0/�� - ���򻬸�,1Ϊ��������Ϊ�Զ�������խȷ��

	GUI_Rectangle* PathWay;//���
	Vector2D Max_Min;//�����ʼֵ/�����Сֵ��ģ��ֵ
	signed long PathWayValueRange;//������̣�ģ��ֵ����� - ��С
	//bool ShowHatched;//�Ƿ���ͼ�������

	GUI_MoveButton* Rocker;//ҡ��
	float LocalValueCapacity;//�ֲ���չʾ�ĳ���
	float RockerScale;//�ֲ�ռȫ���ı�������ť�ĳ����ɣ�����ʾ����δ��ʾ������������ģ��ֵ
	signed long Rocker_Value;//ҡ������ֵ��ģ��ֵ

	GUI_Buttom* Buttom_Forward;//��ǰ��ť
	GUI_Buttom* Buttom_backward;//���ť


	float SeekScale;
	int RockerLenth;
	int UsableLength;

	GUI_Slider(Vector2D Ori, Vector2D Bor, Vector2D M_m, byte Direction,signed long DefaultValue);
	~GUI_Slider() {
		delete PathWay, Rocker,Buttom_Forward,Buttom_backward;
	}
	//ˢ�º���
	void FlushData(NodePropertyList* Seek);
	//���ƺ���
	void  PaintGraphics();
	//�޸ĺ���
	bool Modification(byte ValueSeq, string* PropertyName, string* PropertyValue);
	void CoordCalculate(signed long DefaultValue);

	void ReceiveMessages(NodeType* TypeL, void* Messages1, void* Messages2);
};

//������Ϣ������������ô˺����Ķ�������ͺ� ��Ϣ���������ͨ��
void  GUI_Slider::ReceiveMessages(NodeType* Type = NULL, void* Messages1 = NULL, void* Messages2 = NULL) {

	cout <<"WidgetName\t:\t"<<Name<< "\t>>>ReceiveMessages<<<" << endl;
	//�ж����ŵĶ��󣬿ɸ��ݶ������ͣ����ն�Ӧ����������Ϣ���ݺ�������Ӧ
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
				//��Ϊ����ģʽ����	�µİ�ť���� = Valuefilter(Max����յ�X��Min���X�����x - ƫ��ֵx)
				if (Mode == 0) {
					////////////////////////////////////////////////////////////////////��ɫ��ͼ�Ż�/////////////////////////////////////////////////////////////////////////////////
					//setfillcolor(RGB(FillCol.x, FillCol.y, FillCol.z));
					//fillrectangle(Rocker->Origin.x, Rocker->Origin.y, Rocker->Border.x, Rocker->Border.y);
					////////////////////////////////////////////////////////////////////��ɫ��ͼ�Ż�/////////////////////////////////////////////////////////////////////////////////

					Rocker->Area.x1 = Rocker->DrawOrigin.x = Rocker->Origin.x = Valuefilter(PathWay->Border.x - RockerLenth, PathWay->Origin.x, TMS.x - OFFset.x);
					Rocker->Area.x2 = Rocker->DrawBorder.x = Rocker->Border.x = Rocker->Origin.x + Rocker->Wid_Hei.x;
					
					// lengthΪ��ǰ��ť����λ������ڹ�����ľ���
					length = Rocker->Origin.x - PathWay->Origin.x;
					//�µ�ҡ��ֵΪ��length ռȫ������ı���  *  ֵ��Χ���(MAX-MIN)  +  ��СֵMIN
					Rocker_Value = (((length*1.0f) / UsableLength) *PathWayValueRange) + Max_Min.y;
					cout << "PathWayValueRange : " << PathWayValueRange << "Rocker_Value : " << Rocker_Value << endl;

					////////////////////////////////////////////////////////////////////��ɫ��ͼ�Ż�/////////////////////////////////////////////////////////////////////////////////
					//setfillcolor(RGB(RFillCol.x, RFillCol.y, RFillCol.z));
					//fillrectangle(Rocker->Origin.x, Rocker->Origin.y, Rocker->Border.x, Rocker->Border.y);
					////////////////////////////////////////////////////////////////////��ɫ��ͼ�Ż�/////////////////////////////////////////////////////////////////////////////////
				}
				else
				{
					//��Ϊ����ģʽ����	�µİ�ť���� = Valuefilter(Max����յ�Y��Min���Y�����y - ƫ��ֵy)
					////////////////////////////////////////////////////////////////////��ɫ��ͼ�Ż�/////////////////////////////////////////////////////////////////////////////////
					//setfillcolor(RGB(FillCol.x, FillCol.y, FillCol.z));
					//fillrectangle(Rocker->Origin.x, Rocker->Origin.y, Rocker->Border.x, Rocker->Border.y);
					////////////////////////////////////////////////////////////////////��ɫ��ͼ�Ż�/////////////////////////////////////////////////////////////////////////////////

					Rocker->Area.y1 = Rocker->DrawOrigin.y = Rocker->Origin.y = Valuefilter(PathWay->Border.y - RockerLenth, PathWay->Origin.y, TMS.y - OFFset.y);
					Rocker->Area.y2 = Rocker->DrawBorder.y = Rocker->Border.y = Rocker->Origin.y + Rocker->Wid_Hei.y;

					// lengthΪ��ǰ��ť����λ������ڹ�����ľ���
					length = Rocker->Origin.y - PathWay->Origin.y;
					//�µ�ҡ��ֵΪ��length ռȫ������ı���  *  ֵ��Χ���(MAX-MIN)  +  ��СֵMIN
					Rocker_Value = (((length*1.0f) / UsableLength) *PathWayValueRange) + Max_Min.y;
					cout << "PathWayValueRange : " << PathWayValueRange << "Rocker_Value : " << Rocker_Value << endl;

					////////////////////////////////////////////////////////////////////��ɫ��ͼ�Ż�/////////////////////////////////////////////////////////////////////////////////
					//setfillcolor(RGB(RFillCol.x, RFillCol.y, RFillCol.z));
					//fillrectangle(Rocker->Origin.x, Rocker->Origin.y, Rocker->Border.x, Rocker->Border.y);
					//Rocker->PaintGraphics();
					////////////////////////////////////////////////////////////////////��ɫ��ͼ�Ż�/////////////////////////////////////////////////////////////////////////////////

				}
				PathWay->PaintGraphics();
				Rocker->PaintGraphics();
				TMS = GetMouseMsg();
				EndBatchDraw();
			}

			Rocker->MouseLeftButtomUp(&TMS);
			//������̧��ʱ���޸��¼�ռ�ñ�
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
				//PathWay->PaintGraphics();######################��ɫģʽ�����Ż�
				setfillcolor(RGB(FillCol.x, FillCol.y, FillCol.z));
				fillrectangle(Rocker->Origin.x, Rocker->Origin.y, Rocker->Origin.x + (RockerLenth * 0.03f), Rocker->Border.y);

				Rocker->Area.x1 = Rocker->DrawOrigin.x = Rocker->Origin.x = Valuefilter(PathWay->Border.x - RockerLenth, PathWay->Origin.x, Rocker->Origin.x + (RockerLenth * 0.03f));
				Rocker->Area.x2 = Rocker->DrawBorder.x = Rocker->Border.x = Rocker->Origin.x + RockerLenth;
				Rocker_Value = Valuefilter(Max_Min.x, Max_Min.y, Rocker_Value + (RockerLenth * 0.03f));

				//Rocker->PaintGraphics();#######################��ɫģʽ�����Ż�
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
					//PathWay->PaintGraphics();######################��ɫģʽ�����Ż�
					setfillcolor(RGB(FillCol.x, FillCol.y, FillCol.z));
					//setfillstyle(BS_SOLID);
					fillrectangle(Rocker->Origin.x, Rocker->Origin.y, Rocker->Origin.x + (RockerLenth * 0.01f), Rocker->Border.y);

					Rocker->Area.x1 = Rocker->DrawOrigin.x = Rocker->Origin.x = Valuefilter(PathWay->Border.x - RockerLenth, PathWay->Origin.x, Rocker->Origin.x + (RockerLenth * 0.01f));
					Rocker->Area.x2 = Rocker->DrawBorder.x = Rocker->Border.x = Rocker->Origin.x + RockerLenth;
					Rocker_Value = Valuefilter(Max_Min.x, Max_Min.y, Rocker_Value + (RockerLenth * 0.01f));

					//Rocker->PaintGraphics();#######################��ɫģʽ�����Ż�
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
				//PathWay->PaintGraphics();######################��ɫģʽ�����Ż�
				setfillcolor(RGB(FillCol.x, FillCol.y, FillCol.z));
				//setfillstyle(BS_SOLID);
				fillrectangle(Rocker->Origin.x,		Rocker->Origin.y,		Rocker->Border.x ,		Rocker->Origin.y + (RockerLenth * 0.03f));

				Rocker->Area.y1 = Rocker->DrawOrigin.y = Rocker->Origin.y = Valuefilter(PathWay->Border.y - RockerLenth, PathWay->Origin.y, Rocker->Origin.y + (RockerLenth * 0.03f));
				Rocker->Area.y2 = Rocker->DrawBorder.y = Rocker->Border.y = Rocker->Origin.y + RockerLenth;
				Rocker_Value = Valuefilter(Max_Min.x, Max_Min.y, Rocker_Value + (RockerLenth * 0.03f));

				//Rocker->PaintGraphics();#######################��ɫģʽ�����Ż�
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
					//PathWay->PaintGraphics();######################��ɫģʽ�����Ż�
					setfillcolor(RGB(FillCol.x, FillCol.y, FillCol.z));
					//setfillstyle(BS_SOLID);
					fillrectangle(Rocker->Origin.x, Rocker->Origin.y, Rocker->Border.x, Rocker->Origin.y + (RockerLenth * 0.01f));

					Rocker->Area.y1 = Rocker->DrawOrigin.y = Rocker->Origin.y = Valuefilter(PathWay->Border.y - RockerLenth, PathWay->Origin.y, Rocker->Origin.y + (RockerLenth * 0.01f));
					Rocker->Area.y2 = Rocker->DrawBorder.y = Rocker->Border.y = Rocker->Origin.y + RockerLenth;
					Rocker_Value = Valuefilter(Max_Min.x, Max_Min.y, Rocker_Value + (RockerLenth * 0.01f));

					//Rocker->PaintGraphics();#######################��ɫģʽ�����Ż�
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
				//PathWay->PaintGraphics();######################��ɫģʽ�����Ż�
				setfillcolor(RGB(FillCol.x, FillCol.y, FillCol.z));
				//setfillstyle(BS_SOLID);
				fillrectangle(Rocker->Border.x - (RockerLenth * 0.03f)		, Rocker->Origin.y,		 Rocker->Border.x ,			Rocker->Border.y);

				Rocker->Area.x1 = Rocker->DrawOrigin.x = Rocker->Origin.x = Valuefilter(PathWay->Border.x - RockerLenth, PathWay->Origin.x, Rocker->Origin.x - (RockerLenth * 0.03f));
				Rocker->Area.x2 = Rocker->DrawBorder.x = Rocker->Border.x = Rocker->Origin.x + RockerLenth;
				Rocker_Value = Valuefilter(Max_Min.x, Max_Min.y, Rocker_Value - (RockerLenth * 0.03f));

				//Rocker->PaintGraphics();#######################��ɫģʽ�����Ż�
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
					//PathWay->PaintGraphics();######################��ɫģʽ�����Ż�
					setfillcolor(RGB(FillCol.x, FillCol.y, FillCol.z));
					//setfillstyle(BS_SOLID);
					fillrectangle(Rocker->Border.x - (RockerLenth * 0.01f), Rocker->Origin.y, Rocker->Border.x, Rocker->Border.y);

					Rocker->Area.x1 = Rocker->DrawOrigin.x = Rocker->Origin.x = Valuefilter(PathWay->Border.x - RockerLenth, PathWay->Origin.x, Rocker->Origin.x - (RockerLenth * 0.01f));
					Rocker->Area.x2 = Rocker->DrawBorder.x = Rocker->Border.x = Rocker->Origin.x + RockerLenth;
					Rocker_Value = Valuefilter(Max_Min.x, Max_Min.y, Rocker_Value - (RockerLenth * 0.01f));

					//Rocker->PaintGraphics();#######################��ɫģʽ�����Ż�
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
				//PathWay->PaintGraphics();######################��ɫģʽ�����Ż�
				setfillcolor(RGB(FillCol.x, FillCol.y, FillCol.z));
				//setfillstyle(BS_SOLID);
				fillrectangle(Rocker->Origin.x,			 Rocker->Border.y- (RockerLenth * 0.03f),				Rocker->Border.x,				Rocker->Border.y);

				Rocker->Area.y1 = Rocker->DrawOrigin.y = Rocker->Origin.y = Valuefilter(PathWay->Border.y - RockerLenth, PathWay->Origin.y, Rocker->Origin.y - (RockerLenth * 0.03f));
				Rocker->Area.y2 = Rocker->DrawBorder.y = Rocker->Border.y = Rocker->Origin.y + RockerLenth;
				Rocker_Value = Valuefilter(Max_Min.x, Max_Min.y, Rocker_Value - (RockerLenth * 0.03f));

				//Rocker->PaintGraphics();#######################��ɫģʽ�����Ż�
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
					//PathWay->PaintGraphics();######################��ɫģʽ�����Ż�
					setfillcolor(RGB(FillCol.x, FillCol.y, FillCol.z));
					//setfillstyle(BS_SOLID);
					fillrectangle(Rocker->Origin.x, Rocker->Border.y - (RockerLenth * 0.01f), Rocker->Border.x, Rocker->Border.y);

					Rocker->Area.y1 = Rocker->DrawOrigin.y = Rocker->Origin.y = Valuefilter(PathWay->Border.y - RockerLenth, PathWay->Origin.y, Rocker->Origin.y - (RockerLenth * 0.01f));
					Rocker->Area.y2 = Rocker->DrawBorder.y = Rocker->Border.y = Rocker->Origin.y + RockerLenth;
					Rocker_Value = Valuefilter(Max_Min.x, Max_Min.y, Rocker_Value - (RockerLenth * 0.01f));

					//Rocker->PaintGraphics();#######################��ɫģʽ�����Ż�
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
	//����ֲ�/ȫ��������
	PathWayValueRange =abs( Max_Min.x - Max_Min.y);//total lenght
	RockerScale = LocalValueCapacity / PathWayValueRange;//ȷ����ť��С����
	SeekScale = ((Rocker_Value - Max_Min.y) *1.0f/ PathWayValueRange);//ȷ����ťλ�ñ���
	NodePropertyList Seek;
	//��ʼ����ť
	//����ģʽ
	Vector2D B_B_Ori;
	Vector2D B_B_Bor;
	if (!Mode) {
		Mode = 0;
		//��ťĬ��Ϊ���Σ���Ϊ��
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

		//��ʼ��ҡ�˰�ť
		//ҡ�˰�ť��ʵ������(����/���)  = (�ֲ�/ȫ������) * (���ֿ�� - �������ΰ�ť�Ŀ��)
		RockerLenth = RockerScale * (Wid_Hei.x - (Wid_Hei.y * 2));

		//ʵ�ʺ��̷�Χ���㣬ʵ��ҡ�˿��ƶ��ķ�Χ�ǣ��ܲ��ֿ�ȡ���ȥ3����ť�Ŀ��
		UsableLength = (Wid_Hei.x - (Wid_Hei.y * 2)) - RockerLenth;
		//���X���꼴Ϊ����ǰֵռ��ֵ�ı��� * ʵ�ʹ������
		B_B_Ori = { (Origin.x + Wid_Hei.y) + (SeekScale*UsableLength)  ,  Origin.y };
		//�յ�X���꼴Ϊ�����X + ��ť����
		B_B_Bor = { B_B_Ori.x + RockerLenth,Border.y };
		Seek.origin = B_B_Ori;
		Seek.border = B_B_Bor;
		Rocker->FlushData(&Seek);
	}
	//����
	else if (Mode == 1) {
		//��ťĬ��Ϊ���Σ���Ϊ��
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

		//��ʼ��ҡ�˰�ť
		//ҡ�˰�ť��ʵ������(����/���)  = (�ֲ�/ȫ������) * (���ֿ�� - �������ΰ�ť�Ŀ��)
		RockerLenth = RockerScale * (Wid_Hei.y - Wid_Hei.x - Wid_Hei.x);

		//ʵ�ʺ��̷�Χ���㣬ʵ��ҡ�˿��ƶ��ķ�Χ�ǣ��ܲ��ֿ�ȡ���ȥ3����ť�Ŀ��
		UsableLength = (Wid_Hei.y - Wid_Hei.x - Wid_Hei.x) - RockerLenth;
		//���X���꼴Ϊ����ǰֵռ���ֵ�ı��� * ʵ�ʹ������
		B_B_Ori = { Origin.x,(SeekScale*UsableLength) + (Origin.y + Wid_Hei.x) };
		//�յ�X����
		B_B_Bor = { Border.x	,B_B_Ori.y + RockerLenth };
		Seek.origin = B_B_Ori;
		Seek.border = B_B_Bor;
		Rocker->FlushData(&Seek);
	}
	//����Ӧ
	else {
		if (Wid_Hei.x > Wid_Hei.y) {
			Mode = 0;
			//��ťĬ��Ϊ���Σ���Ϊ��
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

			//��ʼ��ҡ�˰�ť
			//ҡ�˰�ť��ʵ������(����/���)  = (�ֲ�/ȫ������) * (���ֿ�� - �������ΰ�ť�Ŀ��)
			RockerLenth = RockerScale * (Wid_Hei.x - (Wid_Hei.y * 2));

			//ʵ�ʺ��̷�Χ���㣬ʵ��ҡ�˿��ƶ��ķ�Χ�ǣ��ܲ��ֿ�ȡ���ȥ3����ť�Ŀ��
			UsableLength = (Wid_Hei.x - (Wid_Hei.y * 2)) - RockerLenth;
			//���X���꼴Ϊ����ǰֵռ��ֵ�ı��� * ʵ�ʹ������
			B_B_Ori = { (Origin.x + Wid_Hei.y) + (SeekScale*UsableLength)  ,  Origin.y };
			//�յ�X���꼴Ϊ�����X + ��ť����
			B_B_Bor = { B_B_Ori.x + RockerLenth,Border.y };
			Seek.origin = B_B_Ori;
			Seek.border = B_B_Bor;
			Rocker->FlushData(&Seek);
		}
		else {
			Mode = 1;
			//��ťĬ��Ϊ���Σ���Ϊ��
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

			//��ʼ��ҡ�˰�ť
			//ҡ�˰�ť��ʵ������(����/���)  = (�ֲ�/ȫ������) * (���ֿ�� - �������ΰ�ť�Ŀ��)
			RockerLenth = RockerScale * (Wid_Hei.y - Wid_Hei.x - Wid_Hei.x);

			//ʵ�ʺ��̷�Χ���㣬ʵ��ҡ�˿��ƶ��ķ�Χ�ǣ��ܲ��ֿ�ȡ���ȥ3����ť�Ŀ��
			UsableLength = (Wid_Hei.y - Wid_Hei.x - Wid_Hei.x) - RockerLenth;
			//���X���꼴Ϊ����ǰֵռֵ���ı��� * ʵ�ʹ������
			B_B_Ori = { Origin.x,(SeekScale*UsableLength) + (Origin.y + Wid_Hei.x) };
			//�յ�X����
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

//Ĭ�Ϲ��캯��
GUI_Slider::GUI_Slider(Vector2D Ori = { 0,0 }, Vector2D Bor = { 100,100 }, Vector2D M_m = { 100,0 }, byte Direction = 3, signed long DefaultValue = 0)
	:GUI_Rectangle(Ori,Bor)
{
	//��ʼ����Ա��
	//PathWay = new GUI_Buttom(Origin, Border);//�����Χͬ���ַ�Χ
	string* tmp = new string(" ");
	Buttom_backward = new GUI_Buttom(Origin, Border, Image_Buttom); Buttom_backward->ButtomName->Text = tmp;
	Buttom_Forward = new GUI_Buttom(Origin, Border, Image_Buttom); Buttom_Forward->ButtomName->Text = tmp;
	Rocker = new GUI_MoveButton(); Rocker->ButtomName->Text = tmp;//Origin, Border, Solid_Buttom
	PathWay = new GUI_Rectangle(Origin, Border);

	Buttom_backward->HighWidget = this;//�Ӷ���ָ�����һ���Լ�
	Buttom_Forward->HighWidget = this;//�Ӷ���ָ�����һ���Լ�
	Rocker->HighWidget = this;//�Ӷ���ָ�����һ���Լ�
	PathWay->HighWidget = this;//�Ӷ���ָ�����һ���Լ�

	//���Ӷ���ĵ�ַ��ӽ����Ӷ����б�
	SubWidgetList.push_back(Buttom_backward);
	SubWidgetList.push_back(Buttom_Forward);
	SubWidgetList.push_back(Rocker);
	SubWidgetList.push_back(PathWay);

	ShowHatched = TRUE;
	ShowFill = TRUE;

	//��ʼ����Ա����
	Mode = Direction;
	Max_Min = M_m;
	PathWayValueRange = M_m.x - M_m.y;//total lenght
	Rocker_Value = DefaultValue;//the current value of Rocker
	LocalValueCapacity = PathWayValueRange * 0.1f;//�ֲ���ʾ����Ĭ�ϼٶ�Ϊ������20%
	
	//����Ĭ������λ�ü�������ӿؼ�������λ��
	//CoordCalculate(DefaultValue);

}

//ˢ�º���
void GUI_Slider::FlushData(NodePropertyList* Seek = NULL) {
	//ˢ�¹�������
	GUI_Rectangle::FlushData(Seek);

	//ˢ���ڲ�����������
	CoordCalculate(Rocker_Value);
	return;
}

//�����޸ĺ���
bool GUI_Slider::Modification(byte ValueSeq, string* PropertyName, string* PropertyValue) {
	//�ȵ��ø�����޸ĺ������޸Ĺ�������
	bool IsParantProperty = GUI_Rectangle::Modification(ValueSeq, PropertyName, PropertyValue);
	//������Ǹ�������� �ٵ��ñ����޸ĺ������޸����в���
	if (!IsParantProperty) {
		GUI_SliderPropertyType TYPE = StringTo_GUI_SliderPropertyType(PropertyName);
		switch (TYPE)
		{
		case E_Mode:
			Mode = str_to_int(PropertyValue);
			break;
		case E_PathWay:
			//�������������ɫ��Ȩ��
			FillColor.Modification(ValueSeq, PropertyValue);
			break;
		case E_ShowHatched:
			ShowHatched = str_to_int(PropertyValue);
			break;
		case E_Max_Min:
			Max_Min.Modification(ValueSeq, PropertyValue);

			break;
		case E_Rocker:
			//�������������ɫ��Ȩ��
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

//���ƺ���
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