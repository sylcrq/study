GTEST_DIR = /home/syl/developer/gtest-1.6.0

all:
	#g++ -o dns -L/usr/local/lib dnsresolver.cpp main.cpp -lcares -Wl,-rpath=/usr/local/lib
	libtool --mode=compile g++ -I${GTEST_DIR}/include -c magnet_test.cpp
	libtool --mode=link g++ -o magnet_test magnet_test.lo ${GTEST_DIR}/lib/libgtest_main.la
	#g++ -o dns -L/usr/local/lib dnsresolve.cpp main.cpp -lcares
	#libtool --mode=compile g++ -c dnsresolve.cpp
	#libtool --mode=compile g++ -c main.cpp
	#libtool --mode=link g++ -o dns dnsresolve.lo main.lo /usr/local/lib/libcares.la

clean:
	rm -rf *.o *.lo .libs/ magnet_test dns
