#include "pch.h"
#include "../prog3-3/Header.h"
#include "../prog3-3/Source.cpp"

using namespace Spisok1;

TEST(Test3, EmptyConst) {
	Spisok sp;
	ASSERT_EQ(sp.max_size_of_list(), 20);
	ASSERT_EQ(sp.size_of_list(), 0);
}

TEST(Test3, ConstWithElem) {
	Spisok sp(100);
	ASSERT_EQ(sp.max_size_of_list(), 20);
	ASSERT_EQ(sp.size_of_list(), 1);
	ASSERT_EQ(sp.GetElem(0), 100);
}


TEST(Test3, SumOfList) {
	Spisok newlist, sp1(5, 10), sp2(4, 12);
	newlist = sp1 + sp2;
	ASSERT_EQ(newlist.size_of_list(), 9);
	ASSERT_EQ(newlist.GetElem(0), 5);
	ASSERT_EQ(newlist.GetElem(5), 5);
}

TEST(Test3, AddElem) {
	Spisok list, sp(15, 1);
	list = sp + 12;
	ASSERT_EQ(list.size_of_list(), 16);
	ASSERT_EQ(list.GetElem(15), 12);
}

TEST(Test3, Equality) {
	Spisok list(12, 1), sp(14, 2);
	ASSERT_EQ(list.GetElem(1), 6);
	list = sp;
	ASSERT_EQ(list.size_of_list(), 14);
	ASSERT_EQ(list.GetElem(1), 7);
}

TEST(Test3, Sorts) {
	Spisok list(2, 1);
	ASSERT_EQ(list.sorts(), 0);
	list = list + 7 + 2;
	ASSERT_EQ(list.sorts(), 1);
}

TEST(Test3, NoSorts) {
	Spisok list(10);
	list = list + 2 + 11 + 1;
	ASSERT_EQ(list.sorts(), -1);
}

TEST(Test3, AddElemWithEq) {
	Spisok list(12, 1);
	list += 1;
	ASSERT_EQ(list.size_of_list(), 13);
	ASSERT_EQ(list.GetElem(12), 1);
}

TEST(Test3, DifElem) {
	Spisok sp(10, 1);
	ASSERT_EQ(sp.dif_count(), 10);
	sp += 5;
	ASSERT_EQ(sp.size_of_list(), 11);
	ASSERT_EQ(sp.dif_count(), 9);
}