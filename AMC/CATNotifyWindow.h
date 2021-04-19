#pragma once

class CATNotifyWindow
{
public:
	CATNotifyWindow(char * iIdentifier);
	virtual ~CATNotifyWindow();

	void setIconPath(char * iconPath);
	void setTitle(char * text);
	void setTopText(char * text);
	void setBottomText(char * text);
	void showWindow(bool show);
	int Build();
	void setSize(int width, int height);

private:
	CATNotifyWindow(CATNotifyWindow &);
	CATNotifyWindow& operator=(CATNotifyWindow&);
	MSG msg;
	HWND hwnd;
	HWND hwndParent;
	WNDCLASSEX wc;
	char *className;

	int width, height;
};