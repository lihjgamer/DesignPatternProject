#include "ColorText.h"
#include <stdio.h>
#include <cstdlib>
#include <stdarg.h>
#include <string.h>

#pragma warning(disable:4996)

using namespace std;
#ifdef USE_COLOR_TEXT
	CColorText g_clr_output(out_put_to_console);
#endif


#define MAX_STRING_BUF 1024

CColorText::CColorText()
{
#ifdef WIN32
	 hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#endif

	 type = out_put_to_console;
	 m_pStringBuf = new char[MAX_STRING_BUF];
}

// 构造函数 默认 以 可读/可写/追加 方式打开文件 如果想使用情况方式 可以设置模式为 std::ios::in|std::ios::out|std::ios::trunc 覆盖原有文件
CColorText::CColorText(OutPutType outputtype,const char* filename /*= "log.log"*/,std::ios_base::openmode  opentype /*= std::ios::in|std::ios::out|std::ios::app*/)
{
#ifdef WIN32
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#endif

	type = outputtype;
	if (type == out_put_to_file || type == out_put_to_both)
	{
		m_out_put_file.open(filename,opentype);
	}

	m_pStringBuf = new char[MAX_STRING_BUF];
}

CColorText::~CColorText(void)
{
#ifdef WIN32
	CloseHandle(hConsole);
#endif
	if (type == out_put_to_file || type == out_put_to_both)
	{
		m_out_put_file.close();
	}
	
	if (m_pStringBuf != NULL)
	{
		delete []m_pStringBuf;
		m_pStringBuf = NULL;
	}
}

void CColorText::PrintMsg(int nClrIndex,const char* format,...)
{
	nClrIndex = (nClrIndex < 0 || nClrIndex > DEFAULT_COLOR_MSG) ? DEFAULT_COLOR_MSG : nClrIndex;

	va_list args;
	int     len;

	va_start( args, format );
	len = vsnprintf(NULL, 0, format, args ) + 1;
	vsprintf( m_pStringBuf, format, args ); 

	if (type == out_put_to_file || type == out_put_to_both)
	{
		m_out_put_file.write(m_pStringBuf,len - 1);
		m_out_put_file.flush();
	}
#ifdef WIN32
	// 红绿蓝 黑
	int clrlist[] = {
		12,10,9,7,
	};
	SetConsoleTextAttribute(hConsole,clrlist[nClrIndex]);
	printf("%s",m_pStringBuf);
	SetConsoleTextAttribute(hConsole,clrlist[3]);

#else
	// 红绿蓝 黑
	int clrlist[] = {
		31,32,34,37,
	};
	
	// sprintf 不允许 内存重叠
	char sztemp[1024] = {0};
	sprintf(sztemp,"\033[%d;1m%s\033[0m",clrlist[nClrIndex],m_pStringBuf);
	printf("%s",sztemp);
#endif
}
