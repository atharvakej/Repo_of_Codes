#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

// Product class definition
class Product {
public:
    string id;
    string name;
    double price;
    string category;

    // Default constructor
    Product() : id(""), name(""), price(0.0), category("") {}

    // Parameterized constructor
    Product(const string& id, const string& name, float price, const string& category)
        : id(id), name(name), price(price), category(category) {}
};

// CartItem class definition
class CartItem {
public:
    Product product;
    int quantity;

    // Default constructor
    CartItem() : product(), quantity(0) {}

    // Parameterized constructor
    CartItem(const Product& product, int quantity) : product(product), quantity(quantity) {}
};

// Cart class definition
class Cart {
public:
    unordered_map<string, CartItem>& getItems() {
        // Return a reference to the items map
        return items;
    }

    const unordered_map<string, CartItem>& getItems() const {
        // Return a const reference to the items map
        return items;
    }
private:
    unordered_map<string, CartItem> items;
};

// Discount class to apply discount rules
class Discount {
public:
    static float applyDiscount(const Cart& cart) {
        float discount = 0;
        for (const auto& itemPair : cart.getItems()) {
            const auto& item = itemPair.second;
            const Product& product = item.product;
            if (product.category == "Fashion" && item.quantity >= 2) {
                discount += (product.price * (item.quantity / 2)); // Buy 1 Get 1 Free
                cout << "Buy 1 Get 1 Free on " << product.name << " applied.\n";
            } else if (product.category == "Electronics") {
                discount += product.price * item.quantity * 0.10; // 10% off
                cout << "10% Off on " << product.name << " applied.\n";
            }
        }
        return discount;
    }
};

// CurrencyConverter class for converting total cost
class CurrencyConverter {
public:
    static float convert(float amount, const string& currency) {
        unordered_map<string, float> rates = {{"EUR", 0.85}, {"GBP", 0.75}};
        if (rates.find(currency) != rates.end()) {
            return amount * rates[currency];
        }
        cout << "Currency not supported. Showing in USD.\n";
        return amount;
    }
};

// Initialize product catalog with sample products
unordered_map<string, Product> initializeProductCatalog() {
    return {
        {"P001", Product("P001", "Laptop", 1000.00, "Electronics")},
        {"P002", Product("P002", "Phone", 500.00, "Electronics")},
        {"P003", Product("P003", "T-Shirt", 20.00, "Fashion")}
    };
}

// Display available discounts
void listDiscounts() {
    cout << "Available Discounts:\n";
    cout << "1. Buy 1 Get 1 Free on Fashion items\n";
    cout << "2. 10% Off on Electronics\n";
}

int main() {
    unordered_map<string, Product> productCatalog = initializeProductCatalog();
    Cart cart;

    string command;
    while (true) {
        cout << "Enter command (add_to_cart, remove_from_cart, view_cart, checkout, discounts, exit): ";
        cin >> command;

        if (command == "add_to_cart") {
            string productId;
            int quantity;
            cin >> productId >> quantity;

            if (productCatalog.find(productId) != productCatalog.end()) {
                const Product& product = productCatalog[productId];
                cart.getItems()[productId] = CartItem(product, quantity);
                cout << "Added " << quantity << " of " << product.name << " to cart.\n";
            } else {
                cout << "Product not found.\n";
            }
        } else if (command == "remove_from_cart") {
            string productId;
            // cout << "Enter product ID: ";
            cin >> productId;
            // cout<<endl;
            cout<<"Do you want to Remove Entire Product ? (yes/no)"<<endl;
            string consent;
            cin>>consent;
            if(consent=="yes"){
            if (cart.getItems().find(productId) != cart.getItems().end()) {
                cart.getItems().erase(productId);
                cout << "Removed " << productId << " from cart.\n";
            } else {
                cout << "Product not in cart.\n";
            }
            }
            else{
                cout<<"Enter Quantity to Remove: "<<endl;
                int qt;
                cin>>qt;


            if (cart.getItems().find(productId) != cart.getItems().end()) {
                int prevcount = cart.getItems()[productId].quantity;
                if((prevcount<=qt)){

                 cart.getItems().erase(productId);
                 cout << "Removed " << productId << "from cart.\n";
                }
                else{
                    cart.getItems()[productId].quantity=prevcount-qt;
                }
            } else {
                cout << "Product not in cart.\n";
            }


            }
        } else if (command == "view_cart") {
            cout << "Your Cart:\n";
            double total = 0;
            int i=1;
            for (const auto& itemPair : cart.getItems()) {
                const auto& item = itemPair.second;
                total += item.product.price*(item.quantity);
                cout <<i<<"."<<" "<<item.product.name << " - Quantity: " << item.quantity <<", Price: "<<item.product.price<<" USD,"
                <<"Total: "<<item.product.price*(item.quantity)<<" USD"<<endl;
                i++;
            }
            cout<<"Total (before discounts) : "<<fixed<<setprecision(2)<<total<<" USD"<<endl;
        } else if (command == "checkout") {
            float total = 0;
            cout << "Applying Discounts ...."<< "\n";
            for (const auto& itemPair : cart.getItems()) {
                const auto& item = itemPair.second;
                total += item.product.price * item.quantity;
            }
            float discount = Discount::applyDiscount(cart);
            float finalTotal = total - discount;
            cout << "Final Total in USD: " << total << "\n";
            // cout << "Discount: " << discount << "\n";
            cout<<"Would you like to view it in a different currency ? (yes/no):";
            string currency;
            string consent;
            cin>>consent;
            if(consent=="YES"){
            cout << "Available Currencies: EUR, GBP\n";
            cout << "Enter currency: ";
            cin>>currency;
            cout << "Final Total in "<<currency<<" "<<finalTotal << "\n";
            }
            else{
            cout << "Final Total in USD: " << finalTotal << "\n";
            }
            // float convertedTotal = CurrencyConverter::convert(finalTotal, currency);
            // cout << "Final Total in " << currency << ": " << convertedTotal << " " << currency << "\n";
        } else if (command == "list_discounts") {
            listDiscounts();
        } else if (command == "exit") {
            break;
        } else {
            cout << "Invalid command. Please try again.\n";
        }
    }

    return 0;
}