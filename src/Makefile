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
command_inventory.o: command/command_inventory.c
	gcc -c command/command_inventory.c
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
inventory.o: inventory/inventory.c
	gcc -c inventory/inventory.c

driver_pick_up : command/driver_pick_up.c list_linked.o tas.o point.o pesanan.o to_do.o in_progress.o pick_up.o queue.o node.o
	gcc command/driver_pick_up.c list_linked.o tas.o point.o pesanan.o to_do.o in_progress.o pick_up.o queue.o node.o
driver_konfigurasi: konfigurasi/driver_konfigurasi.c charmachine.o wordmachine.o point.o map.o node.o pcolor.o pesanan.o konfigurasi.o
	gcc konfigurasi/driver_konfigurasi.c charmachine.o wordmachine.o point.o map.o node.o pcolor.o pesanan.o konfigurasi.o -o driver_konfigurasi
main_driver: main_driver.c node.o charmachine.o wordmachine.o point.o pesanan.o list_linked.o stack.o queue.o matrix.o map.o buy.o drop_off.o help.o in_progress.o move.o pick_up.o to_do.o command_inventory.o inventory.o pcolor.o konfigurasi.o ability.o tas.o
	gcc main_driver.c node.o charmachine.o wordmachine.o point.o pesanan.o list_linked.o stack.o queue.o matrix.o map.o buy.o drop_off.o help.o in_progress.o move.o pick_up.o to_do.o command_inventory.o inventory.o pcolor.o konfigurasi.o ability.o tas.o -o main_driver
