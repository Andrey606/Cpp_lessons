#pragma once

typedef void(*func)(void);

class CATSelectWindow
{
public:
	CATSelectWindow(char * iIdentifier);
	virtual ~CATSelectWindow();

	void setIconPath(char * iconPath);
	void setTitle(char * text);
	void setTopText(char * text);
	void setBottomText(char * text);
	void showWindow(bool show);
	int Build();
	void setSize(int width, int height);

	void subscribe(func tFunk);
	func ptrFunk;

private:
	CATSelectWindow(CATSelectWindow &);
	CATSelectWindow& operator=(CATSelectWindow&);
	MSG msg;
	HWND hwnd;
	HWND hwndParent;
	WNDCLASSEX wc;
	char *className;

	int width, height;
};