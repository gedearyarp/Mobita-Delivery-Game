charmachine.o: charmachine.c
	gcc -c charmachine.c
wordmachine.o: wordmachine.c
	gcc -c wordmachine.c
point.o: point/point.c
	gcc -c point/point.c
peta.o: peta.c
	gcc -c peta.c
pcolor.o: pcolor/pcolor.c
	gcc -c pcolor/pcolor.c
pesanan.o: pesanan/pesanan.c
	gcc -c pesanan/pesanan.c
konfigurasi.o: konfigurasi.c
	gcc -c konfigurasi.c

test_konfigurasi: test_konfigurasi.c charmachine.o wordmachine.o point.o pcolor.o pesanan.o konfigurasi.o
	gcc test_konfigurasi.c charmachine.o wordmachine.o point.o pcolor.o pesanan.o konfigurasi.o -o test_konfigurasi
test_peta: test_peta.c charmachine.o wordmachine.o point.o peta.o pcolor.o pesanan.o konfigurasi.o
	gcc test_peta.c charmachine.o wordmachine.o point.o peta.o pcolor.o pesanan.o konfigurasi.o -o test_peta