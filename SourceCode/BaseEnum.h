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
//鼠标输入事件类型枚举
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

//键盘输入事件类型枚举
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


//树节点类的基本属性类型
enum NodePropertyType
{
E_NodeProperty_name,//布局节点名称
E_NodeProperty_ratio_origin,//实际原点坐标，左上角
E_NodeProperty_ratio_border,//实际边界坐标，右下角
E_NodeProperty_origin,//实际原点坐标，左上角
E_NodeProperty_border,//实际边界坐标，右下角
E_NodeProperty_Wid_Hei,//实际像素宽
E_NodeProperty_layerXY,//实际像素高
};

//GUI控件类型枚举
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

//图形界面父类，公共属性枚举表，GUI_PublicPropertyType
enum GUI_PublicPropertyType 
{
E_GUI_P_Name,//节点名
E_GUI_P_Origin,//布局起点
E_GUI_P_Border,//布局终点
E_GUI_P_DrawOrigin,//绘制起点
E_GUI_P_DrawBorder,//绘制终点
E_GUI_P_Wid_Hei,//节点宽x高y像素
E_GUI_P_ShowFill,//显示填充
E_GUI_P_FillColor,//填充颜色
E_GUI_P_ShowBorder,//显示描边
E_GUI_P_BorderColor,//描边颜色
};


//GUI_RectanglePropertyType
enum GUI_RectanglePropertyType
{
	//Rectangle即为父类
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


//按钮样式_枚举
enum ButtomStyleType {
	Solid_Buttom,
	Image_Buttom
};
//GUI_SelectButtomPropertyType
enum GUI_SelectButtomPropertyType 
{
	E_S_SwitchState,//开关状态
	E_S_ButtomStyle,//按钮样式
	E_S_ButtomName,//按钮名
	E_S_ButtomExplain,//解释信息

	//图标样式
	E_S_ICO_Static_ON,//静止关闭
	E_S_ICO_Static_OFF,//静止开启
	E_S_ICO_In_ON,//开启状态光标进入
	E_S_ICO_In_OFF,//关闭状态光标进入

	//纯色样式
	E_S_RGB_Static_ON,
	E_S_RGB_Static_OFF,
	E_S_RGB_In_ON,
	E_S_RGB_In_OFF
};

//GUI_ButtomPropertyType
enum GUI_ButtomPropertyType
{
	E_SwitchState,//开关状态
	E_ButtomStyle,//按钮样式
	E_ButtomName,//按钮名
	E_ButtomExplain,//解释信息

	//图标样式
	E_ICO_Up,//静止关闭
	E_ICO_In,//开启状态光标进入
	E_ICO_Down,//关闭状态光标进入

	//纯色样式
	E_RGB_Up,
	E_RGB_Down,
	E_RGB_In,
};

//GUI_SliderPropertyType
enum GUI_SliderPropertyType {
	E_Mode,//方向，横向/纵向,默认为 0/假 - 横向滑杆,1为纵向，其他为自动分析宽窄确定

	E_PathWay,//轨道
	E_Max_Min,//轨道起始值/最大最小值，模拟值
	E_PathWayValueRange,//轨道航程，模拟值，最大 - 最小
	E_ShowHatched,//是否以图案填充轨道

	E_Rocker,//摇杆
	E_LocalValueCapacity,//局部可展示的长度
	E_RockerScale,//局部占全部的比例，按钮的长度由，可显示量与未显示量比例决定，模拟值
	E_Rocker_Value,//摇杆所在值，模拟值

	E_Buttom_Forward,//向前按钮
	E_Buttom_backward//向后按钮

};