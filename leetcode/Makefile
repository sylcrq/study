GMOCK_DIR=/home/syl/developer/gmock-1.6.0
GTEST_DIR=/home/syl/developer/gtest-1.6.0
ADT_DIR=./abstract_data_types

CXXFLAGS=-Wall -g -O0

all:
	g++ -I${GTEST_DIR}/include -I${GTEST_DIR} -I${GMOCK_DIR}/include \
		-I${GMOCK_DIR} -c ${GTEST_DIR}/src/gtest-all.cc
	g++ -I${GTEST_DIR}/include -I${GTEST_DIR} -I${GMOCK_DIR}/include \
		-I${GMOCK_DIR} -c ${GMOCK_DIR}/src/gmock-all.cc
	ar -rv libgmock.a gtest-all.o gmock-all.o
	g++ ${CXXFLAGS} -I${GTEST_DIR}/include -I${GMOCK_DIR}/include \
		-c max_sum_of_subarray_test.cpp
	g++ ${CXXFLAGS} -I${GTEST_DIR}/include -I${GMOCK_DIR}/include \
		-c max_stack_test.cpp
	g++ ${CXXFLAGS} -I${GTEST_DIR}/include -I${GMOCK_DIR}/include \
		-c max_queue_test.cpp
	g++ ${CXXFLAGS} -I${GTEST_DIR}/include -I${GMOCK_DIR}/include \
		-c triangle_test.cpp
	g++ ${CXXFLAGS} -I${GTEST_DIR}/include -I${GMOCK_DIR}/include \
		-c remove_duplicates_from_sorted_array_test.cpp
	g++ ${CXXFLAGS} -I${GTEST_DIR}/include -I${GMOCK_DIR}/include \
		-c two_sum_test.cpp
	g++ ${CXXFLAGS} -I${GTEST_DIR}/include -I${GMOCK_DIR}/include \
		-c longest_substring_without_repeating_char_test.cpp
	g++ ${CXXFLAGS} -I${GTEST_DIR}/include -I${GMOCK_DIR}/include \
		-c merge_two_sorted_lists_test.cpp
	g++ ${CXXFLAGS} -I${GTEST_DIR}/include -I${GMOCK_DIR}/include \
		-c quick_sort_test.cpp
	g++ ${CXXFLAGS} -I${GTEST_DIR}/include -I${GMOCK_DIR}/include \
		-c add_binary_test.cpp
	g++ ${CXXFLAGS} -I${GTEST_DIR}/include -I${GMOCK_DIR}/include \
		-c implement_strstr_test.cpp
	g++ ${CXXFLAGS} -I${GTEST_DIR}/include -I${GMOCK_DIR}/include \
		-c single_number_test.cpp
	g++ ${CXXFLAGS} -I${GTEST_DIR}/include -I${GMOCK_DIR}/include \
		-c max_depth_of_binary_tree_test.cpp
	g++ ${CXXFLAGS} -I${GTEST_DIR}/include -I${GMOCK_DIR}/include \
		-c same_tree_test.cpp
	g++ ${CXXFLAGS} -I${GTEST_DIR}/include -I${GMOCK_DIR}/include \
		-c reverse_integer_test.cpp
	g++ ${CXXFLAGS} -I${GTEST_DIR}/include -I${GMOCK_DIR}/include \
		-c path_sum_test.cpp
	g++ ${CXXFLAGS} -I${GTEST_DIR}/include -I${GMOCK_DIR}/include \
		-c multiply_strings_test.cpp
	g++ ${CXXFLAGS} -I${GTEST_DIR}/include -I${GMOCK_DIR}/include \
		-c the_disjoint_set_test.cpp
	g++ ${CXXFLAGS} -I${GTEST_DIR}/include -I${GMOCK_DIR}/include -I${ADT_DIR} \
		-c linked_list_cycle_test.cpp
	g++ ${CXXFLAGS} -I${GTEST_DIR}/include -I${GMOCK_DIR}/include \
		-c ${ADT_DIR}/singly_linked_list_test.cpp
	g++ ${CXXFLAGS} -I${GTEST_DIR}/include -I${GMOCK_DIR}/include \
		-c ${ADT_DIR}/binary_tree_with_link_test.cpp
	g++ ${CXXFLAGS} -I${GTEST_DIR}/include -I${GMOCK_DIR}/include -I${ADT_DIR} \
		-c populating_next_right_pointers_in_each_node_test.cpp
	g++ ${CXXFLAGS} -I${GTEST_DIR}/include -I${GMOCK_DIR}/include \
		-c roman_to_integer_test.cpp
	g++ -I${GTEST_DIR}/include -I${GMOCK_DIR}/include \
		-c main.cpp
	g++ ${CXXFLAGS} -c max_sum_of_subarray.cpp
	g++ ${CXXFLAGS} -c max_stack.cpp
	g++ ${CXXFLAGS} -c max_queue.cpp
	g++ ${CXXFLAGS} -c triangle.cpp
	g++ ${CXXFLAGS} -c remove_duplicates_from_sorted_array.cpp
	g++ ${CXXFLAGS} -c two_sum.cpp
	g++ ${CXXFLAGS} -c longest_substring_without_repeating_char.cpp
	g++ ${CXXFLAGS} -c merge_two_sorted_lists.cpp
	g++ ${CXXFLAGS} -c quick_sort.cpp
	g++ ${CXXFLAGS} -c add_binary.cpp
	g++ ${CXXFLAGS} -c implement_strstr.cpp
	g++ ${CXXFLAGS} -c single_number.cpp
	g++ ${CXXFLAGS} -c max_depth_of_binary_tree.cpp
	g++ ${CXXFLAGS} -c same_tree.cpp
	g++ ${CXXFLAGS} -c reverse_integer.cpp
	g++ ${CXXFLAGS} -c path_sum.cpp
	g++ ${CXXFLAGS} -c multiply_strings.cpp
	g++ ${CXXFLAGS} -c the_disjoint_set.cpp
	g++ ${CXXFLAGS} -I${ADT_DIR} -c linked_list_cycle.cpp
	g++ ${CXXFLAGS} -c ${ADT_DIR}/singly_linked_list.cpp
	g++ ${CXXFLAGS} -c ${ADT_DIR}/binary_tree_with_link.cpp
	g++ ${CXXFLAGS} -I${ADT_DIR} -c populating_next_right_pointers_in_each_node.cpp
	g++ ${CXXFLAGS} -c roman_to_integer.cpp
	g++ -I${GTEST_DIR}/include -I${GMOCK_DIR}/include \
		roman_to_integer.o roman_to_integer_test.o \
		populating_next_right_pointers_in_each_node.o populating_next_right_pointers_in_each_node_test.o \
		binary_tree_with_link.o binary_tree_with_link_test.o \
		linked_list_cycle.o linked_list_cycle_test.o \
		singly_linked_list.o singly_linked_list_test.o \
		the_disjoint_set.o the_disjoint_set_test.o \
		multiply_strings.o multiply_strings_test.o \
		path_sum.o path_sum_test.o \
		reverse_integer.o reverse_integer_test.o \
		same_tree.o same_tree_test.o \
		max_depth_of_binary_tree.o max_depth_of_binary_tree_test.o \
		single_number.o single_number_test.o \
		implement_strstr.o implement_strstr_test.o \
		add_binary.o add_binary_test.o \
		quick_sort.o quick_sort_test.o \
		merge_two_sorted_lists.o merge_two_sorted_lists_test.o \
		longest_substring_without_repeating_char.o longest_substring_without_repeating_char_test.o \
		two_sum.o two_sum_test.o \
		remove_duplicates_from_sorted_array.o remove_duplicates_from_sorted_array_test.o \
		triangle.o triangle_test.o \
		max_queue.o max_queue_test.o \
		max_stack.o max_stack_test.o \
		max_sum_of_subarray.o max_sum_of_subarray_test.o \
		main.o libgmock.a \
		-lpthread \
		-o test

clean:
	rm -rf *.o *.a test
