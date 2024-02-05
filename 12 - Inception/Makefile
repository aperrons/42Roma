ENV = srcs/.env
COMPOSE = srcs/docker-compose.yml

DB_SRC = srcs/mariadb/
NGINX_SRC = srcs/nginx/
WP_SRC = srcs/wordpress/

DB_PORT = 3306
NGINX_PORT = 443
WP_PORT = 9000

DB_NAME = mariadb
NGINX_NAME = nginx
WP_NAME = wordpress

DB_VLM_SRC = /home/ww/Desktop/Inception/srcs/mariadb/data/
DB_VLM_DST = /var/lib/mysql/
SHRD_VLM_SRC = /home/ww/Desktop/Inception/srcs/shared/
SHRD_VLM_DST = /var/www/html/

N_IMAGES := $(shell sudo docker images -q | wc -l)
N_VOLUMES := $(shell sudo docker volume ls -q | wc -l)

all:
	sudo docker-compose -f $(COMPOSE) up -d

stop:
	sudo docker stop $(DB_NAME)
	sudo docker stop $(NGINX_NAME)
	sudo docker stop $(WP_NAME)

start:
	sudo docker start $(DB_NAME)
	sudo docker start $(NGINX_NAME)
	sudo docker start $(WP_NAME)

run:
	sudo docker run $(DB_NAME)
	sudo docker run $(NGINX_NAME)
	sudo docker run $(WP_NAME)

remove: stop
	sudo docker rm $(DB_NAME)
	sudo docker rm $(NGINX_NAME)
	sudo docker rm $(WP_NAME)

clean:
	@echo "Cleaning..."
	@sudo docker-compose -f $(COMPOSE) down --remove-orphans
	@sudo docker system prune
	@if [ $(N_IMAGES) != 0 ]; then sudo docker image rm --force $$(sudo docker images -q); fi
	@if [ $(N_VOLUMES) != 0 ]; then sudo docker volume rm $$(sudo docker volume ls -q); fi
	@sudo rm -rf $(DB_VLM_SRC)
	@sudo rm -rf $(SHRD_VLM_SRC)
	@mkdir -p $(DB_VLM_SRC)
	@mkdir -p $(SHRD_VLM_SRC)
	@sudo systemctl restart docker
	@echo "Cleaned."

re: clean all
