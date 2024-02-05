#include "hotel.hpp"
#include <iomanip>

// constructor
// initializes the members 
Hotel::Hotel(string name, string city, string stars, string price, string country, string address)
    : name(name), city(city), stars(stars), price(price), country(country), address(address) {}

// returns name
string Hotel::getName() { return name; }
//  returns city
string Hotel::getCity() { return city; }
//  returns stars
string Hotel::getStars() { return stars; }
//  returns price
string Hotel::getPrice() { return price; }
//  returns country
string Hotel::getCountry() { return country; }
//  returns address
string Hotel::getAddress() { return address; }

// converts the Hotel object's data into a single string representation
string Hotel::toString() {
    return name + "," + city + "," + stars + "," + price + "," + country + "," + address;
}

// it prints hotel details
void Hotel::print() {
    cout << "Name: " << name << endl;
    cout << "City: " << city << endl;
    cout << "Stars: " << stars << endl;
    cout << "Price: " << price << endl;
    cout << "Country: " << country << endl;
    cout << "Address: " << address << endl;
}

// print the details of a Hotel object in a tabular format
void Hotel::print2() {
// setw() manipulator sets the field width for the next output operation
    cout << std::left << setw(50) << name << " " << setw(10) << city << " " << setw(5) << stars << " "<< setw(10) << price << " " << setw(20) << country << " " << address << endl;
}
