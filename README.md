[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/pAwGQi_N)

# PA4 Skeleton Code
We expect a fully functioninig command line REPL application for an inventory querying system. Feel free to modify the skeleton code as you see fit.

### How to run the current skeleton code
`make` will compile and execute the skeleton code

The application ships with the zip file containing the csv to minimize the size of the repo.
Assuming your system can run the `unzip` command, it will be unzipped into lib/ on the first run.

Only fields up to SKU will be populated, as anything other than Uniq ID, Product Name, and Categories are useless to this project.

There is an item which has an unprintable character (ID: 2fc087697d6b94b83ba2856c32e58284, char: ). Due to how I ship the csv, I just remove it in the process of turning it into an object, but it could cause issues in other items' fields. No other item has this character in the product name.

Apparently mingw32-make wants Makefile to be all lowercase (eeg. makefile)? That was infuriating.

Run tests with `make test`

The pattern of testing I went with for each object was insertion, access/find, delete (if applicable), and find after delete. I chose this as it seemed like the most robust way to test the objects for faliure.
