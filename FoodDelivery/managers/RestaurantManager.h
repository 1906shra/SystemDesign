#ifndef RESTAURANT_MANAGER_H
#define RESTAURANT_MANAGER_H

#include <iostream>
#include <vector>
#include "../models/Restaurent.h"
using namespace std;
class RestaurantManager {
    private:
    vector<Restuarent> restaurants;
    static RestaurantManager* instance;
    RestaurantManager() {}
    public:
    static RestaurantManager* getInstance() {
        if (instance == nullptr) {
            instance = new RestaurantManager();
        }
        return instance;
    }
    void addRestaurant(const Restuarent& restaurant) {
        restaurants.push_back(restaurant);
    }
    vector<Restuarent> searchByLocation(const string& location) {
        for (const auto& restaurant : restaurants) {
            if (restaurant.getAddress() == location) {
                cout << "Restaurant Found: " << restaurant.getName() << ", Address: " << restaurant.getAddress() << endl;
            }
        }
        return restaurants;
    }

};
RestaurantManager* RestaurantManager::instance = nullptr;

#endif