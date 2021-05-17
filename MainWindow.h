#pragma once
#ifndef MAINWINDOW_H_SY_
#define MAINWINDOW_H_SY_

#include <iostream>
using std::cin;

#include <string>
using std::string;

#include <regex>
using std::regex_match;

#include <map>
using std::map;

#include <utility>
using std::pair;

#include <iostream>
using std::cout; using std::endl;

#include <functional>
using std::function;
using std::bind;

#include <windows.h>

#include "fmt/core.h"
#include "fmt/color.h"

#include "HashMap.hpp"
#include "HashTable.hpp"
#include "formatter.hpp"

class MainWindow
{
public:
	static MainWindow& getInstance() {
		static MainWindow instance;
		return instance;
	}
	~MainWindow() = default;
private:
	sy::HashMap<int, int> hashmap;
	sy::HashTable<string> hashtable;
	
	MainWindow() { init(); }
	void init();

	void insertHashMap();
	void showHashMap() const;
	void searchHashMap() const;
	void deleteHashMap();
	void insertHashTable();
	void showHashTable() const;
	void searchHashTable() const;
	void deleteHashTable();
	void printHelp() const;
	void resetAll();

	void testText(int test_num) const;
	void test1();
	void test2();
	void test3();
	void test4();
	void test5();
	void test6();
	void test7();
	void test8();
	void test9();
	void test10();
	void test11();
	void test12();
	
	static void printLine(const string& s);
	static bool isStringDigital(const string& s);
};

#endif 