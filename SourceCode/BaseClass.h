#pragma once
#include"BaseFunction.h"

using namespace std;
////������
//class Layout {
//public:
//	//�ڵ�����
//	WidgetType WidgetType;
//	//���Խṹ��
//	NodePropertyList PropertyList;
//	//��һ���ڵ��ַ
//	Layout* HigherLevel;
//	//�Ӽ��ڵ��ַ��
//	vector<Layout*> SubLayoutList;
//
//	//Ĭ��ֵ���캯��
//	//Layout(string N = "Layout", int level_Y = 0, Vector2D O = { 0,0 }, Vector2D B = { 0, 0 }) :name(N), LayerLevel(level_Y), Origin(O), Border(B) {}
//	Layout(string N = "Layout", int level_Y = 0) {
//
//		//������ǩ������Ӧ���ڵ�Ŀؼ�����
//		WidgetType = StringToWidgetType(&N);
//		PropertyList.layer_level = level_Y;
//		PropertyList.name = "NULL";
//		PropertyList.ratio_border = 0.5;//Ĭ��������Ϊ0.5
//		PropertyList.RatioOrigin = 0.5;//Ĭ���յ����Ϊ0.5
//
//		PropertyList.Origin = 0;//Ĭ�����(0,0)
//		PropertyList.Border = 10;//Ĭ���յ�(10,10)
//
//		PropertyList.width = PropertyList.Border.x - PropertyList.Origin.x;//������(�յ�X-���X)
//		PropertyList.height = PropertyList.Border.y - PropertyList.Origin.y;//������(�յ�Y-���Y)
//	}
//
//	//��������
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
//	//����Ӳ��ֽڵ�
//	Layout* AddSubLayout(string N = "Layout", int level_Y = 0) {
//		//����һ����ʱ�ڵ㣬�����루�ؼ����ͣ�Y�㼶��
//		Layout* SubLayout = new Layout(N, level_Y);
//		//���ӽڵ���ӵ���ǰ�ڵ���ӽڵ��
//		SubLayoutList.push_back(SubLayout);
//		//�ӽڵ��ƽ�в㼶���У�Ϊ��ǰ�ڵ��б��SIZE
//		SubLayout->PropertyList.sequence_level = SubLayoutList.size();
//		//���ӽڵ�� ����һ��ָ�롱ָ���Լ�
//		SubLayout->HigherLevel = this;
//
//		//�����ӽڵ�������յ����ɱ����������ӽڵ��ʵ��������� >(�����/���յ�) = (�����/���յ�) * (��������/���յ����)
//		SubLayout->PropertyList.Origin = PropertyList.Origin * SubLayout->PropertyList.RatioOrigin;
//		SubLayout->PropertyList.Border = PropertyList.Border	 * SubLayout->PropertyList.ratio_border;
//		//���ݼ�����ʵ�������յ㣬ȷ��ʵ�ʿ��
//		SubLayout->PropertyList.width = SubLayout->PropertyList.Border.x - SubLayout->PropertyList.Origin.x;
//		SubLayout->PropertyList.width = SubLayout->PropertyList.Border.y - SubLayout->PropertyList.Origin.y;
//
//		return SubLayout;
//	}
//
//
//};