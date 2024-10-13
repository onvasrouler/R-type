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

tests:
	cd build && cd tests && ./r-type_tests

clean:
	rm -rf build

re:
	make clean && make build

doc:
	doxygen Doxyfile && xdg-open docs/html/index.html

.PHONY: build clean server client
