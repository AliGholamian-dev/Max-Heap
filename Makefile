CXX = g++
CXXFLAGS = -std=c++2a -Wall -I h -I /usr/local/include/gtest/ -c
LXXFLAGS = -std=c++2a -Ih -pthread
OBJECTS = ./obj/student.o ./obj/apmidterm.o ./obj/main.o ./obj/apmidterm_unittest.o
GTEST = /usr/local/lib/libgtest.a
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) -o $(TARGET) $(OBJECTS) $(GTEST)
./obj/apmidterm.o: ./cpp/apmidterm.cpp
	$(CXX) $(CXXFLAGS) ./cpp/apmidterm.cpp -o ./obj/apmidterm.o
./obj/student.o: ./cpp/student.cpp
	$(CXX) $(CXXFLAGS) ./cpp/student.cpp -o ./obj/student.o
./obj/apmidterm_unittest.o: ./cpp/apmidterm_unittest.cpp
	$(CXX) $(CXXFLAGS) ./cpp/apmidterm_unittest.cpp -o ./obj/apmidterm_unittest.o
./obj/main.o: ./cpp/main.cpp ./h/apmaxheap.h
	$(CXX) $(CXXFLAGS) ./cpp/main.cpp -o ./obj/main.o
clean:
	rm -fv $(TARGET) $(OBJECTS)
