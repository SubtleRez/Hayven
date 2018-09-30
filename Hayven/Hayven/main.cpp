// Main Window
#include <Windows.h>

// Graphics
#include <wrl.h>
#include <d3d11.h>
#include <dxgi.h>
#pragma comment (lib,"d3d11.lib") 

////////////////
//  Graphics  //
////////////////
static constexpr int ScreenWidth = 800;
static constexpr int ScreenHeight = 600;
bool fullscreen = false;

IDXGISwapChain* swapChain = 0;

void initD3D(HWND& hwnd); // Initilize Graphics Card

void BeginFrame(); // begin new frame to draw to screen
void EndFrame(); // stop current frame and draw to screen

///////////////
//  Windows  //
///////////////
char szClassName[] = "Niice";
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE, 
					LPSTR lpszargument, int)
{
	///////////////////
	// Create Window //
	///////////////////
	HWND hwnd;				// This is the handle for our window
	MSG msg;				// Here messages to the application are saved
	WNDCLASSEX wc;		// Data structure for the windowclass

	// The Window Structure
	wc.hInstance = hThisInstance;
	wc.lpszClassName = szClassName;
	wc.lpfnWndProc = WindowProcedure;	// This function is called by windows
	wc.style = CS_DBLCLKS;				// Catch double-clicks
	wc.cbSize = sizeof(WNDCLASSEX);		// Size in RAM

	// Use default icon and mouse-pointer
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.lpszMenuName = NULL;				// No Menu
	wc.cbClsExtra = 0;					// No extra bytes after the winow class
	wc.cbWndExtra = 0;					// Structure or the window instance
	// Use Window's default colour as the background of the iwndow
	wc.hbrBackground = (HBRUSH)COLOR_BACKGROUND;

	// Reister the window class, and if it fails quit the program
	if (!RegisterClassEx(&wc))
		return 0;

	// The class is registered, let's create the program
	RECT wr = { 0,0,ScreenWidth,ScreenHeight };
	hwnd = CreateWindowEx(
		0,										// Extended possiblites for variation
		"Niice",								// Classname
		"Hayven Engine by Niice",				// Title Text
		WS_OVERLAPPEDWINDOW,					// default window
		CW_USEDEFAULT,							// Windows decides the position
		CW_USEDEFAULT,							// where the window ends up on screen
		wr.right - wr.left,						// the programs width
		wr.bottom - wr.top,						// the programs height
		HWND_DESKTOP,							// The window is a child-window to desktop
		NULL,									// No menu
		hThisInstance,							// Program instance handler
		NULL									// No window creation data
	);
	if (!hwnd) return 0; // Bug Check

	// Make the window visible on the screen
	ShowWindow(hwnd, SW_SHOW);

	// Run the message loop, Itwill run until GetMessage() returns 0
	while (GetMessage(&msg, NULL, 0, 0))
	{
		// Translate virtual-key messages into character messages
		TranslateMessage(&msg);
		// Send message to WindowProcedure
		DispatchMessage(&msg);
	}

	// The program return-value is - The value that PostQuitMessage() gave
	return msg.wParam;

	/////////////////////////////////////////
	// Start Using Graphics Card Functions //
	/////////////////////////////////////////
}

// Windows
LRESULT CALLBACK WindowProcedure(HWND hwnd, // window handle
	UINT  message, // message's code
	WPARAM wParam, // extra
	LPARAM lParam) // extra
{
	switch (message)					// handle the messages
	{
	case WM_DESTROY:					// send a WM_QUIT to the message que
		PostQuitMessage(0);
		break;
	default:							// for messages we dont deal with
		return DefWindowProc(hwnd, message, wParam, lParam);
	}

	return 0;
}

/*
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE ,
					LPSTR lpszargument, int)
{
	MainWindow wnd(hInst);
	while(wnd.ProcessMessage());
}
*/

////////////////
//  Graphics  //
////////////////
/* Create buffer to prevent tearing */
void initD3D(HWND& hwnd)
{
	// Declare swap chain function
	DXGI_SWAP_CHAIN_DESC swapchainDesc;
	ZeroMemory(&swapchainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));

	// Resolution of Back Buffer
	swapchainDesc.BufferDesc.Width = ScreenWidth;
	swapchainDesc.BufferDesc.Height = ScreenHeight;

	// Refresh Rate aka Frames per Second
	swapchainDesc.BufferDesc.RefreshRate.Numerator = 1;
	swapchainDesc.BufferDesc.RefreshRate.Denominator = 60;

	// Pixel format  only has one mode that works
	// (beats me what this does)
	swapchainDesc.BufferDesc.Format = 
		DXGI_FORMAT::DXGI_FORMAT_R8G8B8A8_UNORM;

	// Scan Line order 
	// (I think how it reads the pixel like from top to bottom)
	swapchainDesc.BufferDesc.ScanlineOrdering = 
		DXGI_MODE_SCANLINE_ORDER::DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;

	// Scaling (pretty much for full screen mode)
	swapchainDesc.BufferDesc.Scaling =
		DXGI_MODE_SCALING::DXGI_MODE_SCALING_UNSPECIFIED;

	// Multisampling
	// looks like it's for trying to get a smoother image
	swapchainDesc.SampleDesc.Count = 1;
	swapchainDesc.SampleDesc.Quality = 0; // shrug

	// Buffer Usage
	swapchainDesc.BufferUsage =
		DXGI_USAGE_RENDER_TARGET_OUTPUT;

	// Set number of back buffers
	swapchainDesc.BufferCount = 1;

	// Set output window
	swapchainDesc.OutputWindow = hwnd;
	swapchainDesc.Windowed = true;

	// Swap Effect
	swapchainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

	// Flags (not sure what this does yet)
	swapchainDesc.Flags = 0;
}

/* begin new frame to draw to screen */
void BeginFrame() {}

/* stop current frame and draw to screen */
void EndFrame()
{
	HRESULT hr;
}