//#define  __SHOW_CHACKBOX__ //œ‘ æºÏ≤‚øÚ

#include"GraphicManager.h"
#include"EventsManager.h"
#include <MMSystem.h>
#pragma comment(lib, "WINMM.LIB")
using namespace std;

int main() {

	ifstream aa("resource\\layout\\layoutScript.jml");
	Script_JML UILayout01(&aa);
	PAINT(UILayout01.NodeRoot);


	HardwareInputEventDetector EventManage(UILayout01.NodeRoot);
	EventManage.EventCheck();
	

	

	system("pause>nul");
	closegraph();
	return 0;
}