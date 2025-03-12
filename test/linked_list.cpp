#include "../include/linked_list.hpp"
#include <gtest/gtest.h>

class LinkedListTest : public ::testing::Test {
  protected:
    LinkedList<int> list;
};

TEST_F(LinkedListTest, InitiallyEmpty) {
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
}

TEST_F(LinkedListTest, PushFrontIncreasesSize) {
    list.push_front(10);
    EXPECT_FALSE(list.empty());
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list[0], 10);
}

TEST_F(LinkedListTest, InsertAtIndex) {
    list.push_front(10);
    list.insert(0, 20);
    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list[0], 20);
    EXPECT_EQ(list[1], 10);
}

TEST_F(LinkedListTest, PopFrontDecreasesSize) {
    list.push_front(10);
    list.push_front(20);
    list.pop_front();
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list[0], 10);
}

TEST_F(LinkedListTest, RemoveAtIndex) {
    list.push_front(30);
    list.push_front(20);
    list.push_front(10);
    list.remove(1);
    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list[0], 10);
    EXPECT_EQ(list[1], 30);
}

TEST_F(LinkedListTest, ClearEmptiesList) {
    list.push_front(10);
    list.push_front(20);
    list.clear();
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
}

TEST_F(LinkedListTest, FindElement) {
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);
    EXPECT_EQ(list.find(20), 20);
}

TEST_F(LinkedListTest, FindNonExistentElement) {
    list.push_front(10);
    list.push_front(20);
    EXPECT_THROW(list.find(30), std::out_of_range);
}

TEST_F(LinkedListTest, ContainsElement) {
    list.push_front(10);
    list.push_front(20);
    EXPECT_TRUE(list.contains(10));
    EXPECT_FALSE(list.contains(30));
}

TEST_F(LinkedListTest, OperatorIndexAccess) {
    list.push_front(10);
    list.push_front(20);
    EXPECT_EQ(list[0], 20);
    EXPECT_EQ(list[1], 10);
}

TEST_F(LinkedListTest, OperatorIndexOutOfBounds) {
    list.push_front(10);
    EXPECT_THROW(list[1], std::out_of_range);
}

TEST_F(LinkedListTest, InsertAtInvalidIndex) {
    EXPECT_THROW(list.insert(5, 100), std::out_of_range);
}

TEST_F(LinkedListTest, RemoveAtInvalidIndex) {
    EXPECT_THROW(list.remove(0), std::out_of_range);
}

TEST_F(LinkedListTest, FindInEmptyList) {
    EXPECT_THROW(list.find(10), std::out_of_range);
}

TEST_F(LinkedListTest, PopFrontOnEmptyList) {
    EXPECT_THROW(list.pop_front(), std::out_of_range);
}

TEST_F(LinkedListTest, ClearAlreadyEmptyList) {
    list.clear();
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
}

TEST_F(LinkedListTest, PushFrontMultipleValues) {
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);
    EXPECT_EQ(list.size(), 3);
    EXPECT_EQ(list[0], 30);
    EXPECT_EQ(list[1], 20);
    EXPECT_EQ(list[2], 10);
}

TEST_F(LinkedListTest, RemoveLastElement) {
    list.push_front(10);
    list.pop_front();
    EXPECT_TRUE(list.empty());
    EXPECT_EQ(list.size(), 0);
}

TEST_F(LinkedListTest, PrintDoesNotCrash) {
    list.push_front(10);
    list.print();
}

TEST_F(LinkedListTest, CopyConstructor) {
    list.push_front(10);
    list.push_front(20);

    // Create a copy of the list using the copy constructor
    LinkedList<int> copyList = list;

    // Verify that the copy has the same elements
    EXPECT_EQ(copyList.size(), 2);
    EXPECT_EQ(copyList[0], 20);
    EXPECT_EQ(copyList[1], 10);

    // Verify that modifying the original list doesn't affect the copy
    list.push_front(30);
    EXPECT_EQ(copyList.size(), 2); // Copy should still have the original size
    EXPECT_EQ(copyList[0], 20);    // Copy's values should remain the same
    EXPECT_EQ(copyList[1], 10);
}

TEST_F(LinkedListTest, AssignmentOperator) {
    list.push_front(10);
    list.push_front(20);

    // Create another list and assign the first list to it
    LinkedList<int> assignedList;
    assignedList = list;

    // Verify that the assigned list has the same elements
    EXPECT_EQ(assignedList.size(), 2);
    EXPECT_EQ(assignedList[0], 20);
    EXPECT_EQ(assignedList[1], 10);

    // Verify that modifying the original list doesn't affect the assigned list
    list.push_front(30);
    EXPECT_EQ(assignedList.size(),
              2); // Assigned list should still have the original size
    EXPECT_EQ(assignedList[0],
              20); // Assigned list's values should remain the same
    EXPECT_EQ(assignedList[1], 10);
}