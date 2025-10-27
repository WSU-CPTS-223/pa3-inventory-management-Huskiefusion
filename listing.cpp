#include "listing.hpp"

ItemListing ItemListing::fromString(string line){
    
    return ItemListing();
}

ItemListing::ItemListing(){ // default
    this->uniqId = "";
    this->productName = "";
    this->brandName = "";
    this->asin = "";
    this->category = "";
    this->upcEanCode = "";
    this->ListPrice = "";
    this->sellingPrice = "";
    this->quantity = "";
    this->modelNumber = "";
    this->aboutProduct = "";
    this->productSpecification = "";
    this->technicalDetails = "";
    this->shippingWeight = "";
    this->productDimensions = "";
    this->image = "";
    this->variants = "";
    this->sku = "";
    this->productUrl = "";
    this->stock = "";
    this->productDetails = "";
    this->dimensions = "";
    this->color = "";
    this->ingredients = "";
    this->directionToUse = "";
    this->isAmazonSeller = "";
    this->sizeQuantityVariant = "";
    this->productDescription = "";
} // default 

ItemListing::ItemListing(string uniqId, string productName, string brandName, string asin, string category, string upcEanCode, string ListPrice, string sellingPrice, string quantity, string modelNumber, string aboutProduct, string productSpecification, string technicalDetails, string shippingWeight, string productDimensions, string image, string variants, string sku, string productUrl, string stock, string productDetails, string dimensions, string color, string ingredients, string directionToUse, string isAmazonSeller, string sizeQuantityVariant, string productDescription){ // put some arguments
    this->uniqId = uniqId;
    this->productName = productName;
    this->brandName = brandName;
    this->asin = asin;
    this->category = category;
    this->upcEanCode = upcEanCode;
    this->ListPrice = ListPrice;
    this->sellingPrice = sellingPrice;
    this->quantity = quantity;
    this->modelNumber = modelNumber;
    this->aboutProduct = aboutProduct;
    this->productSpecification = productSpecification;
    this->technicalDetails = technicalDetails;
    this->shippingWeight = shippingWeight;
    this->productDimensions = productDimensions;
    this->image = image;
    this->variants = variants;
    this->sku = sku;
    this->productUrl = productUrl;
    this->stock = stock;
    this->productDetails = productDetails;
    this->dimensions = dimensions;
    this->color = color;
    this->ingredients = ingredients;
    this->directionToUse = directionToUse;
    this->isAmazonSeller = isAmazonSeller;
    this->sizeQuantityVariant = sizeQuantityVariant;
    this->productDescription = productDescription;
} 
ItemListing::ItemListing(const ItemListing& obj){ // copy constructor
    this->uniqId = obj.uniqId;
    this->productName = obj.productName;
    this->brandName = obj.brandName;
    this->asin = obj.asin;
    this->category = obj.category;
    this->upcEanCode = obj.upcEanCode;
    this->ListPrice = obj.ListPrice;
    this->sellingPrice = obj.sellingPrice;
    this->quantity = obj.quantity;
    this->modelNumber = obj.modelNumber;
    this->aboutProduct = obj.aboutProduct;
    this->productSpecification = obj.productSpecification;
    this->technicalDetails = obj.technicalDetails;
    this->shippingWeight = obj.shippingWeight;
    this->productDimensions = obj.productDimensions;
    this->image = obj.image;
    this->variants = obj.variants;
    this->sku = obj.sku;
    this->productUrl = obj.productUrl;
    this->stock = obj.stock;
    this->productDetails = obj.productDetails;
    this->dimensions = obj.dimensions;
    this->color = obj.color;
    this->ingredients = obj.ingredients;
    this->directionToUse = obj.directionToUse;
    this->isAmazonSeller = obj.isAmazonSeller;
    this->sizeQuantityVariant = obj.sizeQuantityVariant;
    this->productDescription = obj.productDescription;
}
ItemListing& ItemListing::operator=(const ItemListing& obj){ // copy assignment
    this->uniqId = obj.uniqId;
    this->productName = obj.productName;
    this->brandName = obj.brandName;
    this->asin = obj.asin;
    this->category = obj.category;
    this->upcEanCode = obj.upcEanCode;
    this->ListPrice = obj.ListPrice;
    this->sellingPrice = obj.sellingPrice;
    this->quantity = obj.quantity;
    this->modelNumber = obj.modelNumber;
    this->aboutProduct = obj.aboutProduct;
    this->productSpecification = obj.productSpecification;
    this->technicalDetails = obj.technicalDetails;
    this->shippingWeight = obj.shippingWeight;
    this->productDimensions = obj.productDimensions;
    this->image = obj.image;
    this->variants = obj.variants;
    this->sku = obj.sku;
    this->productUrl = obj.productUrl;
    this->stock = obj.stock;
    this->productDetails = obj.productDetails;
    this->dimensions = obj.dimensions;
    this->color = obj.color;
    this->ingredients = obj.ingredients;
    this->directionToUse = obj.directionToUse;
    this->isAmazonSeller = obj.isAmazonSeller;
    this->sizeQuantityVariant = obj.sizeQuantityVariant;
    this->productDescription = obj.productDescription;
    return *this;
} 
bool ItemListing::operator==(ItemListing& rhs){ 
    return uniqId == rhs.uniqId; 
}
bool ItemListing::operator<(ItemListing& rhs){ 
    return uniqId < rhs.uniqId; 
}
bool ItemListing::operator>(ItemListing& rhs){
    return uniqId > rhs.uniqId; 
}