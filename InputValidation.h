//
// Created by marga on 18/11/2020.
//

#ifndef GRANDE_HOTEL_CENTRAL_INPUTVALIDATION_H
#define GRANDE_HOTEL_CENTRAL_INPUTVALIDATION_H
#include "Client.h"
#include "Date.h"

#include <iostream>

/**
*  Function to validate the nif number
*  @param int_nif
*  Return true if nif has nine digits and it's different of zero
*/
void nifValidation(unsigned int int_nif);
bool dateValidation(Date* date1, Date* date2);

#endif //GRANDE_HOTEL_CENTRAL_INPUTVALIDATION_H
