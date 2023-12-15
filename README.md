# CPP_Docker_Demo
Quick and Easy CPP Dockerfile Demo  

Docker File :
This Dockerfile will create an image that contains the Ubuntu 18.04 base image, the build-essential package, the g++ compiler, the cmake build tool, and your C++ application code.
Note: CMD specifies the command and it's arguments
```
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
```
To build the image, run the following command:
```
docker build -t c++_app .
```
To view the built images, tags, size etc. run the following
```
docker image list
```
To run the application, run the following command:
```
docker run -p 8080:8080 cpp_app:latest
```
TroubleShooting Tips!
View the location of source code, executable, data etc in the container by executing the below command .. It will open up a bash shell with access to the container
```
docker run -it c++_app:latest bash
```
