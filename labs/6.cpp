#include <vector>
#include <iostream>
#include <algorithm>

int maxProfit(std::vector<int>& prices) {
    int n = prices.size();
    if (n <= 1) {
        return 0;
    }

    std::vector<int> leftProfit(n, 0); // Максимальная прибыль при покупке на i-й день и продаже на или до i-го дня
    std::vector<int> rightProfit(n, 0); // Максимальная прибыль при покупке после i-го дня и продаже на или после i-го дня

    int minPrice = prices[0];
    for (int i = 1; i < n; i++) {
        minPrice = std::min(minPrice, prices[i]);
        leftProfit[i] = std::max(leftProfit[i-1], prices[i] - minPrice);
    }

    int maxPrice = prices[n-1];
    for (int i = n-2; i >= 0; i--) {
        maxPrice = std::max(maxPrice, prices[i]);
        rightProfit[i] = std::max(rightProfit[i+1], maxPrice - prices[i]);
    }

    int maxProfit = 0;
    for (int i = 0; i < n; i++) {
        maxProfit = std::max(maxProfit, leftProfit[i] + rightProfit[i]);
    }

    return maxProfit;
}
int main(){
    //Измените значения а при необходимости
    std::vector<int>a={1,2,3,4,5};

    std::cout << maxProfit(a);
    return 0;
}
