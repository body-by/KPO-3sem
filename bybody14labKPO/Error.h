#pragma once

#define ERROR_THROW(id) Error::geterror(id);
#define ERROR_THROW_IN(id, l, c) Error::geterrorin(id, l, c); //ERROR_THROW(id, line, colum)
#define ERROR_ENTRY(id, m) {id, m, {-1, -1}} //Элемент таблицы ошибок
#define ERROR_MAXSIZE_MESSAGE 200
#define ERROR_ENTRY_NODEF(id)		ERROR_ENTRY(-id, "Неопределенная ошибка") // 1 неопределеный элемент в таблице ошибок
//ERROR_ENTRY_NODEF10(id) - 10 неопределенных элеменетов таблицы ошибок
#define ERROR_ENTRY_NODEF10(id)		ERROR_ENTRY_NODEF(id+0), ERROR_ENTRY_NODEF(id+1), ERROR_ENTRY_NODEF(id+2), ERROR_ENTRY_NODEF(id+3), \
									ERROR_ENTRY_NODEF(id+4), ERROR_ENTRY_NODEF(id+5), ERROR_ENTRY_NODEF(id+6), ERROR_ENTRY_NODEF(id+7), \
									ERROR_ENTRY_NODEF(id+8), ERROR_ENTRY_NODEF(id+9)
//ERROR_ENTRY_NODEF100(id) - 100 неопределенных элеменетов таблицы ошибок
#define ERROR_ENTRY_NODEF100(id)	ERROR_ENTRY_NODEF10(id+0), ERROR_ENTRY_NODEF10(id+10), ERROR_ENTRY_NODEF10(id+20), ERROR_ENTRY_NODEF10(id+30), \
									ERROR_ENTRY_NODEF10(id+40), ERROR_ENTRY_NODEF10(id+50), ERROR_ENTRY_NODEF10(id+60), ERROR_ENTRY_NODEF10(id+70), \
									ERROR_ENTRY_NODEF10(id+80), ERROR_ENTRY_NODEF10(id+90)
#define ERROR_MAX_ENTRY 1000 //количество элемнетов в таблице ошибок

namespace Error
{
	struct ERROR	// тип исключения для throw ERROR_THROW | ERROR_THROW_IN и catch(ERROR)
	{
		int id;								   // код ошибки
		char message[ERROR_MAXSIZE_MESSAGE];   // сообщение об ошибке

		struct IN							   // расширение для ошибок при обработке входных данных
		{
			short line;						   // номер строки (0, 1, 2, 3, ...)
			short col;						   // номер позиции в строке (0, 1, 2, 3, ...)
		} inext;
	};

	ERROR geterror(int id);						  // сформировать ERROR для ERROR_THROW
	ERROR geterrorin(int id, int line, int col);  // сформировать ERROR для ERROR_THROW_IN
};