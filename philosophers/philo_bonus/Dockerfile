FROM ubuntu:latest

WORKDIR /app

COPY *.c ./

COPY *.h ./

COPY Makefile ./

RUN apt-get update && apt-get install -y gcc make valgrind

RUN make

# CMD ["./philo_bonus", "100", "210", "100", "100", "10"]
CMD ["valgrind", "--tool=helgrind", "./philo_bonus", "10", "210", "100", "100", "10"]