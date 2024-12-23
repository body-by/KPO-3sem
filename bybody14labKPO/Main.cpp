#include "stdafx.h"; //должен включаться самым первым

void printMenu()
{
	cout << "---	Menu list	---" << endl;
	cout << "1. Test geterror & geterrorin" << endl;
	cout << "2. Test getparm" << endl;
	cout << "3. Test getin 1" << endl;
	cout << "4. Test getin 2" << endl;
	cout << "5. Test getlog" << endl;
	cout << "" << endl;
	cout << "h	Call menu list" << endl;
	cout << "q	Exit" << endl;
	cout << "" << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(LC_ALL, "rus");

	char switch_on;

    try
    {
		printMenu();

		while (1) {
			cout << "mode: " << endl;
			cin >> switch_on;

			switch (switch_on)
			{
			case '1':
				//тест geterror & geterrorin
				std::cout << "---	тест Error::geterror	---" << std::endl;
				try { throw ERROR_THROW(100) }
				catch (Error::ERROR e)
				{
					std::cout << "Ошибка " << e.id << ": " << e.message << std::endl;
				};

				std::cout << "----	тест Error::geterrorin	---" << std::endl;
				try { throw ERROR_THROW_IN(111, 7, 7); }
				catch (Error::ERROR e)
				{
					std::cout << "Ошибка " << e.id << ": " << e.message
						<< ", строка " << e.inext.line
						<< ", позиция " << e.inext.col << std::endl << std::endl;
				};

				break;
			case '2':
				cout << "---- тест Parm::getparm	---" << endl << endl;
				try
				{
					Parm::PARM parm = Parm::getparm(argc, argv);
					wcout << "-in:" << parm.in << ", -out:" << parm.out << ", -log:" << parm.log << endl << endl;
				}
				catch (Error::ERROR e)
				{
					cout << "Ошибка " << e.id << ": " << e.message << endl << endl;
					cout << "Ошибка " << e.id << ": " << e.message << ", строка " << e.inext.line << ", позиция " << e.inext.col << endl << endl;
				}

				break;

			case '3':
				cout << "---- тест In::getin	----" << endl << endl;
				try
				{
					Parm::PARM parm = Parm::getparm(argc, argv);
					In::IN in = In::getin(parm.in);
					cout << in.text << endl;
					cout << "Всего символов: " << in.size << endl;
					cout << "Всего строк: " << in.lines << endl;
					cout << "Пропущено: " << in.ignor << endl;
				}
				catch (Error::ERROR e)
				{
					cout << "Ошибка " << e.id << ": " << e.message << endl << endl;
				};

				break;

			case '4':
				cout << "---- тест In::getin	---" << endl << endl;
				try
				{
					Parm::PARM parm = Parm::getparm(argc, argv);
					In::IN in = In::getin(parm.in);
					cout << in.text << endl;
					cout << "Всего символов: " << in.size << endl;
					cout << "Всего строк: " << in.lines << endl;
					cout << "Пропущено: " << in.ignor << endl;
				}
				catch (Error::ERROR e)
				{
					cout << "Ошибка " << e.id << ": " << e.message << endl;
					cout << "строка " << e.inext.line << " позиция " << e.inext.col << endl << endl;
				};
				break;

			case '5':
				Log::LOG log = Log::INITLOG;
				try
				{
					Parm::PARM parm = Parm::getparm(argc, argv);
					log = Log::getlog(parm.log);
					Log::WriteLine(log, (char*)"Тест:", (char*)" без ошибок \n", "");
					Log::WriteLine(log, (wchar_t*)L"Тест:", (wchar_t*)L" без ошибок \n", L"");
					Log::WriteLog(log);
					Log::WriteParm(log, parm);
					In::IN in = In::getin(parm.in);
					Log::WriteIn(log, in);
					Log::Close(log);
				}
				catch (Error::ERROR e)
				{
					Log::WriteError(log, e);
				};
				break;

			case '6':

				break;

			case 'h':
				printMenu();
				break;

			case 'q':
				cout << "Exiting..." << endl;
				return 0;

			default:
				cout << "Invalid input. Please re-enter or press h to get help" << endl;
				break;
			}
		}
    }
    catch(const char* error_message)
	{
		std::cout << error_message << std::endl;
    }

    return 0;
}
