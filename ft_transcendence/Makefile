FILE=./docker-compose.yml

all : build

build :
	docker compose -f $(FILE) build
	docker compose -f $(FILE) up -d

clean :
	docker compose -f $(FILE) down

fclean : clean
	docker system prune -af --volumes

re : fclean build
