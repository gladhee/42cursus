FROM alpine:3.20
LABEL authors="heesungchoi"

# Install nginx
RUN apk update && apk add --no-cache nginx openssl

# Self-signed certificate 생성
RUN mkdir -p /etc/nginx/ssl/certs /etc/nginx/ssl/private
RUN openssl req -newkey rsa:4096 -x509 -nodes \
       -out /etc/nginx/ssl/certs/heechoi.crt \
       -keyout /etc/nginx/ssl/private/heechoi.key \
       -subj "/C=KR/ST=Seoul/L=Gaepo-dong/O=42Seoul/OU=cadet/CN=heechoi/"

RUN chmod 600 /etc/nginx/ssl/certs/heechoi.crt /etc/nginx/ssl/private/heechoi.key
RUN chown nginx:nginx /etc/nginx/ssl/private/heechoi.key /etc/nginx/ssl/certs/heechoi.crt

COPY ./conf/default.conf /etc/nginx/conf.d

# Copy the configuration file
COPY conf/default.conf /etc/nginx/http.d/default.conf

# Expose the port
EXPOSE 443

# Start the server
CMD ["nginx", "-g", "daemon off;"]