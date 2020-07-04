#pragma once
#include"BaseEnum.h"

using namespace std;

float str_to_int(string* str);
int Valuefilter(int MAX, int MIN, int c);
//��������
struct Vector4D {
	int x1;
	int y1;
	int x2;
	int y2;

	//�����±�ȡֵ
	int operator[](byte Seq)const {
		if (Seq < 0 || Seq>3) {
			Seq = (byte)Valuefilter(3,0,Seq); 
		}
	}

	//������޸ĺ���,ֻ�ܶ�ȡֵ�����޸�ֵ
	bool Modification(byte ValueSeq, string* Value) {
		switch (ValueSeq)
		{
		case 1:
			x1 = str_to_int(Value);
			return TRUE;
		case 2:
			y1 = str_to_int(Value);
			return TRUE;
		case 3:
			x2 = str_to_int(Value);
			return TRUE;
		case 4:
			y2 = str_to_int(Value);
			return TRUE;
		default:
			return FALSE;
		}
	}
};

struct Vector3D {
	float x = 0;
	float y = 0;
	float z = 0;

	Vector3D(float X = 0) :x(X), y(X) ,z(X){}
	Vector3D(float X, float Y, float Z) :x(X), y(Y),z(Z) {}


	//�����±�ȡֵ
	float operator[](byte Seq)const {
		if (Seq < 0 || Seq > 2) {
			Seq = (byte)Valuefilter(2, 0, Seq);
		}
		switch (Seq)
		{
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		default:
			break;
		}
	}

	//������޸ĺ���
	bool Modification(byte ValueSeq, string* Value) {
		switch (ValueSeq)
		{
		case 1:
			x = str_to_int(Value);
			return TRUE;
		case 2:
			y = str_to_int(Value);
			return TRUE;
		case 3:
			z = str_to_int(Value);
			return TRUE;
		default:
			return FALSE;
		}
	}
	Vector3D operator*(Vector3D V1)const {
		Vector3D newV;
		newV.x = x * V1.x;
		newV.y = y * V1.y;
		newV.z = z * V1.z;
		return newV;
	}
	Vector3D operator*(float V1)const {
		Vector3D newV;
		newV.x = x * V1;
		newV.y = y * V1;
		newV.z = z * V1;
		return newV;
	}
	Vector3D operator/(Vector3D V1)const {
		Vector3D newV;
		newV.x = x / V1.x;
		newV.y = y / V1.y;
		newV.z = z / V1.z;
		return newV;
	}
	Vector3D operator/(float V1)const {
		Vector3D newV;
		newV.x = x / V1;
		newV.y = y / V1;
		newV.z = z / V1;
		return newV;
	}
	Vector3D operator+(Vector3D V1)const {
		Vector3D newV;
		newV.x = x + V1.x;
		newV.y = y + V1.y;
		newV.z = z + V1.z;
		return newV;
	}
	Vector3D operator+(float V1)const {
		Vector3D newV;
		newV.x = x + V1;
		newV.y = y + V1;
		newV.z = z + V1;
		return newV;
	}
};

struct Vector2D {
	float x = 0;
	float y = 0;

	Vector2D(float X = 0) :x(X), y(X) {}
	Vector2D(float X, float Y) :x(X), y(Y) {}

	//operator void*() {

	//}


	//�����±�ȡֵ
	float operator[](byte Seq)const {
		if (Seq < 0 || Seq > 1){
			Seq = (byte)Valuefilter(1, 0, Seq);
		}
		switch (Seq)
		{
		case 0:
			return x;
		case 1:
			return y;
		default:
			break;
		}
	}

	//������޸ĺ���
	bool Modification(byte ValueSeq,string* Value) {
		switch (ValueSeq)
		{
		case 1:
			x = str_to_int(Value);
			return TRUE;
		case 2:
			y = str_to_int(Value);
			return TRUE;
		default:
			return FALSE;
		}
	}
	Vector2D operator*(Vector2D V1)const {
		Vector2D newV;
		newV.x = x * V1.x;
		newV.y = y * V1.y;
		return newV;
	}
	Vector2D operator*(float V1)const {
		Vector2D newV;
		newV.x = x * V1;
		newV.y = y * V1;
		return newV;
	}
	Vector2D operator/(Vector2D V1)const {
		Vector2D newV;
		newV.x = x / V1.x;
		newV.y = y / V1.x;
		return newV;
	}
	Vector2D operator/(float V1)const {
		Vector2D newV;
		newV.x = x / V1;
		newV.y = y / V1;
		return newV;
	}
	Vector2D operator+(Vector2D V1)const {
		Vector2D newV;
		newV.x = x + V1.x;
		newV.y = y + V1.y;
		return newV;
	}
	Vector2D operator+(float V1)const {
		Vector2D newV;
		newV.x = x + V1;
		newV.y = y + V1;
		return newV;
	}
	Vector2D operator-(Vector2D V1)const {
		Vector2D newV;
		newV.x = x - V1.x;
		newV.y = y - V1.y;
		return newV;
	}
	Vector2D operator-(float V1)const {
		Vector2D newV;
		newV.x = x - V1;
		newV.y = y - V1;
		return newV;
	}
};

//����������Խṹ��
struct LayoutPropertyList
{
	string name;//���ֽڵ�����

	Vector2D RatioOrigin;//ʵ��ԭ�����꣬���Ͻ�
	Vector2D RatioBorder;//ʵ�ʱ߽����꣬���½�

	Vector2D Origin;//ʵ��ԭ�����꣬���Ͻ�
	Vector2D Border;//ʵ�ʱ߽����꣬���½�

	int Width;//ʵ�����ؿ�
	int Height;//ʵ�����ظ�

	int LayerLevel;//�ڵ�㼶
	int SequenceLevel;//���㼶����
	//void setValue() {}
};
//���ڵ�������Խṹ��
struct NodePropertyList
{
	string name;//���ֽڵ�����

	Vector2D ratio_origin;//ʵ��ԭ�����꣬���Ͻ�
	Vector2D ratio_border;//ʵ�ʱ߽����꣬���½�

	Vector2D origin;//ʵ��ԭ�����꣬���Ͻ�
	Vector2D border;//ʵ�ʱ߽����꣬���½�

	Vector2D Wid_Hei; //ʵ�����ؿ��

	Vector2D layerXY;
	int layer_level;//�ڵ�㼶
	int sequence_level;//���㼶����
	//void setValue() {}
};



struct _DOCINFO
{
	ifstream* File;
	string CharSet="UTF-8";
	unsigned long NumberOfNodes = 0;
	unsigned long long NumberOfChar = 0;
	unsigned long NumberOfLine = 0;
	unsigned int Size_B = 0;
};

