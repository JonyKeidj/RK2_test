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
        if (mediator_) mediator_->GroceryStockChanged(stock_);
        return price_;
    }

    std::int32_t GetPrice() const
    {
        return price_;
    }

    std::int32_t AlterPrice(std::int32_t priceChange)
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

    bool IsOpened() const
    {
        return isOpened_;
    }

    void SetIsOpened(bool isOpened)
    {
        isOpened_ = isOpened;
    }

    std::int32_t GetPrice() const
    {
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
        restaurant_.SetIsOpened(true);
    }
    else
    {
        restaurant_.SetIsOpened(false);
    }
}

void BusinessMediator::GroceryPriceChanged(std::int32_t oldPrice, std::int32_t newPrice)
{
    restaurant_.AlterPrice(newPrice - oldPrice);
}

void BusinessMediator::FoodIsCooked()
{
    groceryStore_.Sell();
}

void BuyFood(Restaurant& restaurant)
{
    auto price = restaurant.CookFood();
    if (price >= 0)
    {
        std::cout << "[BuyFood] The price of food : " << price << std::endl;
    }
    else
    {
        std::cout << "[BuyFood] Restaurant was closed because groceries are lacking." << std::endl;
    }
}

void SupplyGrocery(GroceryStore& groceryStore, std::uint16_t count)
{
    auto newCount = groceryStore.Supply(count);
    auto oldCount = newCount - count;
    std::cout << "Grocery Stock Changes : " << oldCount << " -> " << newCount << std::endl;
}

void ChangeGroceryPrice(GroceryStore& groceryStore, std::int32_t priceChange)
{
    auto newPrice = groceryStore.AlterPrice(priceChange);
    auto oldPrice = newPrice - priceChange;
    std::cout << "Grocery Price Changes : " << oldPrice << " -> " << newPrice << std::endl;
}

void ChangeEstateRentPrice(EstateOwner& estateOwner, std::int32_t newPrice)
{
    auto oldPrice = estateOwner.SetEstateRentPrice(newPrice);
    std::cout << "EstateRentPrice Changes : " << oldPrice << " -> " << newPrice << std::endl;
}
