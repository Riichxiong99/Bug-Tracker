# BugTracker

A console-based bug and feature tracking system written in C++. Manage bugs, feature requests, customers, employees, and products through a menu-driven interface with persistent binary storage.

## Features

- **Bugs** — Create and track bug reports with priority, date, and submitter info
- **Features** — Log feature requests and link them to products
- **Products** — Manage products and generate reports of their associated bugs/features
- **Customers & Employees** — Maintain contact records for stakeholders

## Requirements

- C++17 compatible compiler (g++, clang++)
- CMake 3.28+

## Build & Run

```bash
mkdir -p build && cd build
cmake ..
make
./BugTrackerPro
```

## Data

Records are persisted as binary files in `data/`:

| File | Contents |
|------|----------|
| `customers.dat` | Customer records |
| `employees.dat` | Employee records |
| `products.dat` | Products with embedded bugs and features |

The `data/` directory is created automatically on first run.
