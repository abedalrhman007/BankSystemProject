🏦 Bank Management System (C++ / OOP)

A robust console-based Bank Management System developed in C++, designed using core Object-Oriented Programming (OOP) principles.
The system simulates real-world banking operations including authentication, client management, financial transactions, permissions control, and currency exchange services.

📌 Overview

This project demonstrates a layered and modular software architecture built to ensure scalability, maintainability, and security.

##Key design aspects include:

Persistent file-based data storage
Custom encryption for sensitive information
Role-based access control (RBAC)
Modular screen-driven UI design
Separation of concerns across system layers
##🧱 System Architecture
🔐 Authentication & Security Layer
Secure login system with limited attempts (3 tries)
Encrypted password storage using custom encryption logic
Login activity logging (audit trail)
Role-based access control (Admin / User permissions)
##🧑‍💼 User Management Module
Create, update, and delete system users
Assign and manage granular permissions
Track user login history
Secure user data persistence with encryption
##👥 Client Management Module
Full CRUD operations for client records
Search functionality for efficient retrieval
Structured display of client database
Secure and persistent client storage
##💰 Financial Transactions Module
Deposit and withdrawal operations
Secure transfer of funds between clients
Transaction validation and integrity checks
Complete transaction history logging
##🌍 Currency Exchange Module
Currency data loaded from external files
Search currencies by code or country
Real-time USD-based conversion system
Ability to update exchange rates dynamically
##🖥️ Console UI System
Menu-driven navigation architecture
Screen-based modular UI design
Colored terminal output for better usability
Organized and reusable screen components

🔑 Permission System (RBAC)

The system implements bitwise-based permission control, enabling fine-grained access management:

View Clients
Add Clients
Update Clients
Delete Clients
Perform Transactions
Manage Users
View Login Logs
Full Administrative Access

This design allows flexible role definition while maintaining security boundaries.

🛠️ Technologies & Concepts
Language: C++
Paradigm: Object-Oriented Programming (OOP)
Data Handling: File Streams (fstream)
Libraries: STL (vector, string)
Security: Custom encryption & decryption system
UI: Console-based modular screen architecture
