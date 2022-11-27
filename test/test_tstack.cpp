#include "gtest.h"
#include "Stack.h"

TEST(TStack, can_create_stack_with_positive_length)
{
  ASSERT_NO_THROW(TStack<int> st(4));
}

TEST(TStack, cant_create_stack_with_negative_length)
{
  ASSERT_ANY_THROW(TStack<int> st(-1));
}

TEST(TStack, can_get_size)
{
  TStack<int> st(3);
  st.Push(1);
  st.Push(2);
  st.Push(3);
  EXPECT_EQ(3, st.GetSize());
}

TEST(TStack, can_put_item_into_stack)
{
  TStack<int> st(4);
  ASSERT_NO_THROW(st.Push(3));
}

TEST(TStack, can_pop_item_from_stack)
{
  TStack<int> st(3);
  st.Push(1);
  st.Push(2);
  st.Push(3);
  ASSERT_NO_THROW(st.Pop());
}

TEST(TStack, can_check_for_emptiness)
{
  TStack<int> st(4);
  EXPECT_EQ(st.IsEmpty(), true);
}

TEST(TStack, can_check_for_fullness)
{
  TStack<int> st(3);
  st.Push(1);
  st.Push(2);
  st.Push(3);
  EXPECT_EQ(st.IsFull(), true);
}

TEST(TStack, cant_pop_item_from_empty_stack)
{
  TStack<int> st(4);
  ASSERT_ANY_THROW(st.Pop());
}

TEST(TStack, cant_put_item_into_full_stack)
{
  TStack<int> st(3);
  st.Push(1);
  st.Push(2);
  st.Push(3);
  ASSERT_ANY_THROW(st.Push(5));
}