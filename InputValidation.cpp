//
// Created by marga on 18/11/2020.
//

#include "InputValidation.h"
#include "Exception.h"

/**
*  Return true if nif has nine digits and it's different of zero
*/
void nifValidation(unsigned int int_nif)
{
    unsigned int nif_copy = int_nif;
    std::vector<unsigned int> tmp_nif;
    unsigned int aux;
    do {
        aux = int_nif%10;
        tmp_nif.push_back(aux);
        int_nif /= 10;
    } while (int_nif);

    if (tmp_nif.size() > 9 || nif_copy <= 0) throw InvalidNifException(tmp_nif);
}

bool dateValidation(Date* date1, Date* date2)
{
    if (!((*date2) > (*date1))) throw InvalidDate(*date2);
    if(date1->day > 0 && date1->day <= 31) {
        if (date1->month > 0 && date1->month <= 12)
            if (date1->year >= 2020)
                if (date2->day > 0 && date2->day <= 31)
                    if (date2->month > 0 && date2->month <= 12)
                        if (date2->year >= 2020)
                            return true;

    }
    throw InvalidDate(*date2);
}
