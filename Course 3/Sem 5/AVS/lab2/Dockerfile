FROM gcc:latest

COPY main.c /src/main.c
RUN chmod +x /src/main.c

RUN gcc src/main.c -o /src/main

CMD ["/src/main"]
