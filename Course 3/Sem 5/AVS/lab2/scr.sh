#!/bin/bash

echo "Собираем образ с текущим докерфайлом:"
sudo docker build -t myc .
echo "Запускаем собранный образ:"
cid="$(sudo docker run -d -p 8080:3000 myc)"
echo "$cid"

echo "---------------------------"
echo "Проверяем образ:"
sudo docker ps
echo "---------------------------"
ipdocker="$(sudo docker inspect -f '{{range .NetworkSettings.Networks}}{{.IPAddress}}{{end}}' "$cid")"
echo "$ipdocker"

echo "---------------------------"
echo "Запускаем программу в докере"
sudo docker exec -it "$cid" /src/main /src/main.c
echo "---------------------------"


echo "Изоляция"
# Изоляция файловой системы: Создайте файл внутри контейнера
sudo docker exec -it "$cid" touch /my_file_inside_container.txt
# Изоляция процессов: Выведите информацию о процессах внутри контейнера

sudo docker exec -it "$cid" ps aux
