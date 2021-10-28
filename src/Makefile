charmachine.o: wordmachine/charmachine.c
	gcc -c wordmachine/charmachine.c
wordmachine.o: wordmachine/wordmachine.c
	gcc -c wordmachine/wordmachine.c
point.o: point/point.c
	gcc -c point/point.c
peta.o: peta/peta.c
	gcc -c peta/peta.c
pcolor.o: pcolor/pcolor.c
	gcc -c pcolor/pcolor.c
pesanan.o: pesanan/pesanan.c
	gcc -c pesanan/pesanan.c
konfigurasi.o: konfigurasi/konfigurasi.c
	gcc -c konfigurasi/konfigurasi.c

test_konfigurasi: konfigurasi/test_konfigurasi.c charmachine.o wordmachine.o point.o pcolor.o pesanan.o konfigurasi.o
	gcc konfigurasi/test_konfigurasi.c charmachine.o wordmachine.o point.o pcolor.o pesanan.o konfigurasi.o -o test_konfigurasi
test_peta: peta/test_peta.c charmachine.o wordmachine.o point.o peta.o pcolor.o pesanan.o konfigurasi.o
	gcc peta/test_peta.c charmachine.o wordmachine.o point.o peta.o pcolor.o pesanan.o konfigurasi.o -o test_peta