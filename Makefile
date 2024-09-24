##
## EPITECH PROJECT, 2024
## SURVIVOR
## File description:
## Makefile
##

build:
	mkdir build && cd build && cmake .. && cmake --build .

client:
	cd build && cd client && ./r-type_client

server:
	cd build && cd server && ./r-type_server

clean:
	rm -rf build

re:
	cd build && cmake --build .

.PHONY: build clean server client
