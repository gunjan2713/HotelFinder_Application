#include "hashtable.hpp"
// constructor for the HashTable class
HashTable::HashTable(int capacity) {
    // sets the capacity of the hash table to the value passed as a parameter to the constructor
    this->capacity = capacity;
// initnalize to 0
    size = 0;
    collisions = 0;
// dynamically allocates memory for an array of linked lists called buckets
    buckets = new list<Entry>[capacity];
}


unsigned long HashTable::hashCode(const string key) {
    unsigned long hash = 5381;
	// a for loop that iterates over each character in the string key
    for (size_t i = 0; i < key.length(); ++i) {
		// the current value of hash is multiplied by 37 and then the ASCII value of the current character (key[i]) is added to it
        hash = 31 * hash + key[i];  
    }
	// ensure that the hash value is within the bounds of the hash table's capacity
    return hash % capacity;
}


// function responisble for inserting data into the hashtable , key is hotelname,cityname and value is hotel object
void HashTable::insert(string key, Hotel* value) {
// it calculates the hash code for the key
    unsigned long index = hashCode(key);
// initializes a boolean variable found to false
    bool found = false;
// for loop that iterates through the linked list located at the  index in the buckets array
    for (auto& entry : buckets[index]) {
    // if the key of the current entry matches the key 
        if (entry.key == key) {
        // updates the value of the existing entry with the new value
            entry.value = value;
        // update the boolean variable to true
            found = true;
            cout << "Existing record has been updated" << endl;
            break;
        }
    }
// not empty means multiple keys hashed to the same index
    if (!buckets[index].empty()) {
    // increments the counter
        collisions++;
    }
// if matching entry was not found
    if (!found) {
    // create a new Entry object
        Entry newEntry(key, value);
    // adds the new entry to the end of the linked list at the computed index in the buckets array
        buckets[index].push_back(newEntry);

    // searches for the position of the first comma (,) in the key string
        size_t FirstComma = key.find(",");
    //  if found it means the key contains a city name
        if (FirstComma != string::npos) {
// itextracts the city name by taking a substring of the key string starting from the position after the comma
            string cityName = key.substr(FirstComma + 1);
// it calls insert function of bst class to add the data to bst 
        cityRecords.insert(cityRecords.getRoot(),cityName, value);
        }

        cout << "New record has been successfully added to the database" << endl;
        size++;
    }
}

// it finds the details of the hotel with the key(hotelname,cityname)

Hotel* HashTable::find(string key) {
// calculates the hash code for the key
    unsigned long index = hashCode(key);
//  initializes an integer variable comparisons to 0
    int comparisons = 0; 
// for loop that iterates through the linked list located at the computed index in the buckets array
    for (auto& entry : buckets[index]) {
        comparisons++;  
//  if the key of the current entry matches the key passed as a parameter
        if (entry.key == key) {
            cout << "Number of comparisons: " << comparisons << endl;
    // returns a pointer to the Hotel object associated with the matching key
            return entry.value;
        }
    }

    cout << "No matching record found after " << comparisons << " comparisons." << endl;
    return nullptr;
}

// this function basicallly searches in BST based on the city name and stars
void HashTable::findAll(string city, string stars) {
//    uses the find method of the cityRecords BST
    Node<string, Hotel*>* result = cityRecords.find(cityRecords.getRoot(), city, stars);
// if there is no result 
    if (result == nullptr) {
        cout << "No matching record found for the given city and stars." << endl;
    } 
}

// is responsible for removing an entry from the hash table based on the provided key
void HashTable::erase(string key) {
// calculates the hash code for the key
    unsigned long index = hashCode(key);
// creates a reference bucket that refers to the linked list (bucket) at the computed index in the buckets array
    auto& bucket = buckets[index];
// for loop that iterates through the elements of the linked list  at the computed index
    for (auto it = bucket.begin(); it != bucket.end(); ++it) {
    // if key of the current entry  matches the key passed as a parameter
        if (it->key == key) {
// erase the element and update teh size
            it = bucket.erase(it); 
            size--;
    // call remove method of bst class to delte the hotel record from bst as well
            cityRecords.remove(cityRecords.getRoot(), key, it->value);
            cout<<key<<" has been successfully Deleted"<<endl;
            return;
        }
        else{
            cout<<"Restaurant Not Found in the records"<<endl;
        }
    }
    
    
}

// returns size of the hashtable
unsigned int HashTable::getSize() {
    return size;
}
// retuns no of collisions 
unsigned int HashTable::getCollisions() {
    return collisions;
}

// it dumps the content of the hash table to the provided path
void HashTable::dump(string path) {
// opens the file specified by the path
    ofstream file(path);
// keeps track of the number of entries written to the file
    int count = 0; 
// if the file was successfully opened
    if (file.is_open()) {
// for loop that iterates through the entire hash table
        for (int i = 0; i < capacity; ++i) {
// iterates through each entry in the linked list (bucket) at the current index i
            for (const auto& entry : buckets[i]) {
        // it writes the data of each entry to the file
                file << entry.key << "," << entry.value->getCity() << "," << entry.value->getStars()
                     << "," << entry.value->getPrice() << "," << entry.value->getCountry() << ","
                     << entry.value->getAddress() << "\n";
        // // increment count for each entry written
                count++; 
            }
        }
    // close the file
        file.close();
        cout << count << " entries successfully exported to file '" << path << "'" << endl;
    } else {
        cerr << "Unable to open file for dumping!" << endl;
    }
}

// destructor 
HashTable::~HashTable() {
    delete[] buckets;
}
