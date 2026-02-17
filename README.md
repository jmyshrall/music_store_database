# Music Store Inventory System

A command-line inventory management application written in C++ that tracks music albums across multiple stores or catalog files. Supports loading inventory from flat files, searching by various criteria, and managing album lifecycle states (new, sold, returned).

## Features

- Load and merge inventory from multiple flat files
- Search albums by title, band, year, or band member name
- Mark albums as sold with a sale date
- Process album returns
- Display full inventory with all metadata

## Project Structure

```
├── Album.h / Album.cpp       # Album data model
├── Node.h / Node.cpp         # Linked list node
├── Inventory.h / Inventory.cpp  # Inventory management and search logic
├── Store.h / Store.cpp       # UI layer and user interaction
├── Project.cpp               # Entry point
└── doc/
    ├── MusicDB1.txt          # Sample inventory file (store 1)
    ├── MusicDB2.txt          # Sample inventory file (store 2)
    └── MusicDB3.txt          # Minimal test file
```

## Data File Format

Inventory files follow this structure:

```
<album_count> <store_id>
<album_id> <title> <band> <year> <num_members> <member1> ... <memberN> <state> [date]
```

- `state` is one of: `new`, `sold`, `return`
- `date` is only present for sold/returned albums, formatted `MM-DD-YY`

Example:
```
2 1
101101 Back-In-Black AC/DC 1980 3 Brian-Johnson Angus-Young Malcom-Young new
102101 Some-Girls Rolling-Stones 1978 2 Mick-Jagger Keith-Richards sold 9-20-24
```

Note: multi-word titles, band names, and member names use hyphens in place of spaces.

## Building

Compile all `.cpp` files together with a C++11 or later compiler:

```bash
g++ -std=c++11 -o music_store Project.cpp Store.cpp Inventory.cpp Album.cpp Node.cpp
```

## Usage

Run the compiled binary and interact via the menu:

```
--- Store Menu ---

1. Update Inventory from File
2. Search Inventory
3. Sell an Album
4. Return an Album
5. Display Entire Inventory
6. Exit
```

Multiple inventory files can be loaded sequentially; each load prepends its albums to the existing in-memory list.

## Implementation Notes

- Inventory is stored as a singly linked list; new albums are prepended at the head.
- `Album` objects manage their own `members` array on the heap and clean it up in the destructor.
- Album IDs encode both the album type and copy number (e.g., `105203` = album type 1052, copy 03).
- Search results are numbered and printed to stdout; no persistent state is written back to disk.
