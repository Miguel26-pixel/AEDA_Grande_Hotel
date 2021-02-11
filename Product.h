//
// Created by aluis on 30/10/2020.
//

#ifndef GRANDE_HOTEL_CENTRAL_PRODUCT_H
#define GRANDE_HOTEL_CENTRAL_PRODUCT_H

#include <string>
class DataBase;

/**
 * Class Product
 * Class to create product
*/
class Product {
    const std::string provider;                                         ///< private string provider

    std::string type;                                                   ///< private string type Hygiene or Cleaning

    int quality;                                                        ///< private int quality

    int price;                                                          ///< privateint price

public:

    Product();
    /**
        * Class constructor
        * @param type
    */
    Product(std::string type);

    /**
        * Class constructor
        * @param type
        * @param price
        * @param quality
    */
    Product(std::string type, int quality, int price);

    /**
        * Class Operator <
        * Return true if product's price is higher
    */

    int getQuality() const;

    /**
        * Class Function
        * Return int price
    */
    int getPrice() const;

    /**
        * Class Function
        * Return string type
    */
    std::string getType() const;

    /**
        * Class Function
        * @param type
        * Set the product's type as equal to the argument
    */
    void setType(std::string type);

    /**
        * Class Function
        * @param quality
        * Set the product's quality as equal to the argument
    */
    void setQuality(int quality);

    /**
        * Class Function
        * @param price
        * Set the product's price as equal to the argument price
    */
    void setPrice(int price);

    /**
        * Class operator ==
        * @param product
        * Compare two different products
        * Return true if they are equal on type , quality and price
    */
    bool operator == (Product product);

    bool operator<(const Product &product);

    /**
        * Class Function
        * Return int quality
    */

};


#endif //GRANDE_HOTEL_CENTRAL_PRODUCT_H
