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

driver_command_inventory: command/driver_command_inventory.c node.o charmachine.o wordmachine.o point.o pesanan.o list_linked.o stack.o queue.o matrix.o map.o buy.o drop_off.o help.o in_progress.o move.o pick_up.o to_do.o command_inventory.o inventory.o pcolor.o konfigurasi.o ability.o tas.o
	gcc command/driver_command_inventory.c node.o charmachine.o wordmachine.o point.o pesanan.o list_linked.o stack.o queue.o matrix.o map.o buy.o drop_off.o help.o in_progress.o move.o pick_up.o to_do.o command_inventory.o inventory.o pcolor.o konfigurasi.o ability.o tas.o -o driver_command_inventory
driver_buy: command/driver_buy.c node.o charmachine.o wordmachine.o point.o pesanan.o list_linked.o stack.o queue.o matrix.o map.o buy.o drop_off.o help.o in_progress.o move.o pick_up.o to_do.o command_inventory.o inventory.o pcolor.o konfigurasi.o ability.o tas.o
	gcc command/driver_buy.c node.o charmachine.o wordmachine.o point.o pesanan.o list_linked.o stack.o queue.o matrix.o map.o buy.o drop_off.o help.o in_progress.o move.o pick_up.o to_do.o command_inventory.o inventory.o pcolor.o konfigurasi.o ability.o tas.o -o driver_buy
driver_ability: ability/driver_ability.c node.o charmachine.o wordmachine.o point.o pesanan.o list_linked.o stack.o queue.o matrix.o map.o buy.o drop_off.o help.o in_progress.o move.o pick_up.o to_do.o command_inventory.o inventory.o pcolor.o konfigurasi.o ability.o tas.o
	gcc ability/driver_ability.c node.o charmachine.o wordmachine.o point.o pesanan.o list_linked.o stack.o queue.o matrix.o map.o buy.o drop_off.o help.o in_progress.o move.o pick_up.o to_do.o command_inventory.o inventory.o pcolor.o konfigurasi.o ability.o tas.o -o driver_ability
driver_pesanan: pesanan/driver_pesanan.c pesanan.o point.o
	gcc pesanan/driver_pesanan.c pesanan.o point.o -o driver_pesanan
driver_drop_off : command/driver_drop_off.c list_linked.o tas.o point.o pesanan.o to_do.o in_progress.o drop_off.o queue.o node.o ability.o
	gcc command/driver_drop_off.c list_linked.o tas.o point.o pesanan.o to_do.o in_progress.o drop_off.o queue.o node.o ability.o -o driver_drop_off
driver_pick_up : command/driver_pick_up.c list_linked.o tas.o point.o pesanan.o to_do.o in_progress.o pick_up.o queue.o node.o
	gcc command/driver_pick_up.c list_linked.o tas.o point.o pesanan.o to_do.o in_progress.o pick_up.o queue.o node.o -o driver_pick_up
driver_konfigurasi: konfigurasi/driver_konfigurasi.c to_do.o list_linked.o stack.o queue.o charmachine.o wordmachine.o point.o map.o node.o pcolor.o pesanan.o konfigurasi.o
	gcc konfigurasi/driver_konfigurasi.c to_do.o list_linked.o stack.o queue.o charmachine.o wordmachine.o point.o map.o node.o pcolor.o pesanan.o konfigurasi.o -o driver_konfigurasi
driver_move: command/driver_move.c node.o charmachine.o wordmachine.o point.o pesanan.o list_linked.o stack.o queue.o matrix.o move.o konfigurasi.o ability.o tas.o
	gcc command/driver_move.c node.o charmachine.o wordmachine.o point.o pesanan.o list_linked.o stack.o queue.o matrix.o move.o konfigurasi.o ability.o tas.o -o driver_move
driver_in_progress: command/driver_in_progress.c in_progress.o queue.o node.o list_linked.o point.o pesanan.o tas.o to_do.o
	gcc command/driver_in_progress.c in_progress.o queue.o node.o list_linked.o point.o pesanan.o tas.o to_do.o -o driver_in_progress
driver_to_do: command/driver_to_do.c to_do.o queue.o list_linked.o node.o pesanan.o point.o
	gcc command/driver_to_do.c to_do.o queue.o list_linked.o node.o pesanan.o point.o -o driver_to_do
driver_map: command/driver_map.c to_do.o list_linked.o stack.o queue.o charmachine.o wordmachine.o point.o map.o node.o pcolor.o pesanan.o konfigurasi.o
	gcc command/driver_map.c to_do.o list_linked.o stack.o queue.o charmachine.o wordmachine.o point.o map.o node.o pcolor.o pesanan.o konfigurasi.o -o driver_map
main_driver: main_driver.c node.o charmachine.o wordmachine.o point.o pesanan.o list_linked.o stack.o queue.o matrix.o map.o buy.o drop_off.o help.o in_progress.o move.o pick_up.o to_do.o command_inventory.o inventory.o pcolor.o konfigurasi.o ability.o tas.o
	gcc main_driver.c node.o charmachine.o wordmachine.o point.o pesanan.o list_linked.o stack.o queue.o matrix.o map.o buy.o drop_off.o help.o in_progress.o move.o pick_up.o to_do.o command_inventory.o inventory.o pcolor.o konfigurasi.o ability.o tas.o -o main_driver
