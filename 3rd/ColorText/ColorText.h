#pragma once

#ifdef WIN32
#include <Windows.h>
#endif
#include <fstream>


#define USE_COLOR_TEXT

#define RED_COLOR_MSG		0	
#define GREEN_COLOR_MSG		1	
#define BLUE_COLOR_MSG		2	
#define DEFAULT_COLOR_MSG	3	

class CColorText
{
public:
	void PrintMsg(int nClrIndex,const char* format,...);
	
public:
	CColorText(void);
	~CColorText(void);

	typedef enum{
		out_put_to_console,
		out_put_to_file,
		out_put_to_both,
	}OutPutType;
private:


	OutPutType type;
	std::fstream m_out_put_file;
	char *       m_pStringBuf;
#ifdef WIN32
	HANDLE hConsole;
#endif
};

#ifdef USE_COLOR_TEXT
extern CColorText g_clr_output;
#define PrintColorMsg g_clr_output.PrintMsg
#else
#define PrintColorMsg(...)
#endif
