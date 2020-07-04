#pragma once
#include"ApplyGraphicsFunction.h"
//布局类
class NodeTree{
public:
	//树节点的属性列表
	NodePropertyList PropertyList;
	//节点类型
	NodeType T_NodeType;
	//节点对象地址
	GUI_Rectangle* NodeAddress;
	//上一级节点地址
	NodeTree* HigherLevel;
	//子级节点地址库
	vector<NodeTree*> SubNodeList;

	//默认值构造函数
	NodeTree(string NT = "Rectangle", int level_Y = 0,int Width=1280,int Height=768) {
		//默认上一层指向NULL
		HigherLevel = NULL;

		//节点属性列表初始化
		PropertyList.layerXY.y = level_Y;

		PropertyList.name = "WindowNode";

		Width = GetSystemMetrics(SM_CXSCREEN);
		Height= GetSystemMetrics(SM_CYSCREEN);

		PropertyList.ratio_origin = { 0 ,0};//默认起点比例
		PropertyList.ratio_border = { 1,1 };//默认终点比例

		PropertyList.origin = { 0,0 };//默认起点X(0,0)
		PropertyList.border = { Width*1.0f ,Height*1.0f};//默认终点

		PropertyList.Wid_Hei = PropertyList.border - PropertyList.origin;//像素宽高(终点X-起点X)

		//分析标签名，对应到节点的控件类型
		T_NodeType = StringToNodeType(&NT);

		//根据节点类型用NEW创建新节点，并赋值给NodeAddress
		NodeAddress = MakePoint_NodeType(T_NodeType, &PropertyList);

		//((GUI_Rectangle*)(NodeAddress))->Origin = PropertyList.origin;
		//((GUI_Rectangle*)(NodeAddress))->Border = PropertyList.border;
		//((GUI_Rectangle*)(NodeAddress))->Wid_Hei = PropertyList.Wid_Hei;

	}

	//析构函数
	~NodeTree() {
		delete NodeAddress;
	}
	//PRINT
	void PrintList() {
		cout << "-----------------------PRINT-LIST----------------------" << endl;
		cout << "\tNodeType\t\t\t[" << NodeTypeToString(T_NodeType) << ']' << endl;
		cout << "\t> name\t\t\t\t[" << PropertyList.name << ']' << endl;
		cout << "\t> originX\t\t\t[" << PropertyList.origin.x << ']' << endl;
		cout << "\t> originY\t\t\t[" << PropertyList.origin.y << ']' << endl;
		cout << "\t> borderX\t\t\t[" << PropertyList.border.x << ']' << endl;
		cout << "\t> borderY\t\t\t[" << PropertyList.border.y  << ']' << endl;
		cout << "\t> width\t\t\t\t[" << PropertyList.Wid_Hei.x << ']' << endl;
		cout << "\t> height\t\t\t[" << PropertyList.Wid_Hei.y << ']' << endl;
		cout << "\t> ratio_originX\t\t\t[" << PropertyList.ratio_origin.x << ']' << endl;
		cout << "\t> ratio_originY\t\t\t[" << PropertyList.ratio_origin.y << ']' << endl;
		cout << "\t> ratio_borderX\t\t\t[" << PropertyList.ratio_border.x << ']' << endl;
		cout << "\t> ratio_borderY\t\t\t[" << PropertyList.ratio_border.y << ']' << endl;
		cout << "-------------------------------------------------------" << endl;
	}

	
	//添加子布局节点
	NodeTree* AddSubNode(string N = "Rectangle") {
		//创建一个临时节点，并带入（控件类型，Y层级）
		NodeTree* SubNode = new NodeTree(N, (PropertyList.layerXY.y)+1);

		//根据子节点的起点和终点生成比例，设置子节点的实际起点坐标 >(子起点/子终点) = (父起点/父终点) * (子起点比例/子终点比例)
		((SubNode->NodeAddress))->Origin = SubNode->PropertyList.origin = PropertyList.origin + ((SubNode->PropertyList.ratio_origin)*PropertyList.Wid_Hei);
		((SubNode->NodeAddress))->Border = SubNode->PropertyList.border = PropertyList.origin + ((SubNode->PropertyList.ratio_border)*PropertyList.Wid_Hei);

		//根据计算后的实际起点和终点，确定实际宽高
		((SubNode->NodeAddress))->Wid_Hei = SubNode->PropertyList.Wid_Hei = SubNode->PropertyList.border - SubNode->PropertyList.origin;

		//将子节点添加到当前节点的子节点库
		SubNodeList.push_back(SubNode);
		//子节点的平行层级序列，为当前节点列表的SIZE
		SubNode->PropertyList.sequence_level = SubNodeList.size();//最小值为1
		//将子节点的 “上一层指针”指向本节点
		SubNode->HigherLevel = this;

		return SubNode;
	}
	//属性刷新函数
	void FlushProperty() {
		if (HigherLevel != NULL) {
			//刷新节点本身属性
			PropertyList.origin = HigherLevel->PropertyList.origin + (PropertyList.ratio_origin*HigherLevel->PropertyList.Wid_Hei);
			PropertyList.border = HigherLevel->PropertyList.origin + (PropertyList.ratio_border*HigherLevel->PropertyList.Wid_Hei);
			PropertyList.Wid_Hei = PropertyList.border - PropertyList.origin;
			//刷新指向对象的属性
			((NodeAddress))->FlushData(&(PropertyList));
		}
	}
	//属性修改函数
	bool Modification(byte ValueSeq,string* PropertyName,string* PropertyValue) {
		//如果上一层为空，即本身为根节点，则不需修改属性
        if (HigherLevel != NULL) {
			//定义一个开关和字符串一起传入枚举检测函数，默认为真，当未发现同名属性时为假；
			bool* IsPublicProperty = new bool(TRUE);
			//尝试转为 树节点的属性枚举类	若匹配失败则 IsPublicProperty 被修改为假FALSE，且返回的枚举无效
			NodePropertyType TYPE = StringToNodePropertyType(PropertyName,IsPublicProperty);

			//如果是公用参数则进入枚举匹配修改开关列表
			if (!(*IsPublicProperty))
			{//匹配完成后释放临时指针
				delete IsPublicProperty;
				return FALSE;
			}
			switch (TYPE)
			{
			case E_NodeProperty_name:
				PropertyList.name = *PropertyValue;
				break;
			case E_NodeProperty_ratio_origin:
				PropertyList.ratio_origin.Modification(ValueSeq,PropertyValue);
				break;
			case E_NodeProperty_ratio_border:
				PropertyList.ratio_border.Modification(ValueSeq, PropertyValue);
				break;
			case E_NodeProperty_origin:
				PropertyList.origin.Modification(ValueSeq, PropertyValue);
				break;
			case E_NodeProperty_border:
				PropertyList.border.Modification(ValueSeq, PropertyValue);
				break;
			case E_NodeProperty_layerXY:
				PropertyList.layerXY.Modification(ValueSeq, PropertyValue);
				break;
			//case E_NodeProperty_width:
			//	PropertyList.width = str_to_int(PropertyValue);
			//	return TRUE;
			//case E_NodeProperty_height:
			//	PropertyList.height = str_to_int(PropertyValue);
			//	return TRUE;
			//case E_NodeProperty_layer_level:
			//	PropertyList.layer_level = str_to_int(PropertyValue);
			//	return TRUE;
			//case E_NodeProperty_sequence_level:
			//	PropertyList.sequence_level = str_to_int(PropertyValue);
			//	return TRUE;
			default:
				//匹配完成后释放临时指针
				delete IsPublicProperty;
				return FALSE;
			}
			//刷新关联属性
			//FlushProperty();
			//匹配完成后释放临时指针
			delete IsPublicProperty;
			return TRUE;
		}
	}
};