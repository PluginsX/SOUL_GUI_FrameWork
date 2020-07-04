#pragma once
#include"BaseFunction.h"

using namespace std;
////布局类
//class Layout {
//public:
//	//节点类型
//	WidgetType WidgetType;
//	//属性结构体
//	NodePropertyList PropertyList;
//	//上一级节点地址
//	Layout* HigherLevel;
//	//子级节点地址库
//	vector<Layout*> SubLayoutList;
//
//	//默认值构造函数
//	//Layout(string N = "Layout", int level_Y = 0, Vector2D O = { 0,0 }, Vector2D B = { 0, 0 }) :name(N), LayerLevel(level_Y), Origin(O), Border(B) {}
//	Layout(string N = "Layout", int level_Y = 0) {
//
//		//分析标签名，对应到节点的控件类型
//		WidgetType = StringToWidgetType(&N);
//		PropertyList.layer_level = level_Y;
//		PropertyList.name = "NULL";
//		PropertyList.ratio_border = 0.5;//默认起点比例为0.5
//		PropertyList.RatioOrigin = 0.5;//默认终点比例为0.5
//
//		PropertyList.Origin = 0;//默认起点(0,0)
//		PropertyList.Border = 10;//默认终点(10,10)
//
//		PropertyList.width = PropertyList.Border.x - PropertyList.Origin.x;//宽像素(终点X-起点X)
//		PropertyList.height = PropertyList.Border.y - PropertyList.Origin.y;//高像素(终点Y-起点Y)
//	}
//
//	//析构函数
//	~Layout() {}
//	//PRINT
//	void PrintList() {
//		//system("cls");
//		cout << "------------------PRINT-LIST-----------------" << endl; int i = 0;
//		cout << i << "\t > NodeType : \t[" << EnumToString(WidgetType) << ']' << endl;
//		if (SubLayoutList.size() != 0)
//		{
//			for (vector<Layout*>::iterator iter = SubLayoutList.begin(); iter != SubLayoutList.end(); iter++, i++) {
//				cout << i << "\t > name : \t[" << (*iter)->PropertyList.name << ']' << endl;
//				cout << i << "\t > Width : \t[" << (*iter)->PropertyList.width << ']' << endl;
//				cout << i << "\t > Height : \t[" << (*iter)->PropertyList.height << ']' << endl;
//			}
//			for (vector<Layout*>::iterator iter = SubLayoutList.begin(); iter != SubLayoutList.end(); iter++, i++) {
//				(*iter)->PrintList();
//			}
//				cout << "---------------------------------------------" << endl;
//		}
//	}
//
//
//	//LayoutPropertyList* PropertyNameDispose(Layout* Seek) {
//	//	return &(Seek->PropertyList);
//	//}
//
//	//添加子布局节点
//	Layout* AddSubLayout(string N = "Layout", int level_Y = 0) {
//		//创建一个临时节点，并带入（控件类型，Y层级）
//		Layout* SubLayout = new Layout(N, level_Y);
//		//将子节点添加到当前节点的子节点库
//		SubLayoutList.push_back(SubLayout);
//		//子节点的平行层级序列，为当前节点列表的SIZE
//		SubLayout->PropertyList.sequence_level = SubLayoutList.size();
//		//将子节点的 “上一层指针”指向自己
//		SubLayout->HigherLevel = this;
//
//		//根据子节点的起点和终点生成比例，设置子节点的实际起点坐标 >(子起点/子终点) = (父起点/父终点) * (子起点比例/子终点比例)
//		SubLayout->PropertyList.Origin = PropertyList.Origin * SubLayout->PropertyList.RatioOrigin;
//		SubLayout->PropertyList.Border = PropertyList.Border	 * SubLayout->PropertyList.ratio_border;
//		//根据计算后的实际起点和终点，确定实际宽高
//		SubLayout->PropertyList.width = SubLayout->PropertyList.Border.x - SubLayout->PropertyList.Origin.x;
//		SubLayout->PropertyList.width = SubLayout->PropertyList.Border.y - SubLayout->PropertyList.Origin.y;
//
//		return SubLayout;
//	}
//
//
//};