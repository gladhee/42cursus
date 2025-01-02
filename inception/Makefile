all: up

#prepare:
#	@export $(shell grep -v '^#' srcs/.env | xargs) && \
#	mkdir -p $${WP_DATA_PATH} && \
#	mkdir -p $${DB_DATA_PATH}

up:
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
