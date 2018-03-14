
struct Product {
    std::string name;
    float price;
    int stock;
};

void createProducts(Product products[]) {
    Product cocacola;
    cocacola.name = "cocacola";
    cocacola.price = 2.4;
    cocacola.stock = 3;

    Product agua;
    agua.name = "agua";
    agua.price = 1;
    agua.stock = 4;

    products[0] = cocacola;
    products[1] = agua;
}

bool changeAvailable(float change, float price, float money) {
    bool thereIsChange;
    float changeNeeded = money - price;

    if (changeNeeded <= change) {
        thereIsChange = true;
    } else {
        thereIsChange = false;
    }
    return thereIsChange;
}




bool thereIsStock(Product products[], int size) {
    int stockTotal = 0;

    for (size_t i = 0; i < size; i++) {
        stockTotal = stockTotal + products[i].stock;
    }

    return stockTotal > 0;
}





/*bool changeAvailable(float change, float price, float money) {
    return money - price <= change;
}*/

int main () {
    Product products[2];
    createProducts(products);

    float change = 34.34;

    string product = getProduct(products);
    int index = findProduct(product);
    float money = getMoney();
    float price = getPrice(index, prices);
    if (money >= price // devuelve float
            && productAvailable(stock, index) // devuelve bool
            && changeAvailable(change, price, money)) { // devuelve bool
        removeProduct(product, stock);
        giveProduct(product);
        change = giveAndUpdateChange(price, money, change);
        /* giveChange(price, money);
        change = updateChange(money - price, change); */
    }


    int size = sizeof(products) / sizeof(products);
    do {
        // Pedir producto
        float money = gimmeTheMoney();
        // Vender producto (pedir dinero, cambio, stock--...)
    } while (thereIsStock(products, size));











}
