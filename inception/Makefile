DOCKER_COMPOSE = -f srcs/docker-compose.yml

all: setup build up

setup:
	mkdir -p /home/nbonnet/data/db /home/nbonnet/data/www

build:
	docker compose $(DOCKER_COMPOSE) build

up:
	docker compose $(DOCKER_COMPOSE) up -d

ps:
	docker compose $(DOCKER_COMPOSE) ps

down:
	docker compose $(DOCKER_COMPOSE) down

clean:
	docker compose $(DOCKER_COMPOSE) down -v

fclean:
	docker compose $(DOCKER_COMPOSE) down -v --rmi all
	docker builder prune -a -f
	sudo rm -rf /home/nbonnet/data/

re: fclean all

.PHONY: all setup build up ps down clean fclean re
