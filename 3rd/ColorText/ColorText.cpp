#include "ColorText.h"
#include <stdio.h>
#include <cstdlib>
#include <stdarg.h>
#include <string.h>

using namespace std;
#ifdef USE_COLOR_TEXT
	CColorText g_clr_output;
#endif

CColorText::CColorText(void)
{
#ifdef WIN32
	 hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#endif

	 type = out_put_to_file;
	 if (type == out_put_to_file || type == out_put_to_both)
	 {
		 m_out_put_file.open("log.log",ios::out);
	 }

	 m_pStringBuf = new char[1024];
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
		free(m_pStringBuf);
		m_pStringBuf = NULL;
	}
}

void CColorText::PrintMsg(int nClrIndex,const char* format,...)
{
	if(nClrIndex < 0 || nClrIndex >= 4)
	{
		return;
	}

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
	// ºìÂÌÀ¶ ºÚ
	int clrlist[] = {
		12,10,9,7,
	};
	SetConsoleTextAttribute(hConsole,clrlist[nClrIndex]);
	printf("%s",m_pStringBuf);
	SetConsoleTextAttribute(hConsole,clrlist[3]);

#else
	// ºìÂÌÀ¶ ºÚ
	int clrlist[] = {
		31,32,34,37,
	};
	
	// sprintf ²»ÔÊÐíÄÚ´æÖØµþ  // Modified By lihj 2015-10-10 12:09:09
	sprintf(m_pStringBuf,"\033[%dm%s\033[0m\n",clrlist[nClrIndex],m_pStringBuf);
	printf("%s",m_pStringBuf);

#endif 
}
