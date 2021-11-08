/* Fungsi/prosedur yang dipanggil ketika melakukan drop off*/

#include <stdio.h>
#include "drop_off.h"

#define IDX_UNDEF -1

void drop_OffCommand(Tas *Tas, POINT p, int *uang, int currTime, int *speedBoostTime, boolean *speedBoostActive)
{
    /* Prosedur untuk drop off jika drop location barang paling atas di tas sama dengan lokasi user. 
       Jika tidak sama, tidak akan di drop off */

    /* KAMUS LOKAL */
    Pesanan pesanan;
    int plusMoney;
    char dropLoc, type;
    
    /* ALGORITMA */
    dropLoc = Label(DROP_P(TOP(*Tas)));
    type = TYPE(TOP(*Tas));

    if (Label(p) != dropLoc)
    {
        printf("Tidak dapat pesanan yang dapat diantarkan!\n");
    }
    else if (Label(p) == dropLoc)
    {
        if (type == 'N')
        {
            plusMoney = 200;
            printf("Pesanan Normal Item berhasil diantarkan\n");
        }
        else if (type == 'H')
        {
            plusMoney = 400;
            printf("Pesanan Heavy Item berhasil diantarkan\n");
            *speedBoostTime=0;
            *speedBoostActive=true;
        }
        else if (type = 'P')
        {
            plusMoney = 400;
            printf("Pesanan Perishable Item berhasil diantarkan\n");

        }
        else if (type = 'V')
        {
            plusMoney = 600;
            printf("Pesanan VIP Item berhasil diantarkan\n");
        }

        *uang += plusMoney;
        printf("Uang yang didapatkan: %d Yen\n", plusMoney);
        pop(Tas, &pesanan);
    }
}
