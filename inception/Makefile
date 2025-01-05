all: up

prepare:
	mkdir -p ./srcs/data/wordpressw && \
	mkdir -p ./srcs/data/mariadb

up: prepare
	@docker-compose -f srcs/docker-compose.yaml up -d --build

down:
	@docker-compose -f srcs/docker-compose.yaml down -v

start:
	@docker-compose -f srcs/docker-compose.yaml start

stop:
	@docker-compose -f srcs/docker-compose.yaml stop

status:
	@docker ps

re: down up
