GMOCK_DIR=/home/syl/developer/gmock-1.6.0
GTEST_DIR=/home/syl/developer/gtest-1.6.0


all:
	g++ -I${GTEST_DIR}/include -I${GTEST_DIR} -I${GMOCK_DIR}/include \
		-I${GMOCK_DIR} -c ${GTEST_DIR}/src/gtest-all.cc
	g++ -I${GTEST_DIR}/include -I${GTEST_DIR} -I${GMOCK_DIR}/include \
		-I${GMOCK_DIR} -c ${GMOCK_DIR}/src/gmock-all.cc
	ar -rv libgmock.a gtest-all.o gmock-all.o
	g++ -I${GTEST_DIR}/include -I${GMOCK_DIR}/include \
		-c max_sum_of_subarray_test.cpp
	g++ -I${GTEST_DIR}/include -I${GMOCK_DIR}/include \
		-c max_stack_test.cpp
	g++ -I${GTEST_DIR}/include -I${GMOCK_DIR}/include \
		-c max_queue_test.cpp
	g++ -I${GTEST_DIR}/include -I${GMOCK_DIR}/include \
		-c main.cpp
	g++ -c max_sum_of_subarray.cpp
	g++ -c max_stack.cpp
	g++ -c max_queue.cpp
	g++ -I${GTEST_DIR}/include -I${GMOCK_DIR}/include \
		-lpthread \
		max_queue.o max_queue_test.o \
		max_stack.o max_stack_test.o \
		max_sum_of_subarray.o max_sum_of_subarray_test.o \
		main.o libgmock.a -o test

clean:
	rm -rf *.o *.a test
