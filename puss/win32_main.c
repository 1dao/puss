// win32_main.c

#ifdef _USE_THIS_MODULE

#pragma warning( disable : 4996 )

#ifndef USE_WINMAIN
	#define proxy_main	main
#endif

#define _WIN32_WINNT 0x0502
#include <Windows.h>
#include <tchar.h>
#include <fcntl.h>
#include <stdio.h>
#include <io.h>

#ifdef _DEBUG
	#define _PUSS_DEBUG_DLL_SUFFIX	L"-d.dll"
#else
	#define _PUSS_DEBUG_DLL_SUFFIX	L".dll"
#endif

#ifdef WIN64
	#define GTK_PUB_PATH	L"\\gtk-x64\\bin\\"
	#define PUSS_DLL_SUFFIX	L"-x64" _PUSS_DEBUG_DLL_SUFFIX
#else
	#define GTK_PUB_PATH	L"\\gtk-x86\\bin\\"
	#define PUSS_DLL_SUFFIX	L"-x86" _PUSS_DEBUG_DLL_SUFFIX
#endif

static void set_3rd_dll_path(void) {
	wchar_t path[8192];
	DWORD i = GetModuleFileNameW(0, path, 8192);
	for( --i; i>0; --i ) {
		if( path[i]==L'\\' || path[i]==L'/' )
			break;
		wcscpy(path+i, GTK_PUB_PATH);
		SetDllDirectoryW(path);
	}
}

typedef int (*PussMain)(int argc, char* argv[]);

int proxy_main(int argc, char* argv[]) {
	HINSTANCE hInstance;
	PussMain puss_main;

	set_3rd_dll_path();

	hInstance = LoadLibraryW(L"modules\\puss\\puss" PUSS_DLL_SUFFIX);
	if( !hInstance ) {
		MessageBoxW(NULL, L"not find puss dll or DLL dependence error", L"Puss Error", MB_ICONERROR);
		return 1;
	}

	puss_main = (PussMain)GetProcAddress(hInstance, "main");
	if( !puss_main ) {
		MessageBoxW(NULL, L"not find main() in puss dll", L"Puss Error", MB_ICONERROR);
		return 1;
	}

	return (*puss_main)(argc, argv);
}


int CALLBACK WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow) {
	int res = 0;

	if( getenv("PUSS_DEBUG")==NULL ) {
		// not flush console window when use spawn() 
		if( nCmdShow != SW_HIDE ) {
			char szApp[4096];
			STARTUPINFOA si;
			PROCESS_INFORMATION pi;
			GetModuleFileNameA(NULL, szApp, sizeof(szApp));
			ZeroMemory(&si, sizeof(STARTUPINFO));
			si.cb			= sizeof(STARTUPINFO);
			si.dwFlags		= STARTF_USESHOWWINDOW;
			si.wShowWindow	= SW_HIDE;
			CreateProcessA(szApp, lpCmdLine, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
			return res;
		}
	}

	AllocConsole();
	ShowWindow(GetConsoleWindow(), SW_SHOW);	// in SW_HIDE mode ignore first ShowWindow 

	*stdin = *_fdopen( _open_osfhandle((long)GetStdHandle(STD_INPUT_HANDLE), _O_TEXT), "r" );
	*stdout = *_fdopen( _open_osfhandle((long)GetStdHandle(STD_OUTPUT_HANDLE), _O_TEXT), "w" );
	*stderr = *_fdopen( _open_osfhandle((long)GetStdHandle(STD_ERROR_HANDLE), _O_TEXT), "w" );

	res = proxy_main(__argc, __argv);

	FreeConsole();

	return res;
}

#endif//_USE_THIS_MODULE

