GMOCK_DIR=/home/syl/developer/gmock-1.6.0
GTEST_DIR=/home/syl/developer/gtest-1.6.0


all:
	g++ -I${GTEST_DIR}/include -I${GTEST_DIR} -I${GMOCK_DIR}/include \
		-I${GMOCK_DIR} -c ${GTEST_DIR}/src/gtest-all.cc
	g++ -I${GTEST_DIR}/include -I${GTEST_DIR} -I${GMOCK_DIR}/include \
		-I${GMOCK_DIR} -c ${GMOCK_DIR}/src/gmock-all.cc
	ar -rv libgmock.a gtest-all.o gmock-all.o
	g++ -I${GTEST_DIR}/include -I${GMOCK_DIR}/include \
		-c MockTurtle.cpp
	g++ -I${GTEST_DIR}/include -I${GMOCK_DIR}/include \
		-c main.cpp
	g++ -I${GTEST_DIR}/include -I${GMOCK_DIR}/include \
		-lpthread MockTurtle.o main.o libgmock.a -o mocktest

clean:
	rm -rf *.o *.a mocktest
