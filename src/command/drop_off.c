/* Fungsi/prosedur yang dipanggil ketika melakukan drop off*/

#include <stdio.h>
#include "../boolean.h"
#include "../stack/stack.h"
#include "../point/point.h"
#include "../pesanan/pesanan.h"

void dropOff (Stack *Tas, POINT p, int *uang)
{
    int plusMoney;
    char dropLoc, type;
    
    dropLoc = Label(DROP_P(TOP(*Tas)));  /* di ADT stack bentuknya ElType = int, tapi harusnya Eltype = Pesanan*/ 
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
    }
}