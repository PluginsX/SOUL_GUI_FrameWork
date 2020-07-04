#pragma once
#include"SCRIPT_JML.h"
bool InitgraphIsOk = FALSE;
HWND hWnd;
LPRECT WINDOW;
MOUSEMSG MS;


void FlushData(NodeTree* ROOT) {
	
	for (vector<NodeTree*>::iterator iter = (ROOT->SubNodeList).begin();
		iter != (ROOT->SubNodeList).end(); iter++)
	{
		(*iter)->FlushProperty();
		FlushData(*iter);
	}

}

void PAINT(NodeTree* ROOT) {
	//根据根节点尺寸生成画布
	if (!InitgraphIsOk)
	{
		InitgraphIsOk = TRUE;
		initgraph(0, 0); closegraph();//成功解决问题
		initgraph(ROOT->PropertyList.Wid_Hei.x, ROOT->PropertyList.Wid_Hei.y, SHOWCONSOLE);

		hWnd = GetHWnd();
		SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) + WS_SIZEBOX + WS_MAXIMIZEBOX + WS_MAXIMIZE);
		SetWindowPos(hWnd, HWND_TOP, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), SWP_SHOWWINDOW);
	}
	//setlinestyle(PS_NULL, 0);

	BeginBatchDraw();
	for (vector<NodeTree*>::iterator iter = (ROOT->SubNodeList).begin();
		iter != (ROOT->SubNodeList).end(); iter++)
	{
		((GUI_Rectangle*)((*iter)->NodeAddress))->PaintGraphics();
		//Sleep(2000);
		PAINT(*iter);
	}
	EndBatchDraw();
}


