# E-Commerce Application in C++

## Overview

The entire code is contained within a **single C++ file** for simplicity and ease of development since the project is relatively small (~200 lines). The focus is on implementing essential features with **robust cart management** and **OOP principles**.

---

## Compile Command and Usage

1. Compile the program using:
   ```bash
   g++ -o ecommerce ecommerce.cpp


## Features

1. **Add Products to Cart**  
   Users can add products from the product catalog to their cart, specifying the quantity.

2. **Remove Products from Cart**  
   - **Option 1:** Remove the product entirely from the cart.  
   - **Option 2:** Remove a specific quantity of the product. If the quantity becomes zero, the product is removed automatically.

3. **View Cart**  
   Displays the list of products in the cart along with their quantity, unit price, total price per product, and the total cost of the cart before applying discounts.

4. **Discounts System**  
   - **Buy 1 Get 1 Free** for products under the **Fashion** category (applicable for quantities of 2 or more).
   - **10% Discount** for **Electronics** products on each item purchased.

5. **Checkout with Currency Conversion**  
   - Calculates the total after applying discounts.  
   - Option to display the total in **different currencies** (e.g., EUR, GBP).  
   - If an unsupported currency is entered, it defaults to **USD**.

6. **Command-Based User Interface**  
   Users interact with the system using commands like `add_to_cart`, `remove_from_cart`, `view_cart`, `checkout`, and more.

---



## Commands Supported

- **add_to_cart**  
  `add_to_cart <product_id> <quantity>` – Add a product to the cart.

- **remove_from_cart**  
  `remove_from_cart <product_id>` – Choose to remove all or part of the product from the cart.

- **view_cart**  
  Displays the contents of the cart along with the total price.

- **checkout**  
  Displays the total amount after applying discounts. Users can choose to convert the total to another currency.

- **list_discounts**  
  Displays the available discounts.

- **exit**  
  Exits the application.

---

