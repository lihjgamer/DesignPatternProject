#pragma once

#ifdef WIN32
#include <Windows.h>
#endif
#include <fstream>


// 功能开关 取消定义则不输出
#define USE_COLOR_TEXT


#define RED_COLOR_MSG		0	// 红色
#define GREEN_COLOR_MSG		1	// 绿色
#define BLUE_COLOR_MSG		2	// 蓝色
#define DEFAULT_COLOR_MSG	3	// 白色

typedef enum{
	out_put_to_console,
	out_put_to_file,
	out_put_to_both,
}OutPutType;


class CColorText
{
public:
	void PrintMsg(int nClrIndex,const char* format,...);

private:

	OutPutType type;
	std::fstream m_out_put_file;
	char *       m_pStringBuf;
#ifdef WIN32
	HANDLE hConsole;
#endif

public:
	CColorText();
	CColorText(OutPutType outputtype,const char* filename = "log.log",std::ios_base::openmode  = std::ios::in|std::ios::out|std::ios::app);

	virtual ~CColorText(void);
};

#ifdef USE_COLOR_TEXT
extern CColorText g_clr_output;
#define PrintColorMsg g_clr_output.PrintMsg

#define PrintRedMsg(format,...) g_clr_output.PrintMsg(RED_COLOR_MSG,format,##__VA_ARGS__)
#define PrintBlueMsg(format,...) g_clr_output.PrintMsg(BLUE_COLOR_MSG,format,##__VA_ARGS__)
#define PrintGreenMsg(format,...) g_clr_output.PrintMsg(GREEN_COLOR_MSG,format,##__VA_ARGS__)
#define PrintDefaultMsg(format,...) g_clr_output.PrintMsg(DEFAULT_COLOR_MSG,format,##__VA_ARGS__)

#else
#define PrintColorMsg(...)

#define PrintRedMsg(format,...) //g_clr_output.PrintMsg(RED_COLOR_MSG,format,##__VA_ARGS__)
#define PrintBlueMsg(format,...) //g_clr_output.PrintMsg(BLUE_COLOR_MSG,format,##__VA_ARGS__)
#define PrintGreenMsg(format,...) //g_clr_output.PrintMsg(GREEN_COLOR_MSG,format,##__VA_ARGS__)
#define PrintDefaultMsg(format,...) //g_clr_output.PrintMsg(DEFAULT_COLOR_MSG,format,##__VA_ARGS__)
#endif

