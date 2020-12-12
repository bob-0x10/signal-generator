all: signal-generator

signal-generator: arphdr.o ethhdr.o ip.o mac.o main.o pkt.o
	g++ -o signal-generator arphdr.o ethhdr.o ip.o mac.o main.o pkt.o -std=c++11 -lpcap

arphdr.o: arphdr.cpp arphdr.h \
		mac.h \
		ip.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o arphdr.o arphdr.cpp -std=c++11 -lpcap

ethhdr.o: ethhdr.cpp ethhdr.h \
		mac.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ethhdr.o ethhdr.cpp -std=c++11 -lpcap

ip.o: ip.cpp ip.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ip.o ip.cpp -std=c++11 -lpcap

mac.o: mac.cpp mac.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mac.o mac.cpp -std=c++11 -lpcap

main.o: main.cpp pkt.h \
		ethhdr.h \
		mac.h \
		arphdr.h \
		ip.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp -std=c++11 -lpcap

pkt.o: pkt.cpp pkt.h \
		ethhdr.h \
		mac.h \
		arphdr.h \
		ip.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o pkt.o pkt.cpp -std=c++11 -lpcap

clean:
	rm -f signal-generator *.o
