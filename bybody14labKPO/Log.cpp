#define _CRT_SECURE_NO_WARNINGS

#include "stdafx.h"

namespace Log
{
	LOG getlog(wchar_t logfile[])
	{
		LOG log = INITLOG;

		wcscpy_s(log.logfile, logfile);
		log.stream = new ofstream(logfile);

		if (!log.stream)
			throw ERROR_THROW(112);

		return log;
	}

	void WriteLine(LOG log, char* c, ...)
	{
		char** p = &c;

		while (*p != "")
		{
			(*log.stream) << *p;
			p += 1;
		}
	}

	void WriteLine(LOG log, wchar_t* c, ...)
	{
		wchar_t** p = &c;
		char buff[PARM_MAX_SIZE];

		while (*p != L"")
		{
			wcstombs(buff, *p, PARM_MAX_SIZE);
			(*log.stream) << buff;
			p += 1;
		}
	}

	void WriteLog(LOG log)
	{
		char buffer[PARM_MAX_SIZE];

		time_t rawtime;
		struct tm* timeinfo;

		time(&rawtime);

		timeinfo = localtime(&rawtime);

		strftime(buffer, PARM_MAX_SIZE, "����: %d.%m.%y %H:%M:%S", timeinfo);

		(*log.stream) << "--�-	��������	��--	\n" << buffer << "	\n";
	}

	void WriteParm(LOG log, Parm::PARM parm)
	{
		char inInfo[PARM_MAX_SIZE];
		char outInfo[PARM_MAX_SIZE];
		char logInfo[PARM_MAX_SIZE];

		wcstombs(inInfo, parm.in, sizeof(inInfo));
		wcstombs(outInfo, parm.out, sizeof(outInfo));
		wcstombs(logInfo, parm.log, sizeof(logInfo));

		(*log.stream) << "--�-	���������	��--\n"
			<< " -in:	" << inInfo << "\n"
			<< " -out:	" << outInfo << "\n"
			<< " -log:	" << logInfo << "\n";
	}

	void WriteIn(LOG log, In::IN in)
	{
		(*log.stream) << "\n--�-	������� ������	��--\n";
		(*log.stream) << "���������� ��������:" << in.size << "\n";
		(*log.stream) << "����������������:" << in.ignor << "\n";
		(*log.stream) << "���������� �����:" << in.lines << "\n";

	}

	void WriteError(LOG log, Error::ERROR error)
	{
		if (!log.stream->is_open())
		{
			cout << "������ " << error.id << ": " << error.message << "\n";
		}
		else
		{
			(*log.stream) << "\n������ " << error.id << ": " << error.message << " "
				<< "������ " << error.inext.line << ", �������: " << error.inext.col << endl;
		}
	}

	void Close(LOG log)
	{
		log.stream->close();
	}
}