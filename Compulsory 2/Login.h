
void login();

//-----------------------------------------------------------------------------------------------------------------

void login() {

	string password{"Casino"};
	string passwordGuess{};
	int strike{};
	int sleepTime{500};

	for (size_t i = 0; i < 1;)
	{
		system("cls");
		cout << "*-*-*-*-*-*-*-*-*-*-*" << endl;
		cout << endl;
		cout << "  Enter the Casino " << endl;
		cout << endl;
		cout << "*-*-*-*-*-*-*-*-*-*-*" << endl;
		cout << endl;
		cout << "Password: ";

		cin >> passwordGuess;
		if (password == passwordGuess)
		{
			system("cls");
			cout << "*-*-*-*-*-*-*-*-*-*-*" << endl;
			cout << endl;
			cout << "      Correct! " << endl;
			cout << endl;
			cout << "*-*-*-*-*-*-*-*-*-*-*" << endl;
			Sleep(sleepTime*2);

			system("cls");
			cout << "*-*-*-*-*-*-*-*-*-*-*" << endl;
			cout << endl;
			cout << "   Welcome aboard! " << endl;
			cout << endl;
			cout << "*-*-*-*-*-*-*-*-*-*-*" << endl;
			Sleep(sleepTime*2);

			system("cls");
			i++;
		}
		else
		{
			system("cls");
			cout << "*-*-*-*-*-*-*-*-*-*-*" << endl;
			cout << endl;
			cout << "        Wrong! " << endl;
			cout << endl;
			cout << "*-*-*-*-*-*-*-*-*-*-*" << endl;
			strike += 1;
			Sleep(sleepTime);
		}

		if (strike >= 3)
		{
			system("cls");
			cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
			cout << "Self "; Sleep(sleepTime);
			cout << "destruct "; Sleep(sleepTime);
			cout << "system "; Sleep(sleepTime);
			cout << "activated"; Sleep(sleepTime);
			cout << "."; Sleep(sleepTime / 2);
			cout << "."; Sleep(sleepTime / 2);
			cout << "."; Sleep(sleepTime / 2);
			exit(0);
		}
	}
}