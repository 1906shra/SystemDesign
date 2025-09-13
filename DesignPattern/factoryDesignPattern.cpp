#include <iostream>
#include <memory>
#include <string>
using namespace std;

// ------------------- Product (Abstract Burger) -------------------
class Burger {
public:
    virtual void prepare() = 0;
    virtual ~Burger() = default;
};

// ------------------- Concrete Burgers -------------------
class McdVegBurger : public Burger {
public:
    void prepare() override {
        cout << "🍔 McDonald's Veg Burger with special McSauce" << endl;
    }
};

class McdChickenBurger : public Burger {
public:
    void prepare() override {
        cout << "🍔 McDonald's Chicken Burger with crispy patty" << endl;
    }
};

class BkVegBurger : public Burger {
public:
    void prepare() override {
        cout << "🍔 Burger King Veg Burger with flame-grilled flavor" << endl;
    }
};

class BkChickenBurger : public Burger {
public:
    void prepare() override {
        cout << "🍔 Burger King Chicken Burger with Whopper style" << endl;
    }
};

// ------------------- Abstract Factory -------------------
class BurgerFranchise {
public:
    virtual unique_ptr<Burger> createVegBurger() = 0;
    virtual unique_ptr<Burger> createChickenBurger() = 0;
    virtual ~BurgerFranchise() = default;
};

// ------------------- Concrete Factories -------------------
class McDonalds : public BurgerFranchise {
public:
    unique_ptr<Burger> createVegBurger() override {
        return make_unique<McdVegBurger>();
    }
    unique_ptr<Burger> createChickenBurger() override {
        return make_unique<McdChickenBurger>();
    }
};

class BurgerKing : public BurgerFranchise {
public:
    unique_ptr<Burger> createVegBurger() override {
        return make_unique<BkVegBurger>();
    }
    unique_ptr<Burger> createChickenBurger() override {
        return make_unique<BkChickenBurger>();
    }
};

// ------------------- Client -------------------
int main() {
    // Choose a franchise
    unique_ptr<BurgerFranchise> mcd = make_unique<McDonalds>();
    unique_ptr<BurgerFranchise> bk = make_unique<BurgerKing>();

    cout << "--- McDonald's Menu ---" << endl;
    auto mcdVeg = mcd->createVegBurger();
    auto mcdChicken = mcd->createChickenBurger();
    mcdVeg->prepare();
    mcdChicken->prepare();

    cout << "\n--- Burger King Menu ---" << endl;
    auto bkVeg = bk->createVegBurger();
    auto bkChicken = bk->createChickenBurger();
    bkVeg->prepare();
    bkChicken->prepare();

    return 0;
}
