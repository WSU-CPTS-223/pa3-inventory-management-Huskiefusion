SRCS = main.cpp listing.cpp
TARGETDEST = bin/
TARGET = main

default: execute

out: clean compile execute

compile: clean $(SRCS)
	@g++ -g -Wall -std=c++14 $(SRCS) -o $(TARGETDEST)$(TARGET)

execute: compile lib/data.csv
	@./$(TARGETDEST)$(TARGET)

clean:
	@rm -f $(TARGET)

lib/data.csv:
	@unzip -q ./lib/marketing_data.zip
	@mv marketing_sample_for_amazon_com-ecommerce__20200101_20200131__10k_data.csv lib/data.csv