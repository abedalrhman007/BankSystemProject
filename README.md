# 🏦 Bank Management System

> 💻 A fully-featured console-based banking system developed in C++ using Object-Oriented Programming (OOP) principles.

The project simulates real-world banking operations including authentication, client management, transactions, permissions, and currency exchange. This system demonstrates strong OOP design principles in C++ through a modular, scalable, and maintainable architecture.

---

## 📌 Project Overview
*   **💾 File-Based Data Persistence:** Reliable storage using local text files.
*   **🔒 Secure Storage:** Encrypted handling of sensitive user information.
*   **🧱 Layered Architecture:** Clean separation of UI, business logic, and data access.
*   **🧠 Modular Design:** Highly maintainable codebase with a clear separation of responsibilities.

---

## 🛠️ Technologies Used
*   **Language:** C++
*   **Core Concepts:** Object-Oriented Programming (OOP)
*   **Storage:** File Handling (`fstream`)
*   **Libraries:** Standard Template Library (STL - `vector`, `string`)
*   **Security:** Custom encryption/decryption system
*   **Interface:** Menu-driven Console UI with status indicators

---

## 🧱 System Architecture & Features

### 🔐 Authentication & Security
*   **Secure Login:** Includes a 3-attempt lockout limit.
*   **Encrypted Credentials:** Passwords are encrypted before file storage.
*   **Session Tracking:** Logs all login activity to a dedicated register.
*   **Role-Based Access:** System functionality is restricted based on user permissions.

### 🧑‍💼 User Management
*   **CRUD Operations:** Add ➕, Update ✏️, and Delete ❌ users.
*   **Access Control:** Assign and manage specific administrative permissions.
*   **Audit Trails:** Track and view user login history.

### 👥 Client Management
*   **Client Database:** Add ➕, Update ✏️, and Delete ❌ client records.
*   **Search & View:** Search for specific clients or display the full registry.

### 💰 Transactions System
*   **Core Banking:** Deposit 💵 and Withdraw 💸 funds.
*   **Transfers:** Seamlessly transfer money between client accounts 🔄.
*   **Ledger:** Comprehensive transaction history tracking 📜.

### 🌍 Currency Exchange System
*   **Live Data:** Load currency rates directly from system files 📂.
*   **Search Engine:** Find currencies by code or country 🔍.
*   **Rate Management:** Update exchange rates dynamically ♻️.
*   **Conversion Engine:** USD-based conversion calculations 💲.

---

## 🔑 Permissions System
The system utilizes **bitwise permission control** for highly flexible and efficient role management. Administrators can grant combinations of the following access rights:
*   📋 View Clients
*   ➕ Add Clients
*   ✏️ Update Clients
*   ❌ Delete Clients
*   💰 Transactions
*   🧑‍💼 Manage Users
*   📝 View Login Register
*   👑 Full Access (Admin)

---

## 💾 Data Storage
All system data is securely stored in structured text files, ensuring data persistence between sessions:
*   **`Users.txt`** → User data (includes 🔒 encrypted passwords)
*   **`LoginRegister.txt`** → Audit log of all login history
*   **`Currencies.txt`** → Current exchange rates and currency codes
*   **Clients & Transactions** → Stored in dedicated, structured files





