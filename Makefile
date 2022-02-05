.PHONY: clean # 伪目标

# 自定义环境变量
CC = g++ # 指定编译器

CFLAGS = -I code # 指定头文件目录
CFILES = $(shell find code -name "*.cpp") # 搜索所有的源文件
OBJS = $(CFILES:.cpp=.o) # 所有的目标文件
TARGET = main # 最终生成目标
DATA = data/*.txt # 搜索所有的数据文件

RM = -rm -f # 删除方式

all: $(TARGET)

# 项目构建方式
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

%o : %c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(TARGET) $(OBJS)
