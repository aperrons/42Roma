FROM debian:buster

RUN apt update -y
RUN apt upgrade -y
RUN apt install mariadb-server -y

EXPOSE 3306

COPY tools/50-server.cnf /etc/mysql/mariadb.conf.d/
COPY tools/init.sh init.sh

ENTRYPOINT chmod 777 init.sh && ./init.sh
#CMD /bin/bash
