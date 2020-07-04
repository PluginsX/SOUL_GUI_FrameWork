#pragma once
#include"BaseDataStruct.h"

using namespace std;


//数值过滤器
float Valuefilter(float MAX, float MIN, float c) {
	if (c > MAX) {
		return MAX;
	}
	else if (c < MIN) {
		 return MIN;
	}
	else {
		return c;
	}
}

//从字符串去除字符 '符'
string* RemoveChar(string *ccc, char c, bool All = 1) {
	if (ccc->size() == 0) { return ccc; }
	string* NodeNameCopy = new string;
	if (All) {
		for (string::iterator iter = ccc->begin(); iter != ccc->end(); iter++) {
			if (*iter != c) {
				NodeNameCopy->push_back(*iter);
			}
		}
	}
	else {
		int StrSize = ccc->size() - 1;
		int i = 0;
		for (; (*ccc)[i] == c; i++) {
		}
		for (; (*ccc)[StrSize] == c; StrSize--) {
		}
		for (; i <= StrSize; i++) {
			NodeNameCopy->push_back((*ccc)[i]);
		}
	}
	return NodeNameCopy;
}


//char* 转 int
float str_to_int(string* str) {
	char* star = &(*str)[0];
	stringstream ss;
	float number;
	ss << star;
	ss>>number;
	//RemoveChar(&str,' ');
	//int Value = 0;
	//int size = str->size();
	//for (int i = 1; i < size; i++) {
	//	Value += (int)((*str)[i]) * pow(10, (size - 1) - i);
	//}
	cout << number << endl;
	return number;
}


//可用关键字符检测
char KeyCharCheck(char C) {
	if (C > 47 && C < 58) {
		return 'c';
	}
	else if (C > 64 && C < 91) {
		return 'c';
	}
	else if (C > 96 && C < 123) {
		return 'c';
	}
	else if (0 <= C && C < 33) {
		return 'v';
	}
	else {
		return  'n';
	}
}





//包含坐标检测
bool ContainCoord(Vector4D Area, int CoordX, int CoordY) {
	if (Area.x1 < CoordX && CoordX < Area.x2 &&Area.y1 < CoordY && CoordY < Area.y2) {
		return TRUE;
	}
	else { return FALSE; }
}




//字符串对应枚举_节点类型
NodeType StringToNodeType(string* NodeTypeName) {
	//标签名/节点名 内不应有空字符
	NodeTypeName = RemoveChar(RemoveChar(NodeTypeName, ' '), '\"');

	if (*NodeTypeName == "Rectangle") { return E_Rectangle; }
	else if (*NodeTypeName == "Roundrect") { return E_Roundrect; }
	else if (*NodeTypeName == "BitMap") { return E_BitMap; }
	else if (*NodeTypeName == "Text") { return E_Text; }
	else if (*NodeTypeName == "Sound") { return E_Sound; }
	else if (*NodeTypeName == "Buttom") { return E_Buttom; }
	else if (*NodeTypeName == "SelectButtom") { return E_SelectButtom; }
	else if (*NodeTypeName == "Slider") { return E_Slider; }
	else {return E_Rectangle;}//默认为Rectangle节点
}

////字符串对应枚举_控件类型
//WidgetType StringToWidgetType(string* WidgetTypeName) {
//	//标签名/节点名 内不应有空字符
//	WidgetTypeName = RemoveChar(RemoveChar(WidgetTypeName, ' '), '\"');
//	if (*WidgetTypeName == "Layout") { return E_Widget_Base; }
//	else if (*WidgetTypeName == "WText") { return E_WText; }
//	else if (*WidgetTypeName == "ListXY") { return E_ListXY; }
//	else if (*WidgetTypeName == "Image") { return E_Image; }
//	else if (*WidgetTypeName == "Buttom2S") { return E_Buttom2S; }
//}

//字符串对应枚举_文档信息类型
_DOCINFO_Type StringTo_DOCINFO_Type(string* PropertyName) {
	PropertyName = RemoveChar(RemoveChar(PropertyName, ' '), '\"');
	if (*PropertyName == "File"){return E_File;}
	else if (*PropertyName == "File") { return E_File; }
	else if (*PropertyName == "CharSet") { return E_CharSet; }
	else if (*PropertyName == "NumberOfNodes") { return E_NumberOfNodes; }
	else if (*PropertyName == "NumberOfChar") { return E_NumberOfChar; }
	else if (*PropertyName == "NumberOfLine") { return E_NumberOfLine; }
	else if (*PropertyName == "Size_B") { return E_Size_B; }
	
}
//字符串对应枚举_布局属性类型
NodePropertyType StringToNodePropertyType(string* PropertyName,bool* Find) {
	//标签名/节点名 内不应有空字符
	PropertyName = RemoveChar(RemoveChar(PropertyName, ' '), '\"');
	if (*PropertyName == "name"){return E_NodeProperty_name;}

	else if (*PropertyName == "ratio_origin") { return E_NodeProperty_ratio_origin; }
	else if (*PropertyName == "ratio_border") { return E_NodeProperty_ratio_border; }

	else if (*PropertyName == "origin") { return E_NodeProperty_origin; }
	else if (*PropertyName == "border") { return E_NodeProperty_border; }

	else if (*PropertyName == "Wid_Hei") { return E_NodeProperty_Wid_Hei; }

	else if (*PropertyName == "layerXY") { return E_NodeProperty_layerXY; }

	else {*Find = FALSE;return E_NodeProperty_name;}
}

//字符串转_图形界面父类公共参数
GUI_PublicPropertyType StringToGUI_PublicPropertyType(string* PropertyName,bool* IsParantProperty) {
	PropertyName = RemoveChar(RemoveChar(PropertyName, ' '), '\"');
	if (*PropertyName =="Name" ){return E_GUI_P_Name;}

	else if (*PropertyName == "Origin"){return E_GUI_P_Origin;}//起点
	else if (*PropertyName == "Border"){return E_GUI_P_Border;}//终点

	else if (*PropertyName == "DrawOrigin") { return E_GUI_P_DrawOrigin; }//绘制起点
	else if (*PropertyName == "DrawBorder") { return E_GUI_P_DrawBorder; }//绘制终点

	else if (*PropertyName == "Hei_Wid"){return E_GUI_P_Wid_Hei;}//宽高

	else if (*PropertyName == "ShowFill"){return E_GUI_P_ShowFill;}//是否填充
	else if (*PropertyName == "FillColor"){ return E_GUI_P_FillColor;}//填充颜色RGB

	else if (*PropertyName == "ShowBorder"){ return E_GUI_P_ShowBorder;}//是否描边
	else if (*PropertyName == "BorderColor"){ return E_GUI_P_BorderColor;}//描边颜色RGB

	else { *IsParantProperty = FALSE; return E_GUI_P_Name;}//无效返回名称
}

//GUI_RectanglePropertyType StringToGUI_RectanglePropertyType(string* PropertyName) {
//
//}

GUI_RoundrectPropertyType StringTo_GUI_RoundrectPropertyType(string* PropertyName) {
	PropertyName = RemoveChar(RemoveChar(PropertyName, ' '), '\"');
	if (*PropertyName == "CutX"){return E_GUI_Roundrect_CutX;	}
	else if (*PropertyName == "CutY"){return E_GUI_Roundrect_CutY;	}
}

GUI_BitMapPropertyType StringTo_GUI_BitMapPropertyType(string* PropertyName) {
	PropertyName = RemoveChar(RemoveChar(PropertyName,' '),'\"');
	if (*PropertyName == "BitMapAddress")	{return E_GUI_BitMap_BitMapAddress;}
}

GUI_TextPropertyType StringTo_GUI_TextPropertyType(string* PropertyName) {
	PropertyName = RemoveChar(RemoveChar(PropertyName, ' '), '\"');
	if (*PropertyName == "Text") { return E_GUI_Text_Text; }
	if (*PropertyName == "TextStyle") { return E_GUI_Text_TextStyle; }
	if (*PropertyName == "TextColor") { return E_GUI_Text_TextColor; }
	if (*PropertyName == "OutArea") { return E_GUI_Text_OutArea; }
	if (*PropertyName == "TextHeight") { return E_GUI_Text_TextHeight; }
	if (*PropertyName == "HeightBacke") { return E_GUI_Text_HeightBacke; }
	if (*PropertyName == "Transparent") { return E_GUI_Text_Transparent; }
}

GUI_SoundPropertyType StringTo_GUI_SoundPropertyType(string* PropertyName) {
	PropertyName = RemoveChar(RemoveChar(PropertyName, ' '), '\"');
	if (*PropertyName == "SoundAddress") { return E_SoundAddress; }
	if (*PropertyName == "AutoPlay") { return E_AutoPlay; }
}

GUI_SelectButtomPropertyType StringTo_GUI_SelectButtomPropertyType(string* PropertyName) {
	PropertyName = RemoveChar(RemoveChar(PropertyName, ' '), '\"');
	if (*PropertyName == "SwitchState") { return E_S_SwitchState; }
	if (*PropertyName == "ButtomStyle") { return E_S_ButtomStyle; }
	if (*PropertyName == "ButtomName") { return E_S_ButtomName; }
	if (*PropertyName == "ButtomExplain") { return E_S_ButtomExplain; }
	if (*PropertyName == "ICO_Static_ON") { return E_S_ICO_Static_ON; }
	if (*PropertyName == "ICO_Static_OFF") { return E_S_ICO_Static_OFF; }
	if (*PropertyName == "ICO_In_ON") { return E_S_ICO_In_ON; }
	if (*PropertyName == "ICO_In_OFF") { return E_S_ICO_In_OFF; }
	if (*PropertyName == "RGB_Static_ON") { return E_S_RGB_Static_ON; }
	if (*PropertyName == "RGB_Static_OFF") { return E_S_RGB_Static_OFF; }
	if (*PropertyName == "RGB_In_ON") { return E_S_RGB_In_ON; }
	if (*PropertyName == "RGB_In_OFF") { return E_S_RGB_In_OFF; }

}
ButtomStyleType StringTo_GUI_ButtomStyleType(string* PropertyName) {
	PropertyName = RemoveChar(RemoveChar(PropertyName, ' '), '\"');
	if (*PropertyName == "Solid") { return Solid_Buttom; }
	if (*PropertyName == "Image") { return Image_Buttom; }
}

GUI_ButtomPropertyType StringTo_GUI_ButtomPropertyType(string* PropertyName) {
	PropertyName = RemoveChar(RemoveChar(PropertyName, ' '), '\"');
	if (*PropertyName == "SwitchState") { return E_SwitchState; }
	if (*PropertyName == "ButtomStyle") { return E_ButtomStyle; }
	if (*PropertyName == "ButtomName") { return E_ButtomName; }
	if (*PropertyName == "ButtomExplain") { return E_ButtomExplain; }
	if (*PropertyName == "ICO_Up") { return E_ICO_Up; }
	if (*PropertyName == "ICO_In") { return E_ICO_In; }
	if (*PropertyName == "ICO_Down") { return E_ICO_Down; }
	if (*PropertyName == "RGB_Up") { return E_RGB_Up; }
	if (*PropertyName == "RGB_Down") { return E_RGB_Down; }
	if (*PropertyName == "RGB_In") { return E_RGB_In; }

}

GUI_SliderPropertyType StringTo_GUI_SliderPropertyType(string* PropertyName) {
	PropertyName = RemoveChar(RemoveChar(PropertyName, ' '), '\"');
	if (*PropertyName == "Mode") { return E_Mode; }
	if (*PropertyName == "PathWay") { return E_PathWay; }
	if (*PropertyName == "MaxMin") { return E_Max_Min; }
	//if (*PropertyName == "PathWayValueRange") { return E_PathWayValueRange; }
	if (*PropertyName == "ShowHatched") { return E_ShowHatched; }
	if (*PropertyName == "Rocker") { return E_Rocker; }
	if (*PropertyName == "LocalValueCapacity") { return E_LocalValueCapacity; }
	//if (*PropertyName == "RockerScale") { return E_RockerScale; }
	if (*PropertyName == "RockerValue") { return E_Rocker_Value; }
	if (*PropertyName == "ButtomForward") { return E_Buttom_Forward; }
	if (*PropertyName == "Buttombackward") { return E_Buttom_backward; }
}

//节点类型转字符串
const char* NodeTypeToString(NodeType TYPE) {
	string Buffer;
	switch (TYPE)
	{
	case E_Rectangle:
		return "Rectangle";
	case E_Roundrect:
		return "Roundrect";
	case E_BitMap:
		return "BitMap";
	case E_Text:
		return "Text";
	case E_Sound:
		return "Sound";
	case E_Buttom:
		return "Buttom";
	case E_SelectButtom:
		return "SelectButtom";
	default:
		break;
	}
}
//OLD
//枚举转字符串
//const char* EnumToString(WidgetType TYPE) {
//	switch (TYPE)
//	{
//	case E_Widget_Base:
//		return "Widget_Base";
//		break;
//	case E_Text:
//		return "Text";
//		break;
//	case E_ListXY:
//		return "ListXY";
//		break;
//	case E_Image:
//		return "Image";
//		break;
//	case E_Buttom2S:
//		return "Buttom2S";
//		break;
//	default:
//		break;
//	}
//}
//
////数值过滤器
//int Valuefilter(int MAX, int MIN, int c) {
//	if (c > MAX) {
//		c = MAX; return c;
//	}
//	else if (c < MIN) {
//		c = MIN; return c;
//	}
//	else {
//		return c;
//	}
//}
//包含坐标检测
//bool ContainCoord(RECT Area, Vector2D Coord) {
//	if (Area.left < Coord.x && Coord.x < Area.right && Area.top < Coord.y && Coord.y < Area.Buttom) {
//		return TRUE;
//	}
//	else
//	{
//		return FALSE;
//	}
//}


////批量检测包含关系
//Widget_Base* ContainCoord(vector<Widget_Base*> AreaList, int CoordX, int CoordY, Widget_Base** LastCursorIn) {
//	for (vector<Widget_Base*>::iterator iter = AreaList.begin() + 1; iter != AreaList.end(); iter++) {
//		if ((*iter)->Area.left < CoordX && CoordX < (*iter)->Area.right && (*iter)->Area.top < CoordY && CoordY < (*iter)->Area.Buttom)
//		{
//			//cout << "检测到进入"<< (*iter)->Name<<endl;
//			if ((*iter) == *LastCursorIn) {
//				return *LastCursorIn;
//			}
//			else {
//				(*iter)->Cursor_In();
//				(*LastCursorIn)->Cursor_Leave();
//				*LastCursorIn = (*iter);
//				return (*iter);
//			}
//		}
//	}
//}

////结构体逐值赋值
//void* PerValueToStruct( LayoutPropertyType TYPE,short ValueSequnce, string Value) {
//	switch (TYPE)
//	{
//	case E_Name:
//		break;
//	case E_RatioOrigin:
//		ValueSequnce
//		break;
//	case E_RatioBorder:
//		break;
//	case E_Origin:
//		break;
//	case E_Border:
//		break;
//	case E_Width:
//		break;
//	case E_Height:
//		break;
//	case E_LayerLevel:
//		break;
//	case E_SequenceLevel:
//		break;
//	default:
//		break;
//	}
//
//}


