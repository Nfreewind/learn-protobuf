TARGET = test_SerializeToOstream

CXX = g++
CXXFLAGS = -O0 -g -std=c++11 -I../ # for Debug
#CXXFLAGS = -W -Wall -O3 -std=c++11 # for Release
LDFLAGS =
RM = rm -rf
HEADERS = $(wildcard *.h)
SRCS = $(wildcard *.cc)
OBJS = $(SRCS:.cc=.o)

LIBS = protobuf
ifneq ($(LIBS),)
CXXFLAGS += $(shell pkg-config --cflags $(LIBS))
LDFLAGS += $(shell pkg-config --libs $(LIBS))
endif

PROTOBUF_CPP = msg.pb.cc

.PHONY: all clean

all: $(PROTOBUF_CPP) $(TARGET)

$(PROTOBUF_CPP):
	protoc --cpp_out=. *.proto

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

%.o: %.cpp $(HEADERS)
	$(CXX) -c $(CXXFLAGS) -o $@ $<

clean:
	$(RM) $(OBJS) $(TARGET)

