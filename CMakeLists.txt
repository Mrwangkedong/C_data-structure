cmake_minimum_required(VERSION 3.15)
project(untitled C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled main.c LineList.h Queue/SqQueue.c Test/MillonToEnd.c Stack/LiStack.c Stack/SqStack.c Test/Calculate.c KMP/Kmp.c KMP/MyString.c Tree/MyBiTree.c Tree/TreeQueue.c Tree/ThreadTree.c Tree/TreeStack.c Tree/BSTree.c Search/BinarySearch.c Sort/InsertSort.c Sort/SwiftSort.c Sort/SelectSort.c Sort/Merge.c Tu/TuBase.c Tu/TwoFS.c)