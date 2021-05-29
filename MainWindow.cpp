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
			{ string("s1"), [this] { insertSort(); } },
			{ string("s2"), [this] { quickSort(); } },
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

	vector<int> va = { 1,3,5,7 };
	vector<int> vb = { 0,1,3,3,7 };
	vector<int> vc = { -1,1,3,5,7 };
	vector<int> vd = { 0,2,2,4,5 };
	
	auto f = [](vector<int>& a, vector<int>& b, vector<int>& c) -> void {
		if (a.empty() || b.empty() || c.empty()) {
			fmt::print("Invalid data\n");
			return;
		}

		size_t i = 0, j = 0, k = 0;
		int* ret = nullptr;
		while (i < a.size() && j < b.size() && k < c.size()) {
			if (a[i] < b[j]) i++;
			else if (b[j] < c[k]) j++;
			else if (c[k] < a[i]) k++;
			else {
				ret = &a[i];
				break;
			}
		}
		fmt::print("Min common elem: {}\n", ret == nullptr ? "Not found" : std::to_string(*ret));
	};

	f(va, vb, vc);
	f(va, vc, vd);
	f(vb, vc, vd);
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
	Sleep(600);
	system("cls");
	fmt::print(
		"┌{0:─^{2}}┐\n"
		"│{1: ^{2}}│\n"
		"└{0:─^{2}}┘\n", "", "HashTable", 40);
}

void MainWindow::insertSort()
{
	printLine(string("insertSort"));

	auto t_begin = std::chrono::system_clock::now();
	

	vector<int> data_v = { 0, 4, 6, 8, -4, 2, 0, 4, 3, 10, 24 };

	for(const auto& i : data_v) {
		fmt::print("{:<3} ", i);
	}
	fmt::print("\n");
	
	auto insertSort = [](vector<int>& data) -> void {
		size_t i = 0, j = 0, n = data.size();
		for (i = 2; i < n; i++) {
			if(data[i] < data[i-1]) {
				data[0] = data[i];
				for(j = i - 1; data[0] < data[j]; j--) {
					data[j + 1] = data[j];
				}
				data[j + 1] = data[0];
			}

			for (const auto& ie : data) {
				fmt::print("{:<3} ", ie);
			}
			fmt::print("\n");
		}
	};

	insertSort(data_v);


	auto t_end = std::chrono::system_clock::now();
	std::chrono::duration<double, std::milli> fp_ms = t_end - t_begin;
	fmt::print("duration:{:>10}\n", fp_ms.count());
}


void MainWindow::quickSort()
{
	printLine(string("quickSort"));

	sy::random<int> dice;
	auto data_v = dice(20, 0, 50);
	auto data_v_plus = data_v;
	
	auto partition = [](vector<int>& data, int low, int high) -> int {
		int pivot = data[low];
		while (low < high) {
			while (low < high && data[high] >= pivot) {
				--high;
			}
			data[low] = data[high];
			while (low < high && data[low] <= pivot) {
				++low;
			}
			data[high] = data[low];
		}
		data[low] = pivot;
		return low;
	};
	
	function<void(vector<int>&, int, int)> quickSort = [&](vector<int>& data, int low, int high) {
		if(low < high) {
			int pivotPos = partition(data, low, high);
			quickSort(data, low, pivotPos - 1);
			quickSort(data, pivotPos + 1, high);
		}
	};

	auto swap = [&](int& a, int& b) {
		auto tmp = a;
		a = b;
		b = tmp;
	};

	auto getPivot = [](int first, int mid, int last) -> int {
		if ((first >= mid && first <= last) || (first <= mid && first >= last))
			return first;
		else if ((mid >= first && mid <= last) || (mid <= first && mid >= last))
			return mid;
		else
			return last;
	};

	auto partition_plus = [&](vector<int>& data, int low, int high, bool& isOrdered) -> int {
		int pivotPos = getPivot(low, (low + high) / 2, high);
		swap(data[pivotPos], data[low]);
		int pivot = data[low];
		
		while (low < high) {
			while (low < high && data[high] >= pivot) {
				isOrdered = false;
				--high;
			}
			data[low] = data[high];
			while (low < high && data[low] <= pivot) {
				isOrdered = false;
				++low;
			}
			data[high] = data[low];
		}
		data[low] = pivot;
		
		return low;
	};

	auto tinySort = [&](vector<int>& data, int left, int right) {
		
		if (right - left == 1) {
			if (data[left] > data[right]) {
				swap(data[left], data[right]);
			}
		}
		else {
			if (data[left] > data[left + 1])
				swap(data[left], data[left + 1]);
			if (data[left + 1] > data[right])
				swap(data[left + 1], data[right]);
			if (data[left] > data[left + 1])
				swap(data[left], data[left + 1]);
		}
	};
	
	auto quickSort_plus = [&](vector<int>& data) {
		bool isOrdered = false;             ///标记，用来判断是否已经排好序(未发生过交换)
		int low = 0;
		int high = static_cast<int>(data_v.size()) - 1;
		stack<int> st;
		if (low < high) {
			//如果序列小于等于3个元素
			if (high - low < 3) {
				tinySort(data, low, high);
				return;
			}

			int boundary = partition_plus(data, low, high, isOrdered);   //划分后的中枢所在位置

			if (isOrdered == true)
				return;

			//如果左分区比右分区短
			if (boundary - low < high - boundary) {
				//判断右分区是否存在
				if (boundary + 1 < high) {
					st.push(boundary + 1);
					st.push(high);
				}
				//判断左分区是否存在
				if (boundary - 1 > low) {
					//将左分区端点后入栈以便优先排序
					st.push(low);
					st.push(boundary - 1);
				}
			}
			//如果右分区比左分区短
			else {
				//判断左分区是否存在
				if (boundary - 1 > low) {
					st.push(low);
					st.push(boundary - 1);
				}
				//判断右分区是否存在
				if (boundary + 1 < high) {
					///将右分区端点后入栈以便优先排序
					st.push(boundary + 1);
					st.push(high);
				}
			}

			//栈非空且未排好序
			while (!st.empty()) {
				//得到某分区的左右边界
				int r = st.top(); st.pop();
				int l = st.top(); st.pop();

				boundary = partition_plus(data, l, r, isOrdered);  //boundary为枢轴元素所在位置
				if (isOrdered == true)        //如果已经有序，结束排序。
					return;

				//如果序列小于等于3个元素
				if (high - low < 3) {
					tinySort(data, low, high);
					return;
				}

				//如果左分区比右分区短
				if (boundary - l < r - boundary) {
					//判断右分区是否存在
					if (boundary + 1 < r) {
						st.push(boundary + 1);
						st.push(r);
					}
					//判断左分区是否存在
					if (boundary - 1 > l) {
						///将左分区端点后入栈以便优先排序
						st.push(l);
						st.push(boundary - 1);
					}
				}
				//如果右分区比左分区短
				else {
					//判断左分区是否存在
					if (boundary - 1 > l)  {
						st.push(l);
						st.push(boundary - 1);
					}
					//判断右分区是否存在
					if (boundary + 1 < r) {
						///将右分区端点后入栈以便优先排序
						st.push(boundary + 1);
						st.push(r);
					}
				}
			}
		}
	};



	fmt::print("Original data:\t\t{}", data_v);

	auto t1 = std::chrono::system_clock::now();
	quickSort(data_v, 0, static_cast<int>(data_v.size()) - 1);
	auto t2 = std::chrono::system_clock::now();
	std::chrono::duration<double, std::nano> fp_ns = t2 - t1;
	
	fmt::print("After QuickSort:\t{}", data_v);
	fmt::print("Elapsed time: {:>10}ms\n", fp_ns.count());

	auto t1_plus = std::chrono::system_clock::now();
	quickSort_plus(data_v_plus);
	auto t2_plus = std::chrono::system_clock::now();
	std::chrono::duration<double, std::nano> fp_ns_plus = t2_plus - t1_plus;
	fmt::print("After QuickSort Plus:\t{}", data_v);
	fmt::print("Elapsed time: {:>10}ms\n", fp_ns_plus.count());

	
	for (int i = 100; i < 100000000; i *= 10) {
		auto t_begin = std::chrono::system_clock::now();
		auto data_mega_v = dice(i, 0, 9999);
		auto data_mega_v_plus = data_mega_v;
		auto t_end = std::chrono::system_clock::now();
		std::chrono::duration<double> el_s = t_end - t_begin;
		auto s = fmt::format(std::locale("en_US.UTF-8"), "{:L}", i);
		fmt::print("After generate {} random numbers, ", s);
		fmt::print("Elapsed time:{:>10}s\n", el_s.count());

		auto t1_mega = std::chrono::system_clock::now();
		quickSort(data_mega_v, 0, static_cast<int>(data_v.size()) - 1);
		auto t2_mega = std::chrono::system_clock::now();
		std::chrono::duration<double> fp_mega_s = t2_mega - t1_mega;

		fmt::print("{} elems after QuickSort, Elapsed time:{:>15}s\n", s, fp_mega_s.count());

		auto t1_mega_plus = std::chrono::system_clock::now();
		quickSort_plus(data_mega_v_plus);
		auto t2_mega_plus = std::chrono::system_clock::now();
		std::chrono::duration<double> fp_mega_s_plus = t2_mega_plus - t1_mega_plus;
		fmt::print("{} elems after QuickSort Plus, Elapsed time:\t{:>10}s\n\n", s, fp_mega_s_plus.count());
	}
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

