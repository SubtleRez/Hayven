#include <windows.h>

// Declare Windows Procedure
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

// Make the class name into a global variable
char szClassName[] = "CodeBlocksWindowsApp";

int WINAPI WinMain(HINSTANCE hThisInstance,
					HINSTANCE hPrevInstance,
					LPSTR lpszargument,
					int nCmdShow)
{
	HWND hwnd;				// This is the handle for our window
	MSG msg;				// Here messages to the application are saved
	WNDCLASSEX wincl;		// Data structure for the windowclass

	// The Window Structure
	wincl.hInstance = hThisInstance;
	wincl.lpszClassName = szClassName;
	wincl.lpfnWndProc = WindowProcedure;	// This function is called by windows
	wincl.style = CS_DBLCLKS;				// Catch double-clicks
	wincl.cbSize = sizeof(WNDCLASSEX);

	// Use default icon and mouse-pointer
	wincl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wincl.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wincl.hCursor = LoadCursor(NULL, IDC_ARROW);
	wincl.lpszMenuName = NULL;				// No Menu
	wincl.cbClsExtra = 0;					// No extra bytes after the winow class
	wincl.cbWndExtra = 0;					// Structure or the window instance
	// Use Window's default colour as the background of the iwndow
	wincl.hbrBackground = (HBRUSH)COLOR_BACKGROUND;

	// Reister the window class, and if it fails quit the program
	if (!RegisterClassEx(&wincl))
		return 0;

	// The class is registered, let's create the program
	hwnd = CreateWindowEx(
		0,										// Extended possiblites for variation
		szClassName,							// Classname
		"Hayven Engine by Niice",				// Title Text
		WS_OVERLAPPEDWINDOW,					// default window
		CW_USEDEFAULT,							// Windows decides the position
		CW_USEDEFAULT,							// where the window ends up on screen
		800,									// the programs width
		600,									// the programs height
		HWND_DESKTOP,							// The window is a child-window to desktop
		NULL,									// No menu
		hThisInstance,							// Program instance handler
		NULL									// No window creation data
	);

	// Make the window visible on the screen
	ShowWindow(hwnd, nCmdShow);

	// Run the message loop, Itwill run until GetMessage() returns 0
	while (GetMessage(&msg, NULL, 0, 0))
	{
		// Translate virtual-key messages into character messages
		TranslateMessage(&msg);
		// Send message to tWindowProcedure
		DispatchMessage(&msg);
	}

	// The program return-value is - The value that PostQuitMessage() gave
	return msg.wParam;
}

// This function is called by the Winows funciton DispatchMessage()
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT  message, WPARAM wParam, LPARAM lParam)
{
	switch (message)					// handle the messages
	{
	case WM_DESTROY:
		PostQuitMessage(0);				// send a WM_QUIT to the message que
		break;
	default:							// for messages we dont deal with
		return DefWindowProc(hwnd, message, wParam, lParam);
	}

	return 0;
}