#pragma once
#include"ApplyNodeTree.h"
using namespace std;


class Script_JML {
public:
	//脚本信息
	_DOCINFO DocInformation ;
	//脚本内容	头节点
	NodeTree* NodeRoot;
	char FindDocType;
	bool LastLabelIsend;

	//标签处理函数
	NodeTree** LabelDispose(string* LabelName, NodeTree** LayerSeek);
	//属性&值处理函数
	void Dispose(NodeTree* Seek, byte ValueSeq, string* PropertyName, string* PropertyValue);
	//从文件加载脚本
	NodeTree* LoadScript();

	//构造函数
	Script_JML(ifstream* FileAddress) {
		FindDocType = 0;
		LastLabelIsend = FALSE;
		//初始化树根节点
		NodeRoot = new NodeTree;

		//指定文件
		//DocInformation.File->open(((const char*)FileAddress),ios::in);

		DocInformation.File = FileAddress;

		//如果文件存在则开始解析内容
		if (*(DocInformation.File)) {
			LoadScript();
		}
	}
	//析构函数
	~Script_JML() {}


};

/////////////////标签处理//////////////////////
NodeTree** Script_JML::LabelDispose(string* LabelName, NodeTree** LayerSeek) {
	//判断节点名是否为文档说明节点标记符'!'开头
	if (FindDocType==0)
	{
		if ((*LabelName)[0] == '!') {
			cout << "发现头文件" << endl;
			//开启文档信息开关
			FindDocType = 1;
		}
	}
	
	//判断节点名是否为节点脚标记符'/'开头
	else if ((*LabelName)[0] == '/') {
		LastLabelIsend = TRUE;
		//关闭文档信息开关
		if (FindDocType==1)
		{
			FindDocType = 3;
			return LayerSeek;
		}
		//刷新关联属性
		(*LayerSeek)->FlushProperty();
		//插入指针返回上级
		*LayerSeek = (*LayerSeek)->HigherLevel;

	}
	//若不是脚标签则将当前添加至头标签库
	else {
		LastLabelIsend = FALSE;
		//关闭文档信息开关
		if (FindDocType==1)
		{
			FindDocType = 3;
			//return LayerSeek;
		}
		//刷新关联属性
		//判定1、如果上一层为空则不刷新，等同于节省了对第一层的刷新，第一次的标签为文档声明
		//判定2、并且，上一次标签不为结束标签，因为如果上一标签为结束标签则一定已经刷新过
		if ((*LayerSeek)->HigherLevel!=NULL && !LastLabelIsend)
		{
			(*LayerSeek)->FlushProperty();
		}
		//直接添加到当前Seek的子布局列表 SubLayoutList中
		(*LayerSeek)->AddSubNode(*LabelName);
		//并将LayerSeek指向新添加的Layout节点
		*LayerSeek = *((*LayerSeek)->SubNodeList.end() - 1);
		
	}
	return LayerSeek;
}



//处理读取内容
void Script_JML::Dispose(NodeTree* Seek,byte ValueSeq,string* PropertyName,string* PropertyValue) {
	//是否为文档格式属性
	//如果是声明文件则优先匹配文档信息修改
	if (FindDocType==1)
	{
		_DOCINFO_Type TYPE = StringTo_DOCINFO_Type(PropertyName);
		switch (TYPE)
		{
		case E_File:
			DocInformation.File = new ifstream(&((*RemoveChar(RemoveChar(PropertyValue, ' '), '"'))[0]));
			return;
		case E_CharSet:
			DocInformation.CharSet = *RemoveChar(RemoveChar(PropertyValue,' '),'"');
			return;
		case E_NumberOfNodes:
			DocInformation.NumberOfNodes = str_to_int(PropertyValue);
			return;
		case E_NumberOfChar:
			DocInformation.NumberOfChar = str_to_int(PropertyValue);
			return;
		case E_NumberOfLine:
			DocInformation.NumberOfLine = str_to_int(PropertyValue);
			return;
		case E_Size_B:
			DocInformation.Size_B = str_to_int(PropertyValue);
			return;
		default:
			return;
		}
	}
	//DocInformation.

	//先作为节点属性修改
	bool IsNodeProperty = Seek->Modification(ValueSeq,PropertyName, PropertyValue);
	
	//如果不是节点本身的属性再作为节点所储存的类型的属性修改
	if (!IsNodeProperty) {
		(Seek->NodeAddress)->Modification(ValueSeq, PropertyName, PropertyValue);
	}
}

NodeTree* Script_JML::LoadScript()
{
	NodeTree** NodeSeek = &NodeRoot;//层级指针,默认指向首节点/ROOT

	string* LabelName = new string;//临时存储节点名称
	string* PropertyName = new string;//临时存储属性名
	string* PropertyValue = new string;//临时存储属性值
	
	bool LabelNameSwitch = FALSE;//"标签名读取针" 的开关，为真时开启读取模式。
	bool PropNameSwitch = FALSE;//"属性名读取针" 的开关，为真时开启读取模式。
	bool PropValueSwitch = FALSE;//"属性值读取针" 的开关，为真时开启读取模式。
	byte ValueSequence = 0;//第几个值
	char p;//文件读取针，文档内所有字符都有“文件读取针”获得，并分类储存。


	//_______3.循环遍历文档读取字符
	while (!DocInformation.File->eof())//若未读取到文件结束
	{

		DocInformation.File->get(p);
		//若为UTF-8则转为GB码 if (DocInformation.CharSet == "UTF-8"){}
		if (p == '<') {
			LabelNameSwitch = TRUE;
			DocInformation.File->get(p);
		}
		else if (LabelNameSwitch&&p == '>')
		{
			LabelNameSwitch = FALSE;

			//处理标签名
			NodeSeek = LabelDispose(LabelName, NodeSeek);//分析标签名

			LabelName->clear();//清除临时名称
		}

		////接收属性名/////////////////////////////////////

		if (!LabelNameSwitch && !PropValueSwitch&&KeyCharCheck(p) == 'c') {
			PropNameSwitch = TRUE;
		}
		else if (PropNameSwitch && (p == '='))
		{
			PropNameSwitch = FALSE;
			//暂存属性名称
			cout << "///////////////////处理属性名///////////////////" << endl;
			cout << "PropertyName\t :\t[" << *RemoveChar(PropertyName, ' ', FALSE) << ']' << endl;
			
		}

		////接收属性值/////////////////////////////////////
		if (p == '=') {
			PropValueSwitch = TRUE;
			DocInformation.File->get(p);
		}
		else if (p == ',') {
			
			ValueSequence += 1;//值的次序，+1

			//根据属性名处理属性值
			cout << "///////////////////处理属性值///////////////////" << endl;
			cout << "PropertyValue\t :\t[" << *RemoveChar(PropertyValue, ' ', FALSE) << ']' << endl;
			
			//同时处理属性名和属性值
			Dispose(*NodeSeek, ValueSequence,PropertyName, PropertyValue);

			DocInformation.File->get(p);
			PropertyValue->clear();
		}
		else if (p == ';') {
			ValueSequence += 1;//值的次序，+1

			//处理属性值
			cout << "///////////////////处理属性值///////////////////" << endl;
			cout << "PropertyValue\t :\t[" << *RemoveChar(PropertyValue, ' ', FALSE) << ']' << endl;

			Dispose(*NodeSeek, ValueSequence, PropertyName,PropertyValue);
			
			
			PropValueSwitch = FALSE;
			//LabelName->clear();//清除临时标签名称
			PropertyName->clear();//清除临时属性名称
			PropertyValue->clear();
			ValueSequence = 0;//值的次序归零
			
		}
		else if (p=='/'&&!PropValueSwitch) {
			DocInformation.File->get(p);
			if (p=='/')
			{
				char buffer[100];
				DocInformation.File->getline(buffer,99, '\n');
			}
			else {
				LabelName->push_back('/');
			}
		}

		//暂存标签名
		if (LabelNameSwitch) {
			LabelName->push_back(p);
		}
		else if (PropNameSwitch) {
			PropertyName->push_back(p);
		}
		else if (PropValueSwitch) {
			PropertyValue->push_back(p);
		}
	}

	return NodeRoot;
}