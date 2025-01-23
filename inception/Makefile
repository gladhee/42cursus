all : up

up :
	if [ ! -d "/home/heechoi/data" ]; then \
		mkdir /home/heechoi/data; \
	fi
	if [ ! -d "/home/heechoi/data/html" ]; then \
		mkdir /home/heechoi/data/html; \
	fi
	if [ ! -d "/home/heechoi/data/mysql" ]; then \
		mkdir /home/heechoi/data/mysql; \
	fi
	docker compose -f srcs/docker-compose.yml up --build

down :
	docker compose -f srcs/docker-compose.yml down

clean : down
	docker stop $$(docker ps -q); \
	docker rm $$(docker ps -a -q); \
	docker image rmi -f $$(docker image ls -q); \
	docker volume rm $$(docker volume ls -q); \
	docker builder prune -f

	rm -rf /home/heechoi/data/html/*
	rm -rf /home/heechoi/data/mysql/*

.PHONY : all up down clean
