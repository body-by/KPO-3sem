#include "stdafx.h"

namespace In 
{
	IN getin(wchar_t infile[])
	{
		IN in{};

		in.size = 0;
		in.lines = 0;
		in.ignor = 0;

		int position = 0; //начинаем с 0 позиции

		unsigned char inText[1024] = "";
		in.text = inText;

		unsigned char inputSymbol;

		ifstream fileInput(infile);
		if (fileInput.fail())
			throw ERROR_THROW(110);

		inputSymbol = fileInput.get();

		while (in.size < IN_MAX_LEN_TEXT) 
		{
			if (fileInput.eof()) 
			{
				in.text[in.size] = '\0';
				break;
			}

			if (inputSymbol == '\n' && in.code['\n'] != IN::F)
			{
				position = -1;
				in.lines++;
			}

			switch (in.code[inputSymbol])
			{
			case IN::T:
				position++;
				in.text[in.size] = inputSymbol;
				in.size++;
				break;
			case IN::F:
				throw ERROR_THROW_IN(111, in.lines, position);
				break;
			case IN::I:
				in.ignor++;
				break;
			default:
				position++;
				in.text[in.size] = in.code[inputSymbol];
				in.size++;
				break;
			}

			inputSymbol = fileInput.get();
		}
		
		fileInput.close();

		return in;
	}
}