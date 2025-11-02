SRCS = listing.cpp 
TARGETDEST = bin/
TARGET = main
ALT_TARGET = test

default: execute

out: clean compile execute

all: clean compile

compile: clean $(SRCS)
	@g++ -g -Wall -std=c++14 main.cpp $(SRCS) -o $(TARGETDEST)$(TARGET)
	@g++ -g -Wall -std=c++14 tests.cpp $(SRCS) -o $(TARGETDEST)$(ALT_TARGET)

execute: lib/data.csv compile
	@./$(TARGETDEST)$(TARGET)

test: lib/data.csv compile
	@./$(TARGETDEST)$(ALT_TARGET)

clean:
	@rm -f $(TARGETDEST)$(TARGET)
	@rm -f $(TARGETDEST)$(ALT_TARGET)

lib/data.csv:
	@echo No data.csv detected in lib/, unzipping...
	@unzip -q ./lib/marketing_data.zip
	@mv marketing_sample_for_amazon_com-ecommerce__20200101_20200131__10k_data.csv lib/data.csv