#include "stdafx.h"

namespace Parm
{
	//struct PARM
	//{
	//	wchar_t in[PARM_MAX_SIZE];	// -in:		��� ����� ��������� ����
	//	wchar_t out[PARM_MAX_SIZE];	// -out:	��� ����� ��������� ����
	//	wchar_t log[PARM_MAX_SIZE];	// -log:	��� ����� ���������
	//};

	/*
		wcscpy_s - ����������� ������ ������� ��������
		wcsncat_s - ������������ ���� ����� ������� ��������  
		wcslen - ���������� ����� ������ ������� �������  
		wcsstr - ����� ��������� � ������ ������� ���������  

	*/

	PARM getparm(int argc, _TCHAR* argv[])
	{
		PARM parm{};

		bool hasIN = false;
		bool hasOUT = false;	
		bool hasLOG = false;

		for (int i = 0; i < argc; i++)
		{
			if (wcsstr(argv[i], PARM_IN))
				hasIN = true;
			if (wcsstr(argv[i], PARM_OUT))
				hasOUT = true;
			if (wcsstr(argv[i], PARM_LOG))
				hasLOG = true;
		}

		if (hasIN == false)
			throw ERROR_THROW(100);

		for (int i = 0; i < argc; i++) 
		{
			if (wcslen(argv[i]) > PARM_MAX_SIZE)
				throw ERROR_THROW(104);

			if (wcsstr(argv[i], PARM_IN)) 
				wcscpy_s(parm.in, wcsstr(argv[i], L":") + 1 ); //��������� ������� ����� �������� ����� ������ ����������� �� ���������

			if (wcsstr(argv[i], PARM_OUT))
				wcscpy_s(parm.out, wcsstr(argv[i], L":") + 1);

			if (wcsstr(argv[i], PARM_LOG))
				wcscpy_s(parm.log, wcsstr(argv[i], L":") + 1);
		}

		if (hasOUT == false) {
			wcscpy_s(parm.out, parm.in);
			wcscat_s(parm.out, PARM_OUT_DEFAULT_EXT);
		}

		if (hasLOG == false) {
			wcscpy_s(parm.log, parm.in);
			wcscat_s(parm.log , PARM_LOG_DEFAULT_EXT);
		}

		return parm;
	}
} 