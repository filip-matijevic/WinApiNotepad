#include "RootWindow.h"

LRESULT RootWindow::HandleMessage(
	UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {
	case WM_CREATE:
		return OnCreate();
	case WM_NCDESTROY:
		// Death of the root window ends the thread
		PostQuitMessage(0);
		break;
	case WM_SIZE:
		if (m_hwndChild) {
			SetWindowPos(m_hwndChild, NULL, 0, 0,
				GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam),
				SWP_NOZORDER | SWP_NOACTIVATE);
		}
		return 0;
	case WM_SETFOCUS:
		if (m_hwndChild) {
			SetFocus(m_hwndChild);
		}
		return 0;
	}
	return Window::HandleMessage(uMsg, wParam, lParam);
}
RootWindow *RootWindow::Create()
{
	RootWindow *self = new RootWindow();
	if (self && self->WinCreateWindow(0,
		TEXT("Scratch"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL)) {
		return self;
	}
	delete self;
	return NULL;
}


LRESULT RootWindow::OnCreate()
{
	OutputDebugString("Created a window and set its focus!\n");
	textView = TextView::Create(m_hwnd);
	m_hwndChild = textView->GetHWND();
	return 0;
}