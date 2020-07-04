#pragma once
#include"SCRIPT_JML.h"
//#define DEBUG_KEYBORD_EEVENT
using namespace std;

/////////////////////////////////////����豸��������/////////////////////////////////////
class MouseEventDetector {
public:
	MOUSEMSG* MouseMS;
	MouseEventType*  MouseEvent;
	//������¼���⺯��������ֵΪ����¼�����
	virtual void EventCheck(vector<NodeTree*>* NoodList);
	void CoordCheck(vector<NodeTree*>* NoodList, MouseEventType* EventType);
	void SubWidgetCheck(vector<GUI_Rectangle*> *LIST,MouseEventType* EventType);
	GUI_Rectangle* Last_Cursor_In;
	GUI_Rectangle* Last_LeftButtomDown;
	MouseEventDetector() {
		MouseMS = new MOUSEMSG;
		*MouseMS = GetMouseMsg();
		MouseEvent = new MouseEventType;
		*MouseEvent = E_E_M_INVALID;
		Last_Cursor_In = NULL;
		Last_LeftButtomDown = NULL;
	}
	~MouseEventDetector() {
		delete MouseMS, MouseEvent;
	}
};
//���϶�����Ӧ����
void MouseEventDetector::SubWidgetCheck(vector<GUI_Rectangle*> *LIST, MouseEventType* EventType) {
	if (*EventType == E_E_M_MouseLeftButtomUp)
	{
		if (Last_LeftButtomDown != NULL) {
			Last_LeftButtomDown->MouseResponseManager(MouseMS, new MouseEventType(E_E_M_MouseLeftButtomUp));
		}
		return;
	}

	for (auto a : (*LIST))
	{
		//�������ڴ˽ڵ㲼����
		if (ContainCoord(a->Area, MouseMS->x, MouseMS->y))
		{
			//��ʾ����
#ifdef __SHOW_CHACKBOX__

			setlinestyle(PS_SOLID, 1);
			setfillstyle(BS_NULL);
			setlinecolor(BLUE);
			fillrectangle(a->Area.x1, a->Area.y1, a->Area.x2, a->Area.y2);
			line(a->Area.x1, a->Area.y1, a->Area.x2, a->Area.y2);
			line(a->Area.x1, a->Area.y2, a->Area.x2, a->Area.y1);

#endif // DEBUG

			//��������Ӷ���������Ӷ��������
			if (a->SubWidgetList.size() > 0)
			{
				SubWidgetCheck(&(a->SubWidgetList), EventType);
				return;
			}
			//������Ӷ�������Ҹö����¼��б������ڵ�ǰ�¼���Ӧ���򴥷�
			else 
			if (a->FindMouseEventEvent(EventType))
			{

				//��ʾ����
#ifdef __SHOW_CHACKBOX__

				setlinestyle(PS_SOLID, 1);
				setfillstyle(BS_NULL);
				setlinecolor(GREEN);
				fillrectangle(a->Area.x1, a->Area.y1, a->Area.x2, a->Area.y2);
				line(a->Area.x1, a->Area.y1, a->Area.x2, a->Area.y2);
				line(a->Area.x1, a->Area.y2, a->Area.x2, a->Area.y1);

#endif // DEBUG
				//���ȴ���ֱ���¼�
				a->MouseResponseManager(MouseMS, EventType);

				//�ٴ�������¼�
				if (*EventType == E_E_M_MouseMove)
				{
					if (Last_Cursor_In == NULL) {
						Last_Cursor_In = a; a->MouseResponseManager(MouseMS, new MouseEventType(E_E_M_Cursor_In));
					}
					if (a != Last_Cursor_In) {
						a->MouseResponseManager(MouseMS, new MouseEventType(E_E_M_Cursor_In));
						Last_Cursor_In->MouseResponseManager(MouseMS, new MouseEventType(E_E_M_Cursor_Leave));
						Last_Cursor_In = a;
					}
				}
				//�ٴ�������¼�
				else 
				if (*EventType == E_E_M_MouseLeftButtomDown)
				{
					Last_LeftButtomDown = a;
				}
				else if (*EventType == E_E_M_MouseWheel)
				{
					if (MouseMS->wheel > 0)
					{
						a->MouseResponseManager(MouseMS, new MouseEventType(E_E_M_MouseWheel_Up));
					}
					else if (MouseMS->wheel < 0)
					{
						a->MouseResponseManager(MouseMS, new MouseEventType(E_E_M_MouseWheel_Down));
					}
				}
				return;
			}
		}
	}
	if ((*LIST)[0]->HighWidget == NULL)
	{
		return;
	}
	//��������ӿؼ����򴥷����ؼ��¼�
	(*LIST)[0]->HighWidget->MouseResponseManager(MouseMS, EventType);
	//�ٴ�������¼�
	if (*EventType == E_E_M_MouseMove)
	{
		if (Last_Cursor_In == NULL) {
			Last_Cursor_In = (*LIST)[0]->HighWidget;
			(*LIST)[0]->HighWidget->MouseResponseManager(MouseMS, new MouseEventType(E_E_M_Cursor_In));
		}
		if ((*LIST)[0]->HighWidget != Last_Cursor_In) {
			(*LIST)[0]->HighWidget->MouseResponseManager(MouseMS, new MouseEventType(E_E_M_Cursor_In));
			Last_Cursor_In->MouseResponseManager(MouseMS, new MouseEventType(E_E_M_Cursor_Leave));
			Last_Cursor_In = (*LIST)[0]->HighWidget;
		}
	}
	//�ٴ�������¼�
	else 
	if (*EventType == E_E_M_MouseLeftButtomDown)
	{
		Last_LeftButtomDown = (*LIST)[0]->HighWidget;
	}
	else if (*EventType == E_E_M_MouseWheel)
	{
		if (MouseMS->wheel > 0)
		{
			(*LIST)[0]->HighWidget->MouseResponseManager(MouseMS, new MouseEventType(E_E_M_MouseWheel_Up));
		}
		else if (MouseMS->wheel < 0)
		{
			(*LIST)[0]->HighWidget->MouseResponseManager(MouseMS, new MouseEventType(E_E_M_MouseWheel_Down));
		}
	}
	return;
}
//�¼�����
void MouseEventDetector::CoordCheck(vector<NodeTree*>* NoodList, MouseEventType* EventType) {
	
	if (*EventType == E_E_M_MouseLeftButtomUp) {
		if (Last_LeftButtomDown != NULL) {
			Last_LeftButtomDown->MouseResponseManager(MouseMS, EventType);
		}
		return;
	}

	//for (vector<NodeTree*>::iterator iter = NoodList->begin(); iter != NoodList->end(); iter++)
	for (auto iter : *NoodList)
	{

		if (ContainCoord(iter->NodeAddress->Area, MouseMS->x, MouseMS->y))
		{

#ifdef __SHOW_CHACKBOX__
			setlinestyle(PS_SOLID, 1);
			setfillstyle(BS_NULL);
			setlinecolor(RED);
			fillrectangle(iter->NodeAddress->Area.x1, iter->NodeAddress->Area.y1, iter->NodeAddress->Area.x2, iter->NodeAddress->Area.y2);
			line(iter->NodeAddress->Area.x1, iter->NodeAddress->Area.y1, iter->NodeAddress->Area.x2, iter->NodeAddress->Area.y2);
			line(iter->NodeAddress->Area.x1, iter->NodeAddress->Area.y2, iter->NodeAddress->Area.x2, iter->NodeAddress->Area.y1);

#endif // DEBUG



			if (iter->SubNodeList.size() == 0)
			{
				//��������Ӷ���͵����Ӷ�����������
				if (iter->NodeAddress->SubWidgetList.size() >0)
				{


					SubWidgetCheck(&(iter->NodeAddress->SubWidgetList), EventType);
					return;
				}
				else if (iter->NodeAddress->FindMouseEventEvent(EventType))
				{

					//��ʾ����
#ifdef __SHOW_CHACKBOX__

					setlinestyle(PS_SOLID, 1);
					setfillstyle(BS_NULL);
					setlinecolor(GREEN);
					fillrectangle(iter->NodeAddress->Area.x1, iter->NodeAddress->Area.y1, iter->NodeAddress->Area.x2, iter->NodeAddress->Area.y2);
					line(iter->NodeAddress->Area.x1, iter->NodeAddress->Area.y1, iter->NodeAddress->Area.x2, iter->NodeAddress->Area.y2);
					line(iter->NodeAddress->Area.x1, iter->NodeAddress->Area.y2, iter->NodeAddress->Area.x2, iter->NodeAddress->Area.y1);

#endif // DEBUG



					iter->NodeAddress->MouseResponseManager(MouseMS,EventType);
					if (*EventType == E_E_M_MouseMove)
					{
						if (Last_Cursor_In == NULL) {
							Last_Cursor_In = iter->NodeAddress; iter->NodeAddress->MouseResponseManager(MouseMS, new MouseEventType(E_E_M_Cursor_In));
						}
						if (iter->NodeAddress != Last_Cursor_In) {
							iter->NodeAddress->MouseResponseManager(MouseMS, new MouseEventType(E_E_M_Cursor_In));
							Last_Cursor_In->MouseResponseManager(MouseMS, new MouseEventType(E_E_M_Cursor_Leave));
							Last_Cursor_In = iter->NodeAddress;
						}
					}
					else if (*EventType == E_E_M_MouseLeftButtomDown) 
					{
						Last_LeftButtomDown = iter->NodeAddress;
					}
					else if (*EventType == E_E_M_MouseWheel)
					{
						if (MouseMS->wheel>0)
						{
							iter->NodeAddress->MouseResponseManager(MouseMS, new MouseEventType(E_E_M_MouseWheel_Up));
						}
						else if (MouseMS->wheel < 0)
						{
							iter->NodeAddress->MouseResponseManager(MouseMS, new MouseEventType(E_E_M_MouseWheel_Down));
						}
					}


					return;
				}
			}
			else
			{
				CoordCheck(&(iter->SubNodeList), EventType);
				return;
			}
		}
	}
	//�ӽڵ���δ����ƥ��ڵ�
	//�ص���һ��ڵ�洢�Ŀؼ����¼�
	if ((*NoodList)[0]->HigherLevel ==NULL)
	{
		return;
	}
	(*NoodList)[0]->HigherLevel->NodeAddress->MouseResponseManager(MouseMS, EventType);
	if (*EventType == E_E_M_MouseMove)
	{
		if (Last_Cursor_In == NULL) {
			Last_Cursor_In = (*NoodList)[0]->HigherLevel->NodeAddress;
			Last_Cursor_In->MouseResponseManager(MouseMS, new MouseEventType(E_E_M_Cursor_In));
		}
		else if ((*NoodList)[0]->HigherLevel->NodeAddress != Last_Cursor_In) {
			(*NoodList)[0]->HigherLevel->NodeAddress->MouseResponseManager(MouseMS, new MouseEventType(E_E_M_Cursor_In));
			Last_Cursor_In->MouseResponseManager(MouseMS, new MouseEventType(E_E_M_Cursor_Leave));
			Last_Cursor_In = (*NoodList)[0]->HigherLevel->NodeAddress;
		}
	}
	else if (*EventType == E_E_M_MouseLeftButtomDown) {
		Last_LeftButtomDown = (*NoodList)[0]->HigherLevel->NodeAddress;
	}
	else if (*EventType == E_E_M_MouseWheel)
	{
		if (MouseMS->wheel > 0)
		{
			(*NoodList)[0]->HigherLevel->NodeAddress->MouseResponseManager(MouseMS, new MouseEventType(E_E_M_MouseWheel_Up));
		}
		else if (MouseMS->wheel < 0)
		{
			(*NoodList)[0]->HigherLevel->NodeAddress->MouseResponseManager(MouseMS, new MouseEventType(E_E_M_MouseWheel_Down));
		}
	}


	return;
}

//����¼����
void MouseEventDetector::EventCheck(vector<NodeTree*>* NoodList)
{
	*MouseMS = GetMouseMsg();
	switch (MouseMS->uMsg)
	{
		//����ƶ�
	case WM_MOUSEMOVE:

#ifdef DEBUG_MOUSE_EEVENT
		cout << "[����¼�] : ����ƶ�" << endl;
#endif 
		*MouseEvent = E_E_M_MouseMove;
		CoordCheck(NoodList, MouseEvent);
		break;

		//�������
	case WM_LBUTTONDOWN:
		//ִ���¼��ص�����
#ifdef DEBUG_MOUSE_EEVENT
		cout << "[����¼�] : �������" << endl;
#endif
		*MouseEvent = E_E_M_MouseLeftButtomDown;
		CoordCheck(NoodList, MouseEvent);
		break;

		//�Ҽ�����
	case WM_RBUTTONDOWN:
		//ִ���¼��ص�����
#ifdef DEBUG_MOUSE_EEVENT
		cout << "[����¼�] : �Ҽ�����" << endl;
#endif
		*MouseEvent = E_E_M_MouseRightButtomDown;
		CoordCheck(NoodList, MouseEvent);
		break;

		//�м�����
	case WM_MBUTTONDOWN:
#ifdef DEBUG_MOUSE_EEVENT
		cout << "[����¼�] : �м�����" << endl;
#endif
		*MouseEvent = E_E_M_MouseMiddleButtomDown;
		CoordCheck(NoodList, MouseEvent);
		break;

		//���̧��
	case WM_LBUTTONUP:
		//ִ���¼��ص�����
#ifdef DEBUG_MOUSE_EEVENT
		cout << "[����¼�] : ���̧��" << endl;
#endif
		*MouseEvent = E_E_M_MouseLeftButtomUp;
		CoordCheck(NoodList, MouseEvent);
		break;

		//�Ҽ�̧��
	case WM_RBUTTONUP:
#ifdef DEBUG_MOUSE_EEVENT
		cout << "[����¼�] : �Ҽ�̧��" << endl;
#endif
		*MouseEvent = E_E_M_MouseRightButtomUp;
		CoordCheck(NoodList, MouseEvent);
		break;

		//�м�̧��
	case WM_MBUTTONUP:
#ifdef DEBUG_MOUSE_EEVENT
		cout << "[����¼�] : �м�̧��" << endl;
#endif
		*MouseEvent = E_E_M_MouseMiddleButtomUp;
		CoordCheck(NoodList, MouseEvent);
		break;

		//��ת����
	case WM_MOUSEWHEEL:
#ifdef DEBUG_MOUSE_EEVENT
		cout << "[����¼�] : ��ת����" << endl;
#endif
		*MouseEvent = E_E_M_MouseWheel;
		CoordCheck(NoodList, MouseEvent);
		break;

		//���˫��
	case WM_LBUTTONDBLCLK:
#ifdef DEBUG_MOUSE_EEVENT
		cout << "[����¼�] : ���˫��" << endl;
#endif
		*MouseEvent = E_E_M_MouseLeftButtomCLK;
		CoordCheck(NoodList, MouseEvent);
		break;

		//�Ҽ�˫��
	case WM_RBUTTONDBLCLK:
#ifdef DEBUG_MOUSE_EEVENT
		cout << "[����¼�] : �Ҽ�˫��" << endl;
#endif
		*MouseEvent = E_E_M_MouseRightButtomCLK;
		CoordCheck(NoodList, MouseEvent);
		break;

		//�м�˫��
	case WM_MBUTTONDBLCLK:
#ifdef DEBUG_MOUSE_EEVENT 
		cout << "[����¼�] : �м�˫��" << endl;
#endif
		*MouseEvent = E_E_M_MouseMiddleButtomCLK;
		CoordCheck(NoodList, MouseEvent);
		break;

	default:
		*MouseEvent = E_E_M_INVALID;
		CoordCheck(NoodList, MouseEvent);
		break;
	}
}


/////////////////////////////////////�����豸��������/////////////////////////////////////
class KeyboardEventDetector {
public:
	char Key;
	KeyboardEventType* EventType;
	//GUI_Rectangle* tmp;
	virtual void EventCheck(vector<NodeTree*>* NodeTreeList);
	void DisposeEvent(vector<NodeTree*>* NodeTreeList, KeyboardEventType* EventType);

	KeyboardEventDetector() {
		Key = 0;
		EventType = new KeyboardEventType;
		*EventType = E_E_K_INVALID;
		//tmp = new GUI_Rectangle();
	}
	~KeyboardEventDetector() {
		delete EventType;
	}
};

//�����¼�����
void KeyboardEventDetector::DisposeEvent(vector<NodeTree*>* NodeTreeList, KeyboardEventType* EventType) {
	for (vector<NodeTree*>::iterator iter = NodeTreeList->begin(); iter != NodeTreeList->end(); iter++)
	{
		if((*iter)->NodeAddress->FindKeyBoardEvent(EventType)) {
			(*iter)->NodeAddress->KeyboardResponseManager(Key, EventType);
			if ((*iter)->SubNodeList.size()==0)
			{
				return;
			}
			else
			{
				DisposeEvent(&((*iter)->SubNodeList), EventType);
			}
		}
	}
	return;
}

//�����¼���⺯��
void KeyboardEventDetector::EventCheck(vector<NodeTree*>* NodeTreeList) {
	//ʹ��_getKey()������ȡ���µļ�ֵ
	Key = _getch();
	//char Buffer[100];

	//W;
	if (Key == 'W' || Key == 'w') {
#ifdef DEBUG_KEYBORD_EEVENT 
		cout << "[�����¼�] : ESC" << endl;
#endif
		*EventType = E_E_K_W;
		DisposeEvent(NodeTreeList, EventType);
	}
	//S;
	if (Key == 'S'|| Key == 's') {
#ifdef DEBUG_KEYBORD_EEVENT 
		cout << "[�����¼�] : ESC" << endl;
#endif
		*EventType = E_E_K_S;
		DisposeEvent(NodeTreeList, EventType);
	}
	//A;
	if (Key == 'A'|| Key == 'a') {
#ifdef DEBUG_KEYBORD_EEVENT 
		cout << "[�����¼�] : ESC" << endl;
#endif
		*EventType = E_E_K_A;
		DisposeEvent(NodeTreeList, EventType);
	}
	//D;
	if (Key == 'D'||Key == 'd') {
#ifdef DEBUG_KEYBORD_EEVENT 
		cout << "[�����¼�] : ESC" << endl;
#endif
		*EventType = E_E_K_D;
		DisposeEvent(NodeTreeList, EventType);
	}
	//F;
	if (Key == 'F' || Key == 'f') {
#ifdef DEBUG_KEYBORD_EEVENT 
		cout << "[�����¼�] : ESC" << endl;
#endif
		*EventType = E_E_K_F;
		DisposeEvent(NodeTreeList, EventType);
	}
	//ESC;27
	if (Key == 27) {
#ifdef DEBUG_KEYBORD_EEVENT 
		cout << "[�����¼�] : ESC" << endl;
#endif
		*EventType = E_E_K_ESC;
		DisposeEvent(NodeTreeList,EventType);
	}

	//LEFT_CTRL-
	if (GetAsyncKeyState(VK_LCONTROL)) {
#ifdef DEBUG_KEYBORD_EEVENT 
		cout << "[�����¼�] : LEFT_CTRL" << endl;
#endif
		*EventType = E_E_K_LEFT_CTRL;
		DisposeEvent(NodeTreeList, EventType);
	}

	//RIGHT_CTRL
	if (GetAsyncKeyState(VK_RCONTROL)) {
#ifdef DEBUG_KEYBORD_EEVENT 
		cout << "[�����¼�] : RIGHT_CTRL" << endl;
#endif
		*EventType = E_E_K_RIGHT_CTRL;
		DisposeEvent(NodeTreeList, EventType);
	}

	//LEFT SHIFT
	if (GetAsyncKeyState(VK_LSHIFT)) {
#ifdef DEBUG_KEYBORD_EEVENT 
		cout << "[�����¼�] : LEFT_SHIFT" << endl;
#endif
		*EventType = E_E_K_LEFT_SHIFT;
		DisposeEvent(NodeTreeList, EventType);
	}

	//RIGHT SHIFT
	if (GetAsyncKeyState(VK_RSHIFT)) {
#ifdef DEBUG_KEYBORD_EEVENT 
		cout << "[�����¼�] : RIGHT_SHIFT" << endl;
#endif
		*EventType = E_E_K_RIGHT_SHIFT;
		DisposeEvent(NodeTreeList, EventType);
	}

	//LEFT MENUE
	if (GetAsyncKeyState(VK_LMENU)) {
#ifdef DEBUG_KEYBORD_EEVENT 
		cout << "[�����¼�] : LEFT_ALT" << endl;
#endif
		*EventType = E_E_K_LEFT_ALT;
		DisposeEvent(NodeTreeList, EventType);
	}

	//RIGHT MENU
	if (GetAsyncKeyState(VK_RMENU)) {
#ifdef DEBUG_KEYBORD_EEVENT 
		cout << "[�����¼�] : RIGHT_ALT" << endl;
#endif
		*EventType = E_E_K_RIGHT_ALT;
		DisposeEvent(NodeTreeList, EventType);
	}

	//SPACE
	if (Key == 32) {
#ifdef DEBUG_KEYBORD_EEVENT 
		cout << "[�����¼�] : SPACE" << endl;
#endif
		*EventType = E_E_K_SPACE;
		DisposeEvent(NodeTreeList, EventType);
	}

	//ENTER
	if (Key == 13) {
#ifdef DEBUG_KEYBORD_EEVENT 
		cout << "[�����¼�] : ENTER" << endl;
#endif
		*EventType = E_E_K_ENTER;
		DisposeEvent(NodeTreeList, EventType);
	}

	//TAB
	if (Key == 9) {
#ifdef DEBUG_KEYBORD_EEVENT 
		cout << "[�����¼�] : TAB" << endl;
#endif
		*EventType = E_E_K_TAB;
		DisposeEvent(NodeTreeList, EventType);
	}

	//DELETE
	if (Key == 127) {
#ifdef DEBUG_KEYBORD_EEVENT 
		cout << "[�����¼�] : DELETE" << endl;
#endif
		*EventType = E_E_K_DELETE;
		DisposeEvent(NodeTreeList, EventType);
	}

	//BackSpace
	if (Key == 8) {
#ifdef DEBUG_KEYBORD_EEVENT 
		cout << "[�����¼�] : <BackSpace" << endl;
#endif
		*EventType = E_E_K_BACKSPACE;
		DisposeEvent(NodeTreeList, EventType);
	}

	//UP-38
	if (Key == 22472) {
#ifdef DEBUG_KEYBORD_EEVENT 
		cout << "[�����¼�] : UP" << endl;
#endif
		*EventType = E_E_K_UP;
		DisposeEvent(NodeTreeList, EventType);
	}

	//DOWN-40
	if (Key == 22480) {
#ifdef DEBUG_KEYBORD_EEVENT 
		cout << "[�����¼�] : DOWN" << endl;
#endif
		*EventType = E_E_K_DOWN;
		DisposeEvent(NodeTreeList, EventType);
	}

	//LEFT-37
	if (Key == 22475) {
#ifdef DEBUG_KEYBORD_EEVENT 
		cout << "[�����¼�] : LEFT" << endl;
#endif
		*EventType = E_E_K_LEFT;
		DisposeEvent(NodeTreeList, EventType);
	}

	//RIGHT-39
	if (Key == 22477) {
#ifdef DEBUG_KEYBORD_EEVENT 
		cout << "[�����¼�] : RIGHT" << endl;
#endif
		*EventType = E_E_K_RIGHT;
		DisposeEvent(NodeTreeList, EventType);
	}


	return;
}





/////////////////////////////////////Ӳ�������¼������///////////////////////////////////
class HardwareInputEventDetector{
public:
	MouseEventDetector* MouseED;
	KeyboardEventDetector* KeyboardED;
	//��Ӧ�ؼ���
	vector<NodeTree*>* NodeTreeList;
	bool OpenDetector;

	void AddTree(NodeTree*);
	void EventCheck();

	HardwareInputEventDetector(NodeTree* ROOT) {
		OpenDetector = TRUE;
		//NodeTreeList = &(ROOT->SubNodeList);
		NodeTreeList = new vector<NodeTree*>;
		NodeTreeList->push_back(ROOT);
		MouseED = new MouseEventDetector();
		KeyboardED = new KeyboardEventDetector();
	}
	~HardwareInputEventDetector() {
		delete MouseED, KeyboardED;
	}
};

//
void HardwareInputEventDetector::EventCheck() {
	while (OpenDetector)
	{
		if (_kbhit()) {
			KeyboardED->EventCheck(NodeTreeList);
		}
		//keybd_event
		if (MouseHit()) {
			MouseED->EventCheck(NodeTreeList);
		}
	}
}

//
void HardwareInputEventDetector::AddTree(NodeTree* Tree) {
	NodeTreeList->push_back(Tree);
}

