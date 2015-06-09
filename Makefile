CXX = g++
SERVER = mb_socket 
LOG = log
CFLAGS = -Wall -L.. -lssl -lpthread

INC_PATH_PREFIX = ../output/include

INC_PATH += -I$(INC_PATH_PREFIX)
INC_PATH += -I../output-cpp -I.

MYBROKER_SOURCES = $(wildcard *.cpp) $(wildcard **.h)
MYBROKER_OBJS = $(patsubst %.cpp,%.o,$(MYBROKER_SOURCES))

LD_PATH = -L../output/lib/

all:$(SERVER)

$(SERVER): $(MYBROKER_SOURCES)
	$(CXX) -g -o $@ $^ $(INC_PATH) $(LD_PATH) $(CFLAGS)

clean:
	rm -rf $(CLIENT) $(SERVER) $(LOG)
