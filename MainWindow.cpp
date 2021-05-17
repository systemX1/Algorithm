#include "MainWindow.h"

void MainWindow::init()
{
	string input;

	fmt::print(
		"┌{0:─^{2}}┐\n"
		"│{1: ^{2}}│\n"
		"└{0:─^{2}}┘\n", "", "HashTable", 40);

	while (input != string("#")) {
		printLine(string("Main Menu"));
		fmt::print("\t\t{:<30}{:<30}\n"
			"\t\t{:<30}{:<30}\n"
			"\t\t{:<30}{:<30}\n"
			"\t\t{:<30}{:<30}\n"
			"\t\t{:<30}{:<30}\n"
			"\t\t{:<30}{:<30}\n",
			"0 - Insert HashMap", "1 - Show HashMap",
			"2 - Search from HashMap", "3 - Delete from HashMap",
			"4 - Insert HashTable", "5 - Show HashTable",
			"6 - Search from HashTable", "7 - Delete from HashTable",
			"t+number - Run Test", "h - Help",
			"# - quit", "r - reset all"
		);
		
		map<string, function<void()>> func = {
			{ string("0"), [this] { insertHashMap(); } },
			{ string("1"), [this] { showHashMap(); } },
			{ string("2"), [this] { searchHashMap(); } },
			{ string("3"), [this] { deleteHashMap(); } },
			{ string("4"), [this] { insertHashTable(); } },
			{ string("5"), [this] { showHashTable(); } },
			{ string("6"), [this] { searchHashTable(); } },
			{ string("7"), [this] { deleteHashTable(); } },
			{ string("h"), [this] { printHelp(); } },
			{ string("r"), [this] { resetAll(); } },
			{ string("t1"), [this] { test1(); } },
			{ string("t2"), [this] { test2(); } },
			{ string("t3"), [this] { test3(); } },
			{ string("t4"), [this] { test4(); } },
			{ string("t5"), [this] { test5(); } },
			{ string("t6"), [this] { test6(); } },
			{ string("t7"), [this] { test7(); } },
			{ string("t8"), [this] { test8(); } },
			{ string("t9"), [this] { test9(); } },
			{ string("t10"), [this] { test10(); } },
			{ string("t11"), [this] { test11(); } },
			{ string("t12"), [this] { test12(); } },
		};
		
		cin >> input;

		if (input == string("#"))
			break;
		else if(func.find(input) == func.end())
			fmt::print("Invalid Input in Main Menu\n"); 
		else
			func[input]();
		
	}
	fmt::print("\n");
	system("pause");
}

void MainWindow::insertHashMap()
{
	printLine(string("Insert HashMap"));
	string in;
	int idx = static_cast<int>(hashmap.getSize() );
	while (true)
	{
		idx++;
		cin >> in;
		if (in == string("#"))
			break;
		hashmap.insert(std::stoi(in), idx);
		hashmap.printTable();
	}
}

void MainWindow::showHashMap() const
{
	printLine(string("Show HashMap"));
	hashmap.printTable();
}

void MainWindow::searchHashMap() const
{
	printLine(string("Search HashMap"));
	string in;
	int idx = static_cast<int>(hashmap.getSize());
	while (true)
	{
		idx++;
		cin >> in;
		if (in == string("#"))
			break;

		basic_string<char> s;
		auto i = hashmap.find(std::stoi(in));
		fmt::print("key {}:\t{} {} {}\n", std::stoi(in), s, i == -1 ? "not exists" : "found", i);
	}
}

void MainWindow::deleteHashMap()
{
	printLine(string("Delete HashMap"));
	string in;
	int idx = static_cast<int>(hashmap.getSize());
	while (true)
	{
		idx++;
		cin >> in;
		if (in == string("#"))
			break;

		hashmap.deleteElem(std::stoi(in));
		hashmap.printTable();
	}
}

void MainWindow::insertHashTable()
{
	printLine(string("Insert HashTable"));
	string in;
	int idx = static_cast<int>(hashtable.getSize());
	while (true)
	{
		idx++;
		cin >> in;
		if (in == string("#"))
			break;
		hashtable.insert(in);
		hashtable.printTable();
	}
}

void MainWindow::showHashTable() const
{
	printLine(string("Show HashTable"));
	hashtable.printTable();
}

void MainWindow::searchHashTable() const
{
	printLine(string("Search HashTable"));
	string in;
	int idx = static_cast<int>(hashtable.getSize());
	while (true)
	{
		idx++;
		cin >> in;
		if (in == string("#"))
			break;

		auto prev = hashtable.find(in);
		fmt::print("key {}:\t{}\n",in, prev == nullptr ? "not exists" : "found");
	}
}

void MainWindow::deleteHashTable()
{
	printLine(string("Delete HashTable"));
	string in;
	int idx = static_cast<int>(hashtable.getSize());
	while (true)
	{
		idx++;
		cin >> in;
		if (in == string("#"))
			break;

		hashtable.deleteElem(in);
		hashtable.printTable();
	}
}

void MainWindow::testText(int test_num) const
{
	printLine(string("Run Test" + std::to_string(test_num)));
}

void MainWindow::test1()
{
	testText(1);

	hashmap.reset();
	for (int i = 1; i <= 50; i++)
	{
		hashmap.insert(5, i);
	}
	hashmap.printTable();
}

void MainWindow::test2()
{
	testText(2);

	hashmap.printList(18, 20);
	fmt::print("\n");

	hashmap.reset();
	for (int i = 1; i <= 10; i++)
	{
		hashmap.insert(18, i);
	}
	hashmap.printTable();

	for (int i = 1; i <= 10; i++)
	{
		if (i == 6)
			hashmap.printTable();
		hashmap.deleteElem(18);
	}
	hashmap.printTable();

	hashmap.reset();
	for (int i = 1; i <= 10; i++)
	{
		hashmap.insert(18, i);
	}
	hashmap.printTable();
}

void MainWindow::test3()
{
	testText(3);

	fmt::print("\n");

	hashmap.reset();
	for (int i = 30; i <= 40; i++)
	{
		hashmap.insert(i, i);
	}
	hashmap.printTable();

	for (int i = 30; i <= 40; i++)
	{
		hashmap.deleteElem(i);
	}
	hashmap.printTable();

}

void MainWindow::test4()
{
	testText(4);
	
	hashmap.reset();
	hashmap.insert(18, 1);
	hashmap.insert(18, 2);
	hashmap.insert(18, 3);
	hashmap.printTable();
	
	auto i = hashmap.find(18);
	fmt::print("\tkey 18: {}\n", i == -1 ? "not exists" : "found");
	i = hashmap.find(5);
	fmt::print("\tkey 5: {}\n", i == -1 ? "not exists" : "found");
	i = hashmap.find(6);
	fmt::print("\tkey 6: {}\n", i == -1 ? "not exists" : "found");

	hashmap.deleteElem(18);
	hashmap.deleteElem(5);
	hashmap.printTable();
	
	hashmap.insert(6, 4);
	hashmap.insert(5, 5);
	hashmap.printTable();

	hashmap.deleteElem(34);
	hashmap.deleteElem(5);
	hashmap.printTable();

	i = hashmap.find(18);
	fmt::print("\tkey 18: {}\n", i == -1 ? "not exists" : "found");
}

void MainWindow::test5()
{
	testText(5);
}

void MainWindow::test6()
{
	testText(6);

	hashtable.reset(13);

	vector<string> insertData = { "AA", "AB", "AC", "AD", "ZA" };
	vector<string> searchData = { "AA", "AB", "AC", "AD", "AE", "BB", "ZZ" };
	vector<string> deleteData = { "AB", "AA", "AD", "AC" };

	for(const auto& i : insertData)
	{
		hashtable.insert(i);
		fmt::print("insert {}\n", i);
	}
	hashtable.printTable();
	
	for (const auto& i : searchData)
	{
		auto prev = hashtable.find(i);
		fmt::print("key {}:\t{}\n", i, prev == nullptr ? "not exists" : "found");
	}
	
	for (const auto& i : deleteData)
	{
		hashtable.deleteElem(i);
		fmt::print("delete {}\n", i);
		hashtable.printTable();
	}

	insertData.pop_back();

	for (const auto& i : insertData)
	{
		hashtable.insert(i);
		fmt::print("insert {}\n", i);
	}
	hashtable.printTable();

	for (const auto& i : searchData)
	{
		auto prev = hashtable.find(i);
		fmt::print("key {}:\t{}\n", i, prev == nullptr ? "not exists" : "found");
	}

	for (const auto& i : deleteData)
	{
		hashtable.deleteElem(i);
		fmt::print("delete {}\n", i);
		hashtable.printTable();
	}
}

void MainWindow::test7()
{
	testText(7);

	hashtable.reset(13);

	vector<string> insertData = { "AA", "BA", "CA", "AB", "AC" };
	vector<string> searchData = { "AA", "BA", "CA", "AB", "AC", "BB", "ZZ" };
	vector<string> deleteData = { "AA", "BA", "FF", "AD" };

	for (const auto& i : insertData)
	{
		hashtable.insert(i);
		fmt::print("insert {}\n", i);
	}
	hashtable.printTable();

	for (const auto& i : searchData)
	{
		auto prev = hashtable.find(i);
		fmt::print("key {}:\t{}\n", i, prev == nullptr ? "not exists" : "found");
	}

	for (const auto& i : deleteData)
	{
		hashtable.deleteElem(i);
		fmt::print("delete {}\n", i);
		hashtable.printTable();
	}

	for (const auto& i : searchData)
	{
		auto prev = hashtable.find(i);
		fmt::print("key {}:\t{}\n", i, prev == nullptr ? "not exists" : "found");
	}
}

void MainWindow::test8()
{
	testText(8);
}

void MainWindow::test9()
{
	testText(9);

}

void MainWindow::test10()
{
	testText(10);
}

void MainWindow::test11()
{
	testText(11);

	
}

void MainWindow::test12()
{
	testText(12);

	pair<int, int> pa(1, 1);
	auto ptr = make_shared<pair<int, int> >(pa);
	
	fmt::print("{}\n", *ptr);
	
	sy::point p = { 1000, 2000 };
	fmt::print("{}\n", fmt::format("{}", p));
	sy::pointer<int> mp = { 100, 200 };
	fmt::print("{}\n", fmt::format("{:>12}", mp));
	auto s = fmt::format("({}, {})", p.x, p.y);
	fmt::print("{}\n", s);
}

void MainWindow::printHelp() const
{
	printLine(string("Help"));
	fmt::print(
		"┌{0:─^{1}}┐\n"
		"│{2: ^{1}}│\n"
		"│{3: ^{1}}│\n"
		"│{4: ^{1}}│\n"
		"└{0:─^{1}}┘\n", 
		"", 40, 
		"Data Structures and Algorithms II", 
		"Hashing with quadratic probing", 
		"Hashing with separate chaining");

}

void MainWindow::resetAll()
{
	printLine(string("Reset"));

	fmt::print("{}\n", "input new divisor");
	int in = 13;
	cin >> in;
	hashmap.reset(in);
	hashtable.reset(in);
	
	fmt::print("\tResetting...\n\n");
	Sleep(800);
	system("cls");
	fmt::print(
		"┌{0:─^{2}}┐\n"
		"│{1: ^{2}}│\n"
		"└{0:─^{2}}┘\n", "", "HashTable", 40);
}

void MainWindow::printLine(const string& s)
{
	fmt::print("__________________________________________________________________\n");
	// ReSharper disable once CppLocalVariableMayBeConst
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(handle, &csbiInfo);
	const WORD wOldColorAttrs = csbiInfo.wAttributes;

	SetConsoleTextAttribute(handle,
		BACKGROUND_RED |
		BACKGROUND_GREEN |
		BACKGROUND_BLUE |
		BACKGROUND_INTENSITY
	);
	
	fmt::print("{}", s.c_str());
	
	SetConsoleTextAttribute(handle,
		wOldColorAttrs);

	fmt::print("\n");
	
	//fmt::print("{}\n", s.c_str());
	//fmt::print("\033[7m{}\033[m\n", s.c_str());
	//fmt::print(fg(fmt::color::floral_white) | bg(fmt::color::slate_gray), "{}\n", s.c_str());
}

bool MainWindow::isStringDigital(const string& s)
{
	const std::regex rex("^-?[0-9]+$");
	return std::regex_match(s.begin(), s.end(), rex);
}

