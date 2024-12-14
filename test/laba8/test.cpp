#include "pch.h"
#include "..//calculator//calc.h"
#include "..//calculator//stack.h"

class stack_test : public testing::Test {
	protected:
		stack<int> int_stack;
		stack<int> int_stack2;
		stack<char> char_stack;
		stack<char> char_stack2;
};

class expression_test : public testing::Test {
	protected:
		expression string_1;
};


//int

TEST_F(stack_test, array1) {
	int_stack << 1;
	int number;
	int_stack >> number;
	EXPECT_EQ(number, 1);
}

TEST_F(stack_test, array2) {
	int_stack << 5;
	EXPECT_EQ(int_stack.get_size(), 1);
}

TEST_F(stack_test, array3) {
	int_stack << 10;
	EXPECT_EQ(int_stack[0], 10);
}

TEST_F(stack_test, array4) {
	int_stack2 << 89;
	int_stack2 << 36;
	int_stack = int_stack2;
	EXPECT_EQ(int_stack2.get_size(), 2);
}

TEST_F(stack_test, array5) {
	int_stack2 << 89;
	int_stack2 << 36;
	int_stack = int_stack2;
	EXPECT_EQ(int_stack[1], 89);
}

TEST_F(stack_test, array6) {
	int_stack2 << 89;
	int_stack2 << 36;
	int_stack << -43;
	EXPECT_EQ(int_stack > int_stack2, false);
}

TEST_F(stack_test, array7) {
	int_stack2 << 89;
	int_stack2 << 36;
	int_stack << -43;
	EXPECT_EQ(int_stack == int_stack2, false);
}

TEST_F(stack_test, array8) {
	int_stack2 << 89;
	int_stack2 << 36;
	int_stack << -43;
	EXPECT_EQ(int_stack < int_stack2, true);
}

//char

TEST_F(stack_test, array9) {
	char_stack << 'h';
	char symbol;
	char_stack >> symbol;
	EXPECT_EQ(symbol, 'h');
}

TEST_F(stack_test, array10) {
	char_stack << '8';
	EXPECT_EQ(char_stack.get_size(), 1);
}

TEST_F(stack_test, array11) {
	char_stack << '@';
	EXPECT_EQ(char_stack[0], '@');
}

TEST_F(stack_test, array12) {
	char_stack2 << ',';
	char_stack2 << '9';
	char_stack = char_stack2;
	EXPECT_EQ(char_stack2.get_size(), 2);
}

TEST_F(stack_test, array13) {
	char_stack2 << '$';
	char_stack2 << '-';
	char_stack = char_stack2;
	EXPECT_EQ(char_stack[1], '$');
}

TEST_F(stack_test, array14) {
	char_stack2 << '3';
	char_stack2 << 'n';
	char_stack << '{';
	EXPECT_EQ(char_stack > char_stack2, false);
}

TEST_F(stack_test, array15) {
	char_stack2 << '/';
	char_stack2 << '&';
	char_stack << '!';
	EXPECT_EQ(char_stack == char_stack2, false);
}

TEST_F(stack_test, array16) {
	char_stack2 << '`';
	char_stack2 << 'z';
	char_stack << '$';
	EXPECT_EQ(char_stack < char_stack2, true);
}

//expression

TEST_F(expression_test, statement1) {
	std::string st = "1+1";
	string_1.set_line(st);
	EXPECT_EQ(string_1.check(), 1);
}

TEST_F(expression_test, statement2) {
	std::string st = "1+1)";
	string_1.set_line(st);
	EXPECT_EQ(string_1.check(), 0);
}

TEST_F(expression_test, statement3) {
	std::string st = "1+1";
	string_1.set_line(st);
	string_1.set_line("1-)");
	EXPECT_EQ(string_1.check(), 0);
}

TEST_F(expression_test, statement4) {
	std::string st = "1+1";
	string_1.set_line(st);
	string_1.check();
	EXPECT_EQ(string_1.calculate(), 2);
}

TEST_F(expression_test, statement5) {
	std::string st = "1+1";
	string_1.set_line(st);
	st = "2+1";
	string_1.set_line(st);
	string_1.check();
	EXPECT_EQ(string_1.calculate(), 3);
}

TEST_F(expression_test, statement6) {
	std::string st = "(4+3)";
	string_1.set_line(st);
	string_1.check();
	EXPECT_EQ(string_1.calculate(), 7);
}

TEST_F(expression_test, statement7) {
	std::string st = "(4+3)*2";
	string_1.set_line(st);
	string_1.check();
	EXPECT_EQ(string_1.calculate(), 14);
}

TEST_F(expression_test, statement8) {
	std::string st = "(4+3)*2+1";
	string_1.set_line(st);
	string_1.check();
	EXPECT_EQ(string_1.calculate(), 15);
}

TEST_F(expression_test, statement9) {
	std::string st = "((4+3)*2+1)/3";
	string_1.set_line(st);
	string_1.check();
	EXPECT_EQ(string_1.calculate(), 5);
}

TEST_F(expression_test, statement10) {
	std::string st = "1-1";
	string_1.set_line(st);
	string_1.check();
	EXPECT_EQ(string_1.calculate(), 0);
}

TEST_F(expression_test, statement11) {
	std::string st = "1+(-11)";
	string_1.set_line(st);
	string_1.check();
	EXPECT_EQ(string_1.calculate(), -10);
}

TEST_F(expression_test, statement12) {
	std::string st = "-(1+11)";
	string_1.set_line(st);
	string_1.check();
	EXPECT_EQ(string_1.calculate(), -12);
}

TEST_F(expression_test, statement13) {
	std::string st = "9";
	string_1.set_line(st);
	string_1.check();
	EXPECT_EQ(string_1.calculate(), 9);
}

TEST_F(expression_test, statement14) {
	std::string st = "(1-2)*(1+21)";
	string_1.set_line(st);
	string_1.check();
	EXPECT_EQ(string_1.calculate(), -22);
}

TEST_F(expression_test, statement15) {
	std::string st = "(1+1";
	string_1.set_line(st);
	EXPECT_EQ(string_1.check(), 0);
}

TEST_F(expression_test, statement16) {
	std::string st = "-";
	string_1.set_line(st);
	EXPECT_EQ(string_1.check(), 0);
}

TEST_F(expression_test, statement17) {
	std::string st = "#";
	string_1.set_line(st);
	EXPECT_EQ(string_1.check(), 0);
}

TEST_F(expression_test, statement18) {
	std::string st = "--1";
	string_1.set_line(st);
	EXPECT_EQ(string_1.check(), 0);
}

TEST_F(expression_test, statement19) {
	std::string st = "1+-1";
	string_1.set_line(st);
	EXPECT_EQ(string_1.check(), 0);
}

TEST_F(expression_test, statement20) {
	std::string st = "7+/3";
	string_1.set_line(st);
	EXPECT_EQ(string_1.check(), 0);
}

