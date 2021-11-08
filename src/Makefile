charmachine.o: ADT/wordmachine/charmachine.c
	gcc -c ADT/wordmachine/charmachine.c
wordmachine.o: ADT/wordmachine/wordmachine.c
	gcc -c ADT/wordmachine/wordmachine.c
node.o : ADT/list_linked/node.c
	gcc -c ADT/list_linked/node.c
point.o: ADT/point/point.c
	gcc -c ADT/point/point.c
list_linked.o: ADT/list_linked/list_linked.c
	gcc -c ADT/list_linked/list_linked.c
stack.o: ADT/stack/stack.c
	gcc -c ADT/stack/stack.c
queue.o: ADT/queue/queue.c
	gcc -c ADT/queue/queue.c
matrix.o: ADT/matrix/matrix.c
	gcc -c ADT/matrix/matrix.c
map.o: command/map.c
	gcc -c command/map.c
buy.o: command/buy.c
	gcc -c command/buy.c
drop_off.o: command/drop_off.c
	gcc -c command/drop_off.c
help.o: command/help.c
	gcc -c command/help.c
in_progress.o: command/in_progress.c
	gcc -c command/in_progress.c
move.o: command/move.c
	gcc -c command/move.c
pick_up.o: command/pick_up.c
	gcc -c command/pick_up.c
to_do.o: command/to_do.c
	gcc -c command/to_do.c
inventory.o: command/inventory.c
	gcc -c command/inventory.c
pcolor.o: pcolor/pcolor.c
	gcc -c pcolor/pcolor.c
pesanan.o: pesanan/pesanan.c
	gcc -c pesanan/pesanan.c
konfigurasi.o: konfigurasi/konfigurasi.c
	gcc -c konfigurasi/konfigurasi.c
ability.o: ability/ability.c
	gcc -c ability/ability.c
tas.o: tas/tas.c
	gcc -c tas/tas.c
driver_konfigurasi: konfigurasi/driver_konfigurasi.c charmachine.o wordmachine.o point.o map.o node.o pcolor.o pesanan.o konfigurasi.o
	gcc konfigurasi/driver_konfigurasi.c charmachine.o wordmachine.o point.o map.o node.o pcolor.o pesanan.o konfigurasi.o -o driver_konfigurasi
main_driver: main_driver.c charmachine.o wordmachine.o point.o pesanan.o list_linked.o stack.o queue.o matrix.o map.o buy.o drop_off.o help.o in_progress.o move.o pick_up.o to_do.o inventory.o pcolor.o pesanan.o konfigurasi.o ability.o tas.o
	gcc main_driver.c charmachine.o wordmachine.o point.o pesanan.o list_linked.o stack.o queue.o matrix.o map.o buy.o drop_off.o help.o in_progress.o move.o pick_up.o to_do.o inventory.o pcolor.o pesanan.o konfigurasi.o ability.o tas.o -o main_driver

 