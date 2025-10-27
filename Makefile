SRCS = main.cpp listing.cpp
TARGETDEST = bin/
TARGET = main

default: execute

out: clean compile execute

compile: clean $(SRCS)
	@g++ -g -Wall -std=c++14 $(SRCS) -o $(TARGETDEST)$(TARGET)

execute: lib/data.csv compile
	@./$(TARGETDEST)$(TARGET)

clean:
	@rm -f $(TARGET)

lib/data.csv:
	@echo No data.csv detected in lib/, unzipping...
	@unzip -q ./lib/marketing_data.zip
	@mv marketing_sample_for_amazon_com-ecommerce__20200101_20200131__10k_data.csv lib/data.csv