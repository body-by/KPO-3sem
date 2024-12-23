#pragma once

#include "stdafx.h"

namespace Log		// –абота с протоколом
{
	struct LOG
	{
		wchar_t logfile[PARM_MAX_SIZE];		// им€ файла протокола
		ofstream* stream;					// выходной поток протокола
	};

	static const LOG INITLOG{ L"", NULL };		// структура дл€ начальной инициализации LOG
	LOG getlog(wchar_t logfile[]);				// сформировать структуру LOG
	void WriteLine(LOG log, char* c, ...);		// вывести в протокол конкатенацию строк
	void WriteLine(LOG log, wchar_t* c, ...);	// вывести в протокол конкатенацию строк
	void WriteLog(LOG log);						// вывести в протокол заголовок
	void WriteParm(LOG log, Parm::PARM parm);	// вывести в протокол информацию о входных параметрах
	void WriteIn(LOG log, In::IN in);			// вывести информацию о входном потоке
	void WriteError(LOG log, Error::ERROR error);	// вывести в проотокол информацию об ошибке
	void Close(LOG log);
};