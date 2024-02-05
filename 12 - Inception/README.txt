sudo docker network create vlan
sudo docker run -d --name mariadb -v /home/ww/Desktop/Inception/mariadb/data:/var/www/html --net vlan -p 3306:3306 --env-file ../.env mariadb
sudo docker run -d --name wordpress -v /home/ww/Desktop/Inception/shared:/var/www/html --net vlan -p 9000:9000 --env-file ../.env wordpress
sudo docker run -d --name nginx -v /home/ww/Desktop/Inception/shared:/var/www/html --net vlan -p 443:443 --env-file ../.env nginx
sudo vim /etc/hosts
