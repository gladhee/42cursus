FROM ubuntu:latest

LABEL authors="heechoi"

WORKDIR /app

COPY *.c ./

COPY *.h ./

COPY Makefile ./

RUN apt-get update

RUN apt-get install -y gcc make valgrind

RUN make

CMD ["valgrind", "--tool=helgrind", "./philo", "100", "800", "200", "200"]