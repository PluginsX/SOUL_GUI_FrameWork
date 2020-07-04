#pragma once
//#include<graphics.h>
#include"graphics.h"
#include<iostream>
#include<fstream>
#include<windows.h>
#include<vector>
#include <algorithm>
#include<string>
#include<sstream>
#include<cmath>
#include<queue>
#include<conio.h>
#include<cstdlib>
#include<map>
//#include"BaseEnum.h"

using namespace std;

#pragma comment(lib,"EasyXa.lib")
#pragma comment(lib,"EasyXw.lib")
//��������¼�����ö��
enum MouseEventType
{
	E_E_M_Cursor_In,
	E_E_M_Cursor_Leave,
	E_E_M_MouseWheel,
	E_E_M_MouseWheel_Up,
	E_E_M_MouseWheel_Down,
	E_E_M_MouseMove,
	E_E_M_MouseLeftButtomDown,
	E_E_M_MouseLeftButtomUp,
	E_E_M_MouseLeftButtomCLK,
	E_E_M_MouseRightButtomDown,
	E_E_M_MouseRightButtomUp,
	E_E_M_MouseRightButtomCLK,
	E_E_M_MouseMiddleButtomDown,
	E_E_M_MouseMiddleButtomUp,
	E_E_M_MouseMiddleButtomCLK,

	E_E_M_INVALID
};

//���������¼�����ö��
enum KeyboardEventType {
	E_E_K_W,
	E_E_K_S,
	E_E_K_A,
	E_E_K_D,
	E_E_K_F,
	E_E_K_ESC,
	E_E_K_LEFT_CTRL,
	E_E_K_RIGHT_CTRL,
	E_E_K_SPACE,
	E_E_K_ENTER,
	E_E_K_LEFT_SHIFT,
	E_E_K_RIGHT_SHIFT,
	E_E_K_LEFT_ALT,
	E_E_K_RIGHT_ALT,
	E_E_K_TAB,
	E_E_K_DELETE,
	E_E_K_BACKSPACE,
	E_E_K_UP,
	E_E_K_DOWN,
	E_E_K_LEFT,
	E_E_K_RIGHT,

	E_E_K_INVALID
};



//SCRIPT_JML -> Docinformation -> Property
enum _DOCINFO_Type {
	E_File,
	E_CharSet,
	E_NumberOfNodes,
	E_NumberOfChar,
	E_NumberOfLine,
	E_Size_B
};


//���ڵ���Ļ�����������
enum NodePropertyType
{
E_NodeProperty_name,//���ֽڵ�����
E_NodeProperty_ratio_origin,//ʵ��ԭ�����꣬���Ͻ�
E_NodeProperty_ratio_border,//ʵ�ʱ߽����꣬���½�
E_NodeProperty_origin,//ʵ��ԭ�����꣬���Ͻ�
E_NodeProperty_border,//ʵ�ʱ߽����꣬���½�
E_NodeProperty_Wid_Hei,//ʵ�����ؿ�
E_NodeProperty_layerXY,//ʵ�����ظ�
};

//GUI�ؼ�����ö��
enum NodeType
{
	E_Rectangle,
	E_Roundrect,
	E_BitMap,
	E_Text,
	E_Sound,
	E_Buttom,
	E_SelectButtom,
	E_Slider,
	E_MoveButton
};

//ͼ�ν��游�࣬��������ö�ٱ�GUI_PublicPropertyType
enum GUI_PublicPropertyType 
{
E_GUI_P_Name,//�ڵ���
E_GUI_P_Origin,//�������
E_GUI_P_Border,//�����յ�
E_GUI_P_DrawOrigin,//�������
E_GUI_P_DrawBorder,//�����յ�
E_GUI_P_Wid_Hei,//�ڵ��x��y����
E_GUI_P_ShowFill,//��ʾ���
E_GUI_P_FillColor,//�����ɫ
E_GUI_P_ShowBorder,//��ʾ���
E_GUI_P_BorderColor,//�����ɫ
};


//GUI_RectanglePropertyType
enum GUI_RectanglePropertyType
{
	//Rectangle��Ϊ����
};

//GUI_RoundrectPropertyType
enum GUI_RoundrectPropertyType
{
	E_GUI_Roundrect_CutX,
	E_GUI_Roundrect_CutY
};

//GUI_GUI_BitMapPropertyType
enum GUI_BitMapPropertyType
{
	E_GUI_BitMap_BitMapAddress
};

//GUI_GUI_TextPropertyType
enum GUI_TextPropertyType
{
	E_GUI_Text_Text,
	E_GUI_Text_TextStyle,
	E_GUI_Text_TextColor,
	E_GUI_Text_OutArea,
	E_GUI_Text_TextHeight,
	E_GUI_Text_HeightBacke,
	E_GUI_Text_Transparent
};

//GUI_SoundPropertyType
enum GUI_SoundPropertyType 
{
	E_SoundAddress,
	E_AutoPlay
};


//��ť��ʽ_ö��
enum ButtomStyleType {
	Solid_Buttom,
	Image_Buttom
};
//GUI_SelectButtomPropertyType
enum GUI_SelectButtomPropertyType 
{
	E_S_SwitchState,//����״̬
	E_S_ButtomStyle,//��ť��ʽ
	E_S_ButtomName,//��ť��
	E_S_ButtomExplain,//������Ϣ

	//ͼ����ʽ
	E_S_ICO_Static_ON,//��ֹ�ر�
	E_S_ICO_Static_OFF,//��ֹ����
	E_S_ICO_In_ON,//����״̬������
	E_S_ICO_In_OFF,//�ر�״̬������

	//��ɫ��ʽ
	E_S_RGB_Static_ON,
	E_S_RGB_Static_OFF,
	E_S_RGB_In_ON,
	E_S_RGB_In_OFF
};

//GUI_ButtomPropertyType
enum GUI_ButtomPropertyType
{
	E_SwitchState,//����״̬
	E_ButtomStyle,//��ť��ʽ
	E_ButtomName,//��ť��
	E_ButtomExplain,//������Ϣ

	//ͼ����ʽ
	E_ICO_Up,//��ֹ�ر�
	E_ICO_In,//����״̬������
	E_ICO_Down,//�ر�״̬������

	//��ɫ��ʽ
	E_RGB_Up,
	E_RGB_Down,
	E_RGB_In,
};

//GUI_SliderPropertyType
enum GUI_SliderPropertyType {
	E_Mode,//���򣬺���/����,Ĭ��Ϊ 0/�� - ���򻬸�,1Ϊ��������Ϊ�Զ�������խȷ��

	E_PathWay,//���
	E_Max_Min,//�����ʼֵ/�����Сֵ��ģ��ֵ
	E_PathWayValueRange,//������̣�ģ��ֵ����� - ��С
	E_ShowHatched,//�Ƿ���ͼ�������

	E_Rocker,//ҡ��
	E_LocalValueCapacity,//�ֲ���չʾ�ĳ���
	E_RockerScale,//�ֲ�ռȫ���ı�������ť�ĳ����ɣ�����ʾ����δ��ʾ������������ģ��ֵ
	E_Rocker_Value,//ҡ������ֵ��ģ��ֵ

	E_Buttom_Forward,//��ǰ��ť
	E_Buttom_backward//���ť

};