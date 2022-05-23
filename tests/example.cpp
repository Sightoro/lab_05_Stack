// Copyright 2021 Your Name <your_email>

#include <stdexcept>

#include <gtest/gtest.h>
#include <example.hpp>
#include "iostream"

TEST(method_tests, r_push){
  Stack<int> stack;
  stack.push(7);
  EXPECT_EQ(stack.top_node->data, 7);}

TEST(method_tests, l_push){
  Stack<int> stack;
  int a = 1;
  stack.push(a);
  EXPECT_EQ(stack.top_node->data, 1);}

TEST(exeption_tests, empty_stack){
  Stack<int> stack;
  EXPECT_ANY_THROW(stack.pop( ));}

TEST(method_tests, g_pop){
  Stack<int> stack;
  stack.push(7);
  EXPECT_EQ(stack.pop( ), 7);}
