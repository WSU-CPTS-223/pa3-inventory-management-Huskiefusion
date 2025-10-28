#include "listing.hpp"

using std::cout;
using std::endl;
ItemListing ItemListing::fromString(string line){
    ItemListing tmp;
    int index = line.find(","); // First, get the uniqID
    tmp.uniqId = line.substr(0, index);
    line.erase(0, index+1);
    // now product name
    if(line[0]=='\"'){
        index = line.find("\",");
        tmp.productName = line.substr(1, index-1); // start at 1 to remove quote mark, -1 to offest
        line.erase(0, index+2); // +2 to clear the quote and the comma
    }
    else{
        index = line.find(",");
        tmp.productName = line.substr(0, index);
        line.erase(0, index+1); // +1 to clear the comma
    }
    // brand name (it doesnt actually exist for any of them)
    index = line.find(",");
    tmp.asin = (index==0)? "NA" : line.substr(0, index);
    line.erase(0, index+1);


    // fix the formatting of the name (eg. "" and '', maybe others?)
    // now we do the asin (this also doesnt exist for any of them)
    index = line.find(",");
    tmp.asin = (index==0)? "NA" : line.substr(0, index);
    line.erase(0, index+1);

    // now for category, this should maybe be a list?
    string categoryString;
    if(line[0]=='\"'){
        index = line.find("\",");
        categoryString = line.substr(1, index-1); // start at 1 to remove quote mark, -1 to offest
        line.erase(0, index+2); // +2 to clear the quote and the comma
    }
    else{
        index = line.find(",");
        categoryString = line.substr(0, index);
        line.erase(0, index+1); // +1 to clear the comma
    }
    
    index=categoryString.find(" | ");
    while(index!=-1){
        cout << categoryString.substr(0, index) << endl;
        categoryString.erase(0, index+3);
        index=categoryString.find(" | ");
    }


    cout << categoryString << endl;
    
    //while()
    return tmp;
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

std::ostream& operator<<(std::ostream& lhs, ItemListing& rhs){
    lhs << rhs.uniqId <<", "<< rhs.productName << ", " << rhs.category;
    return lhs;
}