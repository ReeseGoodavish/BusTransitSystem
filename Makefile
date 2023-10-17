CXX = g++
CXXFLAGS = -std=c++11  # You can adjust the C++ standard as needed

SRCS = Drivers.cpp Hwk3Main.cpp
OBJS = $(SRCS:.cpp=.o)
EXECUTABLE = run

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CXX) $(OBJS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXECUTABLE)