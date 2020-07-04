#pragma once
#include"ApplyNodeTree.h"
using namespace std;


class Script_JML {
public:
	//�ű���Ϣ
	_DOCINFO DocInformation ;
	//�ű�����	ͷ�ڵ�
	NodeTree* NodeRoot;
	char FindDocType;
	bool LastLabelIsend;

	//��ǩ������
	NodeTree** LabelDispose(string* LabelName, NodeTree** LayerSeek);
	//����&ֵ������
	void Dispose(NodeTree* Seek, byte ValueSeq, string* PropertyName, string* PropertyValue);
	//���ļ����ؽű�
	NodeTree* LoadScript();

	//���캯��
	Script_JML(ifstream* FileAddress) {
		FindDocType = 0;
		LastLabelIsend = FALSE;
		//��ʼ�������ڵ�
		NodeRoot = new NodeTree;

		//ָ���ļ�
		//DocInformation.File->open(((const char*)FileAddress),ios::in);

		DocInformation.File = FileAddress;

		//����ļ�������ʼ��������
		if (*(DocInformation.File)) {
			LoadScript();
		}
	}
	//��������
	~Script_JML() {}


};

/////////////////��ǩ����//////////////////////
NodeTree** Script_JML::LabelDispose(string* LabelName, NodeTree** LayerSeek) {
	//�жϽڵ����Ƿ�Ϊ�ĵ�˵���ڵ��Ƿ�'!'��ͷ
	if (FindDocType==0)
	{
		if ((*LabelName)[0] == '!') {
			cout << "����ͷ�ļ�" << endl;
			//�����ĵ���Ϣ����
			FindDocType = 1;
		}
	}
	
	//�жϽڵ����Ƿ�Ϊ�ڵ�ű�Ƿ�'/'��ͷ
	else if ((*LabelName)[0] == '/') {
		LastLabelIsend = TRUE;
		//�ر��ĵ���Ϣ����
		if (FindDocType==1)
		{
			FindDocType = 3;
			return LayerSeek;
		}
		//ˢ�¹�������
		(*LayerSeek)->FlushProperty();
		//����ָ�뷵���ϼ�
		*LayerSeek = (*LayerSeek)->HigherLevel;

	}
	//�����ǽű�ǩ�򽫵�ǰ�����ͷ��ǩ��
	else {
		LastLabelIsend = FALSE;
		//�ر��ĵ���Ϣ����
		if (FindDocType==1)
		{
			FindDocType = 3;
			//return LayerSeek;
		}
		//ˢ�¹�������
		//�ж�1�������һ��Ϊ����ˢ�£���ͬ�ڽ�ʡ�˶Ե�һ���ˢ�£���һ�εı�ǩΪ�ĵ�����
		//�ж�2�����ң���һ�α�ǩ��Ϊ������ǩ����Ϊ�����һ��ǩΪ������ǩ��һ���Ѿ�ˢ�¹�
		if ((*LayerSeek)->HigherLevel!=NULL && !LastLabelIsend)
		{
			(*LayerSeek)->FlushProperty();
		}
		//ֱ����ӵ���ǰSeek���Ӳ����б� SubLayoutList��
		(*LayerSeek)->AddSubNode(*LabelName);
		//����LayerSeekָ������ӵ�Layout�ڵ�
		*LayerSeek = *((*LayerSeek)->SubNodeList.end() - 1);
		
	}
	return LayerSeek;
}



//�����ȡ����
void Script_JML::Dispose(NodeTree* Seek,byte ValueSeq,string* PropertyName,string* PropertyValue) {
	//�Ƿ�Ϊ�ĵ���ʽ����
	//����������ļ�������ƥ���ĵ���Ϣ�޸�
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

	//����Ϊ�ڵ������޸�
	bool IsNodeProperty = Seek->Modification(ValueSeq,PropertyName, PropertyValue);
	
	//������ǽڵ㱾�����������Ϊ�ڵ�����������͵������޸�
	if (!IsNodeProperty) {
		(Seek->NodeAddress)->Modification(ValueSeq, PropertyName, PropertyValue);
	}
}

NodeTree* Script_JML::LoadScript()
{
	NodeTree** NodeSeek = &NodeRoot;//�㼶ָ��,Ĭ��ָ���׽ڵ�/ROOT

	string* LabelName = new string;//��ʱ�洢�ڵ�����
	string* PropertyName = new string;//��ʱ�洢������
	string* PropertyValue = new string;//��ʱ�洢����ֵ
	
	bool LabelNameSwitch = FALSE;//"��ǩ����ȡ��" �Ŀ��أ�Ϊ��ʱ������ȡģʽ��
	bool PropNameSwitch = FALSE;//"��������ȡ��" �Ŀ��أ�Ϊ��ʱ������ȡģʽ��
	bool PropValueSwitch = FALSE;//"����ֵ��ȡ��" �Ŀ��أ�Ϊ��ʱ������ȡģʽ��
	byte ValueSequence = 0;//�ڼ���ֵ
	char p;//�ļ���ȡ�룬�ĵ��������ַ����С��ļ���ȡ�롱��ã������ഢ�档


	//_______3.ѭ�������ĵ���ȡ�ַ�
	while (!DocInformation.File->eof())//��δ��ȡ���ļ�����
	{

		DocInformation.File->get(p);
		//��ΪUTF-8��תΪGB�� if (DocInformation.CharSet == "UTF-8"){}
		if (p == '<') {
			LabelNameSwitch = TRUE;
			DocInformation.File->get(p);
		}
		else if (LabelNameSwitch&&p == '>')
		{
			LabelNameSwitch = FALSE;

			//�����ǩ��
			NodeSeek = LabelDispose(LabelName, NodeSeek);//������ǩ��

			LabelName->clear();//�����ʱ����
		}

		////����������/////////////////////////////////////

		if (!LabelNameSwitch && !PropValueSwitch&&KeyCharCheck(p) == 'c') {
			PropNameSwitch = TRUE;
		}
		else if (PropNameSwitch && (p == '='))
		{
			PropNameSwitch = FALSE;
			//�ݴ���������
			cout << "///////////////////����������///////////////////" << endl;
			cout << "PropertyName\t :\t[" << *RemoveChar(PropertyName, ' ', FALSE) << ']' << endl;
			
		}

		////��������ֵ/////////////////////////////////////
		if (p == '=') {
			PropValueSwitch = TRUE;
			DocInformation.File->get(p);
		}
		else if (p == ',') {
			
			ValueSequence += 1;//ֵ�Ĵ���+1

			//������������������ֵ
			cout << "///////////////////��������ֵ///////////////////" << endl;
			cout << "PropertyValue\t :\t[" << *RemoveChar(PropertyValue, ' ', FALSE) << ']' << endl;
			
			//ͬʱ����������������ֵ
			Dispose(*NodeSeek, ValueSequence,PropertyName, PropertyValue);

			DocInformation.File->get(p);
			PropertyValue->clear();
		}
		else if (p == ';') {
			ValueSequence += 1;//ֵ�Ĵ���+1

			//��������ֵ
			cout << "///////////////////��������ֵ///////////////////" << endl;
			cout << "PropertyValue\t :\t[" << *RemoveChar(PropertyValue, ' ', FALSE) << ']' << endl;

			Dispose(*NodeSeek, ValueSequence, PropertyName,PropertyValue);
			
			
			PropValueSwitch = FALSE;
			//LabelName->clear();//�����ʱ��ǩ����
			PropertyName->clear();//�����ʱ��������
			PropertyValue->clear();
			ValueSequence = 0;//ֵ�Ĵ������
			
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

		//�ݴ��ǩ��
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