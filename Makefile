# C++ 컴파일러
CC = g++

# C++ 컴파일러 옵션
CXXFLAGS = -std=c++17 -g -pthread

# 링커 옵션
LDFLAGS = 

# Library
LIBS = -lurcu

# Define
DEFINE = -DSTANDARD

# 소스 파일 디렉토리
SRC_DIR = Source

# 오브젝트 파일 디렉토리
OBJ_DIR = Objs

# Include 파일 디렉토리
INCLUDE = -I $(SRC_DIR)
										
# 생성하고자 하는 실행 파일 이름
TARGET = main

SRCS += $(wildcard $(SRC_DIR)/../*.cpp)
SRCS += $(wildcard $(SRC_DIR)/Parallel/*.cpp)
SRCS += $(wildcard $(SRC_DIR)/Parallel/Thread/*.cpp)

OBJS = ${SRCS:.cpp=.o}
DEPS = $(OBJS:.o=.d)

OBJECTS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRCS))

all: main
$(OBJ_DIR)/%.o : $(SRCS)
	mkdir -p $(shell dirname $@) 
	$(CC) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

$(TARGET) : $(OBJECTS)
	$(CC) $(CXXFLAGS) $(INCLUDE)  $(SRCS) -o  $(TARGET) $(LDFLAGS) 

.PHONY: clean all
clean:
	rm -f $(OBJECTS) $(TARGET)

-include $(DEPS)
