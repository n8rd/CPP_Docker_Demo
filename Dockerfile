FROM ubuntu:18.04

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    g++ \
    libstdc++6-8-dbg

COPY . /app

WORKDIR /app

RUN cmake . && make

CMD ["/app/cpp_app","data.csv",","]