//
// Created by aluis on 23/12/2020.
//

#ifndef GRANDE_HOTEL_CENTRAL_BUYPRODUCT_H
#define GRANDE_HOTEL_CENTRAL_BUYPRODUCT_H

#include <queue>

#include "Product.h"
#include "DataBase.h"

/**
 * ##Class BuyProduct
 * BuyProduct is only accessed by the manager
 * Product is transferred to vector stock_products after being bought
 */
class BuyProduct {
    std::string provider;
    Product * product;
    int rating;
    DataBase * db;
    int stock = 0;

public:
    BuyProduct();
    ~BuyProduct();

    BuyProduct(DataBase * db, Product * name, std::string provider, int rating, int stock);

    int getValueStock() const;

    Product * getProduct() const;

    std::string getProvider() const;

    bool operator < (const BuyProduct &bp1) const ;

    bool operator == (const BuyProduct &bp1) const;

    int getRating() const;

    void setRating(int r);
    void setProduct(Product*p);
    void setProvider(std::string p);
    void setStock(int s);

};



#endif //GRANDE_HOTEL_CENTRAL_BUYPRODUCT_H
