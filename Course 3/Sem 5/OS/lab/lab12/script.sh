echo "cat test.txt"
cat test.txt
gcc -o lab13b lab13b.c
echo "\n./lab13b"
./lab13b
echo "cat test.txt"
cat test.txt

echo "lab13c-1"
gcc -o lab13c-1 lab13c-1.c
./lab13c-1
echo "lab13c-2"
gcc -o lab13c-2 lab13c-2.c
./lab13c-2

echo "lab13d-1"
gcc lab13d-1.c -lrt -o lab13d-1
./lab13d-1
echo "lab13d-2"
gcc lab13d-2.c -lrt -o lab13d-2
./lab13d-2

echo "lab13em-1"
gcc -o lab13em-1 lab13em-1.c
./lab13em-1
echo "lab13em-2"
gcc -o lab13em-2 lab13em-2.c
./lab13em-2

echo "lab13e-1"
gcc lab13e-1.c -lpthread -lrt -o lab13e-1
./lab13e-1
echo "lab13e-2"
gcc lab13e-2.c -lpthread -lrt -o lab13e-2
./lab13e-2