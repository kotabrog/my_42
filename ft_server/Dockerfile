# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksuzuki <ksuzuki@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/25 19:53:05 by ksuzuki           #+#    #+#              #
#    Updated: 2020/08/26 20:33:26 by ksuzuki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

ENV AUTOINDEX=on

RUN apt-get update &&\
	apt-get install -y vim curl\
	nginx\
	default-mysql-server default-mysql-client\
	php-fpm php-mysql php-gd php-mbstring php-xml

COPY srcs/ /tmp/srcs/
EXPOSE 80 443
CMD bash /tmp/srcs/setting.sh && tail -f /dev/null