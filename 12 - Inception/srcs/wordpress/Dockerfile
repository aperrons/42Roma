FROM debian:buster

RUN apt update -y
RUN apt upgrade -y
RUN apt install php-mysql -y
RUN apt install php-fpm -y
RUN apt install wget -y
RUN apt install mariadb-client -y

RUN mkdir -p /run/php && chown www-data:www-data /run/php
COPY tools/www.conf /etc/php/7.3/fpm/pool.d

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN cp wp-cli.phar /usr/bin/wp

EXPOSE 9000

COPY tools/config.sh /config.sh

CMD chown root config.sh && chmod 750 config.sh && ./config.sh

