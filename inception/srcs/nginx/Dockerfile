FROM alpine:3.20
LABEL authors="heesungchoi"

# Install nginx
RUN apk update && apk add --no-cache nginx openssl

COPY ./inception.crt /etc/ssl/certs/inception.crt
COPY ./inception.key /etc/ssl/private/inception.key

CMD chmod 600 /etc/ssl/certs/inception.crt /etc/ssl/private/inception.key
CMd chown nginx:nginx /etc/ssl/private/inception.key /etc/ssl/certs/inception.crt

# Copy the configuration file
COPY conf/www.conf /etc/nginx/http.d/www.conf

# Expose the port
EXPOSE 443

# Start the server
CMD ["nginx", "-g", "daemon off;"]