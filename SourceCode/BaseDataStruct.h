#pragma once
#include"BaseEnum.h"

using namespace std;

float str_to_int(string* str);
int Valuefilter(int MAX, int MIN, int c);
//矩形区域
struct Vector4D {
	int x1;
	int y1;
	int x2;
	int y2;

	//重载下标取值
	int operator[](byte Seq)const {
		if (Seq < 0 || Seq>3) {
			Seq = (byte)Valuefilter(3,0,Seq); 
		}
	}

	//多参数修改函数,只能读取值不能修改值
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


	//重载下标取值
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

	//多参数修改函数
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


	//重载下标取值
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

	//多参数修改函数
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

//布局类的属性结构体
struct LayoutPropertyList
{
	string name;//布局节点名称

	Vector2D RatioOrigin;//实际原点坐标，左上角
	Vector2D RatioBorder;//实际边界坐标，右下角

	Vector2D Origin;//实际原点坐标，左上角
	Vector2D Border;//实际边界坐标，右下角

	int Width;//实际像素宽
	int Height;//实际像素高

	int LayerLevel;//节点层级
	int SequenceLevel;//本层级序列
	//void setValue() {}
};
//树节点类的属性结构体
struct NodePropertyList
{
	string name;//布局节点名称

	Vector2D ratio_origin;//实际原点坐标，左上角
	Vector2D ratio_border;//实际边界坐标，右下角

	Vector2D origin;//实际原点坐标，左上角
	Vector2D border;//实际边界坐标，右下角

	Vector2D Wid_Hei; //实际像素宽高

	Vector2D layerXY;
	int layer_level;//节点层级
	int sequence_level;//本层级序列
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

