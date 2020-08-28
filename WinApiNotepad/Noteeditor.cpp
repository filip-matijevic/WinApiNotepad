#include <ole2.h>
#include <commctrl.h>
#include "RootWindow.h"

int PASCAL
WinMain(HINSTANCE hinst, HINSTANCE, LPSTR, int nShowCmd)
{
	g_hinst = hinst;
	if (SUCCEEDED(CoInitialize(NULL))) {
		InitCommonControls();
		RootWindow *prw = RootWindow::Create();
		if (prw) {
			ShowWindow(prw->GetHWND(), nShowCmd);
			MSG msg;
			while (GetMessage(&msg, NULL, 0, 0)) {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		CoUninitialize();
	}
	return 0;
}