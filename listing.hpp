#pragma once
#include <iostream>
#include "linkedList.hpp"

using std::string;

class ItemListing{
    public:
    static ItemListing fromString(string line);
    ItemListing(); // default
    // This is so many paramaters
    ItemListing(string uniqId, string productName, string brandName, string asin, string category, string upcEanCode, string listPrice, string sellingPrice, string quantity, string modelNumber, string aboutProduct, string productSpecification, string technicalDetails, string shippingWeight, string productDimensions, string image, string variants, string sku, string productUrl, string stock, string productDetails, string dimensions, string color, string ingredients, string directionToUse, string isAmazonSeller, string sizeQuantityVariant, string productDescription); // put some arguments
    ItemListing(const ItemListing& obj); // copy constructor
    ItemListing& operator=(const ItemListing& obj);// copy assignment
    bool operator==(ItemListing& rhs);
    bool operator<(ItemListing& rhs);
    bool operator>(ItemListing& rhs);
    //current thought: store all as strings and convert as needed
    string uniqId, productName, brandName, asin, category,
        upcEanCode, listPrice, sellingPrice, quantity, modelNumber, 
        aboutProduct, productSpecification, technicalDetails, shippingWeight, 
        productDimensions, image, variants, sku, productUrl, stock, productDetails, 
        dimensions, color, ingredients, directionToUse, isAmazonSeller, 
        sizeQuantityVariant, productDescription;
    LinkedList<string, int> categories; // the value field doesnt really matter. maybe it will store a count :D
    
};


std::ostream& operator<<(std::ostream& lhs, const ItemListing& rhs);

static string listingInfoLine = "Uniq Id,Product Name,Brand Name,Asin,Category,Upc Ean Code,List Price,Selling Price,Quantity,Model Number,About Product,Product Specification,Technical Details,Shipping Weight,Product Dimensions,Image,Variants,Sku,Product Url,Stock,Product Details,Dimensions,Color,Ingredients,Direction To Use,Is Amazon Seller,Size Quantity Variant,Product Description";
