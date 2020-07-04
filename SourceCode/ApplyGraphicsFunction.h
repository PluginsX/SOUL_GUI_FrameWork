#pragma once
#include"ApplyGraphicsClass.h"

//根据节点类型用NEW创建新节点
GUI_Rectangle* MakePoint_NodeType(NodeType T_NodeType, NodePropertyList* PropertyList) {
	//GUI_Rectangle* TMP = new GUI_Rectangle;
	switch (T_NodeType)
	{
	case E_Rectangle:
		//TMP = new GUI_Rectangle(PropertyList->origin, PropertyList->border);
		return (new GUI_Rectangle(PropertyList->origin, PropertyList->border));
	case E_Roundrect:
		//TMP = new GUI_Roundrect(PropertyList->origin, PropertyList->border);
		return (new GUI_Roundrect(PropertyList->origin, PropertyList->border));
	case E_BitMap:
		//TMP = new GUI_BitMap(PropertyList->origin, PropertyList->border);
		return (new GUI_BitMap(PropertyList->origin, PropertyList->border));
	case E_Text:
		//TMP = new GUI_Text(PropertyList->origin, PropertyList->border);
		return (new GUI_Text(PropertyList->origin, PropertyList->border));
	case E_Sound:
		//TMP = new GUI_Sound();
		return (new GUI_Sound());
	case E_SelectButtom:
		//TMP = new GUI_SelectButtom(PropertyList->origin, PropertyList->border);
		return (new GUI_SelectButtom(PropertyList->origin, PropertyList->border));
	case E_Buttom:
		//TMP = new GUI_Buttom(PropertyList->origin, PropertyList->border);
		return (new GUI_Buttom(PropertyList->origin, PropertyList->border));
	case E_Slider:
		//TMP = new GUI_Slider(PropertyList->origin, PropertyList->border);
		return (new GUI_Slider(PropertyList->origin, PropertyList->border));
	default:
		return (new GUI_Rectangle(PropertyList->origin, PropertyList->border));
	}
}