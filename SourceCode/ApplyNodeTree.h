#pragma once
#include"ApplyGraphicsFunction.h"
//������
class NodeTree{
public:
	//���ڵ�������б�
	NodePropertyList PropertyList;
	//�ڵ�����
	NodeType T_NodeType;
	//�ڵ�����ַ
	GUI_Rectangle* NodeAddress;
	//��һ���ڵ��ַ
	NodeTree* HigherLevel;
	//�Ӽ��ڵ��ַ��
	vector<NodeTree*> SubNodeList;

	//Ĭ��ֵ���캯��
	NodeTree(string NT = "Rectangle", int level_Y = 0,int Width=1280,int Height=768) {
		//Ĭ����һ��ָ��NULL
		HigherLevel = NULL;

		//�ڵ������б��ʼ��
		PropertyList.layerXY.y = level_Y;

		PropertyList.name = "WindowNode";

		Width = GetSystemMetrics(SM_CXSCREEN);
		Height= GetSystemMetrics(SM_CYSCREEN);

		PropertyList.ratio_origin = { 0 ,0};//Ĭ��������
		PropertyList.ratio_border = { 1,1 };//Ĭ���յ����

		PropertyList.origin = { 0,0 };//Ĭ�����X(0,0)
		PropertyList.border = { Width*1.0f ,Height*1.0f};//Ĭ���յ�

		PropertyList.Wid_Hei = PropertyList.border - PropertyList.origin;//���ؿ��(�յ�X-���X)

		//������ǩ������Ӧ���ڵ�Ŀؼ�����
		T_NodeType = StringToNodeType(&NT);

		//���ݽڵ�������NEW�����½ڵ㣬����ֵ��NodeAddress
		NodeAddress = MakePoint_NodeType(T_NodeType, &PropertyList);

		//((GUI_Rectangle*)(NodeAddress))->Origin = PropertyList.origin;
		//((GUI_Rectangle*)(NodeAddress))->Border = PropertyList.border;
		//((GUI_Rectangle*)(NodeAddress))->Wid_Hei = PropertyList.Wid_Hei;

	}

	//��������
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

	
	//����Ӳ��ֽڵ�
	NodeTree* AddSubNode(string N = "Rectangle") {
		//����һ����ʱ�ڵ㣬�����루�ؼ����ͣ�Y�㼶��
		NodeTree* SubNode = new NodeTree(N, (PropertyList.layerXY.y)+1);

		//�����ӽڵ�������յ����ɱ����������ӽڵ��ʵ��������� >(�����/���յ�) = (�����/���յ�) * (��������/���յ����)
		((SubNode->NodeAddress))->Origin = SubNode->PropertyList.origin = PropertyList.origin + ((SubNode->PropertyList.ratio_origin)*PropertyList.Wid_Hei);
		((SubNode->NodeAddress))->Border = SubNode->PropertyList.border = PropertyList.origin + ((SubNode->PropertyList.ratio_border)*PropertyList.Wid_Hei);

		//���ݼ�����ʵ�������յ㣬ȷ��ʵ�ʿ��
		((SubNode->NodeAddress))->Wid_Hei = SubNode->PropertyList.Wid_Hei = SubNode->PropertyList.border - SubNode->PropertyList.origin;

		//���ӽڵ���ӵ���ǰ�ڵ���ӽڵ��
		SubNodeList.push_back(SubNode);
		//�ӽڵ��ƽ�в㼶���У�Ϊ��ǰ�ڵ��б��SIZE
		SubNode->PropertyList.sequence_level = SubNodeList.size();//��СֵΪ1
		//���ӽڵ�� ����һ��ָ�롱ָ�򱾽ڵ�
		SubNode->HigherLevel = this;

		return SubNode;
	}
	//����ˢ�º���
	void FlushProperty() {
		if (HigherLevel != NULL) {
			//ˢ�½ڵ㱾������
			PropertyList.origin = HigherLevel->PropertyList.origin + (PropertyList.ratio_origin*HigherLevel->PropertyList.Wid_Hei);
			PropertyList.border = HigherLevel->PropertyList.origin + (PropertyList.ratio_border*HigherLevel->PropertyList.Wid_Hei);
			PropertyList.Wid_Hei = PropertyList.border - PropertyList.origin;
			//ˢ��ָ����������
			((NodeAddress))->FlushData(&(PropertyList));
		}
	}
	//�����޸ĺ���
	bool Modification(byte ValueSeq,string* PropertyName,string* PropertyValue) {
		//�����һ��Ϊ�գ�������Ϊ���ڵ㣬�����޸�����
        if (HigherLevel != NULL) {
			//����һ�����غ��ַ���һ����ö�ټ�⺯����Ĭ��Ϊ�棬��δ����ͬ������ʱΪ�٣�
			bool* IsPublicProperty = new bool(TRUE);
			//����תΪ ���ڵ������ö����	��ƥ��ʧ���� IsPublicProperty ���޸�Ϊ��FALSE���ҷ��ص�ö����Ч
			NodePropertyType TYPE = StringToNodePropertyType(PropertyName,IsPublicProperty);

			//����ǹ��ò��������ö��ƥ���޸Ŀ����б�
			if (!(*IsPublicProperty))
			{//ƥ����ɺ��ͷ���ʱָ��
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
				//ƥ����ɺ��ͷ���ʱָ��
				delete IsPublicProperty;
				return FALSE;
			}
			//ˢ�¹�������
			//FlushProperty();
			//ƥ����ɺ��ͷ���ʱָ��
			delete IsPublicProperty;
			return TRUE;
		}
	}
};