//
// Created by aluis on 23/12/2020.
//
#include "BuyProduct.h"
#include <vector>

BuyProduct::BuyProduct() {}

BuyProduct::BuyProduct(DataBase * db, Product *name, std::string provider, int rating, int stock) {
    this-> db = db;
    this-> product = name;
    this-> provider = provider;
    this-> rating = rating;
    this-> stock  = stock;
}

BuyProduct::~BuyProduct() {}

int BuyProduct::getValueStock() const {
    return stock;
}

int BuyProduct::getRating() const {
    return rating;
}

Product * BuyProduct::getProduct() const {
    return product;
}

bool BuyProduct::operator<(const BuyProduct &bp1) const {
    if(rating < bp1.getRating()) return true;
    if(rating > bp1.getRating()) return false;
    return (getValueStock() < bp1.getValueStock());
}

bool BuyProduct::operator==(const BuyProduct &bp1) const {
    return (product == bp1.product && rating == bp1.rating && provider == bp1.provider);
}

std::string BuyProduct::getProvider() const {
    return provider;
}

void BuyProduct::setRating(int r) {
    rating = r;
}

void BuyProduct::setProduct(Product *p) {
    product = p;
}

void BuyProduct::setProvider(std::string p) {
    provider = p;
}

void BuyProduct::setStock(int s) {
    stock = s;
}
