#include <iostream>
#include <stdexcept>
#include <string>

class EstateOwner;
class GroceryStore;
class Restaurant;

class BusinessMediator
{
public:
    BusinessMediator(EstateOwner& estateOwner, GroceryStore& groceryStore, Restaurant& restaurant);

    void EstateRentPriceChanged(std::int32_t oldPrice, std::int32_t newPrice);
    void GroceryStockChanged(std::int32_t currentStock);
    void GroceryPriceChanged(std::int32_t oldPrice, std::int32_t newPrice);
    void FoodIsCooked();

private:
    EstateOwner& estateOwner_;
    GroceryStore& groceryStore_;
    Restaurant& restaurant_;
};

class EstateOwner
{
public:
    std::int32_t SetEstateRentPrice(std::int32_t price)
    {
        auto oldPrice = estateRentPrice_;
        estateRentPrice_ = price;
        if (mediator_) mediator_->EstateRentPriceChanged(oldPrice, price);
        return oldPrice;
    }
    
    BusinessMediator* SetBusinessMediator(BusinessMediator* mediator)
    {
        BusinessMediator* old = mediator_;
        mediator_ = mediator;
        return old;
    }

private:
    BusinessMediator* mediator_{ nullptr };
    std::int32_t estateRentPrice_{ 10000 };
};

class GroceryStore
{
public:
    std::int32_t Supply(std::uint16_t count)
    {
        stock_ += count;
        if (mediator_) mediator_->GroceryStockChanged(stock_);
        return stock_;
    }

    std::int32_t Sell()
    {
        if (stock_ <= 0)
        {
            throw std::logic_error("Not in stock.");
        }

        --stock_;
        if (mediator_) mediator_->FoodIsCooked();
        return price_;
    }

    std::int32_t AlterPrice(std::int32_t priceChange)
    {
        price_ += priceChange;
        return price_;
    }

    BusinessMediator* SetBusinessMediator(BusinessMediator* mediator)
    {
        BusinessMediator* old = mediator_;
        mediator_ = mediator;
        return old;
    }

private:
    GroceryStore& groceryStore_;
    BusinessMediator* mediator_{ nullptr };
    bool isOpened_{ true };
    std::int32_t price_{ 500 };
    std::int32_t stock_{ 0 };

    std::int32_t CookFood()
    {
        if (isOpened_)
        {
            return price_;
        }
        else
        {
            return -1;
        }
    }
};

class Restaurant
{
public:
    Restaurant(GroceryStore& groceryStore) : groceryStore_(groceryStore) {}

    std::int32_t AlterPrice(std::int32_t priceChange)
    {
        price_ += priceChange;
        return price_;
    }

    BusinessMediator* SetBusinessMediator(BusinessMediator* mediator)
    {
        BusinessMediator* old = mediator_;
        mediator_ = mediator;
        return old;
    }

private:
    GroceryStore& groceryStore_;
    BusinessMediator* mediator_{ nullptr };
    std::int32_t price_{ 1000 };
};

BusinessMediator::BusinessMediator(EstateOwner& estateOwner, GroceryStore& groceryStore, Restaurant& restaurant)
    : estateOwner_(estateOwner), groceryStore_(groceryStore), restaurant_(restaurant)
{
    estateOwner_.SetBusinessMediator(this);
    groceryStore_.SetBusinessMediator(this);
    restaurant_.SetBusinessMediator(this);
}

void BusinessMediator::EstateRentPriceChanged(std::int32_t oldPrice, std::int32_t newPrice)
{
    groceryStore_.AlterPrice((newPrice - oldPrice) / 10000);
    restaurant_.AlterPrice((newPrice - oldPrice) / 1000);
}

void BusinessMediator::GroceryStockChanged(std::int32_t currentStock)
{
    if (currentStock > 0)
    {
        restaurant_.SetBusinessMediator(true);
    }
    else
    {
        restaurant_.SetBusinessMediator(false);
    }
}

void BusinessMediator::GroceryPriceChanged(std::int32_t oldPrice, std::int32_t newPrice)
{
    restaurant_.AlterPrice(newPrice - oldPrice);
}

void BusinessMediator::Food
