# 🚗 Drive-Thru Ordering System (C++ DSA Project)

This is a **C++ console-based Drive-Thru Ordering System** developed as part of a **Data Structures & Algorithms (DSA)** course project. It uses **linked lists** to manage inventory, process orders, and simulate customer/admin interactions. The system also features **credit card validation using the Luhn Algorithm** — no database is used.

---

## 📌 Project Summary

- Built entirely in C++ (console)
- No database — all data is stored and manipulated using **linked lists**
- Supports **admin-level inventory control** (add, delete, modify products)
- Allows customers to browse and purchase items by category
- Generates a file with **total revenue of the day**
- Includes **credit card number validation using Luhn’s Algorithm**

---

## 🎮 Features

### 🔹 Customer Panel
- Buy from categories:
  - Fast Food
  - BBQ
  - Italian / Mexican cuisines
  - Breakfast / Veg / Seafood / Deserts
- View shopping cart
- Proceed to checkout
- Validate payment using **Luhn’s Algorithm** (basic card verification)

### 🔹 Admin Panel (Password Protected)
- Add, delete, modify products
- Display all products
- View customer order history
- Queue and dequeue customer orders
- View total earned revenue
- Backup current data

---

## 📂 Project Structure
```
DriveThruDSA/
├── README.md # Project documentation
├── main.cpp # Full source code (>3000 lines)
├── total_earned.txt # Output file for daily sales
├── flowchart.png # System design flowchart

```
---

## 🛠️ Algorithms & Data Structures Used

- **Singly Linked Lists** for:
  - Product stock
  - Cart management
- **Queue** for customer orders
- **Luhn Algorithm** for validating credit card numbers

---

## 📸 System Flowchart

The project logic is illustrated in this flowchart:

![Flowchart](flowchart.png)

---

## 🧪 How to Run

1. Open the project in any C++ IDE (e.g., Code::Blocks, Dev C++, VS Code with MinGW).
2. Compile and run `main.cpp`.
3. Follow the on-screen prompts to interact as either **customer** or **admin**.
4. After checkout, a file `total_earned.txt` will store the session’s earnings.

> ✅ Note: This project is entirely console-based and does **not** require any external libraries.

---

## Outputs:
1)Welcome Window:
<img width="500" height="250" alt="image" src="https://github.com/user-attachments/assets/283cac82-07df-479e-b711-dbc18b6b159b" />

2)Customer Menu Window:
<img width="500" height="250" alt="image" src="https://github.com/user-attachments/assets/f937e298-1122-4772-939f-4f77c31930f2" />

3)Cart(Empty):
<img width="500" height="250" alt="image" src="https://github.com/user-attachments/assets/16d7bc1d-3aae-4d1e-a7b0-3bdbe52221f8" />

4)Cart(not-Empty):
<img width="500" height="250" alt="image" src="https://github.com/user-attachments/assets/cc6d0a14-c0bd-4471-b3a8-ff2fcb1fb2a9" />

5)Billing:
<img width="500" height="250" alt="image" src="https://github.com/user-attachments/assets/3bc70b8a-c996-4a71-9da4-ab61a9f9f6de" />

6)Receipt:
<img width="500" height="250" alt="image" src="https://github.com/user-attachments/assets/6c40ac65-e5f5-4ed3-af93-32b78f3dbade" />

7)Admin Login:
<img width="500" height="250" alt="image" src="https://github.com/user-attachments/assets/c5425b45-9492-415c-8ff8-5834a8c1bc8d" />

8)Admin Options:
<img width="608" height="310" alt="image" src="https://github.com/user-attachments/assets/420cd30c-03ab-4c47-8439-cac02eb6eb98" />

---

## 👨‍💻 Author

**Mirza Areeb Baig**  

