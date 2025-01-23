FROM    debian:bullseye

RUN apt-get -y update
RUN apt-get -y install nginx openssl tini

# Self-signed certificate 생성
RUN mkdir -p /etc/nginx/ssl/certs /etc/nginx/ssl/private
RUN openssl req -newkey rsa:4096 -x509 -nodes \
       -out /etc/nginx/ssl/certs/heechoi.crt \
       -keyout /etc/nginx/ssl/private/heechoi.key \
       -subj "/C=KR/ST=Seoul/L=Gaepo-dong/O=42Seoul/OU=cadet/CN=heechoi/"

RUN chown www-data:www-data \
    /etc/nginx/ssl/private/heechoi.key \
    /etc/nginx/ssl/certs/heechoi.crt


COPY ./conf/default.conf /etc/nginx/conf.d

RUN mkdir -p /run/nginx

EXPOSE 443

ENTRYPOINT ["/usr/bin/tini", "--"]

CMD ["nginx", "-g", "daemon off;"]